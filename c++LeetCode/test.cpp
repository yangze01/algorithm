#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *sourcefptr,*destfptr;
	char ch1,ch2,*s;
	sourcefptr=fopen("p12in.cpp","r");
	destfptr=fopen("p12out.cpp","w");
	if(sourcefptr==NULL)
        printf("can't open the source file.\n");
    else if(destfptr==NULL)
        printf("can't open the dest file.\n");
	else{
		ch1=fgetc(sourcefptr);
		while(!feof(sourcefptr)){
			if(ch1=='/'){
				ch2=ch1;
				ch1=fgetc(sourcefptr);
				if(ch1=='/'||ch1=='*'){
					fseek(sourcefptr,-2,SEEK_CUR);
					fgets(s,sizeof(s),sourcefptr);
					ch1=fgetc(sourcefptr);
					puts(s);
				}
				else{
					fputc(ch2,destfptr);
				}
			}
			else{
				fputc(ch1,destfptr);
				ch1=fgetc(sourcefptr);
			}
		}
	}
	fclose(sourcefptr);
	fclose(destfptr);
	return 0;
 }

