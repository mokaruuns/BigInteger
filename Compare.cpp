//
// Created by marse on 02.08.2022.
//
#include "BigInteger.hpp"

auto BigInteger::compare(BigInteger A, BigInteger B) -> short {
    if (A.is_negate ^ B.is_negate) {
        if (A.is_negate) {
            return -1;
        } else {
            return 1;
        }
    } else {
        if (A.digits.size() == B.digits.size()) {
            for (size_t i = A.digits.size() - 1; i < A.digits.size(); i--) {
                if (A.digits[i] < B.digits[i]) {
                    return (!A.is_negate) ? -1 : 1;
                }
                if (A.digits[i] > B.digits[i]) {
                    return (!A.is_negate) ? 1 : -1;
                }
            }
            return 0;
        } else {
            if (A.digits.size() < B.digits.size()) {
                return (!A.is_negate) ? -1 : 1;
            } else { return (!A.is_negate) ? 1 : -1; }
        }
    }
}

auto operator==(BigInteger &A, BigInteger &B) -> bool {
    return BigInteger::compare(A, B) == 0;
}

auto operator<(BigInteger &A, BigInteger &B) -> bool {
    return BigInteger::compare(A, B) == -1;
}

auto operator>(BigInteger &A, BigInteger &B) -> bool {
    return BigInteger::compare(A, B) == 1;
}

auto operator<=(BigInteger &A, BigInteger &B) -> bool {
    return !(A > B);
}

auto operator>=(BigInteger &A, BigInteger &B) -> bool {
    return !(A < B);
}

auto operator!=(BigInteger &A, BigInteger &B) -> bool {
    return !(A == B);
}
