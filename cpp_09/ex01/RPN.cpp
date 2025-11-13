#include "RPN.hpp"


void myRPN(const std::string &arg)
{
    std::stack<double> myStack;
    std::string token;

    if (arg.empty())
        return (printError(" : empty !"));
    for (size_t i = 0; i < arg.size(); i++)
    {
        char c = arg[i];
        if (c == ' ' || c == '\t')
            continue;
        else if (std::isdigit(c))
        {
            myStack.push(static_cast<double>(c - '0'));
            // std::cout << c << std::endl;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (myStack.size() < 2)
                return (printError(" : not enough operands !"));
            // std::cout << c << std::endl;

            double b = myStack.top() ; myStack.pop();
            double a = myStack.top() ; myStack.pop();

            // if (b > a)
            // {
            //     double tmp = a;
            //     a = b;
            //     b = tmp;
            // }

            double res = 0;

            switch (c)
            {
            case '+':
                res = a + b;
                break;
            case '-':
                res = a - b;
                break;
            case '*':
                res = a * b;
                break;
            case '/':
                if (b == 0)
                    return (printError(" : divion by zero !"));
                res = a / b;
                break;
            default:
                break;
            }
            // std::cout << res << std::endl;
            myStack.push(res);
        }
        else
            return (printError(" : invalid value !"));
    }

    if (myStack.size() != 1)
    {
        // std::cout << myStack.top() << std::endl;
        return (printError(" : invalid size of Stack !"));
    }
   
    std::cout << myStack.top() << std::endl;  
}
