#include<stdio.h>
#include<ctype.h>

int main(){
	int ch = 0;
	while((ch  != EOF)){
		ch = getchar();
		putchar(ch);
	}
	return 0;
}