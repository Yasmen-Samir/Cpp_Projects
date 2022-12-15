#ifndef STK_H
#define STK_H

using namespace std;

template <class t>

class Stk
{
private:

    int top;
    t *arr;
    int initial_size;
    t value;

public:

    Stk();
    Stk(t value, int initial_size);
    ~Stk();
    void push(t elem);
    bool isempty();
    void pop();
    t & get_top();
    int Size ();
    void display ();

};

#endif // STK_H
