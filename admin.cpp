/*
 * driver.cpp
 *
 *  Created on: 12/07/2021
 *      Author: Yinglong Niu and Yucheng Long
 */

#include "admin.h"

admin::admin(){
        password = "000000";//default password
    }
admin::admin(string password){
        this->password = password;
    }
    void admin::setpassword(string password){
        this->password = password;
    }
    void admin::addUser(){
    user u;
    cout<<"Enter as following: \n";
    cout<<"1.The studentID. 2.The student's name. 3.Student's password.\n";
    cin>>u;
    users.push_back(u);
    cout<<"Book added successfully!\n";
}
void admin::delUser(){
        if(users.empty()){
            cout<<"      !!!!!!!!! Error!!! \n user container is empty! Please add user first!\n";
        }
        else {
            for(u=users.begin();u!=users.end();u++){
                u->showUserInfo();
            }
            cout<<endl;
            cout<<"\n\nPlease enter the number of the user to be deleted:\n";
            int x;
            cin>>x;
            u=users.begin()-1+x;
            u->showUserInfo();
            users.erase(u);
            cout<<"Delete user successfully!\n";
        }
    }
     void admin::showAllUser(){
        for(u=users.begin();u!=users.end();u++){
            u->showUserInfo();
      }
    }
    void admin::searchByID(int a){
        int found = 0;
        for(u=users.begin();u!=users.end();u++){
                if (u->getSID() == a){
                    found = 1;
                    u->showUserInfo();
                }
            }
            if (!found){
                cout<<"Cannot find that user!\n";
            }
    }
    void admin::searchByName(string a){
        int found = 0;
        for(u=users.begin();u!=users.end();u++){
                if (u->getName() == a){
                    found = 1;
                    u->showUserInfo();
                }
            }
            if (!found){
                cout<<"Cannot find that user!\n";
            }
    }
    bool admin::isPassword(string x){
       return x==password;
    }
    bool admin::isUser(user U){//if the input's name ID and password can be found in the user vector, it will return true.
        for(u=users.begin();u!=users.end();u++){
            if((u->getName()==U.getName())&&(u->getSID()==U.getSID())&&(U.isPassword(u->getpw()))){
                return 1;
            }
        }
        return 0;
    }
    void admin::changePassword(user U, string x){//allow student to change password also change in user vector.
        for(u=users.begin();u!=users.end();u++){
            if(u->getName()==U.getName()){
                u->setpassword(x);
            }
        }
    }
    void admin::readUser(){//reference:https://blog.csdn.net/qq_37830546/article/details/106197643
        ifstream inFile1;
    	inFile1.open("C:\\Users\\lenovo\\users.txt");
    	user u;
    	if (inFile1){
    		cout << "users.txt1 open scessful\n" << endl;
    		while (inFile1>>u){
    			users.push_back(u);
    		}
    		inFile1.close();
    	}
    	else
    		cout << "users..txt doesn't exist\n" << endl;
        }

