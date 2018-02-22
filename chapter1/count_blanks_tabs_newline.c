#include<stdio.h>

int main(){
	int blanks, tabs, newlines;
	blanks = 0; 
	tabs = 0; 
	newlines = 0;
	int ch;
	while((ch = getchar()) != EOF){
		if(ch == '\t'){
			tabs++;
		}
		if(ch == ' '){
			blanks++;
		}
		if(ch == '\n'){
			newlines++;
		}
	}
	printf("tabs = %d, blanks = %d , newlines = %d\n", tabs, blanks , newlines);
}