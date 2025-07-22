#include "UserList.h"
#include <string>

int UserList::flag = 0;

UserList::UserList()
{}
UserList::UserList(int capacity)
{
    this->capacity = capacity;
    users = new User[capacity];
    usersCount = 0;
}
void UserList::addUser(User& user)
{
    //cin >> user;
    user.setId(usersCount+1);
    users[usersCount] = user;
    usersCount++;
}

User& UserList::searchUser(string name)
{
    flag = 0;
    for (int i = 0; i < usersCount; i++)
    {
        if (users[i].getName() == name)
        {
            flag = 1;
            cout << users[i];
            return users[i];
        }
    }
    cout << "Not found" << endl;
}

User& UserList::searchUser(int id)
{
    for (int i = 0; i < usersCount; i++)
    {
        if (users[i].getId() == id)
        {
            cout << users[i];
            return users[i];
        }
    }
    cout << "Not found" << endl;
}

void UserList::deleteUser(int id)
{
    for (int i = 0; i < usersCount; i++)
    {
        if (users[i].getId() == id)
        {
            for (int j = i; j < usersCount - 1; j++)
            {
                User temp = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp;
            }
            break;
        }
    }
    users[usersCount - 1].setAge(0);
    users[usersCount - 1].setEmail(" ");
    users[usersCount - 1].setName(" ");
    users[usersCount - 1].setPassword(" ");
    usersCount--;
    cout << "user deleted" << endl;
}

ostream& operator<<(ostream& output, UserList& userList)
{
    for (int i = 0; i < userList.usersCount; i++)
    {
        output << userList.users[i] << endl;
    }
    return output;
}
UserList::~UserList()
{
    delete[] users;
}
