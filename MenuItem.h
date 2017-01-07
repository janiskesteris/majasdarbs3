//
// Created by Janis Kesteris on 07/01/17.
//

#ifndef MAJASDARBS3_MENUITEM_H
#define MAJASDARBS3_MENUITEM_H


class MenuItem {

public:
    MenuItem(int id, const char *label);

    MenuItem(int id, const char label, bool disabled);

    MenuItem(int id, const char *label, bool disabled);

    int id;
    const char *label;

    const char *formattedLabel(bool b);

    void setAsHighlighted();

    bool highlighted;

    void removeHighlight();

    bool disabled;

    void display();
};


#endif //MAJASDARBS3_MENUITEM_H
