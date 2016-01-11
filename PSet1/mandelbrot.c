/*Mandelbrot Set*/
#include <stdio.h>
#include <complex.h> 
#include <math.h>

int main() {
	int col;
	int row;

	scanf("%d %d", &col, &row);
	char arr[col + 1][row];

	//complex number
	int c;
	int r;
	double complex var;
	for (r = 0; r < row; r = r + 1) {
		for (c = 0; c < col; c = c + 1) {
			
			var = ( c * 3.5 /col - 2.5) + ((r * 1.0 /row -.5) *  2 * I);
			double complex z = 0.0;
			int count;
			for (count = 1; count <= 500; count = count + 1){
				z = z * z + var;	
			}
			
			double mag = sqrt( creal (z) * creal (z) + cimag (z) * cimag (z) );
			if (mag <= 2.0){
				arr[c][r] = '*';
			}
			else {
				arr[c][r] = ' ';
			}
		}
		arr[col][r] = '\n';
	}
	//print output
	for (r = 0; r < row; r = r + 1){
		for (c = 0; c < col + 1; c = c + 1) {
			printf("%c", arr[c][r]);
		}
	}
	return 0;
}