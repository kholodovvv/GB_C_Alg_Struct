#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 4
#define true 1 == 1
#define false 1 != 1

typedef int boolean;
char seq[size] = "(())";

boolean checkSequence(char *s){

	int chk = 0; //счётчик совпадений
	int idx = 0;
	int num_str = strlen(s);
	
	for(int i = 0; i < num_str; i++){
		
		if(s[i] == seq[idx]){

			if((idx + 1) <= size){
				
				idx++;
			}else{

				return false;
			}
			
			chk++;
		}	
	}

	return chk == size ? true : false;
}

typedef struct{
	
	int dat;
	struct Node *next;
}Node;

typedef struct{
	
	Node *head;
	int size_;
}List;

void initList(List *lst){
	
	lst->head = NULL;
	lst->size_ = 0;
}

void insertNode(List *lst, int data){
	
	Node *new = malloc(sizeof(Node));
	new->dat = data;
	new->next = NULL;
	
	Node *current = lst->head;
	
	if(current == NULL){
		
		lst->head = new;
		lst->size_++;
		return;
	}else{
		
		while(current->next != NULL){
			
			current = current->next;
		}
		current->next = new;
		lst->size_++;
	}
}

List *cpyLst(List *lst){
	
	List *newLst = malloc(sizeof(List));
	initList(newLst);
	
	Node *current = lst->head;
	
	if(current == NULL){
		insertNode(newLst, current->dat);
	}else{
		
	do{
		
		insertNode(newLst, current->dat);
		current = current->next;
	 }while(current != NULL);
	
		}
	
	return newLst;
}

void printNode(Node *n){
	
	if(n == NULL){
		
		printf("[]");
		return;
	}else{
		
		printf("[%d] ", n->dat);
	}
}

void printList(List *lst){
	
	Node *current = lst->head;
	
	if(current == NULL){
		printNode(current);
	}else{
		
	do{
		
		printNode(current);
		current = current->next;
	  }while(current != NULL);
	
	}
	printf("List size: %d", lst->size_);
	
}

boolean checkSort(List *lst){
	
Node *current = lst->head, *n = lst->head;
	
	if(current == NULL){
		return true;
	}else{
		
	for(int i = 1; i < lst->size_; i++){
		
		n = n->next;

		if((current->dat) > (n->dat)){
			
			return false;
		}else{

			current = current->next;
		}

	}
	
	}

	return true;
}

int main(const int argv, const char **argc){

//----------------------- Task 1 ----------------------------------
char str[255];

do{
	printf("ENTER THE STRING TO CHECK: ");
	gets(str);
 }while(strlen(str) == 0);


checkSequence(str) == 1 ? printf("RESULT CHECK: TRUE") : printf("RESULT CHECK: FALSE");

//------------------------------------------------------------------
printf("\n");
//------------------------------------------------------------------
//----------------------- Task 2 -----------------------------------
List *Lst = malloc(sizeof(List));

initList(Lst);

insertNode(Lst, 1);
insertNode(Lst, 20);
insertNode(Lst, 30);

printList(Lst);
printf("\n");

List *cpyLST = cpyLst(Lst);

printList(cpyLST); printf(" <- Copy List");

free(Lst);
free(cpyLST);
//------------------------------------------------------------------
printf("\n");
//------------------------------------------------------------------
//----------------------- Task 3 -----------------------------------
List *L = malloc(sizeof(List));

initList(L);

insertNode(L, 15);
insertNode(L, 20);
insertNode(L, 25);

checkSort(L) == 1 ? printf("RESULT CHECK: TRUE") : printf("RESULT CHECK: FALSE");

free(L);

return 0;
}
