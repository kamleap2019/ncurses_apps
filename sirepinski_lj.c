#include <stdlib.h>
#include <ncurses.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MIN_SIZE 200

#define PADDING 20

void initialize_ncurses();
void close_ncurses();
void print_line(char *str);

void draw_sirepinski(WINDOW *g, int x, int y, int l);
void draw_triangle(WINDOW *g, int x, int y, int l);
void draw_line(WINDOW *g, int x, int y, int l);
void draw_line2(WINDOW *g, int x1, int y1, int x2, int y2);
int get_triangle_height(int l);

void draw_sirepinski(WINDOW *g, int x, int y, int l) {
    if(l <= MIN_SIZE) {
        return;
    }
    else {
        draw_triangle(g, x, y, l);
        // draw_sirepinski(g, x, y, l/2);
        // draw_sirepinski(g, x+l/2, y, l/2);
        // draw_sirepinski(g, x+l/4, y-get_triangle_height(l/2), l/2);
    }
}

void draw_triangle(WINDOW *g, int x, int y, int l) {
        int h = get_triangle_height(l);
        draw_line(g, x, y, l);
        // draw_line(g, x, y, x+l, y);
        // draw_line(g, x, y, x+l/2, y-h);
        // draw_line(g, x+l, y, x+l/2, y-h);
}

void draw_line(WINDOW *g, int x, int y, int l) {
    box(g, l, l);
    mvprintw(g, x, y, "*");
    refresh();
}

void draw_line2(WINDOW *g, int x1, int y1, int x2, int y2) {

}

int get_triangle_height(int l) {
    return (int)(sqrt(3)*l/2);

}

int main(int argc, char **argv){

    int ch;
    initialize_ncurses();

    WINDOW* panel = newwin(HEIGHT, WIDTH, PADDING, PADDING);

    printw("Type S character to start drawing Sirepinski\n");
    refresh();

    do {
        ch = getch();

        if ( (ch == 'S') || (ch = 's') ) {
            ch = "";
            print_line("You pressed the right character. drawing the sirepinski");
//            draw_sirepinski(panel, 0, 0, WIDTH);
        }
        else {
            print_line("incorrect letter entered");
        }
    }while (ch != "S");

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
