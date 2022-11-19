#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#ifdef KEY_AS_STRING
#define ESC "\033"
#define UP "\033[A"
#define DOWN "\033[B"
#define LEFT "\033[D"
#define RIGHT "\033[C"
#else /* KEY_AS_STRING*/

#define ESC 0x1B
#endif /* KEY_AS_STRING*/

#endif /* _KEYBOARD_H */