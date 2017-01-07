#include <iostream>
#include "MenuItem.h"
#include "MenuController.h"

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
//    MenuItem tevaAuto = new MenuItem("WN827253426");
//    Controller *form = new Controller();

    MenuController *menuController = new MenuController();
    menuController->menuItems[0] = new MenuItem(1, "File");
    menuController->menuItems[1] = new MenuItem(2, "Edit");
    menuController->menuItems[2] = new MenuItem(3, "View");
    menuController->menuItems[3] = new MenuItem(4, "Tools");
    menuController->menuItems[4] = new MenuItem(5, "Help");

    menuController->display();

    int key;
    int loop = 1;
    while(loop)
    {
        key = getchar();
        switch(key)
        {
            case 'o':
            case 'O':
                printf("o\n");
                std::cout << "Control with label = '" << "desa" << "' selected" << std::endl;
                break;
            case 'c':
            case 'C':
                printf("c");
//                form->simulateOSselect('c');
                break;
            case 'q':
                loop = 0;
        }
    }
    delete menuController;

    //atgriež kursoru uz 0to pozīciju
//    printf("\r");
//    for(int i=0;i<n;++i){
//        printf(menuItems[i]->display());
//    };

    return 0;
}
