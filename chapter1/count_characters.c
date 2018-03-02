#include<stdio.h>

int main(){
	int ch; 
	int count = 0;
	while((ch = getchar()) != EOF){
		count++;
	}
	printf("%d",count);
	
}