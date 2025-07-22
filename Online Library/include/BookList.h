#include<User.h>
#include<Book.h>
#include<iostream>
#include<string>
#include<iostream>
#include<string>
#include<cstring>
#include "User.h"
#include "Book.h"
#ifndef BOOKLIST_H
#define BOOKLIST_H

class BookList {
private:
    Book* books;
    int capacity;
    int booksCount = 0;
public:
    BookList();
    BookList(int capacity);
    BookList(const BookList& anotherList);
    int array = 0;
    void addBook(Book book);
    Book& searchBook(string name);
    Book& searchBook(int id);
    void deleteBook(int id);
    Book getTheHighestRatedBook();
    void getBooksForUser(User user);
    Book& operator [ ] (int index);
    int getBooksCount();
    void setBookAuthor(User user);
    void setBookName(string Tit);
    void setBookCategory(string Cat);
    void setBookRate(int rate);
    friend ostream& operator<<(ostream& output, BookList& booklist);
    ~BookList();
};
#endif // BOOKLIST_H



