#include <stdio.h>


void increment(int * p) { //changes pointer value(?)
 *p += 1;
}

int main() {
 int x = 0;
 printf("%d\n", x);
 increment(&x);
 printf("%d\n", x);
 return 0;
}