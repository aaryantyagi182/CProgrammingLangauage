#include <stdio.h>

#define TAB_WIDTH 10

void entab();
void replace_blanks(int *nc, int *nb);

main() {
  entab();
  return 0;
}

void entab() {
  int ch;
  int nb = 0;
  int nc = 0;
  int nt = 0;
  int start_column = 0;
  int end_column = 0;
  int is_previous_blank = 0;

  while ((ch = getchar()) != EOF) {
    nc++;
    if (ch == ' ') {
      if (is_previous_blank)
        nb++;
      else {
        is_previous_blank = 1;
        nb = 1;
      }

    } else {
      if (nb > 0) {
        replace_blanks(&nc, &nb);
        nb = 0;
      }
      putchar(ch);
      is_previous_blank = 0;
    }
  }
  if (nb > 0)
    replace_blanks(&nc, &nb);
}

void replace_blanks(int *nc, int *nb) {
  int loop = 0;
  int start_column = (*nc - 1 - *nb) / TAB_WIDTH;
  int end_column = (*nc - 1) / TAB_WIDTH;
  if (start_column == end_column) {
    while (*nb--) {
      putchar(' ');
    }
  } else {
    for (loop = end_column - start_column; loop > 0; loop--) {
      putchar('\t');
    }

    *nb = *nc % TAB_WIDTH;
    while (*nb--) {
      putchar(' ');
    }
  }
}