---
author: 测试
date: 12 01, 2023
paging: Slide %d / %d
---

# 煎饼排序(pancake sort)

煎饼排序是一种排序方式,每次排序过程类似煎饼翻面

---

## 目录

<Toc maxDepth="2"></Toc>

---

## 题目:

给你一个整数数组  `arr` ，请使用 _煎饼翻转_ 完成对数组的排序。

一次煎饼翻转的执行过程如下：

- 选择一个整数  `k` ，`1 <= k <= arr.length`
- 反转子数组  `arr[0...k-1]`（下标从 0 开始）

例如，`arr = [3,2,1,4]` ，选择  `k = 3`  进行一次煎饼翻转，反转子数组  `[3,2,1]` ，得到  `arr = [1,2,3,4]` 。

以数组形式返回能使 `arr` 有序的煎饼翻转操作所对应的 `k` 值序列。任何将数组排序且翻转次数在  `10 * arr.length` 范围内的有效答案都将被判断为正确。

---

## 如何解决

煎饼排序中，每次煎饼翻面意味着反转从顶部开始到一个位置的列表，那么按照传统的排序方式（冒泡/选择，每次只排序一个元素，将列表分为有序和无序两部分）

> 我们可以不断将最大元素放置到无序部分的底部并扩展有序部分的大小，从而完成排序。

---

## 尝试解决子问题:将最大元素移动到无序部分的底部

### 考虑[3,2,1,4]的一般解法

1. 初始状态:`[3,2,1,4],[]`

2. 找到有序部分最大元素`4`

3. 将列表`array[0,3]`反转 得到`[4,1,2,3],[]`

   - 通用的将元素移动至列表顶部的方法

4. 将列表`array[0,3]`反转 得到`[3,2,1,4],[]`

   - 将列表无序部分翻转以将顶部元素换到底部

5. 扩展有序部分 缩减无序部分 得到`[3,2,1],[4]`
   - 这时，最大的元素 `4` 已经位于无序部分的底部
   - 目标是将无序部分的最大元素移动到顶部，以扩展有序部分的大小

---

## 算法实现

基本思路：

- 遍历无序部分，找到最大元素的索引（最大元素在无序部分底部）
- 进行两次煎饼翻转，将最大元素移动到列表顶部

然后：

- 缩小无序部分的范围
- 重复以上步骤，直到列表完全有序

---

## 算法实现（续）

伪代码：

```
pancakeSort(arr):
    n = arr.length
    sortedIndex = n
    while sortedIndex > 1:
        maxIndex = findMaxIndex(arr, sortedIndex)
        flip(arr, maxIndex)
        flip(arr, sortedIndex - 1)
        sortedIndex -= 1
```

---

## 算法分析

时间复杂度：O(n^2)

- 每次煎饼翻转的时间复杂度为 O( n + unsorted_length ) = O(n)
- 总共需要进行 n-1 次煎饼翻转操作，其中 n 为列表长度

空间复杂度：O(1)

- 原地排序，不需要额外的空间

稳定性 : 不稳定

- 翻转可能导致其他元素位置顺序变化

---

## 纯 C 语言实现(非泛型)

```c
// 数组反转
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
//找最大元素
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
```

---

## 纯 C 语言实现(非泛型)(续)

```c
// 非递归煎饼排序
int pancakeSort_no_rec(int *unsorted_array, int sort_start, int sort_end) {
  int max_elem;
  int unsorted_end = sort_end;
  for (; unsorted_end > 0; unsorted_end--) {
    max_elem = find_max_elem(unsorted_array, sort_start, unsorted_end);
    reverse_array(unsorted_array, sort_start, max_elem);
    reverse_array(unsorted_array, sort_start, unsorted_end);
  }
  return 0;
}
//递归煎饼排序
int pancakeSort_rec(int *unsorted_array, int start, int end) {
  int max_elem = find_max_elem(unsorted_array, start, end);
  if (start == end) {
    return 0;
  }
  reverse_array(unsorted_array, start, max_elem);
  reverse_array(unsorted_array, start, end);
  pancakeSort(unsorted_array, start, end - 1);
  return 0;
}
```

---

## 纯 C 语言实现(泛型)

```c
// 数组反转
int reverse_array(void *array, size_t len, size_t elem_byte_size,
                  int (*swap_function)(const void *a, const void *b)) {
  size_t i;
  for (i = 0; i < len / 2; i++) {
    swap_function(((char *)array + i * elem_byte_size),
                  ((char *)array + (len - i - 1) * elem_byte_size));
  }
  return 0;
}

//找最大元素
int find_max_elem(void *array, size_t len, size_t elem_byte_size,
                  int (*compare_function)(const void *a, const void *b)) {
  size_t max_elem = 0;
  size_t i;
  for (i = 0; i < len; i++) {
    if (compare_function((char *)array + max_elem * elem_byte_size,
                         (char *)array + i * elem_byte_size) < 0) {
      max_elem = i;
    }
  }
  return max_elem;
}
```

---

## 纯 C 语言实现(泛型)(续)

```c
// 非递归煎饼排序
int pancakeSort_no_rec(void *unsorted_array, size_t len, size_t elem_byte_size,
                int (*compare_function)(const void *a, const void *b),
                int (*swap_function)(const void *a, const void *b)) {
  size_t max_elem;
  size_t unsorted_len = len;
  for (; unsorted_len > 0; unsorted_len--) {
    max_elem = find_max_elem(unsorted_array, unsorted_len, elem_byte_size,
                             compare_int);
    reverse_array(unsorted_array, max_elem + 1, elem_byte_size, swap_int);
    reverse_array(unsorted_array, unsorted_len, elem_byte_size, swap_int);
  }
  return 0;
}
```

---

## 纯 C 语言实现(泛型)(续)

```c
// 递归煎饼排序
int pancakeSort_rec(void *unsorted_array, size_t len, size_t elem_byte_size,
                int (*compare_function)(const void *a, const void *b),
                int (*swap_function)(const void *a, const void *b)) {
  if (len == 1) {
    return 0;
  }
  size_t max_elem =
      find_max_elem(unsorted_array, len, elem_byte_size, compare_function);
  reverse_array(unsorted_array, max_elem + 1, elem_byte_size, swap_function);
  reverse_array(unsorted_array, len, elem_byte_size, swap_function);
  pancakeSort(unsorted_array, len - 1, elem_byte_size, compare_function,
              swap_function);

  return 0;
}
```

---

## 可改进部分

- 当最大元素本来就在无序部分底部时无需进行煎饼翻转, 可直接进行扩展有序部分
- 当最大元素本来就在无序部分顶部时只需翻转一次
