#include "Stk.h"
#include<iostream>
#include<cstring>

template <class t>
Stk<t>::Stk()
{
    top = -1;
}

template <class t>
Stk<t>::Stk(t value, int initial_size)
{
    top = -1;
    this-> value = value;
    this->initial_size = initial_size;
    arr = new t[initial_size];
}

template <class t>
void Stk<t>::push(t elem)
{
    if(top >= initial_size-1)
    {
        cout<<"the stack is full"<<endl;
    }
    else
    {
        top++;
        arr[top]= elem;
    }

}

template <class t>
bool Stk<t>::isempty()
{
    if(top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class t>
void Stk<t>::pop()
{
    if (isempty())
    {
        cout<<"the stack is empty"<<endl;
    }
    else
    {
        top--;
    }

}

template <class t>
t& Stk<t>::get_top()
{
    if(isempty())
    {
        cout<<"the stack is empty"<<endl;
    }
    else
    {
       return arr[top];
    }
}

template <class t>
int Stk<t>::Size()
{
    return top+1;
}

template <class t>
void Stk<t>::display ()
{
    if(isempty())
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        cout<< "[";
        for (int i=top; i >= 0; i--)
        {
            cout<<arr[i]<<" ";
        }
        cout<< "]";
        cout<< endl;
    }
}

template <class t>
Stk<t>::~Stk()
{
    for (int i=initial_size;i>0;i--)
    {
        delete[] arr;
    }
}

template class Stk<int>;
template class Stk<float>;
template class Stk<double>;
template class Stk<long>;
template class Stk<char>;
template class Stk<string>;
