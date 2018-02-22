#include<stdio.h>


int main(){
	int ch ;
	while((ch =  getchar()) != EOF){
		if(ch == '\b'){
			putchar('\\');
			putchar('b');
		}
		if(ch == '\t'){
			putchar('\\');
			putchar('t');
		}
		if(ch == '\\'){
			putchar('\\');
			putchar('\\');
		}
		else{
			putchar(ch);
		}
	}
}
