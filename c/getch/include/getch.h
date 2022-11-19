#include <stdio.h>
// https://sourceforge.net/p/predef/wiki/OperatingSystems/
#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)

#include <conio.h>
#define sh_getch _getch

#elif defined(__linux__) || defined(__gnu_linux__)

// ncurses maybe work better
// https://www.cnblogs.com/life2refuel/p/5720043.html
#include <termio.h>

/*
 * get only one char without Line buffering
 *        : return the char gotten
 */
inline int sh_getch(void) {
  int cr;
  struct termios nts, ots;

  if (tcgetattr(0, &ots) < 0)
    // get the setting of current terminal (0 stand for stdin)
    return EOF;

  nts = ots;
  cfmakeraw(&nts);
  // set theterminal to raw mode , in this mode all stdin data will be procrssed
  // in byte
  if (tcsetattr(0, TCSANOW, &nts) < 0) // use the modified setting
    return EOF;

  cr = getchar();
  if (tcsetattr(0, TCSANOW, &ots) < 0) // restore the setting to preview mode
    return EOF;

  return cr;
}

#elif defined(__APPLE__)
#else

#error "error : Not supported!"

#endif