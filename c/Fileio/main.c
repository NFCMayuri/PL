#include <stdio.h>
#include <stdlib.h>
int main()
{
   FILE *fp;
   char str1[100],str2[100],str3[100],str4[100];
   int a;
   //fp = fopen("file.txt", "w");

   //fprintf(fp, "%s", "this is an apple");
   //fclose(fp);
   fp = fopen("file.txt", "r");
   fscanf(fp,"%s %s %s %s",str1,str2,str3,str4);
   printf("%s %s %s %s",str1,str2,str3,str4);
   fclose(fp);
   return(0);
}
