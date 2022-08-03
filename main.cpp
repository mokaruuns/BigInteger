#include <iostream>
#include <chrono>
#include "BigInteger.hpp"

auto main() -> int {
    long double time_start;
    long double time_end;
    BigInteger f2 = BigInteger("10000");
    BigInteger f3 = BigInteger("2");
    BigInteger f4 = BigInteger::pow(f3, f2);

    time_start = std::chrono::high_resolution_clock::now().time_since_epoch().count();


    cout << (BigInteger::sqrt(f4)).to_str() << endl;

    time_end = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::cout << (time_end - time_start) / 1000000000 << " sec" << std::endl;
    return 0;
}
