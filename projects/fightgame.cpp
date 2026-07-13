#include <iostream>
#include <random>
#include <vector>
#include <thread>
#include <chrono>

int getRand(int min, int max);
std::vector<int> getStats();
int attack(int strength, int accuracy);
std::string printColor(std::string words, char color);
void slowPrint(const std::string &text, int delay_ms);
void wait(int mseconds);
void showHealth(int health, bool player);
std::string intToString(int i);
std::vector<int> addIntVect(std::vector<int> vect1, std::vector<int> vect2);
void graphic(int num);

int main()
{
    std::vector<std::string> statNames = {"Health: ", "Strength: ", "Accuracy: ", "Speed: "};
    std::vector<int> playerStats = getStats();
    std::vector<int> enemyStats = getStats();
    enemyStats[0] -= 80;
    std::string choice;
    int damageDealt;
    int level = 0;
    int count = 0;
    std::vector<int> pwrUp = {0, 0, 0, 0};
    std::vector<int> balanceUp = pwrUp;
    slowPrint("Someone is here to challenge you!\n", 50);
    graphic(1);
    while (playerStats[0] > 0 && count < 5)
    {
        if (enemyStats[0] <= 0)
        {
            slowPrint(printColor("\nLEVEL UP! +1\n", 'g'), 35);
            pwrUp[0] = getRand(10, 40);
            playerStats[0] += pwrUp[0];
            pwrUp[1] = getRand(1, 6);
            playerStats[1] += pwrUp[1];
            pwrUp[2] = getRand(0, 4);
            playerStats[2] += pwrUp[2];
            pwrUp[3] = getRand(0, 5);
            playerStats[3] += pwrUp[3];
            level += 1;
            slowPrint(printColor("Level: " + intToString(level) + "\n", 'y'), 10);
            enemyStats = getStats();
            enemyStats[0] -= 80 - count * 10;
            enemyStats[1] += count * 2;
            std::cout << printColor("\nSomeone new is here to challenge you!\n", 'y');
            balanceUp = addIntVect(balanceUp, pwrUp);
            wait(1000);
        }
        slowPrint("\nThese are your stats:\n", 25);
        for (int i = 0; i < playerStats.size(); i++)
        {

            std::cout << statNames[i]
                      << printColor(std::to_string(playerStats[i]), 'b') << " +" << balanceUp[i] << "\n";
            wait(1000);
        }
        if (playerStats[3] >= enemyStats[3])
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
        if (playerStats[0] < enemyStats[0])
        {
            slowPrint(printColor("\nYou have been defeated!\n", 'r'), 20);
            return 0;
        }
        else
        {
            slowPrint(printColor("\nYou have won!\n", 'g'), 20);
            slowPrint(printColor("\nGet ready for the next enemy!\n", 'b'), 20);
        }
        count++;
    }
    slowPrint("\nAfter a long day of fighting enemies, you take a nap. ( + 100 health, +10 strength, +8 accuracy, +20 speed)\n", 20);
    slowPrint("\nThen suddenly you hear loud footsteps.....\n", 30);
    slowPrint(printColor("HERE COMES SLEEPER(CHRISTIAN D)", 'r'), 40);
    enemyStats = getStats();
    enemyStats[0] = 200;
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
    if (playerStats[3] >= enemyStats[3])
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
                return 0;
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
}

std::vector<int> getStats()
{
    int health = 100 + getRand(0, 50);
    int strength = 10 + getRand(0, 25);
    int accuracy = 10 + getRand(0, 18);
    int speed = 8 + getRand(0, 30);
    return std::vector<int>{health, strength, accuracy, speed};
}

int getRand(int min, int max)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> distrib(min, max);
    return distrib(rng);
}

int attack(int strength, int accuracy)
{
    int dmgDealt;
    if ((accuracy + getRand(0, 18)) >= 19)
    {
        switch (getRand(1, 10))
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
    switch (color)
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

void slowPrint(const std::string &text, int delay_ms)
{
    for (char c : text)
    {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }
}

void wait(int mseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(mseconds));
}

void showHealth(int health, bool player)
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
    std::vector<int> vectT = vect1;
    for (int i = 0; i < vect1.size(); i++)
    {
        vectT[i] = vect1[i] + vect2[i];
    }
    return vectT;
}

std::string intToString(int i)
{
    return std::to_string(i);
}

void graphic(int num)
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
    default:
        std::cout << " \n";
    }
}