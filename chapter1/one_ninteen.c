#include<stdio.h>

#define MAXLEN 1000
#define LIMIT 80

int getline(char s[], int lim);
void reverse(char line[], int lim);
int find_last_char_pos(char line[], int lim);

int main(){
	char line[MAXLEN];
	int len = 0;
	while((len = getline(line, LIMIT)) > 0){
		reverse(line, MAXLEN);
		printf("%s\n",line);;
	}
}


void reverse(char line[], int lim){
	int last_char_pos = find_last_char_pos(line, lim);
	int start = 0;
	int end = last_char_pos;
	while(start < end){
		int temp = line[start];
		line[start] = line[end];
		line[end] = temp;
		start++;
		end--;
	}
}


int getline(char s[], int lim){
	int c, i;
	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)				
		s[i] = c;
		if(c == '\n'){
			s[i] = c;
			i++;
		}
		s[i] = '\0';
		return i;	
}	

int find_last_char_pos(char line[], int lim){
	int i = 0;
	for(i = 0 ; i < lim && line[i] != '\0'; i++)
		;
	//sending position with zero indexing
	return --i;
}