#include <iostream>
#include <Book.h>
#include <User.h>

int main()
{

    User u1;
    cin>>u1;
    cout<<u1<<endl;
    User u2;
    cin>>u2;
    cout<<u2<<endl;



    Book b1;
    cin>>b1;
    cout<<b1;
    cout  << "====================================" << endl;
    Book b2;
    cin>>b2;
    cout<<b2;
    cout  << "====================================" << endl<<endl;



cout<<"Let's assign an author for the first book, set the first user as an author" << endl;
cout<< "Let's rate the first book with 3 and 4 ratings and print the book info" << endl;


    b1.rateBook(3);
    b1.rateBook(4);
    cout<<b1<<endl;
    cout<<u1<<endl;

cout<<"===================================="<< endl<<endl;
cout<< "Let's add a new rating for b1 with 5 and print the book info" << endl;



    b1.rateBook(5);
    cout<<b1<<endl;
    cout<<u1<<endl;
cout<<"===================================="<< endl<<endl;

    return 0;
}





