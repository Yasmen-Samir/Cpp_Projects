#ifndef QUE_H
#define QUE_H
using namespace std;

template <class t>
class Que
{
private:

    int Back;
    int Front;
    int length;
    t *arr;
    t value;
    int initial_size;

public:

    Que();
    Que(t value, int initial_size);
    ~Que();
    t& get_Front();
    t& get_Back();
    void push(t value);
    void pop();
    int get_Size();
    bool isEmpty();
    bool isFull();
    void display();
};

#endif // QUE_H
