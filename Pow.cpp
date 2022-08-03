//
// Created by marse on 02.08.2022.
//
#include "BigInteger.hpp"

auto BigInteger::pow(const BigInteger &BigInteger_first, const BigInteger &BigInteger_second) -> BigInteger {
    BigInteger first = BigInteger_first;
    BigInteger second = BigInteger_second;
    BigInteger result = BigInteger("1");
    int TWO = 2;
    BigInteger ONE = BigInteger("1");
    BigInteger ZERO = BigInteger("0");
    while (second != ZERO) {
        if (even(second)) {
            second = division_to_short(second, TWO);
            first = first * first;
        } else {
            second = second - ONE;
            result = result * first;
        }
    }
    return result;
}
