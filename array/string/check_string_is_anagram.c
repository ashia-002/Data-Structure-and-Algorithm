
// Checking if two strings are anagrams:
#include <stdio.h>
#include <string.h>

int areAnagrams(char str1[], char str2[])
{
    int i;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2)
    {
        return 0; // Not anagrams
    }

    int count[26] = {0}; // Assuming the strings contain only lowercase alphabets

    /*for (int i = 0; i < len1; i++)
    {
        count[str1[i] - 'a']++;
        printf("String 1: %d \n", count[str1[i] - 'a']++);
        count[str2[i] - 'a']--;
        printf("String 2: %d \n", count[str2[i] - 'a']++);
    }*/

    int x=0;
    if(len1 == len2){
    for(i =0; i<len1 ; i++){
        for(int j=0; j<len2; j++){
             if(str1[i] == str2[j]){
                 x++;
                 break;
                              }
                
        }
        
    }
    if(x == len1)
    return 1;
    else
    return 0;
    }
    
    // if (count[i] != 0)
    // {
    //     return 0; // Not anagrams
    // }
    // else
    // {
    //     return 1; // Anagrams
    // }j

    // for (int i = 0; i < 26; i++)
    // {
    //     printf("counter %d  value %d \n",i, count[i]);
    //     if (count[i] != 0)
    //     {
    //         return 0; // Not anagrams
    //     }
    //     return 1; // Anagrams
    // }
}

int main()
{
    char str1[100], str2[100];
    printf("Enter the first string: ");
    gets(str1);
    printf("Enter the second string: ");
    gets(str2);

    //printf("Function: %d \n", areAnagrams(str1, str2));

    if (areAnagrams(str1, str2) == 1)
    {
        printf("The strings are anagrams.\n");
    }
    else
    {
        printf("The strings are not anagrams.\n");
    }
    return 0;
}