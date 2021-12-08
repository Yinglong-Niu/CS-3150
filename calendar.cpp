/* Yucheng Long try to edit
 * driver.cpp
 *
 *  Created on: 12/07/2021
 *      Author: Yinglong Niu and Yucheng Long
 */

#include "calendar.h"
#include <iostream>
using namespace std;
calendar::calendar()
		{
			yr = 0;
			mon = 0;
            day = 0;
		}

calendar::calendar(int yr, int mon,int day)
		{
			this->yr = yr;
			this->mon = mon;
            this->day = day;
		}
         istream &operator>>(istream  & in,  calendar &x){
       in>>x.yr>>x.mon>>x.day;
       return in;
       }
         ostream &operator<<( ostream &output, const calendar &x )
      {
         output<<x.yr<<" "<<x.mon<<" "<<x.day;
         return output;
      }

