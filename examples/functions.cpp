/*
Where I practiced functions
@Oscarc683
@version 0.1 7/7/26
*/
#include <iostream>

int addNumbers(int a, int b);

int main(){
    std::cout << addNumbers(1, 2) << std::endl;
    return 0;
}
int addNumbers(int a, int b){
    return a + b;
}