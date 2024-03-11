// https://zxbcw.cn/post/218247/

#include <pthread.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

// char HEAD = '@'; // The shape of snake head
// char BODY = 'O'; // The shape of snake body
#define HEAD '@'                                      // The shape of snake head
#define BODY 'O'                                      // The shape of snake body
char map[HEIGHT][WIDTH] = {{BODY, BODY, BODY, HEAD}}; // The initial char is 0
char *snake[HEIGHT * WIDTH] = {&map[0][3], &map[0][2], &map[0][1],
                               &map[0][0]}; // p[0] stand for snake head

int n = 3; // The length of snake body (without head)
int i, j;
int direction = 1;      // 1.right;2.up;3.left;4.down;-1.exit
int delay = 200 * 1000; // delay 0.2s(200ms)
_Bool isPause = 0;
#define moveBody()                                                             \
  {                                                                            \
    *snake[n] = 0;                                                             \
    for (i = n; i > 0; i--) {                                                  \
      snake[i] = snake[i - 1];                                                 \
      /* per part goes to the address of the next part of body*/               \
    }                                                                          \
    *snake[0] = BODY;                                                          \
    /* The First part of snake body come to snake head*/                       \
  }
#define gotoxy(y, x) printf("%c[%d;%df", 0x1B, ((y) + 1), ((x) + 1))

void moveRight() {
  moveBody();
  snake[0] = snake[0] + 1; // Move snake head
  *snake[0] = HEAD; // change the char of new head(new address)'s shape to HEAD
}
void moveLeft() {
  moveBody();
  snake[0] = snake[0] - 1;
  *snake[0] = HEAD;
}
void moveDown() {
  moveBody();
  snake[0] = snake[0] + WIDTH;
  *snake[0] = HEAD;
}
void moveUp() {
  moveBody();
  snake[0] = snake[0] - WIDTH;
  *snake[0] = HEAD;
}

void show() {
  system("clear");
  printf("Your Score is:%d\n", n - 3);
  for (i = 0; i < WIDTH * 2; i++)
    printf("_");
  printf("\n");
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      if (map[i][j] == 0)
        printf("_|"); // □■
      else
        printf("%c|", map[i][j]);
    }
    printf("\n");
  }
  printf("\nw,s,a,d->Up Down Left Right;\nj,k->Speed Up/Down;\nESC: Exit\n");
}

void randomApple() // Random
{
  srand(time(NULL));
  do {
    i = rand() % HEIGHT;
    j = rand() % WIDTH;
    // if random location is 0 ->*;else find again and again
  } while (map[i][j] != 0);
  map[i][j] = '*';
}

void canEat() {
  switch (direction) {
  // Right
  case 1: {
    if (*(snake[0] + 1) == '*') {
      n++; // length++
      snake[n] = snake[n - 1];
      randomApple();
    }
    break;
  }
  // Up
  case 2: {
    if (*(snake[0] - WIDTH) == '*') {
      n++; // length++
      snake[n] = snake[n - 1];
      randomApple();
    }
    break;
  }
  // Left
  case 3: {
    if (*(snake[0] - 1) == '*') {
      n++; // length++
      snake[n] = snake[n - 1];
      randomApple();
    }
    break;
  }
  // Down
  case 4: {
    if (*(snake[0] + WIDTH) == '*') {
      n++; // length++
      snake[n] = snake[n - 1];
      randomApple();
    }
    break;
  }
  }
}

void isFail() {
  if (snake[0] - WIDTH < &map[0][0] && direction == 2 ||
      snake[0] + WIDTH > &map[HEIGHT - 1][WIDTH - 1] && direction == -2 ||
      direction == 1 && (snake[0] - map[0]) % WIDTH == WIDTH - 1 ||
      direction == -1 &&
          (snake[0] - map[0]) % WIDTH == 0) // snake is not in the matrix
  {
    direction = -1;
  } else {
    switch (direction) {
    // Right
    case 1: {
      for (i = n; i > 0; i--) {
        if ((snake[0] + 1) == snake[i]) // Right of the head is body
        {
          printf("fail!\n");
          direction = -1;
        }
      }
      break;
    }
    // Up
    case 2: {
      for (i = n; i > 0; i--) {
        if ((snake[0] - WIDTH) == snake[i]) // Up of the head is body
        {
          printf("fail!\n");
          direction = -1;
        }
      }
      break;
    }
    // Left
    case 3: {
      for (i = n; i > 0; i--) {
        if ((snake[0] - 1) == snake[i]) // Left of the head is body
        {
          printf("fail!\n");
          direction = -1;
        }
      }
      break;
    }
    // Down
    case 4: {
      for (i = n; i > 0; i--) {
        if ((snake[0] + WIDTH) == snake[i]) // Down of the head is body
        {
          printf("fail!\n");
          direction = -1;
        }
      }
      break;
    }
    }
  }
}

void *KeyMonitor(void *arg) // Direction Control：w,s,a,d-->Up Down Left Right
{
  if (direction == -1) {
    pthread_exit(NULL);
  } else {
    char k;
    while (1) {

      k = getchar();
      switch (k) {
      case 'w': // Up
      {
        if (direction != 4)
          direction = 2;
        break;
      }
      case 's': // Down
      {
        if (direction != 2)
          direction = 4;
        break;
      }
      case 'a': // Left
      {
        if (direction != 1)
          direction = 3;
        break;
      }
      case 'd': // Right
      {
        if (direction != 3)
          direction = 1;
        break;
      }
      case 'j': // SpeedUp
      {
        delay = delay * 4 / 5;
        break;
      }
      case 'k': // SpeedDown
      {
        delay = delay * 5 / 4;
        break;
      }
      case 27: // ESC
      {
        printf("Exit!\n");
        isPause = 0;
        direction = -1;
        pthread_exit(NULL);
        break;
      }
      case ' ': // Space
      {
        if (isPause) {
          printf("Continue!\n");
        } else {
          printf("Pause!\n");
        }
        isPause = !isPause;
        break;
      }
      }
    }
  }
}

int main() {
  system("stty -icanon");
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
  // set pthread_attr to detached
  pthread_t tid;
  pthread_create(&tid, &attr, KeyMonitor,
                 NULL); // Create pthread to capture input
  randomApple();
  while (1) {
    show();
    do {
      usleep(delay);

    } while (isPause);
    isFail();          // Judge if will eat self
    canEat();          // Judge if will eat *
    switch (direction) // choose which direction to move
    {
    case 1: // Right
    {
      moveRight();
      break;
    }
    case 2: // Up
    {
      moveUp();
      break;
    }
    case 3: // Left
    {
      moveLeft();
      break;
    }
    case 4: // Down
    {
      moveDown();
      break;
    }
    case -1: // Exit
    {
      printf("Your Final Score is:%d", n - 3);
      return -1;
      break;
    }
    }
  }

  return 0;
}