/*
 * driver.cpp
 *
 *  Created on: 12/07/2021
 *      Author: Yinglong Niu and Yucheng Long
 */

#include "book.h"

book::book(){
        ISBN=0;
        BookName="NULL";
        Author="NULL";
        page = 0;
        pbdat;
        num=3;//Default setting, each book's number is 3.
    }
book::book(int ISBN,int page, string BookName,string Author,calendar pbdat){
        this -> ISBN = ISBN;
        this -> page = page;
        this -> BookName = BookName;
        this -> Author = Author;
        this -> pbdat = pbdat;
        num=3;
    }
    int book::getISBN(){return ISBN;}
    string book::getBookName(){return BookName;}
    string book::getAuthor(){return Author;}
    calendar book::getPublishDate(){return pbdat;}
    int book::getNum(){return num;}

    void book::setNum(int num){this->num=num;}

    string book::getCurrentTime(){
        time_t t = time(0);
        char tp[11];
        strftime(tp,sizeof(tp),"%Y %m %d",localtime(&t));
        return tp;
    }

    string book::dispReturndate(){
    		time_t result  = time(NULL);
		time_t after = result + 3600*24*30*2;
    	        char tp[11];
    	        strftime(tp,sizeof(tp),"%Y %m %d",localtime(&after));
    	        return tp;
    }

    void book::displayBook(){

            cout<< "The ISBN of the book is: "<<ISBN<<endl;
            cout<< "The page of the book is: "<<page<<endl;
            cout<< "The name of the book is: "<<BookName<<endl;
            cout<< "The author of the book is: "<<Author<<endl;
            cout<< "The publish date of the book is: "<<pbdat<<endl;
            cout<< "The number of the book is: "<<num<<endl;

            cout<< "You borrowed book at "<<getCurrentTime()<<endl;
            cout<< "You should return the book at "<<dispReturndate()<<endl;
            cout<< endl;
        }

    void book::showBookinfo(){
            cout<< "The ISBN of the book is: "<<ISBN<<endl;
            cout<< "The page of the book is: "<<page<<endl;
            cout<< "The name of the book is: "<<BookName<<endl;
            cout<< "The author of the book is: "<<Author<<endl;
            cout<< "The publish date of the book is: "<<pbdat<<endl;
            cout<< "The number of the book is: "<<num<<endl;
        }

   istream &operator>>(istream  & in,  book &x){
       in>>x.ISBN>>x.page>>x.BookName>>x.Author>>x.pbdat;
       return in;
       }

