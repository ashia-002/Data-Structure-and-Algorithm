#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char str[100], str1[100];
    printf("Enter the string: ");
    gets(str);
    int ispalindrome = 1;

    
    int length = strlen(str);
    int i,j;
    for(i = 0, j = length - 1; i<j; i++, j--){
        if(str[i] != str[j]){
            ispalindrome = 0;
            break;
        }
        
    }

    if(ispalindrome){
        printf("\nThe string is palindrome.");
    }else{
        printf("\nThe string is not palindrome.");
    }
    

    
    return 0;
}
