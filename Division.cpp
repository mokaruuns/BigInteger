//
// Created by marse on 02.08.2022.
//
#include "BigInteger.hpp"

// long realization
auto BigInteger::division_to_long(BigInteger A, BigInteger B) -> BigInteger {
    unsigned int num = B.digits.back();
    if (num == 0) {
        BigInteger N;
        N.is_nan = true;
        return N;
    }
    BigInteger L, ONE;
    int TWO = 2;
    ONE = BigInteger("1");
    L = BigInteger("0");
    BigInteger R = A;
    R.is_negate = false;
    BigInteger M = division_to_short(sum(L, R), TWO);
    bool sign_tnp = (A.is_negate ^ B.is_negate);
    A.is_negate = false;
    B.is_negate = false;
    while (compare(sum(L, ONE), R) == -1) {
        short tmp = compare(multiplication(M, B), A);
        if (tmp < 0) {
            L = M;
        } else if (tmp > 0) {
            R = M;
        } else {
            return M;
        }
        M = division_to_short(sum(L, R), TWO);
    }
    M.is_negate = sign_tnp && (M.digits.back() != 0);
    return M;
}

// short realization
auto BigInteger::division_to_short(const BigInteger &A, const int &B) -> BigInteger {
    int num = B;
    if (num == 0) {
        BigInteger N;
        N.is_nan = true;
        return N;
    }
    unsigned long long tmp = 0;
    BigInteger C;
    for (size_t i = A.digits.size() - 1; i < A.digits.size(); i--) {
        unsigned long long a = (A.digits[i] + tmp * (int) base) / num;
        tmp = (A.digits[i] + tmp * (int) base) % num;
        C.digits.push_back(a);
    }
    reverse(C.digits.begin(), C.digits.end());
    while (C.digits.size() > 1) {
        if (C.digits.back() == 0) C.digits.pop_back();
        else break;
    }
    C.is_negate = (A.is_negate ^ (num < 0)) && (C.digits.back() != 0);
    return C;
}

auto operator/(BigInteger &A, BigInteger &B) -> BigInteger {
    return BigInteger::division_to_long(A, B);
}

auto operator%(BigInteger &A, BigInteger &B) -> BigInteger {
    return BigInteger::module(A, B);
}