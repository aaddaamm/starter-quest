#include "utils/DiceRoller.h"
#include <stdexcept>

// --- DiceRoller::Result Implementation ---

DiceRoller::Result::Result(int roll_value) : value(roll_value) {}

DiceRoller::Result::Result(DiceRoller::ErrorCode error) : value(error) {}

bool DiceRoller::Result::isError() const {
    return std::holds_alternative<DiceRoller::ErrorCode>(value);
}

int DiceRoller::Result::getRollValue() const {
    if (const int* val = std::get_if<int>(&value)) {
        return *val;
    }
    // If you call getRollValue() on an error, it's a logic error.
    // The original code would have undefined behavior. Throwing is safer.
    throw std::logic_error("Attempted to get roll value from a Result holding an error.");
}

DiceRoller::ErrorCode DiceRoller::Result::getError() const {
    if (const ErrorCode* err = std::get_if<ErrorCode>(&value)) {
        return *err;
    }
    throw std::logic_error("Attempted to get error code from a Result holding a value.");
}

DiceRoller::Result::operator int() const {
    if (isError()) {
        return 0; // For backward compatibility
    }
    return std::get<int>(value);
}

// --- DiceRoller Class Implementation ---

DiceRoller::DiceRoller() {
    std::random_device rd;
    generator.seed(rd());
}

DiceRoller::Result DiceRoller::roll(int sides) {
    // A die must have at least 2 sides.
    if (sides <= 1) {
        return Result(ErrorCode::InvalidNumberOfSides);
    }
    std::uniform_int_distribution<int> distribution(1, sides);
    return Result(distribution(generator));
}

DiceRoller::Result DiceRoller::roll(int sides, int times) {
    if (sides <= 1) {
        return Result(ErrorCode::InvalidNumberOfSides);
    }
    if (times <= 0) {
        return Result(ErrorCode::InvalidNumberOfTimes);
    }

    int total = 0;
    std::uniform_int_distribution<int> distribution(1, sides);
    for (int i = 0; i < times; ++i) {
        total += distribution(generator);
    }
    return Result(total);
}

DiceRoller::Result DiceRoller::roll(int sides, int times, int modifier) {
    Result base_roll = roll(sides, times);
    if (base_roll.isError()) {
        return base_roll;
    }
    return Result(base_roll.getRollValue() + modifier);
}

DiceRoller::Result DiceRoller::roll(int sides, int times, int modifier, int target) {
    Result modified_roll = roll(sides, times, modifier);
    if (modified_roll.isError()) {
        return modified_roll;
    }
    return Result(modified_roll.getRollValue() >= target ? 1 : 0);
}

DiceRoller::Result DiceRoller::roll4() {
    return roll(4);
}

DiceRoller::Result DiceRoller::roll6() {
    return roll(6);
}

DiceRoller::Result DiceRoller::roll8() {
    return roll(8);
}

DiceRoller::Result DiceRoller::roll10() {
    return roll(10);
}

DiceRoller::Result DiceRoller::roll12() {
    return roll(12);
}

DiceRoller::Result DiceRoller::roll20() {
    return roll(20);
}