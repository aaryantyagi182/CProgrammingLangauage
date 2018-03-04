#include <stdio.h>

#define MAXLENGTH 1000
#define MAXLINE 80
#define TAB_WIDTH 10

void detab();

int main() {
  char line[MAXLINE];
  int len = 0;
  detab();
}

void detab() {
  int ch;
  int nc = 0;
  int ns = 0;
  while ((ch = getchar()) != EOF) {
    if (ch == '\t') {
      ns = TAB_WIDTH - (nc % TAB_WIDTH);
      nc = 0;
      while (ns-- > 0) {
        putchar(' ');
      }
    } else if (ch == '\n') {
      putchar(ch);
      nc = 0;

    } else {
      putchar(ch);
      nc++;
    }
  }
}
