#include "Que.h"
#include <iostream>

template<class t>
Que<t>::Que()
{
    Front = 0;
    length = 0;
    this->value = 100;
    this->initial_size = 100;
    arr = new t[100];
    Back = initial_size -1;

}

template<class t>
Que<t>::Que(t value,int initial_size)
{
    Front = 0;
    length = 0;
    this->value = value;
    this->initial_size = initial_size;
    arr = new t[initial_size];
    Back = initial_size -1;

}

template<class t>
bool Que<t>::isEmpty()
{
    if(length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class t>
bool Que<t>::isFull()
{
    if(length == initial_size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class t>
void Que<t>::push(t elem)
{
    if (isFull())
    {
        cout<< "Queue is full" <<endl;
    }
    else
    {
        Back = (Back+1)%initial_size;
        arr[Back] = elem;
        length++;
    }
}

template<class t>
void Que<t>::pop()
{
    if(isEmpty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        Front = (Front+1)%initial_size;
        length--;
    }

}

template<class t>
t& Que<t>::get_Front()
{
    if (isEmpty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        return arr[Front];
    }
}

template<class t>
t& Que<t>::get_Back()
{
    if(isEmpty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        return arr[Back];
    }
}

template<class t>
int Que<t>::get_Size()
{
    return length;
}

template<class t>
void Que<t>::display()
{
    if (isEmpty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<< "[";
        for(int i= Front; i != Back; i= (i+1)%initial_size)
        {
            cout<<arr[i]<<" ";
        }
        cout<<arr[Back];
        cout<< "]";
        cout<< endl;
    }

}

template<class t>
Que<t>::~Que()
{
    for(int i= Front; i!= Back; i=(i+1)%initial_size)
    {
        delete[] arr;
    }
}


template class Que<int>;
template class Que<float>;
template class Que<double>;
template class Que<long>;
template class Que<char>;
template class Que<string>;
