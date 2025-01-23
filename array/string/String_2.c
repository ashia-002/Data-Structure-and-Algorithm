#include<stdio.h>
#include<string.h>
//srtlen()-->for lenght.
//srtcpy(newStr, oldStr)-->copies the old string to the new string
//strcat(firststr, secStr)-->It merges two strings.
int main(){
    char name[] = "Mahindra";
    int length = strlen(name);
    printf("The length is: %d",length);

    char oldstr1[] = "Hello";
    char newstr2[] = "World";
    strcpy(newstr2, oldstr1);
    printf(newstr2);
    strcmp()

    
    strcat(oldstr1,newstr2);
    printf(oldstr1);
}