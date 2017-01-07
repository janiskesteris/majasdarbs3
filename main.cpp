#include <iostream>
#include "MenuItem.h"
#include "MenuController.h"
#include <unistd.h>
#include <termios.h>
using namespace std;

//int getch() {
//    char buf = 0;
//    struct termios old = {0};
//    if (tcgetattr(0, &old) < 0)
//        perror("tcsetattr()");
//    old.c_lflag &= ~ICANON;
//    old.c_lflag &= ~ECHO;
//    old.c_cc[VMIN] = 1;
//    old.c_cc[VTIME] = 0;
//    if (tcsetattr(0, TCSANOW, &old) < 0)
//        perror("tcsetattr ICANON");
//    if (read(0, &buf, 1) < 0)
//        perror ("read()");
//    old.c_lflag |= ICANON;
//    old.c_lflag |= ECHO;
//    if (tcsetattr(0, TCSADRAIN, &old) < 0)
//        perror ("tcsetattr ~ICANON");
//    return (buf);
//}

//int main() {
//    // Output prompt
//    cout << "Press any key to continue..." << endl;
//
//    // Set terminal to raw mode
//    system("stty raw");
//
//    // Wait for single character
//    char input = getchar();
//
//    // Echo input:
//    cout << "--" << input << "--";
//
//    // Reset terminal to normal "cooked" mode
//    system("stty cooked");
//
//    // And we're out of here
//    return 0;
//}

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
//    MenuItem tevaAuto = new MenuItem("WN827253426");
//    Controller *form = new Controller();

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
        system("stty raw");
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
        //atgriež kursoru uz 0to pozīciju
        if(loop == 1) {
            menuController->display();
        }else{
            printf("\n");
        }
        system("stty cooked");
    }

    delete menuController;
    return 0;
}
