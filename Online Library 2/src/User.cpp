#include "User.h"
#include <string.h>
#include <iostream>

int User::count = 0;

User::User()
{
    name = "";
    age = 0;
    count++;
    id = count;
    password = "";
    email = "";
}
User::User(string name, int age, string email, string password)
{
    this->name = name;
    this->age = age;
    count++;
    id = count;
    this->email = email;
    this->password = password;
}
User::User(const User& user)
{
    name = user.name;
    age = user.age;
    id = user.id;
    email = user.email;
    password = user.password;
}
bool User::operator==(const User& user)
{
    if (password == user.password) {
        if (name == user.name) {
            if (age == user.age) {
                if (email == user.email) {
                    return true;
                }
            }
        }
    }
    else {
        return false;
    }
}
void User::setName(string name)
{
    this->name = name;
}
string User::getName() {
    return name;
}
void User::setPassword(string password)
{
    this->password = password;
}
string User::getPassword()
{
    return password;
}
void User::setEmail(string email)
{
    this->email = email;
}
string User::getEmail()
{
    return email;
}
void User::setId(int id)
{
    this->id = id;
}
int User::getId()
{
    return id;
}
void User::setAge(int age)
{
    this->age = age;
}
int User::getAge()
{
    return age;
}
ostream& operator<<(ostream& output, const User& user)
{
    cout << "======= User" << (user.id) << "info =======" << endl;
    output << "Name:" << user.name << "|";
    output << "Age:" << user.age << "|";
    output << "Id:" << user.id << "|";
    output << "Email:" << user.email << "|" << endl;
    cout << "==========================" << endl;
    return output;
}
istream& operator>>(istream& input, User& user)
{
    //if (user.count == 1) { cout << "Let's add user" << endl; }
    //else { cout << "Let's add another user" << endl; }
    input >> user.name >> user.age >> user.email >> user.password;
    return input;
}
