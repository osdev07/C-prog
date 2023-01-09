#include <stdio.h>
#include <string.h>

int main()
{
    char str[8] = "rahul";
    int n = 7,i;
    n = strlen(str);
    for (i = 0; i < n/2; i++) {
         char temp = str[i];
         str[i] = str[n-i-1];
         str[n-i-1] = temp;
    }
    printf("%s", str);
    return 0;
}
