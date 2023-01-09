/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

void reverseWord(char *s, int begin, int end) {
    while(begin <end) {
    char *temp = s[begin];
    s[begin++]   = s[end];
    s[end--]     = temp;
    }
}

void reverse(char *s) {
    
    int len = strlen(s);
    int begin = -1, i = 0;
    
    while(i < len){
        if((s[i] != ' ') && (begin == -1))
            begin = i;
        if ((begin != -1) &&
            ((s[i+1] == ' ') ||
            (s[i+1] == '\0'))){
            reverseWord(s, begin, i);
            begin = -1;
        }
        i++;    
    }
    //printf("%s\n", s);
    reverseWord(s, 0 , len-1);
}
int main()
{
    char arr[] ="i love coding !";
    
    reverse(arr);
    printf("%s", arr);

    return 0;
}
