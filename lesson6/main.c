#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int **initInt2dArray(int **array, const int row, const int col){
	
	array = (int**) calloc(sizeof(int*), row);
	
	for(int i = 0; i < row; ++i){
		
		*(array + i) = (int*) calloc(sizeof(int), col);
	}
	
	return array;
}

void fillInt2dArray(int **array, const int row, const int col){
	
	for(int i = 0; i < row; ++i){
		
		for(int j = 0; j < col; ++j){
			
			*((*(array + i)) + j) = rand() % 20;
		}
		
	}
	
}

void printInt2dArray(int **array, const int row, const int col){
	
	for(int i = 0; i < row; ++i){
		
		for(int j = 0; j < col; ++j){
			
			printf("%3d", *((*(array + i)) + j));
		}
		printf("\n");
		
	}
	
}

void swap(int *a, int *b){
	
	int vr = *a;
	*a = *b;
	*b = vr;
	
}

void boobleSort(int **array, const int row, const int col){
	
	
int count = 0;	
	
	

while(count < (row * col)){

for(int i = 0; i < row; i++){
	
	for(int j = 0; j < col; j++){
		
		if(j - (col - 1) == 0){

		if(i - (row - 1) != 0){
			if(array[i][j] > array[i + 1][0]) swap(&array[i][j], &array[i + 1][0]);}
			
			break;
		}
		else if(array[i][j] > array[i][j + 1]){

		swap(&array[i][j], &array[i][j + 1]);
		}
		
	}
}

count++;
}

}

void TPK(double *arr){

double x;
	
	printf("\n");
	
	for(int i = 10; i >= 0; i--){
		
		x = sqrt(fabs(arr[i])) + 5 * pow(arr[i], 3);
		
		if(x > 400) printf("%fl > 400; \n", x);		
	}
	
}


int main(const int argc, const char **argv){

//------------------------------ Task 1 ------------------------------
const int row = 3, column = 3;

int **arr = initInt2dArray(arr, row, column);

fillInt2dArray(arr, row, column);

printInt2dArray(arr, row, column);

boobleSort(arr, row, column);

printInt2dArray(arr, row, column);
free(arr);
//--------------------------------------------------------------------
printf("\n");
//------------------------------ Task 3 ------------------------------

int i = 0;
double array[11] = {0};

do{
	
	printf("ENTER %d NUMBER: ", i + 1);
	scanf("%lf", &array[i]);
	i++;
	
}while(i < 11);

TPK(array);
//--------------------------------------------------------------------

return 0;
}
