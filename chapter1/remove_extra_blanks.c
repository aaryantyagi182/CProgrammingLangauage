#include<stdio.h>


int main(){
	int ch;
	int flag = 0;
	while((ch = getchar()) != EOF){
		if(ch == ' ' && flag == 0){
			flag = 1;
			putchar(ch);
		}
		else if(ch != ' '){
			flag = 0;
			putchar(ch);
		}
	}
}
