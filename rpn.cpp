// RPN calculator - works with both positive and negative numbers

#include <iostream> 
#include <string>
#include <stack> 

using namespace std;
bool is_str_digit(string);  // returns true if input parameter string is and integer (e.g., "127343")
bool is_str_operator(string); // returns true if the input parameter is an operator character (e.g., "+", "*")
int convert(string);


int main() 
{
    string in;
    stack<string> st;   // stack definition
    int value1, value2, value3;
    string s;

    cin >> in;
    try
    {
        while (in != "q")
        {
            if (is_str_digit(in))
            {
                // add your code here
                st.push(in);
            }
            else if (is_str_operator(in))
            {
                // add your code here
                if (st.size() < 2) throw 2;

                s = st.top();
                st.pop();
                value1 = convert(s);
                s = st.top();
                st.pop();
                value2 = convert(s);

                switch (in[0])
                {
                case '+':
                    value3 = value2 + value1;
                    break;

                case '-':
                    value3 = value2 - value1;
                    break;

                case '*':
                    value3 = value2 * value1;
                    break;

                case '/':
                    value3 = value2 / value1;
                    break;
                }

                // add your code here
                st.push(to_string(value3));
            }
            else
            {
                throw 1;
            }
            cin >> in;
        }
        if (st.size() != 1) throw 3;

        cout << "The answer is : " << st.top() << endl;
    }
    catch(int e)
    {
        switch (e)
        {
            case 1:
                cout << "The token is not operator nor integer!" << endl;
                break;
            case 2:
                cout << "There are not enough operand!" << endl;
                break;
            case 3:
                cout << "There are extra operand in the stack!" << endl;
                break;
        }
    }
    
    return 0; 
}

bool is_str_digit(string s)
{
    int i = 0;
    if (s.length() != 1)
    {
        if (s[i] == '-') { i++; }
    }
    for (; i < s.length(); ++i)
    {
            if(!isdigit(s[i]))
                return false;
    }
    return true;
}
bool is_str_operator(string s)
{
    return (s.length()==1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0]== '/'));
}

int convert(string s)
{
    int num;
    if (s[0] == '-')
    {
        s.erase(0, 1);
        num = stoi(s);
        num *= -1;
    }
    else { num = stoi(s); }
    return num;
}