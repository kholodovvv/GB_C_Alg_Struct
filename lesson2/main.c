#include <stdio.h>


int checkSimpleNumber(int num){
		
	
	for(int j = 2; j < num + 1; j += 2){

		if(j == num){
			
			return 0;
		}
	}
	
	return 1;
}


int main(int argv, const char **argc){

int number = 0;

do{
	
	printf("ENTER NUMBER MORE 2:");
	scanf("%d", &number);
	
}while(number <= 2);

(checkSimpleNumber(number) ? printf("NUMBER SIMPLE \n") : printf("NUMBER NOT SIMPLE \n"));

	return 0;
}
