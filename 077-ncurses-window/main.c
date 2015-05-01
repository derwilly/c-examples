/* Ferdinand Saufler <mail@saufler.de>
 * 16.03.2015
 * curses window example */

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
    int x, y;
    WINDOW *main_win = initscr();

    /* get the terminal size
     * from "man getmayx":
     * All  of these interfaces are macros.  A "&" is not necessary before the
     * variables y and x. */
    getmaxyx(main_win,y,x);

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

    /* create a new window */
    win = newwin(5, 35, 6, 1);

    /* set the terminal background- and font color */
    bkgd(COLOR_PAIR(1));

    /* set the window background- and font color */
    wbkgd(win, COLOR_PAIR(2));

    /* print a text to the first line */
    mvaddstr(0,1, "Hello World! Press \"F2\" to exit...");

    /* print the terminal coordinates */
    mvprintw(3,0, "terminal x: %d", x);
    mvprintw(4,0, "terminal y: %d", y);

    /* put a text in the window */
    mvwaddstr(win, 3, 3, "This is a Window...");

    /* this line is not shown, because its out of the box */
    mvwaddstr(win, 7, 3, "dont show me");

    /* add a border to the box */
    box(win, 0, 0);

    /* print a line of '-' in the secound line */
    mvhline(1, 0, '-', x);

    /* refresh the screen */
    refresh();

    /* refresh the window (win) */
    wrefresh(win);

    /* idle until the "F2"-Key is pressed */
    while(getch() != KEY_F(2))
    {
    }

    return(0);
}
