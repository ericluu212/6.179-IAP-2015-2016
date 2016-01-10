/*Stacking Cups*/
#include <stdio.h>

int main() {
	int cups;
	int ops;
	int index = -1;

	scanf("%d %d", &cups, &ops);
	int arr[cups];
	int i;
	int vals[ops];
	int count = 0;
	for( i = 0; i < ops; i = i + 1){
		char str[12];
		int b;
		scanf("%s %d", str, &b);

		if ( str[1] == 'U' ) {
			index = index + 1;
			arr[index] = b;
		}
		else if ( str[1] != 'U' ) {
			vals[count] = arr[index];
			count = count + 1;
			index = index - 1;
		}
	}
	int x;
	for ( x = 0; x < count; x = x + 1){
		printf("%d",vals[x]);
		printf("%s","\n");
	}	
}

