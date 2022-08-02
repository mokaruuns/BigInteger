#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

class BigInteger {
private:
    bool is_nan = false;
    bool is_negate = false;
    short sep = 9;
    vector<unsigned int> digits;
    static const int base = 1e9;


public:
    BigInteger() = default;

    explicit BigInteger(string unparsed_BigInteger);

    static auto negate(const BigInteger &A) -> BigInteger;

    static auto sum(const BigInteger &BigInteger_first, const BigInteger &BigInteger_second) -> BigInteger;

    static auto subtract(const BigInteger &A, const BigInteger &B) -> BigInteger;

    static auto multiplication(const BigInteger &A, const BigInteger &B) -> BigInteger;

    // long realization
    static auto division_to_long(BigInteger A, BigInteger B) -> BigInteger;

    // short realization
    static auto division_to_short(const BigInteger &A, const int &B) -> BigInteger;

    static auto module(const BigInteger &A, BigInteger B) -> BigInteger;

    static auto sqrt(const BigInteger &A) -> BigInteger;

    static auto pow(BigInteger &A, BigInteger &B) -> BigInteger;

    static auto compare(BigInteger A, BigInteger B) -> short;

    auto to_str() -> string;

    static auto even(const BigInteger &A) -> bool;

    static auto odd(const BigInteger &A) -> bool;

    friend auto operator==(BigInteger &A, BigInteger &B) -> bool;

    friend auto operator<(BigInteger &A, BigInteger &B) -> bool;

    friend auto operator>(BigInteger &A, BigInteger &B) -> bool;

    friend auto operator<=(BigInteger &A, BigInteger &B) -> bool;

    friend auto operator>=(BigInteger &A, BigInteger &B) -> bool;

    friend auto operator!=(BigInteger &A, BigInteger &B) -> bool;

    friend auto operator+(BigInteger &A, BigInteger &B) -> BigInteger;

    friend auto operator-(BigInteger &A, BigInteger &B) -> BigInteger;

    friend auto operator*(BigInteger &A, BigInteger &B) -> BigInteger;

    friend auto operator/(BigInteger &A, BigInteger &B) -> BigInteger;

    friend auto operator%(BigInteger &A, BigInteger &B) -> BigInteger;
};
