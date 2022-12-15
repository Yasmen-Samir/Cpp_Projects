#include <iostream>
#include "Que.h"
#include <cstring>

class Stack
{

private:

    Que<int> q;

public:

    void push(int element);
    void pop();
    int get_top();
};

void Stack::push(int element)
{
    int siz = q.get_Size();

    q.push(element);

    for (int i=0; i < siz; i++)
    {
        q.push(q.get_Front());
        q.pop();
    }
}

void Stack::pop()
{
    if (q.isEmpty())
    {
        cout << "queue is empty";
    }
    else
        q.pop();
}

int Stack::get_top()
{
    if (q.isEmpty())
    {
        cout << "queue is empty";
    }
    else
    {
        return q.get_Front();
    }
}

int main()
{
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(40);
    stk.push(50);
    cout<<stk.get_top()<< endl;
    stk.pop();
    stk.push(30);
    stk.pop();
    cout<<stk.get_top()<< endl;
    stk.pop();
    stk.push(30);
    stk.pop();
    cout<<stk.get_top()<< endl;
    stk.pop();
    stk.push(30);
    stk.pop();
    cout<<stk.get_top()<< endl;

    return 0;
}
