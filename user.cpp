/*
 * driver.cpp
 *
 *  Created on: 12/07/2021
 *      Author: Yinglong Niu and Yucheng Long
 */

#include "user.h"

user::user(){
        studentID=0;
        name ="?";
        password = "?";
        booknum = 0;
        userborrowed;
    }
user::user(int studentID, string name, string password){
        this->studentID=studentID;
        this->name = name;
        this->password = password;
        booknum=0;
        userborrowed;
    }
    int user::getSID(){
        return studentID;
    }
    string user::getName(){
        return name;
    }
    string user::getpw(){
        return password;
    }
    int user::getnm(){
        return booknum;
    }
    void user::setnum(int booknum){
        this->booknum = booknum;
    }
     void user::setpassword(string password){
        this->password = password;
    }
    bool user::isPassword(string x){
       return x==password;
    }
    void user::showUserInfo(){
        cout<<"Student ID: "<<studentID<<endl;
        cout<<"Student Name: "<<name<<endl;
        cout<<"Password: "<<password<<endl;
        cout<<"The number of book borrowed: "<<booknum<<endl;
    }
    void user::borrowbook(library & lib,int x){
        int num = (lib.books[x-1].getNum()-1);
		if(num == -1){
			cout<<"Library do not have enough book! You cannot borrow it!"<<endl;
			return;
		}
		lib.books[x-1].setNum(num);
		userborrowed.push_back(lib.books[x-1]);
        booknum++;
        cout<<"Borrow success!\n";
    }
     void user::showAllborrowedbook(){
        for(ub=userborrowed.begin();ub!=userborrowed.end();ub++){
            ub->displayBook();
           }
    }
   void user::returnbook(library & lib){
        if(userborrowed.empty()){
            cout<<"      !!!!!!!!! Error!!! \n user's borrow container is empty! Please borrow books first!\n";
        }
        else {
            for(ub=userborrowed.begin();ub!=userborrowed.end();ub++){
                ub->displayBook();
            }
            cout<<endl;
            cout<<"\n\nPlease enter the number of the book to be returned:\n";
            int x;
            cin>>x;
            ub=userborrowed.begin()-1+x;
            ub->showBookinfo();
            userborrowed.erase(ub);
            booknum--;
            for(lib.b=lib.books.begin();lib.b!=lib.books.end();lib.b++){
                if (lib.b->getISBN() == ub->getISBN()){
                    lib.b->setNum(lib.b->getNum()+1);
                }
            }
            cout<<"Return book successfully!\n";
        }
    }
    istream &operator>>(istream  & in,  user &x){
       in>>x.studentID>>x.name>>x.password;
       return in;
       }

