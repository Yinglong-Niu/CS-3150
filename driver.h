/*
 * driver.cpp
 *
 *  Created on: 12/07/2021
 *      Author: Yinglong Niu and Yucheng Long
 */

#ifndef DRIVER_H_
#define DRIVER_H_
#include "admin.h"
class driver {
public:
    admin am;
    library lib;
    user ui;
    void entrance();
    void read();
    void Admin();
    void User();
};

#endif /* DRIVER_H_ */
