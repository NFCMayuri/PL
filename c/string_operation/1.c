#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
//	printf("%s\n",str(1));
	if (argc != 3)
	{
		printf("Plz input 2 str,and I will do a strcat\n");
		return 0;
	}
    printf("argv[1]=%s\nargv[2]=%s\n",argv[1],argv[2]);
	printf("strcat(argv[1],argv[2])=%s\n\n",strcat(argv[1],argv[2]));
    printf("strlen(argv[1])=%d\n",strlen(argv[1]));
    printf("strlen(argv[2])=%d\n",strlen(argv[2]));
    char str[strlen(argv[1])+1];
    printf("str[i]\ni=%d\n\n",sizeof(str)/sizeof(str[0]));
    sprintf(str,"%s%s",argv[1],argv[2]);
  	printf("sprintf(str,\"%s%s\",argv[1],argv[2])\nstr=%s\n","%s","%s",str);
	return 0;
}
