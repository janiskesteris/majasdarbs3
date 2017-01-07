#include <iostream>
#include "MenuController.h"
#include <sstream>
using namespace std;

MenuController::MenuController() {
    this->currentMenuItemIndex = -1;
    this->hoverStateActive = true;
}

void MenuController::display() {
    stringstream menuString; //stringstream atļauj modifcēt definētu string mainīgo kura izmērs var patvaļīgi mainīties

    int menuItemCount = getMenuItemCount();
    for(int i=0;i<menuItemCount;++i){
        menuString << " " << menuItems[i]->formattedLabel(this->hoverStateActive) << " ";
    };
    printf("\r"); //atgriež kursoru uz 0to pozīciju rindā
    printf(menuString.str().c_str()); //pārvērš stringstream uz char mainīgā tipu
}

size_t MenuController::getMenuItemCount() const { return sizeof(menuItems) / sizeof(menuItems[0]); }

void MenuController::selectNextItem() {
    int nextItemIndex = this->currentMenuItemIndex + 1;
    int lastItemIndex = getMenuItemCount() - 1;
    if(this->currentMenuItemIndex == -1 || nextItemIndex > lastItemIndex){
        this->currentMenuItemIndex = 0;
    } else{
        this->currentMenuItemIndex = nextItemIndex;
    }

    if(menuItems[this->currentMenuItemIndex]->disabled){
        selectNextItem(); //rekursīvi meklē nākamo atļauto menuItem ja current ir disabled
    } else{
        removeItemHighlighting();
        this->currentMenuItemIndex = this->currentMenuItemIndex;
        menuItems[this->currentMenuItemIndex]->setAsHighlighted();
    }
}

void MenuController::removeItemHighlighting() {
    int menuItemCount = getMenuItemCount();
    for(int i=0;i<menuItemCount;++i){
        menuItems[i]->removeHighlight();
    };
}

void MenuController::toggleHoverState() {
    if(this->hoverStateActive == true){
        this->hoverStateActive = false;
    } else{
        this->hoverStateActive = true;
    }

}

void MenuController::displaySelectedMenuItem() {
    if(this->currentMenuItemIndex != -1) {
        menuItems[this->currentMenuItemIndex]->display();
    }
}
