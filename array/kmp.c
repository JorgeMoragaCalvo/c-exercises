#include <stdio.h>
#include <string.h>

void computeLPSArray(char *, int, int *);
void KMPSearch(char *, char *);

int main(){
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMPSearch(pat, txt);

    return 0;
}

void computeLPSArray(char *pat, int M, int *lps){
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while(i < M){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }else{ // (pat[i] != pat[len])
        // This is tricky. Consider the example AAACAAAA and i = 7. The idea is similar to search step.
            if(len != 0){
                len = lps[len - 1];
            }else{ // if (len == 0)
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char *pat, char *txt){
    int M = strlen(pat);
    int N = strlen(txt);

    int lps[M];

    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while(i < N){
        if(pat[j] == txt[i]){
            j++;
            i++;
        }

        if(j == M){
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1];
        }else if(i < N && pat[j] != txt[i]){ // mismatch after j matches
            // Do not match lps[0..lps[j - 1]] characters, they will match anyway
            if(j != 0){
                j = lps[j - 1];
            }else{
                i = i + 1;
            }
        }
    }
}