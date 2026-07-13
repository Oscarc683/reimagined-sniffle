#include <iostream>
#include <random>

int main()
{
    // Both players hand value, User starts with $10
    int handPlayer;
    int handDealer;
    int balance = 100;
    int bet;
    char act;
    bool wait = true;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,10); // distribution in range [1, 6]
    /*or
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1,10);
    */

    std::cout << "Weclome To Blackjack! Your starting balance is $10." << std::endl;

    while (balance > -11)
    {
        // Both start off with random # 1-10
        handDealer = dist6(rng);
        handPlayer = dist6(rng);
        act = 'h';
        std::cout << "Input your bet amount" << std::endl;
        std::cin >> bet;
        balance -= bet;
        std::cout << "Your Balance is now: " << balance << std::endl;

        std::cout << "Dealers Hand: " << handDealer << std::endl;
        std::cout << "Your hand: " << handPlayer << std::endl;
        std::cout << "Your Balance: " << balance << std::endl;

        while (act != 's')
        {
            std::cout << "Input 'h' to Hit, 's' to Stand, and 'd' to double your bet." << std::endl;
            std::cin >> act;
            if (act == 'h')
            {
                handPlayer += dist6(rng);
                std::cout << "Your hand: " << handPlayer << std::endl;
            }
            if (handPlayer > 21)
            {
                act = 's';
            }
        }

        if (handPlayer > 21)
        {
            std::cout << "You Lost." << std::endl;
            std::cout << "Your Balance is now: " << balance << std::endl;
        }
        else
        {
            while (handDealer <= handPlayer)
            {
                handDealer += dist6(rng);
                std::cout << "Dealer's hand: " << handDealer << std::endl;
            }
            if (handDealer > handPlayer && handDealer < 22)
            {
                std::cout << "You Lose" << std::endl;
                std::cout << "Your Balance is now: " << balance << std::endl;
                handDealer, handPlayer = 0;
            }
            else
            {
                std::cout << "You Win!" << std::endl;
                balance += bet * 2;
                std::cout << "Your Balance is now: " << balance << std::endl;
            }
        }
    }

    return 0;
}