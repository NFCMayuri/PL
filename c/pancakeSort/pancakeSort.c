#include <stdio.h>

#define length_of_array(array) sizeof(array) / sizeof(array[0])

#ifndef REC_IMP
#define NO_REC_IMP
#endif

#if defined DEBUG
static int reverse_times = 0;
#endif

// todo: use generic for c
int reverse_array(int *array, int start, int end) {
  size_t i, j;
  int temp;
  for (i = start, j = end; i < j; i++, j--) {
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
  return 0;
}

int find_max_elem(int *array, int start, int end) {
  int i;
  int max_elem = start;
  for (i = start + 1; i <= end; i++) {
    if (array[max_elem] < array[i]) {
      max_elem = i;
    }
  }
  return max_elem;
}

#if defined NO_REC_IMP

int pancakeSort(int *unsorted_array, int sort_start, int sort_end) {
  int max_elem;
  int unsorted_end = sort_end;
  for (; unsorted_end > 0; unsorted_end--) {
    max_elem = find_max_elem(unsorted_array, sort_start, unsorted_end);
    reverse_array(unsorted_array, sort_start, max_elem);
    reverse_array(unsorted_array, sort_start, unsorted_end);
  }
  return 0;
}

#endif

#if defined REC_IMP


int pancakeSort(int *unsorted_array, int start, int end) {
  int max_elem = find_max_elem(unsorted_array, start, end);
  if (start == end) {
    return 0;
  }
  reverse_array(unsorted_array, start, max_elem);

#if defined DEBUG
  reverse_times++;
  printf("the %d times reverse:", reverse_times);
  for (int i = start; i <= end; i++)
    printf("%d ", unsorted_array[i]);
  printf("\n");
#endif

  reverse_array(unsorted_array, start, end);
  pancakeSort(unsorted_array, start, end - 1);

#if defined DEBUG
  reverse_times++;
  printf("the %d times reverse:", reverse_times);
  for (int i = start; i <= end; i++)
    printf("%d ", unsorted_array[i]);
  printf("\n");
#endif

  return 0;
}


#endif

int main() {
  int array1[] = {5, 2, 1, 0, 3, 2, 9}; // {5,2,1,0,3,2*,9} => {0,1,2,2*,3,5,9}
  int i;

  printf("before sort: ");
  for (i = 0; i < length_of_array(array1); i++)
    printf("%d ", array1[i]);
  printf("\n");

  pancakeSort(array1, 0, length_of_array(array1) - 1);

  printf("after sort:  ");
  for (i = 0; i < length_of_array(array1); i++)
    printf("%d ", array1[i]);
  printf("\n");
}
