#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string notation;
        cin >> notation;
        string output;
        stack<char> n_stack;

        for (int i = 0; i < notation.length(); i++)
        {
            if (notation[i] == '(')
            {
                n_stack.push(notation[i]);
            }
            else if (notation[i] >= 'a' &&  notation[i] <= 'z')
            {
                output = output + notation[i];
            }
            else if (notation[i] == ')')
            {
                while (n_stack.top() != '(')
                {
                    output = output + n_stack.top();
                    n_stack.pop();
                }
                n_stack.pop();
            }
            else
            {
                n_stack.push(notation[i]);
            }
        }

        cout << output << endl;
    }

    return 0;
}
