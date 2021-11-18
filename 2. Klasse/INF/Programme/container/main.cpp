#include <iostream>
#include "VekQueue.hpp"

int main() {
    auto test = VekQueue(2);
    std::cout << test.empty() << "\n";
    test.push(32);
    test.push(24);

    std::cout << test.pop() << "\n" << test.size(0) << test.size(1);

    return 0;
}