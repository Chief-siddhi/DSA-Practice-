#include <iostream>
#include <stack>
using namespace std;

bool isValid(string str)
{
    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];

        // opening brackets
        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else
        {
            if (s.empty())
                return false;

            char top = s.top();

            if ((top == '(' && ch == ')') ||
                (top == '[' && ch == ']') ||
                (top == '{' && ch == '}'))
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return s.empty();
}

int main()
{
    string str1 = "([}])";
    string str2 = "([{}])";

    cout << isValid(str1) << endl; // 0 (false)
    cout << isValid(str2) << endl; // 1 (true)

    return 0;
}
