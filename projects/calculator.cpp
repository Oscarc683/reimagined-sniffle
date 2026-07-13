#include <iostream>
extern int addNumbers(int a, int b);
int main(){
    double a, b, sol;
    char op;
    bool done = 0;
    while (done == 0){
        std::cout << "Please input your equation separated by spaces (ex: 1 + 2):" << std::endl;
        std::cin >> a >> op >> b;
        switch(op){
            case '+': sol = addNumbers(a,b);
            break;
            case '-': sol = a - b;
            break;
            case '*': sol = a * b;
            break;
            case '/': sol = a / b;
            default: std::cout << "Invalid Operator" << std::endl;
        }
        std::cout << "Answer: " << sol << std::endl;
        std::cout << "Are you done with the calculator? 1-Yes/0-No" << std::endl;
        std::cin >> done;
    } return 0;
}
/*if (op == '+'){
            sol = a + b;
        } else if (op == '+'){
            sol = a - b;
        } else if (op == '*'){
            sol = a * b;
        } else if (op == '/'){
            sol = a / b;
        } else{
            std::cout << "Invalid Operator, solution set to 0";
            sol = 0;
        }*/