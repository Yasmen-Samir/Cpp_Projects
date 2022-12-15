#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include "User.h"
#include <string>
#include<iostream>


class UserList {
private:
	User* users;
	int capacity;
	int usersCount;
public:
	static int flag;

	UserList();
	UserList(int capacity);
	void addUser(User& user); // at the end of the array.
	User& searchUser(string name);
	User& searchUser(int id);
	void deleteUser(int id);
	friend ostream& operator<<(ostream& output, UserList& userList);//to display all books
	~UserList();
};
#endif // LIST_H_INCLUDED
