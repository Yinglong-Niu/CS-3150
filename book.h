/*
 * driver.cpp
 *
 *  Created on: 12/07/2021
 *      Author: Yinglong Niu and Yucheng Long
 */
#ifndef BOOK_H_
#define BOOK_H_
#include "calendar.h"
#include <time.h>
class book {
	private:
    int ISBN;
    int page;
    string BookName;
    string Author;
    calendar pbdat;//publish date
    int num;
public:
    book();
        book(int ISBN,int page, string BookName,string Author,calendar pbdat);
        int getISBN();
        string getBookName();
        string getAuthor();
        calendar getPublishDate();
        int getNum();

        void setNum(int num);

        string getCurrentTime();

        string dispReturndate();

        void displayBook();

        void showBookinfo();

        friend istream &operator>>(istream  & in,  book &x);
    };

#endif /* BOOK_H_ */
