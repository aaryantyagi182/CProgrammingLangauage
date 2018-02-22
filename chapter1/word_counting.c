#include<stdio.h>

#define IN 0
#define OUT 1

int main(){
	int ch;
	int status = OUT;
	long word_count = 0;
	while((ch = getchar()) != EOF){
		if((ch == '\t' || ch == '\n' || ch == ' ') && status == IN){
				status = OUT;
		}
		/* 
		Assuming that no other escape character is present
		*/
		else if(status == OUT){
			status = IN;
			word_count++;
		}
	}
	printf("\nTotal number of words are %ld\n",word_count);
}