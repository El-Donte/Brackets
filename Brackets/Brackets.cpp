#include <iostream>
#include <string>
#include <stack>

char bracketsOpen[3] = { '[','{','(' };
char bracketsClose[3] = { ']','}',')', };

bool isValidBrackets(std::string str,std::stack<char>& Stack) {
    if (str[str.size()-1] != ';') {
        return false;
    }
    else {
        for (int ii = 0; ii < str.size(); ii++) {
            if (str[ii] == bracketsOpen[0] ||
                str[ii] == bracketsOpen[1] ||
                str[ii] == bracketsOpen[2]) {
                Stack.push(str[ii]);
            }
            else if (str[ii] == bracketsClose[0] ||
                str[ii] == bracketsClose[1] ||
                str[ii] == bracketsClose[2]) {
                if (Stack.empty() || Stack.top() == bracketsClose[0] ||
                    Stack.top() == bracketsClose[1] ||
                    Stack.top() == bracketsClose[2]) {
                    return false;
                }
                else
                    Stack.pop();
            }
        }
        return Stack.empty();
    }
}

int main()
{
    
    std::string str;
    getline(std::cin, str);
    std::stack<char> Stack;

    if (isValidBrackets(str, Stack)) {
        std::cout << "true";
    }
    else
        std::cout << "false";


}

