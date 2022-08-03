//
// Created by marse on 02.08.2022.
//

#include "BigInteger.hpp"

auto BigInteger::sum(const BigInteger &A, const BigInteger &B) -> BigInteger {
    if (A.is_negate) {
        if (B.is_negate) return negate(sum(negate(A), negate(B)));
        else return subtract(B, negate(A));
    } else if (B.is_negate) return subtract(A, negate(B));
    BigInteger C;
    size_t max_size = max(A.digits.size(), B.digits.size());
    unsigned long long tmp = 0;
    for (size_t i = 0; i < max_size; i++) {
        long long a = (i < A.digits.size() ? A.digits[i] : 0);
        long long b = (i < B.digits.size() ? B.digits[i] : 0);
        tmp = (a + b + tmp);
        unsigned int c = tmp % (int) base;
        tmp /= base;
        C.digits.push_back(c);
    }
    if (tmp != 0) {
        C.digits.push_back(tmp);
    }
    while (C.digits.size() > 1) {
        if (C.digits.back() == 0) C.digits.pop_back();
        else break;
    }
    return C;
}

auto operator+(const BigInteger &A, const BigInteger &B) -> BigInteger {
    return BigInteger::sum(A, B);
}
