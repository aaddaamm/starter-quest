/**
 * @file DiceRoller.cpp
 * @brief A utility class for simulating dice rolls for tabletop games.
 *
 * This class provides functionality for simulating various dice rolls with
 * different configurations, including single rolls, multiple rolls, rolls with
 * modifiers, and target checks. It uses the Mersenne Twister algorithm for
 * high-quality random number generation.
 */
#include <random>
#include <iostream>

/**
 * @class DiceRoller
 * @brief Simulates dice rolls for tabletop games.
 *
 * The DiceRoller class provides methods for simulating dice rolls with varying
 * configurations. It uses a Mersenne Twister random number generator seeded
 * with a random device to ensure high-quality randomness.
 */
class DiceRoller {
private:
    std::mt19937 generator; ///< Mersenne Twister random number generator

public:
    /**
     * @brief Constructor that initializes the random number generator with a random seed.
     */
    DiceRoller() {
        std::random_device rd;
        generator.seed(rd());
    }

    /**
     * @brief Roll a single die with the specified number of sides.
     *
     * @param sides The number of sides on the die.
     * @return The result of the die roll (1 to sides) or 0 if invalid input.
     */
    int roll(int sides) {
        if (sides <= 0) {
            std::cout << "Invalid number of sides: " << sides << std::endl;
            return 0;
        }
        std::uniform_int_distribution<int> distribution(1, sides);
        return distribution(generator);
    }

    /**
     * @brief Roll a die with the specified number of sides multiple times and sum the results.
     *
     * @param sides The number of sides on the die.
     * @param times The number of times to roll the die.
     * @return The sum of all die rolls or 0 if invalid input.
     */
    int roll(int sides, int times) {
        if (sides <= 0) {
            std::cout << "Invalid number of sides: " << sides << std::endl;
            return 0;
        }
        if (times <= 0) {
            std::cout << "Invalid number of times: " << times << std::endl;
            return 0;
        }
        int total = 0;
        for (int i = 0; i < times; i++) {
            total += roll(sides);
        }
        return total;
    }

    /**
     * @brief Roll a die multiple times and add a fixed modifier to the sum.
     *
     * @param sides The number of sides on the die.
     * @param times The number of times to roll the die.
     * @param modifier The value to add to the sum of the rolls.
     * @return The sum of all die rolls plus the modifier, or 0 if invalid input.
     */
    int roll(int sides, int times, int modifier) {
        if (sides <= 0) {
            std::cout << "Invalid number of sides: " << sides << std::endl;
            return 0;
        }
        if (times <= 0) {
            std::cout << "Invalid number of times: " << times << std::endl;
            return 0;
        }
        if (modifier <= 0) {
            std::cout << "Invalid modifier: " << modifier << std::endl;
            return 0;
        }

        return roll(sides, times) + modifier;
    }

    /**
     * @brief Roll a die multiple times with a modifier and check against a target number.
     *
     * @param sides The number of sides on the die.
     * @param times The number of times to roll the die.
     * @param modifier The value to add to the sum of the rolls.
     * @param target The target value that the roll must meet or exceed.
     * @return 1 if the modified roll is greater than or equal to the target, 0 otherwise or if invalid input.
     */
    int roll(int sides, int times, int modifier, int target) {
        if (sides <= 0) {
            std::cout << "Invalid number of sides: " << sides << std::endl;
            return 0;
        }
        if (times <= 0) {
            std::cout << "Invalid number of times: " << times << std::endl;
            return 0;
        }
        if (modifier <= 0) {
            std::cout << "Invalid modifier: " << modifier << std::endl;
            return 0;
        }
        if (target <= 0) {
            std::cout << "Invalid target: " << target << std::endl;
            return 0;
        }

        return roll(sides, times, modifier) >= target;
    }

    /**
     * @brief Convenience method to roll a 4-sided die.
     * @return The result of rolling a 4-sided die (1 to 4).
     */
    int roll4() {
        return roll(4);
    }

    /**
     * @brief Convenience method to roll a 6-sided die.
     * @return The result of rolling a 6-sided die (1 to 6).
     */
    int roll6() {
        return roll(6);
    }

    /**
     * @brief Convenience method to roll an 8-sided die.
     * @return The result of rolling an 8-sided die (1 to 8).
     */
    int roll8() {
        return roll(8);
    }

    /**
     * @brief Convenience method to roll a 10-sided die.
     * @return The result of rolling a 10-sided die (1 to 10).
     */
    int roll10() {
        return roll(10);
    }

    /**
     * @brief Convenience method to roll a 12-sided die.
     * @return The result of rolling a 12-sided die (1 to 12).
     */
    int roll12() {
        return roll(12);
    }

    /**
     * @brief Convenience method to roll a 20-sided die.
     * @return The result of rolling a 20-sided die (1 to 20).
     */
    int roll20() {
        return roll(20);
    }
};
