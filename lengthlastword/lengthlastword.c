#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

int lengthOfLastWord(char *);


int main(){

    char *s = {"Hello World"};

    printf("%d\n", lengthOfLastWord(s));

    return 0;
}

int lengthOfLastWord(char *s){
    int length = strlen(s);
    int cont = 0;

    while (s[length - 1] != ' '){
        cont++;
        length--;
    }

    return cont;
}