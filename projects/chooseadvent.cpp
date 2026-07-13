/*
My choose your own adventure game, where the user and Carl are planning to rob a bank/gold reserve.
@Oscarc683
@version 1.0 7/9/26
*/
#include <iostream>
#include <thread>
#include <chrono>

void slowPrint(const std::string &text, int delay_ms);

int main()
{
    char choice;
    std::string guess;
    std::cout << "........................................................................\n"
              << "........................................................................\n"
              << "........................................................................\n"
              << "........................................................................\n"
              << "..................................    ..................................\n"
              << "..............................-@@@@@@@@@@-..............................\n"
              << "..........................*@@@@@@@@@@@@@@@@@@*..........................\n"
              << "........................@@@@@@@@@@@@@@@@@@@@@@@@........................\n"
              << ".......................@@@@@@@@@@@@@@@@@@@@@@@@@@.......................\n"
              << "......................@@@@@@@@@@@@@@@@@@@@@@@@@@@@......................\n"
              << "......................@@@@@@@@@@@@@@@@@@@@@@@@@@@@......................\n"
              << "......................@@@@@@@@@@@@@@@@@@@@@@@@@@@@......................\n"
              << ".....................@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.....................\n"
              << "................... .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.....................\n"
              << ".....................@@@:.. ..%@@@@@@@@@@%.....:@@@.....................\n"
              << ".....................@@@.........+@@@@+.........@@@.....................\n"
              << ".....................@@@@.......@@@@@@@@.......@@@@.....................\n"
              << "................... @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ...................\n"
              << "................... @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ...................\n"
              << "....................@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ...................\n"
              << "....................+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+....................\n"
              << ".....................@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@. ...................\n"
              << "......................@@@@@@@@@#........#@@@@@@@@@ .....................\n"
              << "......................@@@@@@@@@@@......@@@@@@@@@@@......................\n"
              << "..................... @@@@@@@@@@@@@@@@@@@@@@@@@@@@......................\n"
              << ".................... @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ....................\n"
              << ".................. =@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@= ...................\n"
              << "...................:@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@......................\n"
              << "....................@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@....................\n"
              << ".....................@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ....................\n"
              << "......................=@@@@@@@@@@@@@@@@@@@@@@@@@@=......................\n"
              << ".........................#@@@@@@@@@@@@@@@@@@@@#.........................\n"
              << ".............................:#@@@@@@@@@@#:.............................\n"
              << "........................................................................\n";
    slowPrint("\nCarl: Hey man, you ready to get this plan into action?\n", 20);
    slowPrint("\nYou: Yeah, let's do this!\n", 20);
    slowPrint("\nCarl: Alright, so we have two options here. We can either go with Plan A or Plan B.\n", 20);
    slowPrint("Plan A involves a more direct approach where we'll hit the bank downtown.\n", 20);
    slowPrint("While Plan B is a bit more subtle and requires some patience, so we'll go after a gold reserve.\n", 20);
    slowPrint("\nYou: Hmm, I see. I think I'll pick....\n", 20);
    std::cout << "\nA) Plan A\nB) Plan B\n";
    std::cin >> choice;
    if (choice == 'A' || choice == 'a')
    {
        slowPrint("You: Alright, let's go with Plan A.\n", 20);
        slowPrint("\nCarl: Sounds good. Let's get our gear and head out. \n", 20);
        slowPrint("\n--You and Carl get geared up, and head off on motorcycles.--\n", 20);
        slowPrint("\n--You make it to the bank, and are preparing to bust in the building.--\n", 20);
        std::cout << "\n   ^ _______________________________\n"
                  << "    [=U=U=U=U=U=U=U=U=U=U=U=U=U=U=U=]\n"
                  << "    |.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.|\n"
                  << "    |        +-+-+-+-+-+-+-+        |\n"
                  << "    |        |BitCount Bank|        |\n"
                  << "    |        +-+-+-+-+-+-+-+        |\n"
                  << "    |.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.|\n"
                  << "    |  _________  __ __  _________  |\n"
                  << "  _ | |___   _  ||[]|[]||  _      | | _\n"
                  << " (!)||OPEN|_(!)_|| ,| ,||_(!)_____| |(!)\n"
                  << ".T~T|:.....:T~T.:|__|__|:.T~T.:....:|T~T.\n"
                  << "||_||||||||||_|||||||||||||_||||||||||_||\n"
                  << "~/=/~~~~~~~~/=/~~~~~~~~~~~/=/~~~~~~~~/=/~\n"
                  << " | -------- | ----------- | -------- |\n"
                  << "~ |~^ ^~~^ ~~| ~^  ~~ ^~^~ |~ ^~^ ~~^ |^~\n";
        slowPrint("\nCarl: we're here.\n", 20);
        slowPrint("You wanna take care of hostages or crack the safe in the back?\n", 20);
        std::cout << "\nA) Take care of hostages\nB) Crack the safe\n";
        std::cin >> choice;
        if (choice == 'A' || choice == 'a')
        {
            slowPrint("\nYou: I'll take care of the hostages.\n", 20);
            slowPrint("\nCarl: Alright, I'll get the safe then.\n", 20);
            slowPrint("\n--You take round up all of the people inside the bank, and the alarms start ringing.--\n", 20);
            slowPrint("\n--It's time to start negotiating with the police, you need to buy Carl some time.--\n", 20);
            slowPrint("\n--You pick up the phone and call the police.--\n", 20);
            std::cout << "\nA) (Tell them you'll only release the hostages periodically)\n B) (Tell them you want a helicopter in exchange for the hostages)\n";
            std::cin >> choice;
            if (choice == 'A' || choice == 'a')
            {
                slowPrint("\nYou: I'll only release the hostages periodically.\n", 20);
                slowPrint("\nPolice: If you stop now, you'll face less jail time.\n", 20);
                slowPrint("\nYou: Thats not going to happen. And dont try to interfere, or there will be less hostages that survive.\n", 20);
                slowPrint(" \n--You hang up the phone and begin to hear police sirens from far away.--\n", 20);
                slowPrint(" --Looks like the police are going to intervene anyways, you're gonna have to help Carl crack the safe faster.--\n", 20);
                slowPrint("\nCarl: DUDE, the drill is stuck!. We need to fix it!\n", 20);
                slowPrint("Get the hemunculator wrench!\n", 20);
                slowPrint("\nYou: *What the heck is a hemunculator wrench?*\n", 20);
                slowPrint(" \n--You look into the tool bag, but only find two weird looking tools. You only have time to use one.--\n", 20);
                slowPrint("\nA) (Use the wrench that looks like a silly straw)\nB) (Use the wrench that has 8 arms)\n", 20);
                std::cin >> choice;
                if (choice == 'A' || choice == 'a')
                {
                    slowPrint("\n--You try using the sily wrench, but it ends up making things worse.--\n", 20);
                    slowPrint("--You and Carl lock eyes, as the drill starts to build up heat and smoke. The drill is about to explode!--\n", 20);
                    slowPrint("--You realize you'll never get to tell Carl your true feelings, as you both are vaporized instantly by the explosion. (It was a big drill.)--\n", 20);
                    std::cout << "\n     _.-^^---....,,--\n"
                              << " _--                  --_\n"
                              << "<                        >)\n"
                              << "|                         |\n"
                              << " |._                   _./\n"
                              << "    ```--. . , ; .--'''\n"
                              << "          | |   |\n"
                              << "       .-=||  | |=-.\n"
                              << "       `-=#$%&%$#=-'\n"
                              << "          | ;  :|\n"
                              << " _____.,-#%&$@%#&#~,._____\n"
                              << "----------------------------\n";
                }
                else if (choice == 'B' || choice == 'b')
                {
                    slowPrint("\n--You use the 8-armed wrench.--\n", 20);
                    slowPrint("--You don't know what you're doing. You get it to work eventually, but it's too late--\n", 20);
                    slowPrint("\nThe police capture you and Carl, and both of you are sentenced to 40 years in prision. (Bad Ending) :( \n", 20);
                }
                else
                {
                    std::cout << "Invalid input.\n";
                }
            }
            else if (choice == 'B' || choice == 'b')
            {
                slowPrint("\nYou: I want a helicopter in exchange for the hostages.\n", 20);
                slowPrint("\nPolice: You can  either stop now or continue and face worse punishment. It's your choice.\n", 20);
                slowPrint("\n--You shoot into the ceiling, and start threating the hostages.--\n", 20);
                slowPrint("\nPolice: Alright! You need to release ALL the hostages, then maybe we'll get you a helicopter.\n", 20);
                slowPrint("\n--Carl eventually gets the safe open, and the helicopter arrives.\n", 20);
                slowPrint("--You release the hostages all at once, as you get into the helicopter with carl.--\n", 20);
                slowPrint("\nCarl: Dude the police are still on us! Get the rpg from the bag!\n", 20);
                slowPrint("\nA) Shoot at the police cars.\nB) Shoot at the nearby Donut SHop.\n", 20);
                std::cin >> choice;
                if (choice == 'A' || choice == 'a')
                {
                    slowPrint("\n--Dang those police cars must be new or something, that rocket did nothing!.--\n", 20);
                    slowPrint("--They respond with a rocket of their own. You and Carl go out in a blaze of glory!--\n", 20);
                }
                else if (choice == 'B' || choice == 'b')
                {
                    slowPrint("\n--You shoot at the donut shop, and it explodes into a huge fireball!--\n", 20);
                    slowPrint("--The police have their priorities, and decide to let you go.--\n", 20);
                    slowPrint("--You and Carl are now millionaires, and live happily ever after. (Good Ending) :)\n", 20);
                }
                else
                {
                    std::cout << "Invalid input.\n";
                }
            }
            else
            {
                std::cout << "Invalid input.\n";
            }
        }
        else if (choice == 'B' || choice == 'b')
        {
            slowPrint("You: I'll get to the safe.\n", 20);
            slowPrint("\nCarl: Alright, I'll round up the hostages.\n", 20);
            slowPrint("\n--As you prepare the drill, it runs into an error.--\n", 20);
            std::cout << "\nA) Input restart code.\nB) Try to fix the drill manually.\n";
            std::cin >> choice;
            if (choice == 'A' || choice == 'a')
            {
                std::cout << "My first digit is less than five, but the sum of my first two is seven.\n"
                          << "My third digit is three more than my third but one less than my last, and my last is an eight.\n"
                          << "What number am I?\n";
                std::cin >> guess;
                if (guess != "3478")
                {
                    slowPrint("\n--You input the wrong code, and the drill explodes!--\n", 20);
                    return 0;
                }
                slowPrint("\n--You input the correct code, and the drill starts working again!--\n", 20);
                slowPrint("\n--Carl negotiates with the police, and you guys are able to escape with the money!--\n", 20);
                std::cout << "   _....._\n"
                             "  ';-.--';'\n"
                             "    }===={       _.---.._\n"
                             "  .'  _|_ '.    ';-..--';\n"
                             " /:: (_|_`  |    `}===={\n"
                             "|::  ,_|_)   |  .:  _|_ '.\n"
                             "|::.   |     /_;:_ (_|_`  |\n"
                             " '::_     _-;'--.-';_|_)   |\n"
                             "     `````  }====={  |     /\n"
                             "          .'  _|_  '.   _.'\n"
                             "         /:: (_|_`   |``\n"
                             "        |::  ,_|_)    |\n"
                             "        |::.   |      /\n"
                             "         '::_      _.'\n"
                             "             ``````\n";
            }
            else if (choice == 'B' || choice == 'b')
            {
                slowPrint("\n--You try to fix the drill manually, but it's too complicated. You explode.--\n", 20);
            }
        }
        else
        {
            std::cout << "Invalid input.\n";
        }
    }
    else if (choice == 'B' || choice == 'b')
    {
        slowPrint("You: Alright, let's go with Plan B.\n", 20);
        slowPrint("\nCarl: Sounds good. Let's get our gear and head out. \n", 20);
        slowPrint("\n--You and Carl get geared up, and head off in the vehichle.--\n", 20);
        slowPrint("--You make it to the gold reserve, and are preparing to sneak in.--\n", 20);
        std::cout << "\nA) Go through the vent system.\nB) Disguise yourselves as guards.\n";
        std::cin >> choice;
        if (choice == 'A' || choice == 'a')
        {
            slowPrint("\nYou: Let's go through the vent system.\n", 20);
            slowPrint("\n--Both of you crawl through the vents. Until you reach the room with the vault door.--", 20);
            slowPrint("\nCarl: ALright you need to disable the security system, while I laser the door.", 20);
            std::cout << "How will you disable the security system?\nA) Hack using Mini Computer\nB) Unscrew and cut the wires\n";
            std::cin >> choice;
            if (choice == 'A' || choice == 'a')
            {
                slowPrint("\n--You use the mini computer to hack the security system, and disable it.--\n", 20);
                slowPrint("\n--Carl lasers the door open, and you both escape with the gold back through the vents!--\n", 20);
                slowPrint("\n--You and Carl are now millionaires, and live happily ever after. (Good Ending) :)\n", 20);
                std::cout << "   _....._\n"
                             "  ';-.--';'\n"
                             "    }===={       _.---.._\n"
                             "  .'  _|_ '.    ';-..--';\n"
                             " /:: (_|_`  |    `}===={\n"
                             "|::  ,_|_)   |  .:  _|_ '.\n"
                             "|::.   |     /_;:_ (_|_`  |\n"
                             " '::_     _-;'--.-';_|_)   |\n"
                             "     `````  }====={  |     /\n"
                             "          .'  _|_  '.   _.'\n"
                             "         /:: (_|_`   |``\n"
                             "        |::  ,_|_)    |\n"
                             "        |::.   |      /\n"
                             "         '::_      _.'\n"
                             "             ``````\n";
            }
            else if (choice == 'B' || choice == 'b')
            {
                slowPrint("\n--You unscrew and cut the wires, but accidentally trigger the alarm.--\n", 20);
                slowPrint("\n--The police arrive and capture you and Carl. You both are sentenced to 40 years in prison. (Bad Ending) :( \n", 20);
                std::cout << "............................-#####.......---+++#########+++----.......#####-........................\n"
                          << "............................-#####-......--++++++###++++++++---.......#####-........................\n"
                          << "............................-#####.......--+++++++++++++++++----......#####-........................\n"
                          << ".............................#####.......---++++++++++++++++-----.....#####-........................\n"
                          << "............................---..+.......--+++++++++++++++++..--......-+--++-.......................\n"
                          << ".........................--+++++++..#+##+---++++++++++++++++.+###+....++++++----....................\n"
                          << ".................-++++++++++++++++-...##+---++++++++++++++++.-+++....-+++++++++++++++-..............\n"
                          << "................-+++#+++++++++++##+---.+-.--++++++++++++++++--.+...--+##+#++++++++++++-.............\n"
                          << "................-+++++###++++######+++-..---+++++++++++++++----..-+--+######+####++++--.............\n"
                          << ".................---++++++++++++#++--++.-----+++++++++++++++++---.-+++++#++++++++++++...............\n"
                          << "................+###+++##+##++#####++..--++++++++++++++++++++#+-..-++#########++++++++++............\n"
                          << "...............+###+#################+..--#####++-+++---+#####+-..+###++++++++++++++#+#+-...........\n"
                          << "...............+####++++#############-...++#####+--++--++####+++..++#######+######+#####+...........\n"
                          << "...............++++++++++###########+--..-++###++..++.--++###+++-..+#####+++++#+###+++++--..........\n"
                          << "...............--++++++++++++#+######...-+++#+--...++..---++++++...##########+##+#+++++-.-..........\n"
                          << ".............-..-#+##+###############...-++++--...-+-....-++++++..-+####+++#+#++#######-----........\n"
                          << "..........-....--####++++############-..-----+-...-+-....-++++---.+++###+++#####++####+--.----......\n"
                          << ".........-+...-..+###+#++++++++++#++#+....--+++...++-....-+++---....++#+++++++#++#+##+-----.---.....\n"
                          << "........+--..--.-#################---.-....-++....+++-....++++-...--+#################---+-.--++-...\n"
                          << "......-++-.-....-#################++++-....----..-+++-.--++++--...+++#################+--++--+-++-..\n"
                          << "......-+-..----+++##################+......---++---+----++++---....--.#################+++++++--+---\n"
                          << "####################################################################################################\n"
                          << "####################################################################################################\n"
                          << "...-++-.-++++++++++----------#####.--...--------++#####++---++---++--.#####+---------+++#+++##+++-+-\n"
                          << "--+++.-++++###+++------------#####.--...-+--------+++++--++++--+##+--.#####+----.---..-++++++++###-+\n"
                          << "#++..-+++#+##++-.------------#####.--...-##---++++#####+++++++###+---.#####+----------.-++#########+\n"
                          << "#+--++#++###++-.-------------#####-----.-###----+++++++++++++####----.#####+-------------+##########\n"
                          << "##+++++####++-.-----------+++#####.-------+##++-+++++++++#####++----+-######--------------+#########\n"
                          << "####+#+####+--------------+++#####-----------+###########+++-------++-######-+------------+++#######\n"
                          << "###########-------+++------+######-----+++---+####+++++++----------++-######++-------------+++######\n"
                          << "##########++#+----+++-----++######---+--+##++-+####++++----------+++--######++++------------########\n"
                          << "#############-+--++++----+++######+------++##++++++++++---------++++--######+++++-----+------#######\n"
                          << "###########--++++++++----+++######+-------++###+++++++++-------+++++-+######+++++-----++--++--######\n"
                          << "#########---++++++++-----+++######++-------+++++++++++++------+++++--+######++++++----++++++-.-#####\n"
                          << "#######+-----+++++++----++++######+++------++++++++++++------++++++--+######++++++----++++#++-.++###\n"
                          << "#####++---+-+++++++++---++++########+---+---+++++#+++++-----+++++++-++######+++++++---+++++++--.+#+#\n";
            }
            else
            {
                std::cout << "Invalid input.\n";
            }
        }
        else if (choice == 'B' || choice == 'b')
        {
            slowPrint("\nYou: Let's disguise ourselves as guards.\n", 20);
            slowPrint("\n--You take out the disguise kit, and use your counterfit key cards to enter.--\n", 20);
            slowPrint("\nCarl: Go get the vault key. I'll create a distraction on the other side of the building so we can escape.\n", 20);
            slowPrint("\n--What will you tell vault security?--\n", 20);
            std::cout << "\nA) I need access to the vault bathroom. I really need to go!\nB) Try to hypnotize them.\n";
            std::cin >> choice;
            if (choice == 'A' || choice == 'a')
            {
                slowPrint("\nYou: I'm about to pee my pants, let me in the vault bathroom!\n\nGuard: Sorry, but no can do.\n", 20);
                slowPrint("\nYou: C'mon man just let me in, I'll be quick.\n\nGuard: When did you start working here? Do you even work here?\n", 20);
                slowPrint("\nYou: Uhhh....\n\n--You fail to convince the guard. They find you and Carl out shortly after.--\n", 20);
                slowPrint("\n--The police arrive and capture you and Carl. You both are sentenced to 40 years in prison. (Bad Ending) :( \n", 20);
            }
            else if (choice == 'B' || choice == 'b')
            {
                slowPrint("\nYou: Look into my watch....You will do as I say and give me the vault key.\n", 20);
                slowPrint("\n--The guard is hypnotized, and gives you the vault key. Wow!--\n", 20);
                slowPrint("\n--You stuff your bags full of gold bars, and escape on Carl's signal. (Good Ending) :)\n", 20);
                std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@----------------:----:::::::--=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=-----------:---:-::-::--::-::--::@@@@@#----+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@--------------:-:-:-:::-:-::-:-:::--#@%--:.---:-%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@------:-------:--:----:-::::-:-:::::::=-:...-------@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=-----:----:--:::--::::::-:::-::-::::::::....---------%*=---*@@@@@@@@@@@@@@@@@@@@@@@@@\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@------:---:--:--:-:-.-:--:::-:::::.:::..:::-----------:::::::-=@@@@@@@@@@@@@@@@@@@@@@@\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+---:--:--:---:-::::.:::-:-:-::::::::....::::--------::.....::::-#@@@@@@@@@@@@@@@@@@@@@\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=---::--:-::-:-:-::::-:::::-.:::::::.:..::::.:----:-:......:::::::-@@@@@@@@@@@@@@@@@@@@\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=-------::-::-:::::::-::::::::::.:..::..:::...---::....:.::::::::::-@@@@@@@@@@@@@@@@@@@\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=---::::-::-:-:-.-.-.:.-.-:::.::.:::.:::::...:---:..---------:::::::-@@@@@@@@@@@@@@@@@@\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#-:----:::-:::-:-:::-:::::::..:..:::.::::....:---:----::-----------::-@@@@@@@@@@@@@@@@@\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%--:-----:-::-:--:-:-:-.::::..:::::.::......::---:--:.--------::::::---@@@@@@@@@@@@@@@@\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-:-----:::--:::.-.:.::.:.:==-:::::.::....:::.---:-::-----=--=======-.-+@@@@@@@@@@@@@@@\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+:::------.:-:::::.:::**=-=+*-:::.:::..:.::::---:::-------=============#@@@@@@@@@@@@@@\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@------:::::::-:.:.--+*:=*###-:::::...:::::.:---::--:--====--------------=#@@@@@@@@@@@\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*--::::::::-.:-.--=*%%#%#%%--::::....:::::.:--:.---=========----------------@@@@@@@@@\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=:-++=-:-::::--=++#####%=-:::::::.::::::..:--:--:-==-=--=--------------------@@@@@@@\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=.-=##=**+-:++*#%#+--::-:-:::::.:.:.::...:--:-:-----=------==--:--------------@@@@@\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#:#%%##+--:::::::-::::-:::::::.:::.:....::-::------==----------------:::------%@@@\n"
                          << "@@@@@@@@@@@@@@@@@@%%@%=#@@@@@@@@@@@@@@@--%%=----::::::::::::::::::.:.::.::....:::---=---=-----------------------:----=@@\n"
                          << "@@@@@@@@@@@@@@@@@%%%+##*%@@@@@@@@@@@@@@%-------::::::::::::::::.:.:.::........::--------=------------------------:::---@\n"
                          << "@@@@@@@@@@@@@@@@@%##%#%#+%@@@@@@@@@@@@@@+--:--::--::::::.:.::..:....:.:.......:--:-----=-:------------------------::::--\n"
                          << "@@@@@@@@@@@@@@@@%%%*#####+%@@@@@@@@@@@@@@--:---:::::..::.:...:...:............:-::---=---:---------------::------::-::::\n"
                          << "@@@@@@@@@@@@@@@%=%#%+#*++#+%@@@@@@@@@@@@@@-:::::::::...::...:.:...:...........--:---=--:::---------------::-------:::.::\n"
                          << "@@@@@@@@@@@@@@@+%*++%*+*+##+%-:-----*%@@@@@+:::::..-==++=:::...:.............:-::-----::::----------------:::-----::::::\n"
                          << "@@@@@@@@@@@@@%@%++%=*#++*%--:::.:::.:::::.+@@:::::..:=++=*::.::..............--::-----:.:-----------------::::-----:::.:\n"
                          << "@@@@@@@@@@@@@%@#%%=#=+*=*#=--==:.::..:.::....%@:::::=####+:::.:.............--::-----:.:-------------------:::-:--:::::.\n"
                          << "@@@@@@@@@@@@@%@%%%%#+=#*-#==::.:::..:.:.::..:::@@--::::::-::..:::..........:--:.----:..--------------------:::::--::::::\n"
                          << "@@@@@@@@@@@@@@@%%%%%%=%-#+=*#%%%#*+=#%=:::......:@@-:-::::.:..:............--:::-=-::.:--------------------:::::::-:::::\n"
                          << "@@@@@@@@@@@@@@%+%+*%=%%=#=%--:-+++##@@%%@+%+.......*%:::.:.................--:..---:..:---------------------:::::-:-::::\n"
                          << "@@@@@@@@@@@@@@%%%=+#+##%%#*--:----%@@@#%%@@@#%-......:::..:..:............--::..--::..:---------------------:::::-::::::\n"
                          << "@@@@@@@@@@@@@@#%%%%#=+**%%%+-------=-####@@%@:........:.::.:.:::.........:--::..--::..:---------------------::::::::::::\n"
                          << "@@@@@@@@@@@@@@@%#+=%%%%==%*+%----------------:.............::::::........---::.:--:..:-----------------------:::::::::::\n"
                          << "@@@@@@@@@@@@@@@%%@%%%+=%%@%+#**---------------:::..........::::::::..::.:---::..:::..:-----------------------:::::::::::\n"
                          << "@@@@@@@@@@@@@@@@@@%#%%@%@@%**%@%*----------::-:::::.......:.::::::...:..----::..:-:..:------------:----------:::::::::::\n"
                          << "@@@@@@@@@@@@@@@@%=++#%###%%%%%@%%%+-------:::::--:--::....::::::::.....-----::...-:..:-----------:-----------:::::::::::\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+-:-------:-----::----:::.::::::::..::.------:...-:..-----------::-----------::.::::::::\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@=::::--:--:-::::::--::::-----:---::::.::.::.---:-:::::.::..:--------:--------------:::::::::::\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@+:::::-:::::::::::::-:::---------....::..:---::::-::::.::.:-------:--------------::::::::::::\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@%--:--::::::::::::.-:.---:----:.....::..:-:::..::::::..:::----------------------::::.:::::::\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:-::::::::::::::.-::--------.:::::::::--::.....::::::.::----::----------------:::::.::::::\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=::::::::::::::.:.:-:-----::------------:......::::::.:-------------------::::::::.::::::\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#=--:...:::::.-::::--:--.----------::..........::::::-----------------::::::::::.::::::\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:........:..:::::::::.....::...........::::::::::::::::..::::.............\n"
                          << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
            }
        }
        else
        {
            std::cout << "Invalid input.\n";
        }
    }
    else
    {
        std::cout << "Invalid input.\n";
    }
    return 0;
}

void slowPrint(const std::string &text, int delay_ms)
{
    for (char c : text)
    {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }
}