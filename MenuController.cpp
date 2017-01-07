//
// Created by Janis Kesteris on 07/01/17.
//
#include <iostream>
#include "MenuController.h"

MenuController::MenuController() {
}

void MenuController::display() {
    //nosakidro cik elementi masīvā
    int n = sizeof(menuItems)/sizeof(menuItems[0]);
    std::cout << n << "\n";
    for(int i=0;i<n;++i){
//        printf("\r[%3d%%]",i);
        printf("  ");
        printf(menuItems[i]->display());
    };
}
