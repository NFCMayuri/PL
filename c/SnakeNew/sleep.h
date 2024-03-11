#ifndef _SLEEP_H
#define _SLEEP_H

#if defined(__linux__)
	// Linux
	#include<unistd.h>
#elif defined(__APPLE__)
    // MacOS
	#include<unistd.h>
#elif defined(_WIN32)
	// Windows
	#include<windows.h>
#endif

void s_sleep(int time) {
#if defined(__linux__)
	// Linux
	sleep(time);
#elif defined(__APPLE__)
    // MacOS
    sleep(time);
#elif defined(_WIN32)
	// Windows
	Sleep((time*1000));
#endif
}


void ms_sleep(int time) {
#if defined(__linux__)
	// Linux
	usleep(time*1000);
#elif defined(__APPLE__)
    // MacOS
    usleep(time*1000);
#elif defined(_WIN32)
	// Windows
	Sleep(time);
#endif
}

void us_sleep(int time) {
#if defined(__linux__)
	// Linux
	usleep(time);
#elif defined(__APPLE__)
    // MacOS
    usleep(time);
#elif defined(_WIN32)
	// Windows
	// Sleep(time/1000);
	_Static_assert(1 == 0, "unimplemented");
#endif
}

#endif /* _SLEEP_H */