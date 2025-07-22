#include "BookList.h"
#include <string>
#include<iostream>

using namespace std;

BookList::BookList(){

}
BookList::BookList(int capacity) {
    this->capacity = capacity;
    books = new Book[capacity];
}
void BookList::addBook(Book book) {
    books[booksCount] = book;
    booksCount++;
    array++;
}
BookList::BookList(const BookList& anotherList) {
    for (int i = 0; i < booksCount; i++) {
        books[i] = anotherList.books[i];
    }
    array = anotherList.array;
    capacity = anotherList.capacity;
}
void BookList::setBookAuthor(User user) {
    books[booksCount].setAuthor(user);
}
void BookList::setBookName(string Tit) {
    books[booksCount].setTitle(Tit);
}
void BookList::setBookCategory(string Cat) {
    books[booksCount].setCategory(Cat);
}
void BookList::setBookRate(int rate) {
    books[booksCount].rateBook(rate);
}
Book& BookList::searchBook(string n) {
    for (int i = 0; i < booksCount; i++) {
        if (books[i].getTitle() == n) {
            return books[i];
        }
    }
}
Book& BookList::searchBook(int ID) {
    for (int i = 0; i < booksCount; i++) {
        if (books[i].getId() == ID) {
            return books[i];
        }
    }
}
void BookList::deleteBook(int ID) {
    for (int i = 0; i < booksCount; i++) {
        if (books[i].getId() == ID) {
            array--;
            for (int x = i; x < array; x++) {
                delete (books + x);
                books[x] = books[x + 1];
            }
        }

    }
}
Book BookList::getTheHighestRatedBook() {
    int HieghestRate = 0;
    for (int i = 0; i < booksCount; i++) {
        if (books[i].getRate() > HieghestRate)
            HieghestRate = books[i].getRate();
    }
    for (int i = 0; i < booksCount; i++) {
        if (books[i].getRate() == HieghestRate)
            return books[i];
    }
}
void BookList::getBooksForUser(User user) {
    for (int i = 0; i < booksCount; i++) {
        if (books[i].getAuthor() == user)
            cout << books[i];
    }
}
Book& BookList::operator[] (int index) {
    for (int i = 0; i < booksCount; i++) {
        return books[index];
    }
}
int BookList::getBooksCount() {
    return booksCount;
}
ostream& operator<<(ostream& output, BookList& booklist) {
    for (int i = 0; i < booklist.array; i++) {
        output << booklist.books[i];
    }
    return output;
}
BookList::~BookList() {
    delete[] books;
}
