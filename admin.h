/*
 * driver.cpp
 *
 *  Created on: 12/07/2021
 *      Author: Yinglong Niu and Yucheng Long
 */
#ifndef ADMIN_H_
#define ADMIN_H_
#include "user.h"
class admin {
	private:
    string password;
    public:
    vector<user> users;
    vector<user>::iterator u;
public:
    admin();
        admin(string password);
        void setpassword(string password);
        void addUser();
        void delUser();
        void showAllUser();
        void searchByID(int a);
        void searchByName(string a);
        bool isPassword(string x);
        bool isUser(user U);
        void changePassword(user U, string x);
        void readUser();
};

#endif /* ADMIN_H_ */
