#ifndef SORT_COMPONENT_H
#define SORT_COMPONENT_H

#if defined _WIN32 || defined __CYGWIN__
#ifdef EXPORTING_DLL
#ifdef __GNUC__
#define DECLSPEC __attribute__((dllexport))
#else
#define DECLSPEC __declspec(dllexport)
#endif
#else
#ifdef __GNUC__
#define DECLSPEC __attribute__((dllimport))
#else
#define DECLSPEC __declspec(dllimport)
#endif
#endif
#else
#if __GNUC__ >= 4
#define DECLSPEC __attribute__((visibility("default")))
#else
#define DECLSPEC
#endif
#endif

extern "C" {
DECLSPEC void sortNumbers(int *numbers, int size);
}
#endif // SORT_COMPONENT_H
