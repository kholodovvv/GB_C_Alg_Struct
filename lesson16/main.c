#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1 == 1
#define false 1 != 1
typedef int bool;

char* caesar(char* in, int key, bool encrypt){
int i = 0, cum = 0;

if(encrypt == true){

    while(in[i] != '\0'){
        cum = in[i] + key;
        in[i] = (char)cum;
        i++;
    }
    return in;
}else{

    while(in[i] != '\0'){
        cum = in[i] - key;
        in[i] = (char)cum;
        i++;
    }
    return in;
}

}

void searchSpace(char *array){

int len = strlen(array);

for(int i = 0; array[i] != '\0'; i++){

    if(array[i] == ' '){
		
		for(int j = i; j <= len; j++)
			array[j] = array[j + 1];
    }
}

}

char* shuffle(char* in, int key, bool encrypt){

int current = 0;

if(encrypt == true){

searchSpace(in);

char *array = (char*)calloc((strlen(in) + 1), sizeof(char)); 
int step = key + 1;

for(int i = 0; current < strlen(in); i++){
	array[current] = in[i];
	array[++current] = in[i + step];
	current++;
}

array[current] = '\0';
strcpy(in, array);
free(array);

return in;

}else{

int step = strlen(in) / (key + 1);
char *array = (char*)calloc((strlen(in) + 1), sizeof(char));

for(int i = 0; i < step; i++){
array[current += i] = in[i];
	for(int j = i; j <= (key + (step + i)); j+=step)
		array[++current] = in[j + step];
}

array[++current] = '\0';
strcpy(in, array);
free(array);
return in;
}

}

int main(int const argv, char const  **argc){

/*------------------- ЗАДАНИЕ 1 -------------------
* Реализовать шифрование и расшифровку цезаря с 
* передаваемым в функцию сообщением и ключом
* bool encrypt - Если true, то происходит шифрование
* строки char* in. Если false, то расшифровка.
-------------------------------------------------*/
char word[12] = "Hello word!\0";
int key = 3;

printf("encrypt: %s\n", caesar(word, key, true));
printf("decrypt: %s\n", caesar(word, key, false));

/*------------------- ЗАДАНИЕ 2 -------------------
* Реализовать шифрование и расшифровку перестановками  
* с передаваемым в функцию сообщением и количеством 
* столбцов. bool encrypt - Если true, то происходит 
* шифрование строки char* in. Если false, то расшифровка
-------------------------------------------------*/

int ckey = 4;

printf("encrypt: %s\n", shuffle(word, ckey, true));
printf("decrypt: %s\n", shuffle(word, ckey, false));
    
    return 0;
}
