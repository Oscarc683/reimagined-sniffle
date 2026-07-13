#include <iostream>
int main(){
    char choice;
    std::cout << "Where do you want to go?\n";
    std::cout << "A. Ohio\n B. Japan\n";
    std::cin >> choice;
    if (choice == 'A' || choice == 'a'){
        std::cout << "You chose Ohio!\n";
        std::cout << "what city do you want to go to?\n";
        std::cout << "A. Cleveland\n B. Columbus\n C. Cincinnati\n";
        std::cin >> choice;
        if (choice == 'A' || choice == 'a'){
            std::cout << "You chose Cleveland!\n";
        }
        else if (choice == 'B' || choice == 'b'){
            std::cout << "You chose Columbus!\n";
        }
        else if (choice == 'C' || choice == 'c'){
            std::cout << "You chose Cincinnati!\n";
        }
        else{
            std::cout << "Invalid input.\n";
        }
}
    else if (choice == 'B' || choice == 'b'){
        std::cout << "You chose Japan!\n";
        std::cout << "what city do you want to go to?\n";
        std::cout << "A. Tokyo\n B. Kyoto\n C. Osaka\n";
        std::cin >> choice;
        if (choice == 'A' || choice == 'a'){
            std::cout << "You chose Tokyo!\n";
        }
        else if (choice == 'B' || choice == 'b'){
            std::cout << "You chose Kyoto!\n";
        }
        else if (choice == 'C' || choice == 'c'){
            std::cout << "You chose Osaka!\n";
        }
        else{
            std::cout << "Invalid input.\n";
        }
    }
    else{
        std::cout << "Invalid input.\n";
    }
    return 0;
}