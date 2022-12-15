#include <iostream>
#include<cstring>
#include "Stk.h"

bool matching_pair(char Start, char End)
{
    if (Start == '{'&& End == '}' || Start == '(' && End == ')' || Start == '[' && End == ']')
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool balanced (string sentence)
{
    Stk<char> s(sentence[0],sentence.length());
    for(int i = 0; i<sentence.length(); i++)
    {
        if (sentence[i] == '{' || sentence[i] == '(' || sentence[i] == '[' )
            {
                s.push(sentence[i]);
            }

        else if (sentence[i] == '}' || sentence[i] == ')' || sentence[i] == ']' )
        {
            if (s.isempty()|| !matching_pair(s.get_top(), sentence[i]))
            {
                return false;
            }
            else
            {
                s.pop();
            }

        }

    }

    return s.isempty();
}

int main()
{
    string sentence;
    cin>> sentence;

    if (balanced(sentence))

    {
        cout<< "balanced!"<<endl;
    }

    else
    {
        cout<< "not balanced!"<<endl;
    }

    return 0;
}
