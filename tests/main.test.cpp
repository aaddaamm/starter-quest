#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"

#include "../utils/DiceRoller.h"

TEST_CASE("DiceRoller Roll Validation", "[DiceRoller]") {
    DiceRoller roller;

    SECTION("Single roll") {
        for (int i = 0; i < 100; ++i) {
            auto result = roller.roll(6);
            REQUIRE(!result.isError());
            int value = result.getRollValue();
            REQUIRE(value >= 1);
            REQUIRE(value <= 6);
        }
    }

    SECTION("Multiple rolls") {
        for (int i = 0; i < 100; ++i) {
            auto result = roller.roll(6, 2);
            REQUIRE(!result.isError());
            int value = result.getRollValue();
            REQUIRE(value >= 2);
            REQUIRE(value <= 12);
        }
    }

    SECTION("Multiple rolls with modifier") {
        for (int i = 0; i < 100; ++i) {
            auto result = roller.roll(6, 2, 5);
            REQUIRE(!result.isError());
            int value = result.getRollValue();
            REQUIRE(value >= 7);
            REQUIRE(value <= 17);
        }
    }

    SECTION("Roll with target") {
        for (int i = 0; i < 100; ++i) {
            auto result = roller.roll(20, 1, 0, 10);
            REQUIRE(!result.isError());
            int value = result.getRollValue();
            REQUIRE((value == 0 || value == 1));
        }
    }
}

TEST_CASE("DiceRoller Convenience Methods", "[DiceRoller]") {
    DiceRoller roller;

    SECTION("roll4") {
        for (int i = 0; i < 100; ++i) {
            auto result = roller.roll4();
            REQUIRE(!result.isError());
            int value = result.getRollValue();
            REQUIRE(value >= 1);
            REQUIRE(value <= 4);
        }
    }

    SECTION("roll6") {
        for (int i = 0; i < 100; ++i) {
            auto result = roller.roll6();
            REQUIRE(!result.isError());
            int value = result.getRollValue();
            REQUIRE(value >= 1);
            REQUIRE(value <= 6);
        }
    }

    SECTION("roll8") {
        for (int i = 0; i < 100; ++i) {
            auto result = roller.roll8();
            REQUIRE(!result.isError());
            int value = result.getRollValue();
            REQUIRE(value >= 1);
            REQUIRE(value <= 8);
        }
    }

    SECTION("roll10") {
        for (int i = 0; i < 100; ++i) {
            auto result = roller.roll10();
            REQUIRE(!result.isError());
            int value = result.getRollValue();
            REQUIRE(value >= 1);
            REQUIRE(value <= 10);
        }
    }

    SECTION("roll12") {
        for (int i = 0; i < 100; ++i) {
            auto result = roller.roll12();
            REQUIRE(!result.isError());
            int value = result.getRollValue();
            REQUIRE(value >= 1);
            REQUIRE(value <= 12);
        }
    }

    SECTION("roll20") {
        for (int i = 0; i < 100; ++i) {
            auto result = roller.roll20();
            REQUIRE(!result.isError());
            int value = result.getRollValue();
            REQUIRE(value >= 1);
            REQUIRE(value <= 20);
        }
    }
}

TEST_CASE("DiceRoller Error Handling", "[DiceRoller]") {
    DiceRoller roller;

    SECTION("Invalid number of sides") {
        auto result = roller.roll(1);
        REQUIRE(result.isError());
        REQUIRE(result.getError() == DiceRoller::ErrorCode::InvalidNumberOfSides);
    }

    SECTION("Invalid number of times") {
        auto result = roller.roll(6, 0);
        REQUIRE(result.isError());
        REQUIRE(result.getError() == DiceRoller::ErrorCode::InvalidNumberOfTimes);
    }
}