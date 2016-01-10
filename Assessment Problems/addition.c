/*Addition*/
#include <stdio.h>

int main() {
	int x;
	int sum = 0;
	
	scanf("%d", &x);
	while (x > 0) {
		int a;
		scanf("%d", &a);
		sum = sum + a;
		x = x - 1;
	}
	printf("%d",sum);
	return sum;
}
