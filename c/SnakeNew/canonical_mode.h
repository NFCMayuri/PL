#ifndef _CANONICAL_MODE_H
#define _CANONICAL_MODE_H


int disable_canonical_mode();
int restore_terminal_settings();

#include <stdio.h>
#if defined(__linux__) || defined(__gnu_linux__)

#include <termios.h>
#include <unistd.h>
struct termios old_termios; // 全局变量存储旧的终端设置

int disable_canonical_mode() {
  struct termios new_termios;

  tcgetattr(STDIN_FILENO, &old_termios);
  new_termios = old_termios;
  new_termios.c_lflag &= ~(ICANON);

  tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
  return 0;
}

int restore_terminal_settings() {
  tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
  return 0;
}
#elif defined(__APPLE__)
int disable_canonical_mode() {
  struct termios new_termios;

  tcgetattr(STDIN_FILENO, &old_termios);
  new_termios = old_termios;
  new_termios.c_lflag &= ~(ICANON);

  tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}

int restore_terminal_settings() {
  tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
}
#elif defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
#include <windows.h>
DWORD originalMode;
int disable_canonical_mode() {
  HANDLE hInput;

  hInput = GetStdHandle(STD_INPUT_HANDLE);

  if (hInput == INVALID_HANDLE_VALUE) {
    fprintf(stderr, "Error getting input handle\n");
    return 1;
  }

  // 获取当前控制台模式
  if (!GetConsoleMode(hInput, &originalMode)) {
    fprintf(stderr, "Error getting console mode\n");
    return 1;
  }

  // 禁用规范模式
  DWORD newMode = originalMode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
  if (!SetConsoleMode(hInput, newMode)) {
    fprintf(stderr, "Error setting console mode\n");
    return 1;
  }

  return 0;
}

int restore_terminal_settings() {
  HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);

  if (hInput == INVALID_HANDLE_VALUE) {
    fprintf(stderr, "Error getting input handle\n");
    return 1;
  }

  // 恢复原始控制台模式
  if (!SetConsoleMode(hInput, originalMode)) {
    fprintf(stderr, "Error restoring console mode\n");
    return 1;
  }

  return 0;
}
#endif
#endif /* _CANONICAL_MODE_H */
