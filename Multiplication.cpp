//
// Created by marse on 02.08.2022.
//
#include "BigInteger.hpp"

auto BigInteger::multiplication(const BigInteger &A, const BigInteger &B) -> BigInteger {
    BigInteger C;
    for (size_t i = 0; i < A.digits.size() + B.digits.size(); i++) {
        C.digits.push_back(0);
    }
    unsigned long long tmp;
    for (size_t i = 0; i < A.digits.size(); i++) {
        tmp = 0;
        for (size_t j = 0; j < B.digits.size() || tmp; j++) {
            unsigned long long res =
                    A.digits[i] * (unsigned long long) (j < B.digits.size() ? B.digits[j] : 0) + tmp;
            unsigned long long dig = C.digits[i + j] + res;
            C.digits[i + j] = dig % (int) base;
            tmp = dig / (int) base;
        }
    }
    while (C.digits.size() > 1) {
        if (C.digits.back() == 0) C.digits.pop_back();
        else break;
    }
    C.is_negate = (A.is_negate ^ B.is_negate) && (C.digits.back() != 0);
    return C;
}

auto operator*(BigInteger &A, BigInteger &B) -> BigInteger {
    return BigInteger::multiplication(A, B);
}