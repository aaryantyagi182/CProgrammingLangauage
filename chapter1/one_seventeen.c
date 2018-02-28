#include<stdio.h>
#define MAXLINE 10

int getline(char line[], int maxline);
void copy(char form[], char to[]);


int main(){
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	
	max = 0;
	while((len = getline(line, MAXLINE)) > 0){
		if(len >= max){
			max = len;
			copy(longest, line);
		}
		if(max > 0){
			printf("%d\n",len);
			printf("%s",longest);
		}
	
	}
	return 0;	
}


int getline(char s[], int lim){
	int c, i;
	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)				
		s[i] = c;
	
		if(c == '\n' ){
			if(i < lim - 1){
				s[i] = c;
			}
			else{
				s[i] = '\0';
			}
			i++;
		}
		else if(c != EOF){
			i++;
			while((c = getchar()) != EOF && c != '\n')
				i++;
		}
		if(i <= lim  - 1)
			s[i] = '\0';
		return i;
	
}			

void copy(char to[], char from[]){
	int i = 0; 
	while((to[i] = from[i]) != '\0')
		++i;
}
