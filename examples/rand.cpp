#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int randNum = (std::rand() % 20) + 1;

    std::cout << randNum << std::endl;

    std::cout << "guess an animal: " << std::endl;

    return 0;
}