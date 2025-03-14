/**
 * @file DiceRoller.h
 * @brief A utility class for simulating dice rolls for tabletop games.
 *
 * This class provides functionality for simulating various dice rolls with
 * different configurations, including single rolls, multiple rolls, rolls with
 * modifiers, and target checks. It uses the Mersenne Twister algorithm for
 * high-quality random number generation.
 */
#pragma once

#include <random>
#include <iostream>
#include <variant>

/**
 * @enum ErrorCode
 * @brief Error codes for dice rolling operations
 */
enum class ErrorCode {
    InvalidNumberOfSides,
    InvalidNumberOfTimes,
    InvalidModifier,
    InvalidTarget,
    ValidParameters,
    Success
};

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

    /**
     * @struct Result
     * @brief Represents the result of a dice roll operation
     */
    struct Result {
        std::variant<int, ErrorCode> value;

        /**
         * @brief Constructor for success result
         * @param roll_value The successful roll value
         */
        Result(int roll_value);

        /**
         * @brief Constructor for error result
         * @param error The error code
         */
        Result(ErrorCode error);

        /**
         * @brief Check if the result is an error
         * @return true if the result is an error, false otherwise
         */
        bool isError() const;

        /**
         * @brief Get the roll value (only valid if !isError())
         * @return The roll value
         */
        int getRollValue() const;

        /**
         * @brief Get the error code (only valid if isError())
         * @return The error code
         */
        ErrorCode getError() const;

        /**
         * @brief Implicit conversion to int for backward compatibility
         * @return The roll value or 0 if error
         */
        operator int() const;
    };

public:
    /**
     * @brief Constructor that initializes the random number generator with a random seed.
     */
    DiceRoller();

    /**
     * @brief Roll a single die with the specified number of sides.
     *
     * @param sides The number of sides on the die.
     * @return Result containing the die roll value or an error code.
     */
    Result roll(int sides);

    /**
     * @brief Roll a die with the specified number of sides multiple times and sum the results.
     *
     * @param sides The number of sides on the die.
     * @param times The number of times to roll the die.
     * @return Result containing the sum of all die rolls or an error code.
     */
    Result roll(int sides, int times);

    /**
     * @brief Roll a die multiple times and add a fixed modifier to the sum.
     *
     * @param sides The number of sides on the die.
     * @param times The number of times to roll the die.
     * @param modifier The value to add to the sum of the rolls.
     * @return Result containing the sum of all die rolls plus the modifier, or an error code.
     */
    Result roll(int sides, int times, int modifier);

    /**
     * @brief Roll a die multiple times with a modifier and check against a target number.
     *
     * @param sides The number of sides on the die.
     * @param times The number of times to roll the die.
     * @param modifier The value to add to the sum of the rolls.
     * @param target The target value that the roll must meet or exceed.
     * @return Result containing 1 if the modified roll >= target, 0 if not, or an error code.
     */
    Result roll(int sides, int times, int modifier, int target);

    /**
     * @brief Convenience method to roll a 4-sided die.
     * @return Result containing the result of rolling a 4-sided die.
     */
    Result roll4();

    /**
     * @brief Convenience method to roll a 6-sided die.
     * @return Result containing the result of rolling a 6-sided die.
     */
    Result roll6();

    /**
     * @brief Convenience method to roll an 8-sided die.
     * @return Result containing the result of rolling an 8-sided die.
     */
    Result roll8();

    /**
     * @brief Convenience method to roll a 10-sided die.
     * @return Result containing the result of rolling a 10-sided die.
     */
    Result roll10();

    /**
     * @brief Convenience method to roll a 12-sided die.
     * @return Result containing the result of rolling a 12-sided die.
     */
    Result roll12();

    /**
     * @brief Convenience method to roll a 20-sided die.
     * @return Result containing the result of rolling a 20-sided die.
     */
    Result roll20();
};
