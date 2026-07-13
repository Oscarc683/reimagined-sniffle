/*
Fighting Game/Simulator created by me. The game has 6 stages with 5 enemies that get progressively stronger, and then ending with a final boss.
I made sure to include nested if and switch statements,functions, and different kinds of loops.

@Oscarc683

@version 1.8 7/10/26

*/

// Libraries
#include <iostream>
#include <random>
#include <vector>
#include <thread>
#include <chrono>

// My functions
int getRand(int min, int max);                                               // Provides a random # within a given range
std::vector<int> getStats();                                                 // Used to give stats(int vector) to player and enemy, basically spawns enemy and the player
int attack(int strength, int accuracy);                                      // preforms an attack action, returns how much damage is dealt
std::string printColor(std::string words, char color);                       // returns a string with color code
void slowPrint(const std::string &text, int delay_ms);                       // prints out a string slowly
void wait(int mseconds);                                                     // waits # milliseconds
void showHealth(int health, bool player);                                    // prints out health of a given stats vector
std::string intToString(int i);                                              // returns string, (int to string)
std::vector<int> addIntVect(std::vector<int> vect1, std::vector<int> vect2); // Adds values of two int vectors together, used to keep track of upgrades
void graphic(int num);                                                       // prints out an ACSII art copy paste

int main()
{
    std::vector<std::string> statNames = {"Health: ", "Strength: ", "Accuracy: ", "Speed: "}; // Makes printing out stat labels much easier
    std::vector<int> playerStats = getStats();
    std::vector<int> enemyStats = getStats();
    enemyStats[0] -= 80; // Makes enemies spawn with less health
    std::string choice;
    int damageDealt;
    int level = 0;
    int count = 0;
    std::vector<int> pwrUp = {0, 0, 0, 0}; // Used with addIntVect() function to upgrade player stats
    std::vector<int> balanceUp = pwrUp;    // Keeps track of total upgrade values for each stat
    slowPrint("Someone is here to challenge you!\n", 50);
    graphic(1);
    while (playerStats[0] > 0 && count < 5) // Loops 5 times(5 enemies), and stops if players health goes below 1 hp
    {
        if (enemyStats[0] <= 0)//spawns in the next enemy when previous is defeated
        {
            slowPrint(printColor("\nLEVEL UP! +1\n", 'g'), 35);//icreases player stats by randoms amounts
            pwrUp[0] = getRand(25, 60);
            playerStats[0] += pwrUp[0];
            pwrUp[1] = getRand(1, 8);
            playerStats[1] += pwrUp[1];
            pwrUp[2] = getRand(0, 4);
            playerStats[2] += pwrUp[2];
            pwrUp[3] = getRand(0, 5);
            playerStats[3] += pwrUp[3];
            level += 1;
            slowPrint(printColor("Level: " + intToString(level) + "\n", 'y'), 10);
            enemyStats = getStats();
            enemyStats[0] -= 80 - count * 10;//count variable increases each round, so enemies health and strength become increasingly better
            enemyStats[1] += count * 2;
            std::cout << printColor("\nSomeone new is here to challenge you!\n", 'y');
            balanceUp = addIntVect(balanceUp, pwrUp);//updates balance vector to show cumalitive increase in stats
            wait(1000);
        }
        slowPrint("\nThese are your stats:\n", 25);
        for (int i = 0; i < playerStats.size(); i++)//goes through vector and prints out player stats
        {

            std::cout << statNames[i]
                      << printColor(std::to_string(playerStats[i]), 'b') << " +" << balanceUp[i] << "\n";
            wait(1000);
        }
        if (playerStats[3] >= enemyStats[3])//if player is faster, they attack first
        {
            slowPrint("\nEnemy Stats: \n", 25);
            for (int i = 0; i < enemyStats.size(); i++)
            {

                std::cout << statNames[i]
                          << printColor(std::to_string(enemyStats[i]), 'b') << "\n";
                wait(1000);
            }
            slowPrint("\nYou attack first!\n", 20);

            while (playerStats[0] > 0 && enemyStats[0] > 0)//continues the fight sequence until either the player or enemy dies
            {
                slowPrint("\n\nFight - F/f | Run Away R/r\n", 20);
                std::cin >> choice;
                if (choice == "F" || choice == "f")
                {
                    slowPrint("\nYou attack!", 20);
                    damageDealt = attack(playerStats[1], playerStats[2]);
                    std::cout << printColor(intToString(damageDealt), 'r') << " DAMAGE\n";
                    enemyStats[0] -= damageDealt;
                    showHealth(enemyStats[0], false);
                    slowPrint(" \n", 100);
                    if (enemyStats[0] <= 0)
                    {
                        wait(100);
                    }
                    else
                    {
                        slowPrint("\nEnemy attacks!", 20);
                        damageDealt = attack(enemyStats[1], enemyStats[2]);
                        std::cout << printColor(intToString(damageDealt), 'r') << " DAMAGE\n";
                        playerStats[0] -= damageDealt;
                        showHealth(playerStats[0], true);
                        slowPrint(" \n", 100);
                    }
                }
                else if (choice == "R" || choice == "r")//ends the program when user inputs r
                {
                    slowPrint(printColor("\nYou coward.\n", 'g'), 20);
                    return 0;
                }
                else//anything other than 'f'/'F' or 'r'/'R' restarts the prompt
                {
                    std::cout << printColor("\nINAVLID INPUT\n", 'r');
                    std::cout << printColor("TRY AGAIN\n", 'r');
                }
            }
        }
        else //If enemy is faster the same fight sequences plays out but where enemy attacks first
        {
            slowPrint("\nEnemy Stats: \n", 25);
            for (int i = 0; i < enemyStats.size(); i++)
            {

                std::cout << statNames[i]
                          << printColor(std::to_string(enemyStats[i]), 'b') << "\n";
                wait(1000);
            }
            slowPrint("\nThe enemy attacks first!\n", 20);
            while (playerStats[0] > 0 && enemyStats[0] > 0)
            {
                slowPrint("\n\nFight - F/f | Run Away R/r\n", 20);
                std::cin >> choice;
                if (choice == "F" || choice == "f")
                {
                    slowPrint("\nEnemy attacks!", 20);
                    damageDealt = attack(enemyStats[1], enemyStats[2]);
                    std::cout << printColor(intToString(damageDealt), 'r') << " DAMAGE\n";
                    playerStats[0] -= damageDealt;
                    showHealth(playerStats[0], true);
                    if (playerStats[0] < 1)//ends the program if player dies after first turn
                    {
                        slowPrint(printColor("\nYou have been defeated!\n", 'r'), 20);
                        return 0;
                    }
                    slowPrint(" \n", 100);
                    slowPrint("\nYou attack!", 20);
                    damageDealt = attack(playerStats[1], playerStats[2]);
                    std::cout << printColor(intToString(damageDealt), 'r') << " DAMAGE\n";
                    enemyStats[0] -= damageDealt;
                    showHealth(enemyStats[0], false);
                    slowPrint(" \n", 100);
                }
                else if (choice == "R" || choice == "r")
                {
                    slowPrint(printColor("\nYou coward.\n", 'g'), 20);
                    return 0;
                }
                else
                {
                    std::cout << printColor("\nINAVLID INPUT\n", 'r');
                    std::cout << printColor("TRY AGAIN\n", 'r');
                }
            }
        }
        if (playerStats[0] < enemyStats[0])//once the fight sequence while loop stops, whoever has lower health loses
        {
            slowPrint(printColor("\nYou have been defeated!\n", 'r'), 20);
            return 0;
        }
        else
        {
            slowPrint(printColor("\nYou have won!\n", 'g'), 20);
            slowPrint(printColor("\nGet ready for the next enemy!\n", 'b'), 20);
        }
        count++;//acts a counter for the level/# of enemy
    }
    slowPrint("\nAfter a long day of fighting enemies, you take a nap. ( + 100 health, +10 strength, +8 accuracy, +20 speed)\n", 20);
    slowPrint("\nThen suddenly you hear loud footsteps.....\n", 30);
    slowPrint(printColor("HERE COMES SLEEPER(CHRISTIAN D)", 'r'), 40);
    enemyStats = getStats();//spawns in one last enemy
    enemyStats[0] = 200;//prepares the player and boss enemy stats
    enemyStats[1] = 67;
    enemyStats[2] = 15;
    enemyStats[3] = 60;
    playerStats[0] += 100;
    playerStats[1] += 10;
    playerStats[2] += 8;
    playerStats[3] += 20;
    slowPrint("\nThese are your final stats....\n", 70);
    for (int i = 0; i < playerStats.size(); i++)
    {

        std::cout << statNames[i]
                  << printColor(std::to_string(playerStats[i]), 'b') << " +" << balanceUp[i] << "\n";
        wait(1500);
    }
    if (playerStats[3] >= enemyStats[3])//same sequence as in the small enemies stage while loop
    {
        slowPrint("\nEnemy Stats: \n", 25);
        for (int i = 0; i < enemyStats.size(); i++)
        {

            std::cout << statNames[i]
                      << printColor(std::to_string(enemyStats[i]), 'b') << "\n";
            wait(1000);
        }
        slowPrint("\nYou attack first!\n", 20);

        while (playerStats[0] > 0 && enemyStats[0] > 0)
        {
            slowPrint("\n\nFight - F/f | Run Away R/r\n", 20);
            std::cin >> choice;
            if (choice == "F" || choice == "f")
            {
                slowPrint("\nYou attack!", 20);
                damageDealt = attack(playerStats[1], playerStats[2]);
                std::cout << printColor(intToString(damageDealt), 'r') << " DAMAGE\n";
                enemyStats[0] -= damageDealt;
                showHealth(enemyStats[0], false);
                slowPrint(" \n", 100);
                if (enemyStats[0] <= 0)
                {
                    wait(100);
                }
                else
                {
                    slowPrint("\nEnemy attacks!", 20);
                    damageDealt = attack(enemyStats[1], enemyStats[2]);
                    std::cout << printColor(intToString(damageDealt), 'r') << " DAMAGE\n";
                    playerStats[0] -= damageDealt;
                    showHealth(playerStats[0], true);
                    slowPrint(" \n", 100);
                }
            }
        }
    }
    else
    {
        slowPrint("\nEnemy Stats: \n", 25);
        for (int i = 0; i < enemyStats.size(); i++)
        {

            std::cout << statNames[i]
                      << printColor(std::to_string(enemyStats[i]), 'b') << "\n";
            wait(1000);
        }
        slowPrint("\nThe enemy attacks first!\n", 20);
        while (playerStats[0] > 0 && enemyStats[0] > 0)
        {
            slowPrint("\n\nFight - F/f | Run Away R/r\n", 20);
            std::cin >> choice;
            if (choice == "F" || choice == "f")
            {
                slowPrint("\nEnemy attacks!", 20);
                damageDealt = attack(enemyStats[1], enemyStats[2]);
                std::cout << printColor(intToString(damageDealt), 'r') << " DAMAGE\n";
                playerStats[0] -= damageDealt;
                showHealth(playerStats[0], true);
                if (playerStats[0] < 1)
                {
                    slowPrint(printColor("\nYou have been defeated!\n", 'r'), 20);
                    return 0;
                }
                slowPrint(" \n", 100);
                slowPrint("\nYou attack!", 20);
                damageDealt = attack(playerStats[1], playerStats[2]);
                std::cout << printColor(intToString(damageDealt), 'r') << " DAMAGE\n";
                enemyStats[0] -= damageDealt;
                showHealth(enemyStats[0], false);
                slowPrint(" \n", 100);
            }
            else if (choice == "R" || choice == "r")
            {
                slowPrint(printColor("\nYou coward.\n", 'g'), 20);
                return 0;
            }
            else
            {
                std::cout << printColor("\nINAVLID INPUT\n", 'r');
                std::cout << printColor("TRY AGAIN\n", 'r');
            }
        }
    }
    //if boss is defeated, a trophy is printed and the player gets a win message
    graphic(2);
    slowPrint(printColor("YOU WON!",'g'),50);
    return 0;
}

std::vector<int> getStats()//fills a vector with random stats and returns it
{
    int health = 100 + getRand(0, 50);
    int strength = 10 + getRand(0, 25);
    int accuracy = 10 + getRand(0, 18);
    int speed = 8 + getRand(0, 30);
    return std::vector<int>{health, strength, accuracy, speed};
}

int getRand(int min, int max)//provides a random number between a given range
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> distrib(min, max);
    return distrib(rng);
}

int attack(int strength, int accuracy)
{
    int dmgDealt;//is returned at the end
    if ((accuracy + getRand(0, 18)) >= 19)
    {
        switch (getRand(1, 10))//determines what type of hit is landed, random chance for critical, good, bad, normal hit, or miss
        {
        case 1:
            std::cout << "\nCritical Hit!\n";
            dmgDealt = strength * 2;
            break;
        case 2:
            std::cout << "\nGood Hit!\n";
            dmgDealt = strength * 1.5;
            break;
        case 3:
            std::cout << "\nBad Hit!\n";
            dmgDealt = strength * 0.5;
            break;
        default:
            std::cout << "\nHit!\n";
            dmgDealt = strength;
        }
        return dmgDealt;
    }
    else
    {
        std::cout << "\nAttack Missed!\n";
        return 0;
    }
}

std::string printColor(std::string words, char color)
{
    switch (color)//based off color, wraps the given string in a color code and returns it, if no color is given, it just returns the string
    {
    case 'g':
        return "\033[32m" + words + "\033[0m";
        break;
    case 'b':
        return "\033[1;36m" + words + "\033[0m";
        break;
    case 'r':
        return "\033[31m" + words + "\033[0m";
        break;
    case 'y':
        return "\033[33m" + words + "\033[0m";
        break;
    default:
        return words;
    }
}

void slowPrint( const std::string &text, int delay_ms)//uses the thread and chronos libraries with a constant reference to avoid copying the string, and save memory
{
    for (char c : text)//goes through each character of the string
    {
        std::cout << c << std::flush;//makes sure the character is printed before the next one is processed
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));//makes progam wait 
    }
}

void wait(int mseconds)//a delay
{
    std::this_thread::sleep_for(std::chrono::milliseconds(mseconds));
}

void showHealth(int health, bool player)//takes in the health value, and prints out a unique message based off if it is the player or enemy health
{
    if (player)
    {
        slowPrint(printColor("Your health is: ", 'b'), 10);
        slowPrint(printColor(intToString(health), 'r'), 100);
    }
    else
    {
        slowPrint(printColor("Enemy health is: ", 'y'), 10);
        slowPrint(printColor(intToString(health), 'r'), 100);
    }
}

std::vector<int> addIntVect(std::vector<int> vect1, std::vector<int> vect2)
{
    std::vector<int> vectT = vect1;//creates a final vector to return
    for (int i = 0; i < vect1.size(); i++)//goes through vectors of the same size and adds the values at each index together
    {
        vectT[i] = vect1[i] + vect2[i];
    }
    return vectT;
}

std::string intToString(int i)//turns int values into strings
{
    return std::to_string(i);
}

void graphic(int num)//place to store ASCII art, prints out different art based on the given number
{
    switch (num)
    {
    case 1:
        std::cout << "\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@@##%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%=.....  .... .. ....*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%-....... ..... .....  .  ...=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*......... ........... .. .... ..=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=.............. ..  .. ... .........*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-........  .    .  . . ...   ..  .....#@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=..:.... .  . ... .. .  ....... .......+@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        wait(500);
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#:.........  . .. ......   ..  .....  ...%@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=:.:......      .  ..      .. .. ....  ..+@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=..:... .                   ..     .  ...=@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@::..... .                   ..     .   ..-@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%:.::::.....               ..  ...      ..:@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%::---:-.....     .       . .......   ....-@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#:--=++++=-:...:-.  ...::.................=@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%---+++++++*#***=-:--==++++=--::::::.:::::=@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        wait(500);
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+-++*++++++***#*******++++=--:::---=++=::#*%@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#+#**+++==++******+++++++==--:::--=+*#*-:.:*@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=#***+++++**************+==------==*##-::+#@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*#*+*+++++*************+=-==------*###=-::@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%##*+=++==+++++++++++*++=-=-:....:+###+-:-@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#*-:.....::-=+++++==:.  ....:::--==###:-*@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#**=:=: ..:..:-==-:.....--  =...:.-#%#=+@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#****===+=-:-==+=-:::...-=-::----=#%*=#@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#**+++===++**+**+==-=++++++++++=-+##%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*%++++++***++**#*+=-=+***++*++=-=+**@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@**+++++**+++**##+=---+++*+++==--=+**#@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%**++++++==+**#*++==-=++++==----=+*=:.:::-=+%@@@@@@@@@@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#***+++++*******=-=--=+===----=+++=........:::::::-+#@@@@@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@##**+++**-:-==-::::--==------=+:..............::::-=+=+%@@@@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#***+++**++**=--:::====-----==:.......::::::::::::=++++===*@@@@\n"
                  << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#=+++****+++++*****++=====--=----.......:::::::::::::-+++++++=====*\n"
                  << "@@@@@@@@@@@@#----:-=+@@@@@@@@@%+++****+++*+=----==--::....::----:........::::::::::::-++=++++++++===\n"
                  << "@@@@@@@@@@*---::::::...=*:-::.:=*+****++++*===+******+=-:--::-:..........::::::::::..=++*+++++++++++\n";
        wait(500);
        std::cout << "@@@@@@@@#=:::-::::::......==.....=+++******+===---:::::::::::...........::::::::::..=+++++++++++++++\n"
                  << "@@@@@@@@==--:::::::..........::...++==++++**+++=-------::::::..........:::::..::::..=++****+++++++++*\n"
                  << "@@@@@@#=---::::::::............. ***+=+**+++++++++===----::...........::::....::::-+++**********++++*\n"
                  << "@@@@@*=--:::::::::::........... +***+=+****+++++==-:::::.............::.....:::::+**+++************++\n"
                  << "@@@@#+---:::::::::::...........+****++++*+++++++====-..............::.....::::-=+***++++*************\n"
                  << "@@@#++--:-::::::::::...........=****+++++++***++=+++++-:................:::::=+******+++++***********\n"
                  << "@@@+*----::::::::::::::........:****++**+++*****+++****+=:.............:::-=***********+++++*********\n"
                  << "@@#*--:--:-=-=-:::-::::........:+*++***++****#****++++****:........:::::-+#*************++++++*******\n"
                  << "@@#=------+**+-*-::--:.:.......-++++***+*******************=........::-*#***************++++++++++++*\n"
                  << "@@*=---=+%@%+=-::--:::-:......:+++++*++************##********=::::::=********************++++++++++++\n"
                  << "@@*+=+*+=-----:-::-::........-+++++++****************+++*##******************************+++++=++++++\n"
                  << "@#=---::::::::::::::::.::..:+==+=+++*************+-::::::=*****************************++++=====+==-:\n"
                  << "#-#*:::::::-:::............======++*****++=-::::.::::---::+*+*********************++++++++==-==-..:::\n"
                  << "#----::-::.................+===-==+=-:::::::::::::::::--::=+++++++++************+++++++===--:.......:\n"
                  << "@*=-=-=-::::..............:==-----=:..:::::::::::::::-----++++++++++++++++*++++++++++===--.:-:.......\n"
                  << "@%=-----::::::............-==-:::--....:::::::::::::::---=++++++++++*****+++++++++++===-:...:::......\n";
        wait(500);
        std::cout << "@@@%-=-:--:::....::.......:++=--:.-.....:::::::::::::::::::-++++++******+++*+++++++====--............\n"
                  << "@@@@#=-:---::::::.........=*++==-::......:::::::::::::::::..:++++**********+++++++====-:.:::----::...\n"
                  << "@@@@@#+--:::::::...:.......=*++==-:.......::::::::::::::::...:+++++++++++++++++++====-:.::::-------::\n"
                  << "@@@@@@@--=---::::...........**++==:........:::::::::::::::.. .-==+++++++++++++++====.......:--------:\n"
                  << "@@@@@@@@*+=-::::::::::.....:**+++=-:........::::::::::::::... .-==+++++++++++++====:......:-+-==+==--\n"
                  << "@@@@@@@@%+%+---:::::::.....+**+++=-:..........:::::::::::......:=++++++++++++=====-... ...::--=*#+===\n"
                  << "@@@@@@@@@+*%@%-:-:::....:..::**++=-::..........:::::::::::......-+++++++++++====---.....::===-=**=---\n"
                  << "@@@@@@@@@*#*%%-::-::::=*:-:+#**+=--::.........::::::::::::......:==++++++++====----=-......::-=-----:\n"
                  << "@@@@@@@@@%*=%%-=--::=+--:=##***+=--:::.............:::::::......:-============-----=+.........:::::::\n"
                  << "@@@@@@@@@@@*+++++===------*****+=--:::.............:::::::.......-==========------:-+:..........:::::\n"
                  << "@@@@@@@@@@@@*=-------==--:=****+=--::::%*+=-::....::::::::.......:======----------:::-............:::\n"
                  << "@@@@@@@@@@@#*++=----==----:***++=---::*@#=-==--:::::::...::---------------:::::=-...........:::::::::\n";
    case 2:
        std::cout << "⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⠀⠀⠀⠀\n"
                  << "⢠⣤⣤⣤⣼⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣄⣤⣤⣠\n"
                  << "⢸⠀⡶⠶⠾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡷⠶⠶⡆⡼\n"
                  << "⠈⡇⢷⠀⠀⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠇⠀⢸⢁⡗\n"
                  << "⠀⢹⡘⡆⠀⢹⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡸⠀⢀⡏⡼⠀\n"
                  << "⠀⠀⢳⡙⣆⠈⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠇⢀⠞⡼⠁⠀\n"
                  << "⠀⠀⠀⠙⣌⠳⣼⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣞⡴⣫⠞⠀⠀⠀\n"
                  << "⠀⠀⠀⠀⠈⠓⢮⣻⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡼⣩⠞⠉⠀⠀⠀⠀\n"
                  << "⠀⠀⠀⠀⠀⠀⠀⠉⠛⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠞⠋⠁⠀⠀⠀⠀⠀⠀\n"
                  << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⢤⣀⠀⠀⠀⠀⢀⣠⠖⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                  << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⡇⢸⡏⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                  << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                  << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠖⠒⠓⠚⠓⠒⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                  << "⠀⠀⠀⠀⠀⠀⠀⣀⣠⣞⣉⣉⣉⣉⣉⣉⣉⣉⣉⣉⣙⣆⣀⡀⠀⠀⠀⠀⠀⠀\n"
                  << "⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀\n"
                  << "⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀\n"
                  << "⠀⠀⠀⠀⠀⠀⠀⠓⠲⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠖⠃⠀⠀⠀⠀⠀⠀\n";
        break;
    default:
        std::cout << " \n";
    }
}