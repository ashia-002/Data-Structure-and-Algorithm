#include<stdio.h>
#include<string.h>

int main(){
    char str[100];
    printf("enter the string: ");
    fgets(str, 100, stdin);
    int length = strlen(str)-1;
    int j = 0;
    for(int i = length-1; i>=j; --i){
            int temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            j++;
        
    }
    printf("\nThe reversed array is : ");
    for(int i=0; i<length; i++){
        printf("%c", str[i]);
    }


//WE can also do it this way.
    // int start = 0;
    // int end = length - 1;

    // while (start < end) {
    //     char temp = str[start];
    //     str[start] = str[end];
    //     str[end] = temp;
    //     start++;
    //     end--;




    return 0;
}