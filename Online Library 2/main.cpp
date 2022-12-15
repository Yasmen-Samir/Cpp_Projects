#include "User.h"
#include "Book.h"
#include "UserList.h"
#include "BookList.h"
#include<cstring>
#include<iostream>
#include <string>
using namespace std;

bool flag = 0;
UserList* u1 = new UserList();

void add_new_user() {
    cout << "Enter the user information in this order" << endl;
    cout << "Name  Age  Email  Password (space separated)" << endl;
    User u2;
    cin >> u2;
    u1->addUser(u2);
}

int main() {
    BookList b1;
    while (true) {
        cout << "Select one of the following choices: " << endl;
        cout << "1- Books Menu" << endl;
        cout << "2- Users Menu" << endl;
        cout << "3- Exit" << endl;
        int selection;
        cin >> selection;
        if (selection == 1) {
            cout << "How many books will you add ?" << endl;
            int numberOfBooks;
            cin >> numberOfBooks;
            BookList b(numberOfBooks);
            b1 = b;
            while (true)
            {
                cout << "Books Menu" << endl;
                cout << "1- Create a book and add it to the list" << endl;
                cout << "2- Search for a book" << endl;
                cout << "3- Display all books (with book rating)" << endl;
                cout << "4- Get the highest rating book" << endl;
                cout << "5- Get all books of a user" << endl;
                cout << "6- Copy the current book list to a new book list and switch to it" << endl;
                cout << "7- Back to the main menu" << endl;

                cin >> selection;
                if (selection == 1)
                {
                    cout << "Enter the book information in this order" << endl;
                    cout << "Title       ISBN         Category (space separated)" << endl;
                    Book b2;
                    cin >> b2;
                    while (true)
                    {
                        cout << "1- Assign Author" << endl;
                        cout << "2- Continue" << endl;
                        cin >> selection;
                        if (selection == 1)
                        {
                            cout << "Enter Author (user) id" << endl;
                            int d;
                            cin >> d;
                            User author = u1->searchUser(d);
                            b2.setAuthor(author);
                            b.addBook(b2);
                            break;
                        }
                        else
                        {
                            b.addBook(b2);
                            break;
                        }

                    }
                }
                else if (selection == 2)
                {
                    while (true) {
                        cout << "Search for a book" << endl;
                        cout << "1-Search by name" << endl;
                        cout << "2-Search by id" << endl;
                        cout << "3-return to book menu" << endl;
                        cin >> selection;
                        if (selection == 3)
                        {
                            break;
                        }
                        else if (selection == 1)
                        {
                            string n;
                            cout << "Enter name" << endl;
                            cin >> n;
                            cout << b.searchBook(n);
                        }
                        else if (selection == 2)
                        {
                            int ID;
                            cout << "Enter id" << endl;
                            cin >> ID;
                            cout << b.searchBook(ID);
                        }
                        while (true)
                        {
                            cout << "1- Update Author" << endl;
                            cout << "2- Update name" << endl;
                            cout << "3- Update Category" << endl;
                            cout << "4- Delete book" << endl;
                            cout << "5-Rate book" << endl;
                            cout << "6-Get back to books menu" << endl;

                            cin >> selection;
                            if (selection == 1)
                            {
                                cout << "Enter Author (user) id" << endl;
                                int d;
                                cin >> d;
                                User author = u1->searchUser(d);

                                if (UserList::flag == 1)
                                {
                                    b.setBookAuthor(u1->searchUser(d));
                                    break;
                                }
                                else
                                {
                                    cout << "No Author found with id " << d << endl;
                                }
                            }
                            else if (selection == 2)
                            {
                                cout << "Enter the new name" << endl;
                                string Tit;
                                cin >> Tit;
                                b.setBookName(Tit);
                            }
                            else if (selection == 3)
                            {
                                cout << "Enter the new category " << endl;
                                string Cat;
                                cin >> Cat;
                                b.setBookCategory(Cat);
                            }
                            else if (selection == 4)
                            {
                                cout << "Enter book id " << endl;
                                int bookID;
                                cin >> bookID;
                                b.deleteBook(bookID);
                            }

                            else if (selection == 5)
                            {
                                cout << "Enter rate" << endl;
                                int r;
                                cin >> r;
                                b.setBookRate(r);

                            }
                            else if (selection == 6)
                            {
                                break;
                            }
                        }

                    }

                }
                else if (selection == 3)
                {
                    cout << b;
                }
                else if (selection == 4)
                {
                    cout << b.getTheHighestRatedBook();
                }
                else if (selection == 5)
                {
                    User userr;
                    cout << "Enter ID" << endl;
                    int userrId;
                    cin >> userrId;
                    userr = u1->searchUser(userrId);
                    b.getBooksForUser(userr);
                }
                else if (selection == 6)
                {
                    b1 = b;
                }
                else if (selection == 7)
                {
                    break;
                }

                b1 = b;
            }
        }
        else if (selection == 2)
        {
            cout << "How many users will be added ?" << endl;
            int numOfUsers;
            cin >> numOfUsers;
            u1 = new UserList(numOfUsers);
            //u1 = u;
            while (true)
            {
                cout << "USERS MENU" << endl;
                cout << "1-Create a user and add it to the list" << endl;
                cout << "2-Search for a user" << endl;
                cout << "3-Display all users" << endl;
                cout << "4-Back to the main menu" << endl;
                cin >> selection;
                if (selection == 1)
                {
                    add_new_user();
                    //break;
                }
                else if (selection == 2)
                {
                    while (true)
                    {
                        cout << "1- search by name " << endl;
                        cout << "2- search by id " << endl;
                        cout << "3- Return to users menu" << endl;
                        cin >> selection;
                        User userr;
                        if (selection == 1)
                        {
                            cout << "Enter name" << endl;
                            string userrName;
                            cin >> userrName;
                            userr = u1->searchUser(userrName);
                            cout << userr;
                        }
                        else if (selection == 2)
                        {
                            cout << "Enter ID" << endl;
                            int userrId;
                            cin >> userrId;
                            userr = u1->searchUser(userrId);
                            cout << userr;
                        }
                        else if (selection == 3)
                        {
                            break;
                        }
                        cout << "1- Delete user" << endl;
                        cout << "2- Return to users menu" << endl;
                        cin >> selection;
                        if (selection == 1)
                        {
                            u1->deleteUser(userr.getId());
                        }
                        else if (selection == 2)
                        {
                            break;
                        }
                    }
                }
                else if (selection == 3)
                {
                    cout << *u1;
                }
                else if (selection == 4)
                {
                    break;
                }
            }
            //u1 = u;
        }
        else if (selection == 3)
        {
            return 0;
        }

    }
    return 0;
}





