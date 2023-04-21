#include <stdio.h>
#include <string.h>

int strStr(char *, char *);

int main(){
    char *haystack = "butsad";
    char *needle = "sad";

    printf("%d\n", strStr(haystack, needle));

    return 0;
}

int strStr(char *haystack, char *needle){
    int j, len1, len2;

    if(!haystack || !needle) return -1;

    len2 = strlen(needle);
    if(!len2) return 0;

    len1 = strlen(haystack);

    for(int i = 0; i <= len1 - len2; i++){
        for(j = 0; j < len2 && haystack[i + j] == needle[j]; j++){
        }
        if(j == len2) return i;
    }
    return -1;
}