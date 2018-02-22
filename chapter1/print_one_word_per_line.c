#include<stdio.h>

#define IN 0
#define OUT 1

int main(){
	int ch;
	int state = OUT;
	while((ch = getchar()) != EOF){
		if(ch == '\t' || ch == '\n' || ch == ' ' && state == IN){
			state = OUT;
			putchar('\n');
		}
		else if(state == OUT){
			state = IN;
		}
		if(state == IN){
			putchar(ch);
		}
	}
	if(state == IN){
		putchar('\n');
	}
}