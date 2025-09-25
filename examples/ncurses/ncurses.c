#include <ncurses.h>
#include <string.h>

// On macOS, using clang:
// $ clang ncurses.c -lncurses -o ncurses
// $ ./ncurses

int main() {
  WINDOW *window = initscr();

  printw("Hello, ncurses!");

  int y;
  int x;
  getmaxyx(window, y, x);
  char* middle_message = "Middle!";
  int middle_message_y = y / 2;
  int middle_message_x = (x / 2) - (strlen(middle_message) / 2);
  mvprintw(middle_message_y, middle_message_x, "%s", middle_message);

  refresh();

  getch();
  endwin();

  return 0;
}
