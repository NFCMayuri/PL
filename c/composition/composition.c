#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void write();
int main(int argc,char *argv[]){
    //char str1[20]="114514";
    ////char *str2 ="1919810";
    //char str3[]= *str2;
    //printf("%s\n%s\n",&str1,str2);
    ////strcpy(str1,str3);
    ////printf("strcpy(str1,str3):%s\n",str3)
	    // {'b','a','k','a','\0'};
    if ( argc == 1 )
    {
	    printf("please input name\n");
	    //char name[] = "baka";
	    return 0;
    }
  /*  else
    {
	    char *name = argv[1];
    }
    */
    char composition[99];
    //write(composition,name);
    write(composition,argv[1]);
    printf(composition);
    return 0;
}

void write(char saying1[],const char *name){
    sprintf(saying1,"%s,my %s,I do love u so much. ",name,name);
    char saying2[]="Pls take me away";
    strcat(saying1,saying2);
}
