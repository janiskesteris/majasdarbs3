//
// Created by Janis Kesteris on 07/01/17.
//

#ifndef MAJASDARBS3_MENUITEM_H
#define MAJASDARBS3_MENUITEM_H


class MenuItem {

public:
    MenuItem(int id, const char label);

    MenuItem(int id, const char *label);

    int id;
    const char *label;

    const char *display();
};


#endif //MAJASDARBS3_MENUITEM_H
