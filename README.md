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
```

In the app we specify the to get ncurses from system library path by saying `include <ncurses>`

4. compile the app using `gcc -Wall -lncurses app.c`
5. run using `.app`
Congratulations on your first ncurses.js app. But it does nothing

TODO: Congratulations on your first ncurses.js app that has a window.

## References
* [ncurses - wikipedia](https://en.wikipedia.org/wiki/Ncurses)
* [ncurses getting started - Linux Journal](https://www.linuxjournal.com/content/getting-started-ncurses)
* [ncurse HOW TO - TLDP](http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/)

