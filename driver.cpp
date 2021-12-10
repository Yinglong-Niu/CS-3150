/*
 * driver.cpp
 *
 *  Created on: 12/07/2021
 *      Author: Yinglong Niu and Yucheng Long
 */

#include "driver.h"

	void driver::read(){
        lib.readBook();
        am.readUser();
    }
    void driver::entrance(){
        cout<<"1.Administrator menu\n";
        cout<<"2.User menu\n";
        cout<<"3.Exit\n";
        int x;
        cin>>x;
        switch(x){
            case 1:{
                system("cls");
                cout<<"Enter 000000, you can change your password later.\n";
                string a;
                renter: cin>>a;
                if(am.isPassword(a)){
                    Admin();
                }
                else{
                    system("cls");
                    cout<<"Password error!\n";
                    cout<<"1.Re-enter the password\n";
                    cout<<"2.Go back to the entrance\n";
                    int x;
                    cin>>x;
                    switch(x){
                        case 1: {goto renter;break;}
                        case 2: {entrance();break;}
                    }
                }
                break;
            }
            case 2:{
                if(am.users.empty()){
                    system("cls");
                cout<<"Users is empty now.\n";
                 system("pause");
                entrance();
                }
                reu: cout<<"Please enter following to log in.\n";
                cout<<"1.student ID"<<"  "<<"2.Your name."<<"  "<<"3.Your password."<<endl;
                cin>>ui;
                if(am.isUser(ui)){
                User();
                }
                else{
                    system("cls");
                    cout<<"Information error!\n";
                    cout<<"1.Re-enter all the information\n";
                    cout<<"2.Go back to the entrance\n";
                    int x;
                    cin>>x;
                    switch(x){
                        case 1: {goto reu;break;}
                        case 2: {entrance();break;}
                    }
                }
                break;
            }
            case 3:{
                system("cls");
                cout<<"Thanks for using our system.\n";
                 exit(0);
                 break;
            }
            default:{
                system("cls");
                cout<<"Enter Error!\n";
                system("pause");
                entrance();
            }
        }
    }
    void driver::Admin(){
        ad: cout<<"1.Back to the entrance\n";
            cout<<"2.Add new book.\n";
            cout<<"3.Delete the book.\n";
            cout<<"4.Add new user.\n";
            cout<<"5.Delete the user.\n";
            cout<<"6.search the user.\n";
            cout<<"7.Show all the books of library.\n";
            cout<<"8. Show all users' infomation.\n";
            cout<<"9. Change the password.\n";
            int x;
    enterx: cin>>x;
    switch(x){
        case 1:{
            system("pause");
            entrance();
            break;
        }
        case 2:{
            system("cls");
            lib.addBook();
            system("pause");
            goto ad;
            break;
        }
        case 3:{
            system("cls");
            lib.delBook();
            system("pause");
            goto ad;
            break;
        }
        case 4:{
            system("cls");
            am.addUser();
            system("pause");
            goto ad;
            break;
        }
        case 5:{
            system("cls");
            am.delUser();
            system("pause");
            goto ad;
            break;
        }
        case 6:{
            cout<<"1.Search by student's ID.\n";
            cout<<"2.Search by student's name.\n";
            int x;
            enteru: cin>>x;
            switch(x){
                case 1:{
                    system("cls");
                    int x;
                    cin>>x;
                    am.searchByID(x);
                    system("pause");
                    goto ad;
                    break;
                }
                case 2:{
                    system("cls");
                    string x;
                    cin>>x;
                    am.searchByName(x);
                    system("pause");
                    goto ad;
                    break;
                }
                default:{
                cout<<"Enter Error!\n";
                goto enteru;
            }
            }
        }
        case 7:{
            system("cls");
            lib.showAllbook();
             system("pause");
            goto ad;
            break;
        }
        case 8:{
            system("cls");
            am.showAllUser();
            system("pause");
            goto ad;
            break;
        }
        case 9:{
            system("cls");
            cout<<"Enter old password.\n";
            string a;
            re: cin>>a;
            if(am.isPassword(a)){
                cout<<"enter new password\n";
                string b;
                cin>>b;
                am.setpassword(b);
                cout<<"success!\n";
            }else{
                system("cls");
                cout<<"Password error!\n";
                system("pause");
                    goto re;
            }
            goto ad;
            break;
        }
        default:{
                system("cls");
                cout<<"Enter Error!\n";
                system("pause");
                goto enterx;
            }
    }
    }
    void driver::User(){
        system("cls");
        ur: cout<<"1.Back to the entrance\n";
            cout<<"2.Borrow book.\n";
            cout<<"3.Return book.\n";
            cout<<"4.search book.\n";
            cout<<"5.Show all the borrowed books.\n";
            cout<<"6.Show my infomation.\n";
            cout<<"7.Change the password.\n";
            int a;
            entera: cin>>a;
            switch (a)
            {
            case 1:{
            entrance();
            break;
        }
            case 2:{
                system("cls");
                lib.showAllbook();
                int a;
                cout<<"Enter the number of book you want to borrow.\n";
                cin>>a;
                ui.borrowbook(lib, a);
                for(am.u=am.users.begin();am.u!=am.users.end();am.u++){
                if (am.u->getName() == ui.getName()){
                    am.u->setnum(am.u->getnm()+1);//to set the number of book that user borrowed in user vector.
                }
            }
                system("pause");
                goto ur;
                break;
            }
            case 3:{
                system("cls");
                ui.returnbook(lib);
                for(am.u=am.users.begin();am.u!=am.users.end();am.u++){
                if (am.u->getName() == ui.getName()){
                    am.u->setnum(am.u->getnm()-1);//to set the number of book that user borrowed in user vector.
                }
            }
                system("pause");
                goto ur;
                break;
            }
            case 4:{
            cout<<"1.Search by book's ISBN.\n";
            cout<<"2.Search by book's author.\n";
            cout<<"3.Search by book's name.\n";
            int x;
            enterb: cin>>x;
            switch(x){
                case 1:{
                    system("cls");
                    int x;
                    cin>>x;
                    lib.searchByISBN(x);
                    system("pause");
                    goto ur;
                    break;
                }
                case 2:{
                     system("cls");
                    string x;
                    cin>>x;
                    lib.searchByAuthor(x);
                    system("pause");
                    goto ur;
                    break;
                }
                case 3:{
                    system("cls");
                    string x;
                    cin>>x;
                    lib.searchBybookName(x);
                    system("pause");
                    goto ur;
                    break;
                }
                default:{
                cout<<"Enter Error!\n";
                goto enterb;
            }
            }
            }
            case 5:{
                system("cls");
                ui.showAllborrowedbook();
                system("pause");
                goto ur;
                break;
            }
            case 6:{
                system("cls");
                ui.showUserInfo();
                system("pause");
                goto ur;
                break;
            }
            case 7:{
                cout<<"Enter your new password\n";
                string a;
                cin>>a;
                am.changePassword(ui,a);
                ui.setpassword(a);
                cout<<"change successful!\n";
                User();
                break;
            }
            default:{
                cout<<"Enter Error!\n";
                goto entera;
            }
            }
    }

