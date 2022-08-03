//
// Created by marse on 02.08.2022.
//

#include "BigInteger.hpp"

auto BigInteger::subtract(const BigInteger &A, const BigInteger &B) -> BigInteger {
    if (B.is_negate) return sum(A, negate(B));
    else if (A.is_negate) return negate(sum(negate(A), B));
    else if (compare(A, B) == -1) return negate(subtract(B, A));
    size_t max_size = max(A.digits.size(), B.digits.size());
    long long tmp = 0;
    BigInteger C;
    for (size_t i = 0; i < max_size; i++) {
        long long a = (i < A.digits.size() ? A.digits[i] : 0);
        long long b = (i < B.digits.size() ? B.digits[i] : 0);
        a -= tmp;
        tmp = 0;
        if (a < b) {
            tmp = 1;
            a += base;
            a += base;
        }
        C.digits.push_back((a - b) % base);
    }
    while (C.digits.size() > 1) {
        if (C.digits.back() == 0) C.digits.pop_back();
        else break;
    }
    return C;
}

auto operator-(const BigInteger &A, const BigInteger &B) -> BigInteger {
    return BigInteger::subtract(A, B);
}