/* My first ncurses application */

#include <stdlib.h>
#include <ncurses.h>

void initialize_ncurses();
void close_ncurses();
void print_line(char *str);

int main(int argc, char **argv){

    initialize_ncurses();

    print_line("Bismillah, Welcome Humands");

    close_ncurses();
    return 0;
}

void initialize_ncurses() {
    initscr();
    cbreak();
    noecho();

    clear();
    refresh();
}

void close_ncurses() {
    endwin();
    exit(0);
}

void print_line(char *str){
    addstr(str);
    refresh();
}