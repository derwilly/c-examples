/* Ferdinand Saufler <mail@saufler.de>
 * 16.03.2015
 * curses hello world example */

#include <curses.h>
#include <stdlib.h>

WINDOW *win;

void quit(void)
{
    delwin(win);
    endwin();
}

int main(void)
{
    initscr();
    atexit(quit);

    /* clear the screen */
    clear();

    /* disable echo for typed characters */
    noecho();

    /* dont display the cursor */
    curs_set(0);

    /* The cbreak routine disables line buffering and erase/kill
     * character-processing */
    cbreak();

    /* The keypad option enables the keypad of the user's terminal. */
    keypad(stdscr, 1);

    /* init two colors-pairs. Colors are always used in pairs */
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_WHITE);

    /* set the terminal background- and font color */
    bkgd(COLOR_PAIR(1));

    /* print a text in the first line */
    mvaddstr(0,0, "Hello World! Press \"F2\" to exit...");

    /* refresh the screen */
    refresh();

    /* idle until the "F2"-Key is pressed */
    while(getch() != KEY_F(2)){;}

    return(0);
}
