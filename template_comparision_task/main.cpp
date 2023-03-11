#include <iostream>
#include "first_task.h"

int main() {
    NewA a1(1, 2);
    NewA a2(2, 3);
    std::cout << (a1 >= a2) << (a1 <= a2) << (a1 == a2) << (a1 != a2) << '\n';
    std::cout << (a1 >= 4) << (a1 <= 4) << (a1 == 4) << (a1 != 4) << '\n';
    std::cout << (a1 >= 4.0) << (a1 <= 4.0) << (a1 == 4.0) << (a1 != 4.0) << '\n';
}
