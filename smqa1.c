#include<stdio.h>

void main(){
	FILE *file;
	int blspc=0, linecount=0, totalchar=0, comcount=0 ,f=1;
	char name[55], buf[55];
	printf("What is file name?\n~");
	scanf("%s",name);
	file=fopen(name,"r");
	if(file==NULL){
		printf("File not found\n \n");
		return;
	}	
	while(fread(buf,1,1,file)){  //this is a comment
    		if(buf[0]=='/' && f==1){
     	  		comcount++;
       			f=0;
		}
	    	else if(buf[0]=='/'){
    			f=1;
    			continue;
		}
    	
	
		if(buf[0]=='\n'){
    			linecount++;
    			f=0;
    		}
		else if(buf[0]==' '){
			blspc++;
			f=0;
		}
		else if(isascii(buf[0]) || isdigit(buf[0])){ //sample comment
			totalchar++;
			f=0;
		}
	}
	fclose(file);
	printf("\nComment lines are: %d",comcount);	
	printf("\nLines Count are: %d",linecount);
	printf("\nBlankspaces count are: %d",blspc);
	printf("\nTotal number of characters: %d\n",totalchar);
}


/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
output:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
student@student-HCL-Desktop:~/Desktop$ gcc smqa1.c
student@student-HCL-Desktop:~/Desktop$ ./a.out
What is file name?
~smqa1.c

lines Count are: 46
Blankspaces count are: 98
Comment lines are: 2
Total number of characters: 687
student@student-HCL-Desktop:~/Desktop$ 
*/
