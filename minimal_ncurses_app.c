#include <ncurses.h>

// Reference: https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/helloworld.html

int main() {

    initscr();                  // Initialize ncurses mode
    printw("Welcome humans !");
    refresh();                  // print out to the screen
    getch();
    endwin();                   // end ncurses mode

    return 0;
}