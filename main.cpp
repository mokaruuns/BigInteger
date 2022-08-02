#include <iostream>
#include <chrono>
#include "BigInteger.hpp"

auto main() -> int {
    long double time_start;
    long double time_end;
    time_start = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    BigInteger f1 = BigInteger("2");
    BigInteger f2 = BigInteger("1000000");
    cout << BigInteger::pow(f1, f2).to_str() << endl;

    time_end = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::cout << (time_end - time_start) / 1000000000 << " sec" << std::endl;
    return 0;
}
