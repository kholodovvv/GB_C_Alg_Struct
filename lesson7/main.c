#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER 100

void fillArray(int *arr, int len){
	
	for(int i = 0; i < len; i++){
		
		arr[i] = rand() % MAX_NUMBER;
	}
	
}

void printArray(int *arr, int len){
	
	for(int i = 0; i < len; i++){
		
		printf("%d ", arr[i]);
	}
	
}

void blockSort(int *arr, int len){
	
	int const MAX = len;
	int const BASKET = 10;
	
	int BASKETS[BASKET][MAX + 1];
	
	for(int i = 0; i < BASKET; ++i){
		
		BASKETS[i][MAX] = 0;
	}
	
	for(int i = 0; i < BASKET; i++){
		
		for(int j = 0; j < MAX; j++){
			
			BASKETS[i][j] = 0;
		}
	}
	
	for(int limit = 1; limit < MAX_NUMBER; limit *= 10){
		
		for(int i = 0; i < MAX; ++i){
			

			if((arr[i] % 2) == 0){

			int digit = (arr[i] / limit) % BASKET;

			int counter = BASKETS[digit][MAX];
			BASKETS[digit][counter] = arr[i];

			counter++;

			BASKETS[digit][MAX] = counter;
			}
			
		}
		
		int index = 0;
		for(int i = 0; i < BASKET; ++i){
			
			for(int j = 0; j < BASKETS[i][MAX]; ++j){
						
				if((arr[index] % 2) == 0){

					arr[index++] = BASKETS[i][j];
				}else{
					
					j--;
					index++;
				}
			}
			BASKETS[i][MAX] = 0;
		}
	}

}

void swapInt(int *a, int *b){

	int t = *a;
	*a = *b;
	*b = t;
}

void xoarSort(int *ar, int first, int last){
	
	int x = ar[(first + last) / 2];
	
		int i = first, j = last;

	do{
		
		while(ar[i] < x) i++;
		while(ar[j] > x) j--;
		
		if(i <= j) {
		swapInt(&ar[i], &ar[j]);

		i++;
		j--;
		}

	}while(i <= j);
	
	if(i < last) xoarSort(ar, i, last);
	if(first < j) xoarSort(ar, first, j);
	
}

void improvedSort(int *arr, int f, int l){
	
	int aver = (l + 1) / 2; //индекс среднего элемента
	
	int temp, pos;
	
	if((l + 1) <= 10){
		
		for(int i = 1; i < l + 1; ++i){
			
			temp = arr[i];
			pos = i - 1;
			
			while(pos >= 0 && arr[pos] > temp){
				
				arr[pos + 1] = arr[pos];
				pos--;
			}
			arr[pos + 1] = temp;
		}
		
	}else{
	
		
	if((arr[aver] <= arr[f] && arr[f] <= arr[l]) || (arr[aver] > arr[f] && arr[f] > arr[l])){

		temp = arr[aver];
		arr[aver] = arr[f];
		arr[f] = temp;

	}
	else{

		temp = arr[aver];
		arr[aver] = arr[l];
		arr[l] = temp;
	}
	
	xoarSort(arr, f, l);

}

}


int main(const int argv, const char **argc){

//----------------------- Task 2 ----------------------------------
int const size = 10;

int array[size];

fillArray(array, size);

printArray(array, size);
printf("\n");

blockSort(array, size);
printf("\n");

printArray(array, size);
//-----------------------------------------------------------------
printf("\n");
//-----------------------------------------------------------------
//----------------------- Task 1 ----------------------------------

printf("\n");
fillArray(array, size);
printArray(array, size);
printf("\n");

improvedSort(array, size - size, size - 1);
printArray(array, size);

return 0;
}
