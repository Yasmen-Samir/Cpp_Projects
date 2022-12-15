#include "Book.h"
#include "string.h"
#include <iostream>

using namespace std;

int Book::count = 0;

Book::Book() {
    title = "";
    isbn = "";
    category = "";
    averageRating = 0;
    count++;
    id = count;
}
Book::Book(string title, string isbn, string category)
{
    this->title = title;
    this->isbn = isbn;
    this->category = category;
    this->averageRating = averageRating;
    id = count;
}
Book::Book(const Book& book)
{
    title = book.title;
    isbn = book.isbn;
    category = book.category;
    averageRating = book.averageRating;
    id = book.id;
    author = book.author;
}
bool Book::operator==(const Book& book)
{
    if (title == book.title) {
        if (isbn == book.isbn) {
            if (category == book.category) {
                if (averageRating == book.averageRating) {

                    return true;
                }
            }
        }
    }

    else {
        return false;
    }

}

void Book::setTitle(string title)
{
    this->title = title;
}
string Book::getTitle() {
    return title;
}
void Book::setIsbn(string isbn)
{
    this->isbn = isbn;
}
string Book::getIsbn()
{
    return isbn;
}
void Book::setCategory(string category)
{
    this->category = category;
}
string Book::getCategory()
{
    return category;
}
void Book::setId(int id)
{
    this->id = id;
}
int Book::getId() {
    return id;
}
void Book::setAuthor(User user) {
    author = user;
}

User Book::getAuthor() {
    cout << "======= Book Author info =======" << endl;
    cout << "Name:" << author.getName() << "|";
    cout << "Age:" << author.getAge() << "|";
    cout << "Id:" << author.getAge() << "|";
    cout << "Email:" << author.getAge() << endl;
    cout << "====================================" << endl;
    return author;
}

void Book::rateBook(int rating)
{

    sum += rating;
    num_of_rating++;
    averageRating = sum / num_of_rating;
}

ostream& operator<<(ostream& output, const Book& book)
{
    cout << "======= Book" << (book.id) << "info =======" << endl;
    output << "Title:" << book.title << "|";
    output << "ISBN:" << book.isbn << "|";
    output << "Id:" << book.id << "|";
    output << "Category:" << book.category << "|";
    output << "Avg Rating:" << book.averageRating << endl << endl;
    return output;
}
double Book::getRate()
{
    return averageRating;
}

istream& operator>>(istream& input, Book& book)
{

    input >> book.title >> book.isbn >> book.category;
    return input;
}


