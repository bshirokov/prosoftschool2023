#include <iostream>
#include "second_task.h"

int main() {

A a1{1, 2};
A a2{2, 3};
A a3{53, 2};
A a4{1, 2};
B b1{"abc"};
B b2{"bcd"};
std::string_view b3{"bcd"};
std::string b4{"abc"};

//Сравнение A с A
std::cout << (a1 > a2) << (a1 <= a2) << (a1 == a2) << (a1 != a2) << std::endl;
//Сравнение A с int
std::cout << (a1 >= 4) << (a1 <= 4) << (a1 == 4) << (a1 != 4) << std::endl;
//Сравнение A с double
std::cout << (a1 >= 4.0) << (a1 <= 4.0) << (a1 == 4.0) << (a1 != 4.0) << std::endl;
//Сравнение A с float
std::cout << (a1 >= 4.0f) << (a1 <= 4.0f) << (a1 == 4.0f) << (a1 != 4.0f) << std::endl;
//Сравнение A с char
std::cout << (a3 >= '6') << (a3 <= '4') << (a3 == '5') << (a3 != '5') << std::endl;
//Сравнение A с bool
std::cout << (a1 >= false) << (a1 <= false) << (a1 == false) << (a1 != false) << std::endl;
//Сравнение одинаковых A
std::cout << (a1 >= a4) << (a1 <= a4) << (a1 == a4) << (a1 != a4) << std::endl;

//Сравнение B с B
std::cout << (b1 >= b2) << (b1 <= b2) << (b1 == b2) << (b1 != b2) << std::endl;
//Сравнение B с l-value std::string_view
std::cout << (b1 >= b3) << (b1 <= b3) << (b1 == b3) << (b1 != b3) << std::endl;
//Сравнение B с r-value std::string_view
std::cout << (b1 >= std::string_view{"bcd"}) << (b1 <= std::string_view{"bcd"})
          << (b1 == std::string_view{"bcd"}) << (b1 != std::string_view{"bcd"}) << std::endl;
//Сравнение B с одинаковой l-value std::string
std::cout << (b1 >= b4) << (b1 <= b4) << (b1 == b4) << (b1 != b4) << std::endl;
//Сравнение B с r-value std::string
std::cout << (b1 >= std::string{"bcd"}) << (b1 <= std::string{"bcd"})
          << (b1 == std::string{"bcd"}) << (b1 != std::string{"bcd"});
}
