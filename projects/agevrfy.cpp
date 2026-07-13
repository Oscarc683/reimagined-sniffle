/*
Age Verification Program
@Oscarc683 7/6/2026
Will take age input and respond, >18 "Ancient", <18 "Young", =18 "Normal". 
*/
#include <iostream>

int main()
{
    int age;
    std::cout << "Please input your age:" << std::endl;
    std::cin >> age;
    if (age > 18)
    {
        std::cout << "Welcome, Ancient one." << std::endl;
    }
    else if (age < 18)
    {
        std::cout << "Welcome, young apprentice" << std::endl;
    }
    else
    {
        std::cout << "What a normal age to be at!" << std::endl;
    }
    return 0;
}