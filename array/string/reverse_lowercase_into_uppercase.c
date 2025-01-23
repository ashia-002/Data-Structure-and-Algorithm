#include<stdio.h>
#include<string.h>


int main(){
    char as = 'a'-'A'; 
    printf("%d\n",(int)as);
    //reverse lowecase latters into uppercase using string.
    char str[] = "abcdefghijklmnopqrstuvwxyz";

    for(int i = 0; i<27; i++){
        if(str[i]>='a' && str[i]<='z')
            str[i] -= 32;
    }
    printf("%s\n", str);

    //reverse uppercase latters into lowecase using string.
    char str2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    for(int i =0; i<27; i++){
        if(str2[i] >= 'A' && str2[i] <= 'Z')
            str2[i] += 32;
    }
    printf("%s", str2);



    return 0;
}