#include <stdio.h>
#include <stdlib.h>
#include "geek.c"

#define SIZE 6

void clrArray(int *array, int size){
	
	for(int i = 0; i < size; ++i){
		
		array[i] = 0;
	}
}

void adjacencyCount(int** matrix, const int size){
	
	TwoLinkList *queue = malloc(sizeof(TwoLinkList));
	initTwoLinkList(queue);
	
	int count[size];
	int visited[size];
	clrArray(visited, size);
	clrArray(count, size);
	
	TwoLinkEnqueue(queue, 0);
	
	while(queue->size > 0){
		
		int idx = TwoLinkDequeue(queue);
		if(visited[idx] == 1) continue;
		visited[idx] = 1;
		printf("piak = %d ", idx);
		
		for(int i = 0; i < size; ++i){
			
			if(get2dInt(matrix, idx, i) == 1 && visited[i] == 0){

				TwoLinkEnqueue(queue, i);
			}
			else if(get2dInt(matrix, idx, i) == 1 && visited[i] == 1){ 
				count[i] = count[i] + 1; //подсчёт количества рёбер, входящих в вершину
			}
		}
	}
	printf("\n");
	for(int i = 0; i < size; ++i){
		printf("link = %d ", count[i]);
	}
	
	free(queue);
}

int Count[SIZE];
int Visited[SIZE];
int counter;
boolean flag = false;

void traversalCount(int** matrix, int start, const int size){

int current;

if(flag == false){
	//Счетаем исходящие ссылки до смежных вершин
	for(int i = 0; i < size; ++i){
		if(get2dInt(matrix, start, i) == 1){
			counter = counter + 1;
			
		}
	}
	flag = true;
	current = start;
}	

	//Счетаем входящие ссылки до смежных вершин
	if(start <= size - 1){
		
		if(get2dInt(matrix, start, current) == 1){
			counter = counter + 1;
			traversalCount(matrix, ++start, size);
		}else{
		traversalCount(matrix, ++start, size);
		}
	}
	
}
//-----------------------------------------------------------------------------------
int Stack[SIZE];
int cursor = -1;

boolean PushStack(int data){
	
	if(cursor < SIZE){
		
		Stack[++cursor] = data;
		return true;
	}else{
		
		printf("STACK OVERFLOW \n");
		return false;
	}
}

int PopStack(){

	if(cursor != -1){
		
		return Stack[cursor--];
	}else{
		
		printf("STACK IS EMPTY! \n");
		return -1;
	}
	
}

void depthTraversStack(int** matrix, int size){
	
	int current;
	int n = 0;
	PushStack(n);
	Visited[n] = 1;
	
do{
	n = current;
	printf("%d ", n);
	for(current = 0; current < size; ++current){
		if(get2dInt(matrix, n, current) == 1 && !Visited[current]){
			PushStack(current);
			Visited[current] = 1;

			break;
		}
	}
	if(current == size){
		
		current = PopStack();
		if(current + 1 <= size - 1 && !Visited[current + 1]){
			current++;
			PushStack(current);
			Visited[current] = 1;
		}else{
			current = size;
		}
	}
}while(current < size);

clrArray(Visited, size);

}
		
int main(const int argc, const char **argv){

//---------------------------- Task 1 ----------------------------	
int **matrix = init2dIntArray(matrix, SIZE, SIZE);

for(int i = 0; i < SIZE; ++i){
	
	for(int j = 0; j < SIZE; ++j){
		matrix[i][j] = 0;
	}
}

set2dInt(matrix, 0, 1, 1);
set2dInt(matrix, 0, 2, 1);
set2dInt(matrix, 1, 3, 1);
set2dInt(matrix, 1, 4, 1);
set2dInt(matrix, 1, 5, 1);
set2dInt(matrix, 2, 5, 1);
set2dInt(matrix, 3, 0, 1);
set2dInt(matrix, 5, 1, 1);
set2dInt(matrix, 5, 2, 1);
set2dInt(matrix, 5, 4, 1);

print2dIntArray(matrix, SIZE, SIZE, 2);
printf("\n");

depthTraversStack(matrix, SIZE);
//----------------------------------------------------------------
printf("\n");
//---------------------------- Task 2a----------------------------

printf("\n");
adjacencyCount(matrix, SIZE);
//----------------------------------------------------------------
printf("\n");
//---------------------------- Task 2б----------------------------
//Исходя из условия задания нужно подсчитать количество ссылок
//на каждый из узлов графа (полустепень захода).
//Обход графа функцией (с подсчётом только смежных со стартовой вершин).
//Так как граф не ориентированный, буду считать, что полустепенью захода
//будет количество входящих и исходящих ссылок от стартовой вершины к 
//смежным.
traversalCount(matrix, 0, SIZE);
printf("\n");

printf("INCOMING AND OUTGOING LINKS = %d ", counter);


free2dIntArray(matrix, SIZE, SIZE);
    return 0;
}
