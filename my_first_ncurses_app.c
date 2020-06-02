/* My first ncurses application */

#include <stdlib.h>
#include <ncurses.h>

void initialize_ncurses();
void close_ncurses();
void print_line(char *str);

int main(int argc, char **argv){

    initialize_ncurses();

    print_line("Bismillah, Welcome Humans");

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
    getch();    /* Wait for the user input so that ncurses mode stays on */
    endwin();
    exit(0);
}

void print_line(char *str){
    addstr(str);
    refresh();
}