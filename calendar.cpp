/* 
 * driver.cpp
 *
 *  Created on: 12/07/2021
 *      Author: Yinglong Niu and Yucheng Long
 */

#include "calendar.h"
#include <iostream>	//Provides input and output support for objects of built-in types
using namespace std;	//Declare that this file uses the C++ standard library
calendar::calendar()
		{		// Default constructor initialize private variables
			yr = 0;
			mon = 0;
            		day = 0;
		}

calendar::calendar(int yr, int mon,int day)
		{		// Parameter constructor initialize private variables
			this->yr = yr;
			this->mon = mon;
            		this->day = day;
		}
				// Overload the input operator
         istream &operator>>(istream  & in,  calendar &x){
       		in>>x.yr>>x.mon>>x.day;
      		return in;	// Support continuous reading
       }
				// Overload the output operator
         ostream &operator<<( ostream &output, const calendar &x )
      {
         	output<<x.yr<<" "<<x.mon<<" "<<x.day;
         	return output;	// Support continuous output
      }

