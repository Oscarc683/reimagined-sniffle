/*
Using functions to simulalate ordering at a restaurant.
@Oscarc683 
@version 1.0 7/8/2026
*/
#include <iostream>
#include <random>

//Forward declarations of my functions so I can build them later
void menu();
float pickItem(char pick);
int invalidInput(char in);
std::string goodBye(int d);

int main()
{
    //creating the random number generator to pick a random goodbye message
    std::random_device dial;
    std::mt19937 rnd(dial());
    std::uniform_int_distribution<int> distrib(1, 3);

    char input;
    std::cout << "Welcome to King's Restaurant!\nMy name is Mazir, and I'll be your server and we have no drinks.\nWhat would you like?" << std::endl;
    menu();
    std::cin >> input;
    input = invalidInput(input);
    float total = pickItem(input);
    std::cout << "Your total is: " << total << std::endl;
    std::cout << goodBye(distrib(rnd)) << std::endl;
    return 0;
}

void menu() //Prints out the whats on the menu, including the prices
{
    std::cout << "1. Royal Burger - $3.99\n2. Kamehameha Nuggets - $3.99\n3. Fries - $2.99\n4. Side of sauce 😊 - $0.01\n5. Thats it." << std::endl;
}

int invalidInput(char in) //Will loop until the user inputs one of the options 4 or less 
{
    while (in != '1' && in != '2' && in != '3' && in != '4') //only these options stop the loop
    {
        std::cout << "Try again.\n";
        std::cin >> in;
    }
    return in;
}

float pickItem(char pick) //Once the user inputs a valid character, it saves the orders and returns the total cost 
{
    std::string order;
    float total;
    while (pick == '1' || pick == '2' || pick == '3' || pick == '4')
    {
        switch (pick)
        {
        case '1':
            order += "Royal Burger\n"; //Adds the item to the order string
            total += 3.99; //adds to the total cost
            break;
        case '2':
            order += "Kamehameha Nuggets\n";
            total += 3.99;
            break;
        case '3':
            order += "Fries\n";
            total += 2.99;
            break;
        case '4':
            order += "Side of sauce 😊\n";
            total += 0.01;
            break;
        default://anything else stops the order
            pick = '5';
            break;
        }
        std::cout << "Anything else?\n";
        std::cin >> pick;
    }
    std::cout << "You ordered:\n"
              << order;//prints out the order and returns the total
    return total;
}

std::string goodBye(int d) //prints out a random goodbye message based on rng(dial()) in the main function
{
    std::string farewell;
    switch (d)
    {
    case 1:
        farewell = "Have a nice day!";
        break; 
    case 2:
        farewell = "Enjoy your food. ;)";
        break;
    case 3:
        farewell = "Yo";
        break;
    }
    return farewell;
}