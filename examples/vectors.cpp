#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> fruit = {"kiwis", "coconuts", "pears", "mangos"};
    fruit[0] = "apples";
    fruit[1] = "watermelons";
    fruit[3] = "bananas";
    for(int i = 0; i < fruit.size(); i++){
        std::cout << fruit[i] << std::endl;
    }
    return 0;
}