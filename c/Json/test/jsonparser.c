#include <stdio.h>
#include <string.h>
int jumpChar(const char *string, int *index, char Char) {
  while (string[*index] == ' ') {
    index++;
  }
  return *index;
}
int jumpNULL(const char *string, int *index) {
  while (string[*index] == ' ' || string[*index] == '\n') {

    index++;
  }
  return *index;
}

// strchr() or  strpbrk() and strcspn()
int indexCharInString(const char *string, int length, const char target) {
  int i;
  for (i = 0; i < length; i++) {
    if (string[i] == target) {
      { return i; }
    }
  }
  return -1;
}
int sliceString(const char *string, int index, int length) { return 0; }

// strstr()
// int indexStringInString(const char *string, int length, const char *target) {
//   int index = 0;
//   index = indexCharInString(string + index, length - strlen(target),
//   target[0]); while (memcmp(string + index, target, strlen(target)) != 0) {
//     if (index > length) {
//       return -1;
//     } else {
//       index++;
//       length--;
//       index =
//           indexCharInString(string + index, length - strlen(target),
//           target[0]);
//     }
//   }
//   return index;
// }

// strstr()
char *indexStringInString(const char *string, int length, const char *target) {
  // char *ret = memchr(string, target[0], length);
  char *ret = strchr(string, target[0]);
  while (strncmp(ret, target, strlen(target)) != 0 && ret != NULL) {
    ret++;
    // ret = memchr(ret, target[0], length + string - ret);
    ret = strchr(ret, target[0]);
  }
  return ret;
}
int main() {
  char a[] = "heollo.xyz";
  // printf("%d", indexCharInString(a, strlen(a), '.'));
  // printf("%s", a + indexStringInString(a, strlen(a), "o."));
  // printf("%s", indexStringInString(a, strlen(a), "o."));
  // puts(indexStringInString(a, strlen(a), "o."));
  puts(strstr(a, "o."));
}
// int main() {
//   const char json[] =
//       "{\"int1\":1,\"str1\":\"2\",\"double1\":3.14,\"bool1\":true,"
//       "\"char1\":48,\"null1\":null,\"array1\":[\"string\",1,null,"
//       "true,false,3.14],\"json1\":{\"id\":0,\"status\":200}}";
//   puts(json);
//   struct json1 {
//     int int1;
//     char *str1;
//     double double1;
//     _Bool bool1;
//     char char1;
//     void *null1;
//     void **array1;
//     struct json1 *next;
//   };
//   int strindex = 0;
//   jumpNULL(json, &strindex);
//   if (json[strindex] != '{') {
//     printf("json parse failed");
//   } else {
//     strindex++;
//     jumpNULL(json, &strindex);
//     if (json[strindex] != '"') {
//       { jumpNULL(json, &strindex); }
//     }
//     if (json[strindex] != '"') {
//       printf("json parse failed");
//     } else {
//     }
//   }
// }