#ifndef BOOK_H
#define BOOK_H
#include<cstring>
#include<iostream>
#include "User.h"
using namespace std;

class Book {
private:
    string title;
    string isbn;
    int id;
    string category;
    double averageRating;
    double sum = 0;
    int num_of_rating = 0;
    User author;
public:
    static int count;
    Book();
    Book(string title, string ispn, string category);
    Book(const Book& book);
    bool operator==(const Book& book);
    void setTitle(string title);
    string getTitle();
    void setIsbn(string isbn);
    string getIsbn();
    void setId(int id);
    int getId();
    void setCategory(string category);
    string getCategory();
    void setAuthor(User user);
    User getAuthor();
    void rateBook(int rating);
    double getRate();
    friend ostream& operator<<(ostream& output, const Book& book);
    friend istream& operator>>(istream& input, Book& book);
};
#endif // BOOK_H


