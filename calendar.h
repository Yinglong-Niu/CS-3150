/*
 * driver.cpp
 *
 *  Created on: 12/07/2021
 *      Author: Yinglong Niu and Yucheng Long
 */

#ifndef CALENDAR_H_
#define CALENDAR_H_
#include <iostream>
using namespace std;
class calendar {
public:
private:
		int yr; //year
		int mon;//month
        int day;//day
public:
		//constructor
		calendar();


		calendar(int yr, int mon,int day);

        friend istream &operator>>(istream  & in,  calendar &x);

        friend ostream &operator<<( ostream &output, const calendar &x );
};

#endif /* CALENDAR_H_ */
