#include <stdio.h>
#include <stdlib.h>

#define size 10
#define ST int
#define true 1 == 1
#define false 1 != 1

typedef int boolean;

typedef struct{
	
	int prior;
	int dat;
	
} Node;

Node *array[size];
ST Stack[size];

int items = 0, cursor = -1;

void initArray(){
	
	for(int i = 0; i < size; i++){
		
		array[i] = 0;
	}
	
}

void insert(int pr, int dt){
	
	Node *node = (Node*)malloc(sizeof(Node));
	node->prior = pr;
	node->dat = dt;
	
	if(items < size){
		
		array[items++] = node;

	}else{
		
		printf("THE QUEUE IS FULL!\n");
		return;
	}
}

Node* rem(){


	if(items == 0){

		return NULL;
	}else{
		int idx = 0, pr = array[0]->prior;
		
		for(int i = 0; i < items; i++){
		
		if(array[(i + 1) % size] != NULL){
			if(array[(i + 1) % size]->prior < pr){
				
				pr = array[i + 1]->prior;
				idx = i + 1;
			}
			
		}
		}

		Node *ref = array[idx];
		int p = idx;
		
		if((items - 1) > 1){

		for(int i = 0; i < ((items - 1) - p); i++){

			Node *temp = array[idx + 1];
			array[idx + 1] = array[idx];
			array[idx] = temp;
			idx++;
		}
		
		array[idx] = NULL;
		items--;
		return ref;
		
		}else{
	
		Node *ref = array[idx];
		array[idx] = NULL;
		items--;
		return ref;
		}
	
	}
	
}

void printQueue(){
	
	printf("[ ");
	
	for(int i = 0; i < size; i++){
		
		if(array[i] == NULL){
			
			printf("[*, *] ");
		}else{
			
			printf("[%d, %d] ", array[i]->prior, array[i]->dat);
		}
		
	}
	printf(" ]\n");
	
}

void freeMemory(){
	
	for(int i = 0; i < size; i++){
		
		free(array[i]);
	}

}

boolean PushStack(ST data){
	
	if(cursor < size){
		
		Stack[++cursor] = data;
		return true;
	}else{
		
		printf("STACK OVERFLOW \n");
		return false;
	}
}

ST PopStack(){

	if(cursor != -1){
		
		return Stack[cursor--];
	}else{
		
		printf("STACK IS EMPTY! \n");
		return -1;
	}
	
}


int main(const int argv, const char **argc){

//----------------------- Task 1 ----------------------------------
initArray();

insert(8, 10);
insert(3, 20);
insert(5, 30);
insert(2, 40);
insert(4, 50);
insert(6, 70);
insert(1, 60);
insert(7, 80);
insert(10, 100);
insert(9, 90);

printQueue();


for(int i = 0; i < 3; i++){
Node* n = rem();

printf("pr=%d, dat=%d \n", n->prior, n->dat);
}

printQueue();
freeMemory();
//------------------------------------------------------------------
printf("\n");
//----------------------- Task 2 ----------------------------------

int decNum = 0;

do{
	
	printf("ENTER A NUMBER BETWEEN 0 AND 999: ");
	scanf("%d", &decNum);
}while(decNum < 0 || decNum > 999);


while(decNum > 0){
	
	if(decNum % 2 == 0){
		
	PushStack(0);
	}else{
		
	PushStack(1);
	}
	
	decNum = decNum / 2;
}

while(cursor != -1){
	printf("%d ", PopStack());
}

return 0;
}
