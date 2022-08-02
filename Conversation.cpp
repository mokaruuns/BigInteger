//
// Created by marse on 02.08.2022.
//
#include "BigInteger.hpp"

BigInteger::BigInteger(string unparsed_BigInteger) {
    is_negate = (unparsed_BigInteger[0] == '-');
    size_t pos = unparsed_BigInteger.size();
    for (size_t i = (unparsed_BigInteger.size() - is_negate) / sep; i > 0; i--) {
        pos -= sep;
        string s = unparsed_BigInteger.substr(pos, sep);
        digits.push_back(stoi(s));
    }
    if (pos - is_negate != 0) {
        string s = unparsed_BigInteger.substr(is_negate, (unparsed_BigInteger.size() - is_negate) % sep);
        digits.push_back(stoi(s));
    }
}

auto BigInteger::to_str() -> string {
    string str_result;
    if (is_nan) {
        return "NaN";
    }
    if (is_negate) {
        str_result += "-";
    }
    str_result += to_string(digits.back());
    for (size_t i = digits.size() - 1; i > 0; i--) {
        string str_tmp = "000000000";
        str_tmp += to_string(digits[i - 1]);
        str_result += str_tmp.substr(str_tmp.size() - sep);
    }
    return str_result;
}