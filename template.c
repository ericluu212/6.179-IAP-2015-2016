#include <stdio.h>

typedef struct date_t {
 int year;
 int month;
 int day;
} Date;

Date makeDate(int y, int m, int d) {
 Date date = {y, m, d};
 printf("%p\n", &date);
 return date;
}
int main() {
 Date today = makeDate(2016, 1, 13);
 printf("%p\n", &today);
 return 0;
}