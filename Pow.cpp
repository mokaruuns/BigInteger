//
// Created by marse on 02.08.2022.
//
#include "BigInteger.hpp"

auto BigInteger::pow(BigInteger &BigInteger_first, BigInteger &BigInteger_second) -> BigInteger {
    BigInteger result = BigInteger("1");
    int TWO = 2;
    BigInteger ONE = BigInteger("1");
    BigInteger ZERO = BigInteger("0");
    while (BigInteger_second != ZERO) {
        if (even(BigInteger_second)) {
            BigInteger_second = division_to_short(BigInteger_second, TWO);
            BigInteger_first = BigInteger_first * BigInteger_first;
        } else {
            BigInteger_second = BigInteger_second - ONE;
            result = result * BigInteger_first;
        }
    }
    return result;
}
