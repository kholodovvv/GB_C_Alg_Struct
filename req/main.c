#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int simpleHashSum(char* in){

int i = 0, counter = 0;

while(in[i] != '\0'){

    counter += in[i];

i++;
}

    return counter;
}

void clearArray(int *array, int size){

    for(int i = 0; i < size; i++)
        array[i] = 0;
}

void boobleSort(int *array, int size){
int a = 0, counter = 0;

for(int j = 0; j < size; j++){
    for(int i = 0; i < size - 1; i++){
        if(array[i] < array[i + 1] && array[i] != 0){
            counter += 1;
            a = array[i];
            array[i] = array[i + 1];
            array[i + 1] = a;
        }
    }
    if(counter == 0) break;
}
}

int *countArray;

int* exchange(int* money, int size, int sum){

countArray = (int*) malloc(size * sizeof(int));
clearArray(countArray, size);
boobleSort(money, size); //Сортируем номеналы монет от большего к меньшему

while (sum != 0)
{

    for(int i = 0; i < size; ++i){

        if(money[i] <= sum && money[i] != 0){
            countArray[i] += 1;
            sum -= money[i];
            break;
        }
    }

}

    return countArray;
}

int main(int const argv, char const  **argc){

/*------------------- ЗАДАНИЕ 1 -------------------
* Реализовать простейшую хеш-функцию.
* На вход функции подается строка, на выходе сумма 
* кодов символов.
-------------------------------------------------*/

char word[12] = "Hello word!\0";

printf("SUM OF CHARACTER CODES %d", simpleHashSum(word));
printf("\n");
/*------------------- ЗАДАНИЕ 2 -------------------
* Имеются монеты номиналом 50, 10, 5, 2, 1 коп.
* Напишите функцию которая минимальным количеством 
* монет наберет сумму 98 коп.
* Для решения задачи используйте “жадный” алгоритм.
* int* money - Массив с доступными номиналами монет
* размером size.
-------------------------------------------------*/

int money[SIZE] = {50, 10, 5, 2, 1};

int *count = exchange(money, SIZE, 98);

printf("selected: ");
for(int i = 0; i < SIZE; i++){
    if(count[i] != 0)
        printf("coin with a face value of %d - %d time; ", money[i], count[i]);
}
    
free(countArray);

    return 0;
}