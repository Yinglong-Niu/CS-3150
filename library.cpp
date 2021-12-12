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
            //An iterator added to or subtracted from an integer returns an iterator, similar to a pointer added to an integer, pointing to a different position.
            b=books.begin()-1+x;//books.begin() means that index start from 0, if I want to delete No.x of book, the index of elements should be x-1.
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
        int found = 0;//the "found" can seem as a flag. If the book not exist, it will be false. And the if sentence will tell user the book cannot be found.
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
      // When had overload the input operator in class book, so we can diractly input the object of class book.
      // After process the input, the overloaded method would return an istream reference.
      // If the returned reference is NULL, it is equivalent to false.
    		while (inFile1>>b){//the process of putting the elements in vector.
    			books.push_back(b);
    		}
    		inFile1.close();
    	}
    	else
    		cout << "books..txt doesn't exist\n" << endl;//if the file cannot be found
        }



