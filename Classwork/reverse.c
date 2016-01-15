#include <stdio.h>
#include <string.h>

//REVERSE1 with brackets
void reverse1(char* str, int length) {
  char x;
  int i;
  for (i = 0; i < length / 2; i++){
  	x = str[length - 1 - i];
  	str[length - 1 - i] = str[i];
  	str[i] = x;
  }

}

//REVERSE2 with pointers
void reverse2(char* str, int length) {
  char x;
  int i;
  for (i = 0; i < length / 2; i++){
    x = *(str + length - 1 - i);
    *(str + length - 1 - i) = *(str + i);
    *(str + i) = x;
  }

}

int main() {
  char phrase[] = "dar era sretniop";
  printf("Before: %s\n", phrase);
  reverse2((char*)&phrase, strlen(phrase));
  printf("After: %s\n", phrase);
  return 0;
}