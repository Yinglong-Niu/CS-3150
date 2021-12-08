/*
 * driver.cpp
 *
 *  Created on: 12/07/2021
 *      Author: Yinglong Niu and Yucheng Long
 */

#ifndef USER_H_
#define USER_H_
#include "library.h"
class user {
private:
   int studentID;
   string name;
   string password;
   int booknum;
   public:
   vector<book> userborrowed;
   vector<book>::iterator ub;
   user();
      user(int studentID, string name, string password);
      int getSID();
      string getName();
      string getpw();
      int getnm();
      void setnum(int booknum);
       void setpassword(string password);
      bool isPassword(string x);
      void showUserInfo();
      void borrowbook(library & lib,int x);
       void showAllborrowedbook();
     void returnbook(library & lib);
      friend istream &operator>>(istream  & in,  user &x);
};

#endif /* USER_H_ */
