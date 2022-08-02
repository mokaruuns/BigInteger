//
// Created by marse on 02.08.2022.
//
#include "BigInteger.hpp"

auto BigInteger::negate(const BigInteger &A) -> BigInteger {
    BigInteger B = A;
    B.is_negate = !A.is_negate;
    return B;
}

auto BigInteger::even(const BigInteger &A) -> bool {
    return (A.digits.back() & 1) == 0;
}

auto BigInteger::odd(const BigInteger &A) -> bool {
    return !even(A);
}

auto BigInteger::module(const BigInteger &A, BigInteger B) -> BigInteger {
    unsigned int num = B.digits.back();
    if (num == 0) {
        BigInteger N;
        N.is_nan = true;
        return N;
    }
    return subtract(A, multiplication(B, division_to_long(A, B)));
}

auto BigInteger::sqrt(const BigInteger &A) -> BigInteger {
    if (A.is_negate) {
        BigInteger N;
        N.is_nan = true;
        return N;
    }
    BigInteger L;
    L = BigInteger("1");
    int T = 2;
    BigInteger R;
    size_t k = ceil((double) A.digits.size() / 2.0);
    for (size_t i = 0; i < k; i++) {
        R.digits.push_back(base - 1);
    }
    if (compare(A, R) == -1) {
        R = A;
    }
    BigInteger M1 = BigInteger("0");
    BigInteger M = division_to_short(sum(L, R), T);
    while (compare(M, M1) != 0) {
        short tmp = compare(multiplication(M, M), A);
        if (tmp < 0) {
            L = M;
        } else if (tmp > 0) {
            R = M;
        } else {
            return M;
        }
        M1 = M;
        M = division_to_short(sum(L, R), T);
    }
    return M;
}