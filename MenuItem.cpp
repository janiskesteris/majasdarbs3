//
// Created by Janis Kesteris on 07/01/17.
//

#include "MenuItem.h"

MenuItem::MenuItem(int id, const char *label) {
    this->id = id;
    this->label = label;
}

const char *MenuItem::display() {
    return this->label;
}
