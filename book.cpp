/*
 * driver.cpp
 *
 *  Created on: 12/07/2021
 *      Author: Yinglong Niu and Yucheng Long
 */

#include "book.h"

book::book(){
        ISBN=0;			// The default constructor initializes private variables
        BookName="NULL";
        Author="NULL";
        page = 0;
        pbdat;
        num=3;//Default setting, each book's number is 3.
    }
book::book(int ISBN,int page, string BookName,string Author,calendar pbdat){	// The parameterized constructor initializes private variables
        this -> ISBN = ISBN;
        this -> page = page;
        this -> BookName = BookName;
        this -> Author = Author;
        this -> pbdat = pbdat;
        num=3;
    }
    int book::getISBN(){return ISBN;}			// return ISN.
    string book::getBookName(){return BookName;}	// return book name.
    string book::getAuthor(){return Author;}		//return author name.
    calendar book::getPublishDate(){return pbdat;}	// return book number
    int book::getNum(){return num;}

    void book::setNum(int num){this->num=num;}		// set book number

    string book::getCurrentTime(){			// get current time
        time_t t = time(0);
        char tp[11];
        strftime(tp,sizeof(tp),"%Y %m %d",localtime(&t));
        return tp;
    }

    string book::dispReturndate(){			// display reutn time
    		time_t result  = time(NULL);
		time_t after = result + 3600*24*30*2;
    	        char tp[11];
    	        strftime(tp,sizeof(tp),"%Y %m %d",localtime(&after));
    	        return tp;
    }

    void book::displayBook(){				//This method is designed for user because it can print borrow time and return time.

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

    void book::showBookinfo(){				// This method just prints all the information of the books.
            cout<< "The ISBN of the book is: "<<ISBN<<endl;
            cout<< "The page of the book is: "<<page<<endl;
            cout<< "The name of the book is: "<<BookName<<endl;
            cout<< "The author of the book is: "<<Author<<endl;
            cout<< "The publish date of the book is: "<<pbdat<<endl;
            cout<< "The number of the book is: "<<num<<endl;
        }

   istream &operator>>(istream  & in,  book &x){	//Overload the input operator
       in>>x.ISBN>>x.page>>x.BookName>>x.Author>>x.pbdat;
       return in;
       }

