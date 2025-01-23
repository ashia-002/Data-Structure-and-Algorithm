#include<stdio.h>
#include<string.h>

int main(){
    char string[100];
    printf("Enter the String to count: ");
    gets(string);

    int count = 0;
    for(int i = 0; string[i] != '\0'; i++){
        count++;
    }

    printf("\nThe maximum charecter in the given string is %d", count);



    return 0;
}