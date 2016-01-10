/*Fib Numbers modulo 1000000007*/
#include <stdio.h>

int main() {
	int x;
	
	scanf("%d", &x);

	if (x < 2){
		printf("1");
		return 1;
	}
	else {
		int arr[x];
		arr[0] = 1;
		arr[1] = 1;
		int i;
		for( i = 2; i <= x; i = i + 1){
			arr[i] = (arr[i-1] + arr[i-2])% 1000000007;
		}
		printf("%d",arr[x]);
		return arr[x];
	}
}
