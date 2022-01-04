#include <stdio.h>
#include <limits.h>

int main(){
    printf("One Byte is %d bit\n",CHAR_BIT);

    printf("The min of signed char is %d\n",SCHAR_MIN);
    printf("The max of signed char is %d\n",SCHAR_MAX);
    printf("The max of unsigned char is %u\n",UCHAR_MAX);
 
    printf("The min of signed short is %d\n",SHRT_MIN);
    printf("The max of signed short is %d\n",SHRT_MAX);
    printf("The max of unsigned short is %u\n",USHRT_MAX);

    printf("The min of signed int is %d\n",INT_MIN);
    printf("The max of signed int is %d\n",INT_MAX);
    printf("The max of unsigned int is %u\n",UINT_MAX);

    printf("The min of signed long is %ld\n",LONG_MIN);
    printf("The max of signed long is %ld\n",LONG_MAX);
    printf("The max of unsigned long is %lu\n",ULONG_MAX);

    printf("The min of signed long long is %lld\n",LLONG_MIN);
    printf("The max of signed long long is %lld\n",LLONG_MAX);
    printf("The max of unsigned long long is %llu\n",ULLONG_MAX);
                                      
}
