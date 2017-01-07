#include <iostream>
#include "MenuItem.h"
#include "MenuController.h"
using namespace std;

int main(int argc, const char * argv[]) {
    MenuController *menuController = new MenuController();
    menuController->menuItems[0] = new MenuItem(1, "File", false);
    menuController->menuItems[1] = new MenuItem(2, "Edit", true);
    menuController->menuItems[2] = new MenuItem(3, "View", false);
    menuController->menuItems[3] = new MenuItem(4, "Tools", false);
    menuController->menuItems[4] = new MenuItem(5, "Help", true);
    menuController->display();

    int key;
    int loop = 1;
    while(loop)
    {
        system("stty raw"); //http://stackoverflow.com/a/1799024/1909627
        key = getchar();
        switch(key)
        {
            case '\t': //Tab
                menuController->selectNextItem();
                break;
            case '\n': //Enter
            case '\r':
                menuController->displaySelectedMenuItem();
                break;
            case 27: //ESC
                menuController->toggleHoverState();
                break;
            case 'q':
                loop = 0;
        }
        if(loop == 1) {
            menuController->display();
        }else{
            printf("\n");
        }
        system("stty cooked"); //http://stackoverflow.com/a/1799024/1909627
    }

    delete menuController;
    return 0;
}
