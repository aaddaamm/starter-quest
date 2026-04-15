# Scenario System Design

## Overview

A **Scenario** is the top-level container for a self-contained game experience. It coordinates one or more **Quests**, which are composed of **Scenes** (branching narrative moments) and **Encounters** (combat or challenge events). This document describes the class hierarchy, data flow, and C++ implementation plan.

---

## Hierarchy

```text
Scenario
└── Quest[]
    └── Scene[]
        ├── Encounter  (optional - combat/challenge)
        └── Choice[]   (optional - branching narrative)
```

A Scenario runs Quests in sequence (or by player choice). Each Quest runs its Scenes in order. A Scene may present choices, trigger an Encounter, or both.

---

## Class Designs

### 1. `Scenario`

The outermost container. Owns a list of Quests and tracks overall game state.

```cpp
class Scenario {
public:
  Scenario(const std::string& title, const std::string& description);

  void addQuest(Quest* quest);
  void run(Character* character);   // drives the main game loop

  std::string getTitle() const;
  bool isComplete() const;

private:
  std::string title;
  std::string description;
  std::vector<Quest*> quests;
  int currentQuestIndex;
};
```

**Responsibilities:**
- Present the scenario premise to the player
- Advance through quests as each one completes
- Report overall success/failure when all quests resolve

---

### 2. `Quest`

A named objective with a sequence of Scenes. A Quest resolves as `success`, `failure`, or `abandoned`.

```cpp
enum class QuestOutcome { Success, Failure, Abandoned };

class Quest {
public:
  Quest(const std::string& name, const std::string& objective);

  void addScene(Scene* scene);
  QuestOutcome run(Character* character);

  std::string getName() const;
  std::string getObjective() const;

private:
  std::string name;
  std::string objective;
  std::vector<Scene*> scenes;
  QuestOutcome outcome;
};
```

**Responsibilities:**
- Display the quest objective at start
- Run scenes in sequence, passing the character through
- Resolve the outcome based on scene results (e.g., a failed Encounter ends the quest as Failure)

---

### 3. `Scene`

A single narrative beat. Can contain descriptive text, player choices, and/or an Encounter. Scenes are the primary place where story branching happens. Scenes can also grant items to the character's inventory.

```cpp
enum class SceneOutcome { Continue, QuestSuccess, QuestFailure };

struct Choice {
  std::string prompt;           // e.g. "Attempt to pick the lock"
  Scene* leadsTo;               // nullptr = end of branch
};

class Scene {
public:
  Scene(const std::string& description);

  void setEncounter(Encounter* encounter);
  void addChoice(const std::string& prompt, Scene* next);
  void addItem(Item* item);           // item granted on entering this scene

  // Separate next-scenes for each encounter outcome
  void setVictoryScene(Scene* next);
  void setDefeatScene(Scene* next);
  void setFledScene(Scene* next);     // nullptr = same as defeat by default

  SceneOutcome run(Character* character);

private:
  std::string description;
  Encounter* encounter;
  std::vector<Choice> choices;
  std::vector<Item*> grantedItems;    // awarded to character on entry
  Scene* victoryScene;
  Scene* defeatScene;
  Scene* fledScene;

  int promptChoice() const;
};
```

**Responsibilities:**
- Print the scene description
- Grant any items to the character on entry
- Run an Encounter if present; branch to victory/defeat/fled scene
- Present choices to the player and advance to the selected next Scene
- Return a `SceneOutcome` that the Quest uses to determine continuation

**Branching rules:**
- Encounter `Victory` → advance to `victoryScene` (or next choice prompt if null)
- Encounter `Defeat` → `QuestFailure`
- Encounter `Fled` → advance to `fledScene` (falls back to `defeatScene` if not set)
- No encounter, choices present → player picks; advance to linked Scene
- No encounter, no choices → `QuestSuccess`

---

### 4. `Encounter`

A structured challenge event. The most common type is combat, but Encounters can also represent skill challenges (persuasion, stealth, trap disarming).

```cpp
enum class EncounterType { Combat, Skill, Social };
enum class EncounterResult { Victory, Defeat, Fled };

class Encounter {
public:
  Encounter(const std::string& description, EncounterType type);

  EncounterResult run(Character* character);

  void addCreature(Creature* creature);     // for Combat
  void setDifficultyClass(int dc);          // for Skill/Social

private:
  std::string description;
  EncounterType type;
  std::vector<Creature*> creatures;
  int difficultyClass;

  EncounterResult runCombat(Character* character);
  EncounterResult runSkillChallenge(Character* character);
  EncounterResult runSocial(Character* character);
};
```

**Combat loop:**
```text
while character is alive AND creatures remain:
  print current combatants and health
  prompt: [A]ttack / [F]lee
  if Flee:
    character takes a penalty hit (e.g. half average creature damage)
    return Fled
  character attacks one creature (target selection: lowest health first, or player picks)
  each living creature attacks character
report Victory or Defeat
```

**Flee cost:** Taking a hit on retreat means fleeing isn't free, but a badly wounded character can cut their losses. The Scene receiving a `Fled` result treats it as a branch — typically a less favorable path than Victory, but not as bad as Defeat.

**Skill challenge:**
```text
roll relevant stat vs. difficultyClass
pass → Victory, fail → Defeat
player may also choose to flee before attempting (same flee cost as combat)
```

---

### 5. `Creature`

A combatant that is not the player's Character. Mirrors the Character interface enough to participate in Encounters.

```cpp
class Creature {
public:
  Creature(const std::string& name, int health, int attackPower, int defense);

  std::string getName() const;
  int getHealth() const;
  bool isAlive() const;

  int rollAttack() const;       // returns damage dealt
  void takeDamage(int amount);

private:
  std::string name;
  int health;
  int attackPower;
  int defense;
};
```

This fills in the existing stub at `baseClasses/Creature.cpp`.

---

### 6. `Item`

Items are granted by Scenes and stored in the character's inventory. They may unlock Scene choices, modify stats, or be consumed in Encounters.

```cpp
enum class ItemType { Key, Consumable, Equipment };

class Item {
public:
  Item(const std::string& name, const std::string& description, ItemType type);

  std::string getName() const;
  std::string getDescription() const;
  ItemType getType() const;
  bool isConsumed() const;      // true after a one-use item is used

private:
  std::string name;
  std::string description;
  ItemType type;
  bool consumed;
};
```

**Character inventory additions** (extends `Character`):
```cpp
void addItem(Item* item);
bool hasItem(const std::string& name) const;   // used by Scene to gate choices
void removeItem(const std::string& name);
std::vector<Item*> getInventory() const;
```

**Item-gated choices** — A `Choice` can optionally require an item:
```cpp
struct Choice {
  std::string prompt;
  Scene* leadsTo;
  std::string requiredItem;     // empty = always available
};
```
If `requiredItem` is set and the character doesn't have it, the choice is hidden (or shown as locked, depending on preference).

---

### 7. Save State

Game state is serialized to a save file so a session can be resumed. The save captures:

- Character name, health, vocation, stats, inventory
- Current Scenario title
- Current Quest index
- Current Scene identifier

```cpp
class SaveManager {
public:
  static void save(const std::string& path, const Character* character, const Scenario* scenario);
  static bool load(const std::string& path, Character*& character, Scenario*& scenario);
};
```

Save format: plain JSON (no external library needed for a simple implementation — hand-rolled serialization is fine at this scale). File written to `saves/<character_name>.json`.

Each `Scene` needs a stable string `id` (e.g. `"road_in_scene_1"`) so the save can locate the right scene on load without relying on vector index positions.

---

## Data Flow

```text
main()
  └── SaveManager::load() OR new Character + class selection
  └── Scenario::run(character)
        └── Quest::run(character)          [for each quest]
              └── Scene::run(character)    [for each scene]
                    ├── grant items to character inventory
                    ├── Encounter::run(character)  [if present]
                    │     └── combat/skill loop → Victory / Defeat / Fled
                    └── player picks Choice (filtered by inventory) → next Scene
  └── SaveManager::save() after each Scene completes
```

---

## File Layout

```text
scenarios/
  Scenario.h / Scenario.cpp
  Quest.h / Quest.cpp
  Scene.h / Scene.cpp
  Encounter.h / Encounter.cpp

baseClasses/
  Creature.h / Creature.cpp    (fill existing stub)
```

---

## Dependencies on Existing Work

This system depends on — or would be significantly improved by — the following items from the existing TODO list:

| Dependency | Why it matters |
|---|---|
| Stats wired into Character | Skill challenges need a stat to roll against |
| Weapon / attack values | Combat damage needs numbers, not just print statements |
| Character health as mutable | Encounters need to reduce and check health |
| Interactive class selection | Player should choose their vocation before a scenario starts |

The scenario system can be stubbed in without all of these (using placeholder damage values), but full mechanics require them.

---

## Example Scenario (Prose)

> **The Cursed Village** — A nearby village has gone silent. Three quests lead to the truth.
>
> - **Quest 1: The Road In** — Travel to the village. Encounter bandits on the road (Combat). Choose to help a wounded traveler or press on (Choice → branches to different Scene 2).
> - **Quest 2: The Village Square** — Investigate. Scenes include talking to a frightened elder (Social Encounter), searching the inn (Skill challenge: perception), and discovering a locked cellar (Skill challenge: lockpicking or force).
> - **Quest 3: The Source** — Descend into the cellar. Linear sequence of Combat encounters with a final boss Creature.

---

## Decisions

| Question | Decision |
|---|---|
| Quest outcomes affect later quests? | No — each quest is independent |
| Flee mechanic? | Yes — flee costs a penalty hit; leads to a less favorable Scene branch |
| Scenes grant items? | Yes — items can gate choices and be consumed in Encounters |
| Save between sessions? | Yes — saved to `saves/<character_name>.json` after each Scene |
