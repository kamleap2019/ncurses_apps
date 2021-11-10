# ncurses_apps
textual UI based apps

# Introduction
This repo/folder contains basic textual UI (ncurses) based web apps. Refernce apps will be kept in separate branches here.

## [ncurses](https://invisible-mirror.net/archives/ncurses/) Apps
ncurses allows to write text based user interface.

## Creating a ncurses App

### What is needed for a ncurses app
In its simplest form, nothing except ncurses library should be available on your system. I am using mac and it can be installed using HomeBrew like
`brew install ncurses`

### The first ncurses app (Welcome Humans)
To keep it simple, all of the below stuff is done from a terminal (aka cli=command line interface).

1. Create a C source ```my_first_ncurses_app.c```
2. Open the file using whatever editor you prefer ```vi app.js``` and paste the below code in that file. This code is based upon LJ article from [here](https://www.linuxjournal.com/content/getting-started-ncurses)

```
/* My first ncurses application */

#include <ncurses.h>
#include <stdlib.h>

void initialize_ncurses();
void close_ncurses();

int main(int argc, char **argv){

    initialize_ncurses();



    close_ncurses();
    return 0;
}

void initialize_ncurses() {
    initscr();  /* initialize stdscr where all of ncurses drawing happens */

    clear();
    refresh();
}

void close_ncurses() {
    getch();        /* wait for any user input for closing window */
    endwin();
    exit(0);
}
```

In the app we specify to get ncurses from system library path by saying `include <ncurses>`
`initscr()` is the core function that initializes the ncurses system in the current terminal and allocates memory for the present window called stdscr.
4. compile the app using `gcc -Wall -lncurses app.c`
5. run using `.app`
6. Let add a print statement to this application. Create the below print function and call it from the main function after initscr(). This function uses ncurses function addstr() for adding a string to the window and the printing it out to terminal by calling refresh(). If you don't call refresh() nothing will be printed.
```
void print_line(char *str){
    addstr(str);
    refresh();
}
```
Congratuations on your first ncurses app

## References
* [ncurses - wikipedia](https://en.wikipedia.org/wiki/Ncurses)
* [ncurse HOW TO - TLDP](http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/)
* [ncurses getting started - Linux Journal](https://www.linuxjournal.com/content/getting-started-ncurses)
