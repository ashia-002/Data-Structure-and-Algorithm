#include<stdio.h>

int main(){
    char car1[] = "Tesla";
    char car2[] = "Mahindra";

//This will print character by character.
    for(int i = 0; car1[i] != '\0'; i++){
        printf("%c", car1[i]);
    }
    printf("\n");
    for(int i = 0; car2[i] != '\0'; i++){
        printf("%c", car2[i]);
    }
    printf("\n");
//This will input output as a string.
    char name[50];
    scanf("%s", name);
    printf("\nyour name is %s", name);
//String can't take more then one word
      /* scanf()--> can't take multi-word
Here, gets(), puts() come into picture. 
Note. gets() is not safe so has been removed from latest c.*/
    char Fullname[100];
    scanf("%s", Fullname);
    printf("\nyour name is %s", Fullname);//here if we give Nahida Akter , it will only print Nahida.
    gets(Fullname);
    fgets(Fullname, 100, stdin);//Using this is safe.
    puts(Fullname);

//if string is a array you can't change it but you can change pointer.
    char *change = "Hello World";
    puts(change);
    change = "World";
    puts(change);

//Take name from user and print it's length.
    char name[100];
    fgets(name, 100, stdin);
    int count = 0;
    for(int i = 0;name[i]!= '\0';i++){
        count++;
    }
    printf("%d", count-1);




    return 0;
}