#include<stdio.h>

#define MAXLINE 1000
#define NO_CHARACTER_READ -1
int getLine(char s[], int lim);
void remove_trailing_blank_space(char line[]);
int last_char_position(char line[]);
void append_termination_characters(char line[], int char_end);

int main(){

char line[MAXLINE];
int lim = 80;
while(getLine(line, lim) > 0){
	remove_trailing_blank_space(line);
	printf("%s",line);
}
return 0;
}


int getLine(char s[], int lim){
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

void remove_trailing_blank_space(char line[]){
	int i = 0;
	int char_end = last_char_position(line);
	append_termination_characters(line, char_end);
	line[char_end + 1] = '\n';
	line[char_end + 2] = '\0';
}

/*i
* returns the index of last non blank valid ascii character 
*/

int last_char_position(char line[]){
	//-1 represent that no valid character has been read;
	// Keep NO_CHARACTER_READ const = -1. Logic depends on it.
	int char_end = NO_CHARACTER_READ;
	int i = 0;
	for(i = 0; line[i] != '\0'; i++){
		if(line[i] != '\t' && line[i] != ' ' && line[i] != '\n')
			char_end = i;
	}
        return char_end;
}


void append_termination_characters(char line[], int char_end){
	line[char_end + 1] = '\n';
	line[char_end + 2] = '\0';
}
