//============================================================================
// Name        : Lib.cpp
// Author      : Yinglong Niu and Yucheng Long
// Version     :
// Copyright   : Your copyright notice
// Description : Library Management System
//============================================================================
//All of the search method, no matter srach book or search user, I did not know how to print the sentence that not found first time.
//I did some reserach and I used one person's idea.
//Reference: https://blog.csdn.net/weixin_44335707/article/details/106829327
#include <iostream>
using namespace std;
#include "info.h"
#include "driver.h"
int main() {
		info i;
	    i.about();
	    driver d;
	    d.read();
	    d.entrance();
}
