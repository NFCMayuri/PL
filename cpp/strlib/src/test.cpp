#include "../include/head.hpp"
int main(){
    struct head_link *test1=add();
    test1->type[0]=1;
    strval(&(test1->name),"hello ",1);
    strval(&(test1->name),"world",2);
    strval(&(test1->name),"goodbye world",3);
    printf("name:%s\nnum:%d\n",(test1->name),(test1->type[0]));
    return 0;
}

