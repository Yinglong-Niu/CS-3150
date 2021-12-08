/*
 * driver.cpp
 *
 *  Created on: 12/07/2021
 *      Author: Yinglong Niu and Yucheng Long
 */

#include "library.h"


 library::library(){
     books;
 }
void library::addBook(){
    book b;
    cout<<"Please enter in the following order"<<endl;
    cout<<"1.ISBN"<<" "<<"2.Page"<<" "<<"3.BookName"<<" "<<"4.Author"<<" "<<"5.Publish Year Month Day\n";
    cin>>b;
    books.push_back(b);
    cout<<"\nBook added successfully!\n";
}
void library::delBook(){
        if(books.empty()){
            cout<<"      !!!!!!!!! Error!!! \n Book container is empty! Please add books first!\n";
        }
        else {
            for(b=books.begin();b!=books.end();b++){
                b->showBookinfo();
            }
            cout<<endl;
            cout<<"\n\nPlease enter the number of the book to be deleted:\n";
            int x;
            cin>>x;
            b=books.begin()-1+x;
            b->showBookinfo();
            books.erase(b);
            cout<<"Delete book successfully!\n";
        }
    }
    void library::showAllbook(){
        for(b=books.begin();b!=books.end();b++){
            b->showBookinfo();
           }
    }
    void library::searchBybookName(string name){
        int found = 0;
        for(b=books.begin();b!=books.end();b++){
                if (b->getBookName() == name){
                    found = 1;
                    b->showBookinfo();
                }
            }
            if (!found){
                cout<<"Cannot find that book!\n";
            }
    }
    void library::searchByAuthor(string name){
        int found = 0;
        for(b=books.begin();b!=books.end();b++){
                if (b->getAuthor() == name){
                    found = 1;
                    b->showBookinfo();
                }
            }
            if (!found){
                cout<<"Cannot find that book!\n";
            }
    }
    void library::searchByISBN(int a){
        int found = 0;
        for(b=books.begin();b!=books.end();b++){
                if (b->getISBN() == a){
                    found = 1;
                    b->showBookinfo();
                }
            }
            if (!found){
                cout<<"Cannot find that book!\n";
            }
    }
    void library::readBook(){//reference:https://blog.csdn.net/qq_37830546/article/details/106197643
        ifstream inFile1;
    	inFile1.open("C:\\Users\\lenovo\\books.txt");
    	book b;
    	if (inFile1){
    		cout << "books.txt1 open scessful\n" << endl;
    		while (inFile1>>b){
    			books.push_back(b);
    		}
    		inFile1.close();
    	}
    	else
    		cout << "books..txt doesn't exist\n" << endl;
        }



