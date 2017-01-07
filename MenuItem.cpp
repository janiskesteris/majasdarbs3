#include "MenuItem.h"
#include <sstream>
#include <iostream>
using namespace std;

MenuItem::MenuItem(int id, const char *label, bool disabled) {
    this->id = id;
    this->label = label;
    this->highlighted = false;
    this->disabled = disabled;
}

const char *MenuItem::formattedLabel(bool hoverStateActive) {
    stringstream formattedLabel;
    if(this->highlighted && hoverStateActive){
        formattedLabel << ">" << this->label << "<";
    }else if(this->disabled){
        formattedLabel << "-" << this->label << "-";
    } else{
        formattedLabel << this->label;
    }
    return formattedLabel.str().c_str();
}

void MenuItem::setAsHighlighted() {
    this->highlighted = true;
}

void MenuItem::removeHighlight() {
    this->highlighted = false;
}

void MenuItem::display() {
    cout << endl << "\r" << this->label << " -> id: " << this->id << endl;
}
