/*
 * driver.cpp
 *
 *  Created on: 12/07/2021
 *      Author: Yinglong Niu and Yucheng Long
 */
#ifndef LIBRARY_H_
#define LIBRARY_H_
#include "book.h"
#include <fstream>
#include<vector>
class library {
public:
public:
vector<book> books;
vector<book>::iterator b;
 library();
void addBook();
void delBook();
    void showAllbook();
    void searchBybookName(string name);
    void searchByAuthor(string name);
    void searchByISBN(int a);
    void readBook();
};

#endif /* LIBRARY_H_ */
