#include <iostream>
#include "first_task.h"

int main() {

NewA a1{1, 2};
NewA a2{2, 3};
NewA a3{53, 2};
NewB b1{"abc"};
std::string b2{"bcd"};
NewB b3{"bcd"};

//Сравнение NewA с NewA
std::cout << (a1 >= a2) << (a1 <= a2) << (a1 == a2) << (a1 != a2) << std::endl;
//Сравнение NewA с int
std::cout << (a1 >= 4) << (a1 <= 4) << (a1 == 4) << (a1 != 4) << std::endl;
//Сравнение NewA с double
std::cout << (a1 >= 4.0) << (a1 <= 4.0) << (a1 == 4.0) << (a1 != 4.0) << std::endl;
//Сравнение NewA с float
std::cout << (a1 >= 4.0f) << (a1 <= 4.0f) << (a1 == 4.0f) << (a1 != 4.0f) << std::endl;
//Сравнение NewA с char
std::cout << (a3 >= '6') << (a3 <= '4') << (a3 == '5') << (a3 != '5') << std::endl;
//Сравнение NewA с bool
std::cout << (a1 >= false) << (a1 <= false) << (a1 == false) << (a1 != false) << std::endl;

//Сравнение NewB с NewB
std::cout << (b1 >= b3) << (b1 <= b3) << (b1 == b3) << (b1 != b3) << std::endl;
//Сравнение NewB с l-value std::string
std::cout << (b1 >= b2) << (b1 <= b2) << (b1 == b2) << (b1 != b2) << std::endl;
//Сравнение NewB с r-value std::string
std::cout << (b1 >= std::string{"bcd"}) << (b1 <= std::string{"bcd"}) << (b1 == std::string{"bcd"}) << (b1 != std::string{"bcd"});
}
