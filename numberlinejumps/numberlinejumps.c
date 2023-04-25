#include <stdio.h>

char *kangaroo(int, int, int, int);
    
int main(){
    int x1 = 0, v1 = 2, x2 = 5, v2 = 3;
    
    char *resp;
    resp = kangaroo(x1, v1, x2, v2);
    printf("%s\n", resp);

}

char *kangaroo(int x1, int v1, int x2, int v2){
    int cont = 0;

    char *str[] = {"NO", "YES"};

    int i = x1, j = x2;
    if(x2 > x1 && v2 > v1) return str[0];
    else{
        for(i, j; cont < v1 * x2; i = i + v1, j = j + v2, cont++){
            if(i == j) return str[1];
        }
    }
}