//
// Created by Janis Kesteris on 07/01/17.
//

#ifndef MAJASDARBS3_MENUCONTROLLER_H
#define MAJASDARBS3_MENUCONTROLLER_H


#include "MenuItem.h"

class MenuController {

public:
    MenuController();

    void display();

    MenuItem *menuItems[5];
};


#endif //MAJASDARBS3_MENUCONTROLLER_H
