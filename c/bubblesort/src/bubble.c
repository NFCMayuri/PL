#include "../include/bubblesort.h"
int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int i;
    for (i=0;i<sizeof(a)/sizeof(a[0]);i++){
        printf("%d\n",a[i]);
    }
    return 0;
}
int *bubblesort(int *array){
    int i,j,temp;
    for (i=0;i<sizeof(array)/sizeof(array[0]);i++){
        for (j=0;j<sizeof(array)/sizeof(array[0])-i-1;j++){
            if (array[j]>array[j+1]){
                temp =array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    return *array;
}