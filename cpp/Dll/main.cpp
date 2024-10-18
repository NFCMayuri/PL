#include "SortComponent.h"
#include <iostream>

int main() {
  int numbers[10] = {5, 3, 8, 6, 2, 7, 4, 9, 1, 0};

  sortNumbers(numbers, 10);

  for (int i = 0; i < 10; ++i) {
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
