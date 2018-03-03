#include<stdio.h>


#define MAXLENGTH 1000
#define MAXLINE 80
#define TAB_WIDTH 4




void detab(char line[], int lim);
int getline(char s[], int lim);
void replace_tab(char line[], int last_char, 	int pos, int lim);
int arr_len(char line[], int lim);
void shift_line(char  line[],int end, int tab, int lim);

int main(){	
	char line[MAXLINE];
	int len = 0;
	while((len = getline(line, MAXLINE)) > 0){
		detab(line, MAXLINE);
		printf("%s\n",line);
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

void detab(char line[], int lim){
	int i = 0; 
	int last_char = arr_len(line, lim);
	for(i = 0; i < lim && (line[i] != '\n' || line[i] != '\0'); i++){	
		if(line[i] == '\t')
			replace_tab(line, i, last_char, lim);
	}
}

void replace_tab(char line[], int pos, int last_char, int lim){
	shift_line(line, last_char, pos, lim);
}

int arr_len(char line[], int lim){
		int last_char = 0;
		for( ; last_char < lim && line[last_char] != '\0'; last_char++)
		;
		return last_char;
}


void shift_line(char  line[],int end, int tab, int lim){
	if(end + TAB_WIDTH - 1 >= lim)
		return;
	for( ; end  > tab  ; end--){
			line[end + TAB_WIDTH - 1] = line[end];
	}
	// Replace tab with black spaces
	// Move end to the place where to start filling with blank space
	end = end + TAB_WIDTH - 1;
	while(end >= tab){		
		line[end--] = ' ';
	}
}
	 