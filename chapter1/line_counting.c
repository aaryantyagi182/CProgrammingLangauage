#include<stdio.h>

int main(){
	int lines, chars,  ch = 0;
	lines = 0;
	chars = 0;
	while((ch = getchar()) != EOF){
		if(ch == '\n'){
			lines++;
		}
		else{
			chars++;
		}
		
	}
	printf("lines are %d \n characters are %d",lines, chars);
}