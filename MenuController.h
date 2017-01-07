#ifndef MAJASDARBS3_MENUCONTROLLER_H
#define MAJASDARBS3_MENUCONTROLLER_H


#include "MenuItem.h"

class MenuController {

public:
    MenuController();

    void display();

    MenuItem *menuItems[5];

    void selectNextItem();

    int currentMenuItemIndex;

    size_t getMenuItemCount() const;

    void removeItemHighlighting();

    void toggleHoverState();

    bool hoverStateActive;

    void displaySelectedMenuItem();
};


#endif //MAJASDARBS3_MENUCONTROLLER_H
