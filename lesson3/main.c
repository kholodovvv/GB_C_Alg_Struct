#include <stdio.h>
#include <math.h>
#include <time.h>

#define WIDTH_BOARD 8
#define HEIGHT_BOARD 8
#define IMPEDIMENT 1

int BOARD[WIDTH_BOARD][HEIGHT_BOARD];

void getBinaryView(int num){

	if(num >= 2){
		
		getBinaryView(num / 2);
	}
		
	printf("%d", num % 2);
}

double getExpo(double number, int degree){
	
	if(degree == 0) return 1.0;
	if(degree < 0) return getExpo(1.0 / number, -degree);
	if(degree % 2) return number * getExpo(number, degree - 1);
	
	return getExpo(number * number, degree / 2);
}

double expo(double n, int deg){
	
	if(deg % 2 == 0){

		 return expo(n * n, deg / 2);
	 }else{
		 
		 return n * pow(n, deg - 1);
	 }
	
	return pow(n, deg);
}

void resetArray(){
	
	for(int i = 0; i < WIDTH_BOARD; ++i)
	for(int j = 0; j < HEIGHT_BOARD; ++j)
		BOARD[i][j] = 0;
}

void setImpediment(){
	
	srand(time(NULL));
	BOARD[1 + (rand()%8)][1 + (rand()%8)] = IMPEDIMENT;
}


int stepKing(int x, int y){
	
	if(x == 0 && y == 0)
		return 0;
	else if(BOARD[x][y] == 1)
		return 0;
	else if(x == 0 ^ y == 0)
		return 1;
	else 
	return stepKing(x, y - 1) + stepKing(x - 1, y);

}

int main(const int argv, const char **argc){

//----------------------- Task 1 ----------------------------------
int number = 0;

	do{
		printf("ENTER NUMBER MORE 0: ");
		scanf("%d", &number);
	}while(number < 0);

getBinaryView(number);
//-----------------------------------------------------------------
printf("\n");
//----------------------- Task 2 ----------------------------------
int degr = 0;
double num = 0.0;	
	
	
printf("ENTER THE NUMBER AND THE DEGREE OF THE NUMBER SEPARATED BY A SPACE: ");
scanf("%lf %d", &num, &degr);

	printf("%lf \n", getExpo(num, degr));
	
//-----------------------------------------------------------------
printf("\n");
//----------------------- Task 3 ----------------------------------
degr = 0;
num = 0.0;

printf("ENTER THE NUMBER AND THE DEGREE OF THE NUMBER SEPARATED BY A SPACE: ");
scanf("%lf %d", &num, &degr);

	printf("%lf \n", expo(num, degr));
	
//-----------------------------------------------------------------
printf("\n");
//----------------------- Task 4 ----------------------------------

resetArray();
setImpediment();

	for(int i = 0; i < WIDTH_BOARD; ++i){
	for(int j = 0; j < HEIGHT_BOARD; ++j){
		printf("%5d", BOARD[i][j]);
	}
	
	printf("\n");
}
printf("\n");

	for(int i = 0; i < WIDTH_BOARD; ++i){
	
		for(int j = 0; j < HEIGHT_BOARD; ++j){
			
			printf("%5d", stepKing(i, j));
		}
		printf("\n");
	}


return 0;
}
