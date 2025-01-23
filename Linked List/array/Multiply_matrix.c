#include<stdio.h>

int main(){
    int row1,col1,row2,col2;
    printf("Enter the row of the 1st array. ");
    scanf("%d", &row1);
    printf("\nEnter the coloum of the 1st array. ");
    scanf("%d", &col1);
    printf("\nEnter the row of the 2st array. ");
    scanf("%d", &row2);
    printf("\nEnter the coloum of the 2st array. ");
    scanf("%d", &col2); 

    int arr1[row1][col1];
    int arr2[row2][col2];

    while(col1 != row2){
        printf("\nThe Matrix can't be multiplied");
        printf("\nEnter the row of the 1st array. ");
        scanf("%d", &row1);
        printf("\nEnter the coloum of the 1st array. ");
        scanf("%d", &col1);
        printf("\nEnter the row of the 2st array. ");
        scanf("%d", &row2);
        printf("\nEnter the coloum of the 2st array. ");
        scanf("%d", &col2);
    }

    printf("\nFor 1st Matrix: ");
   
    for(int i = 0; i<row1; i++){
        for(int j = 0; j<col1; j++){
            printf("\n The elements in position[%d][%d]- ", i,j);
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("\nFor 2nd Matrix: ");
    for(int i = 0; i<row2; i++){
        for(int j = 0; j<col2; j++){
            printf("\n The elements in position[%d][%d]- ", i,j);
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("\nThe first array is: \n");
    for(int i = 0; i<row1; i++){
        for(int j = 0; j<col1; j++){
            printf("%d\t", arr1[i][j]); 
        }
        printf("\n");
    }
    
    printf("\nThe second array is: \n");
    for(int i = 0; i<row2; i++){
        for(int j = 0; j<col2; j++){
            printf("%d\t", arr2[i][j]); 
        }
        printf("\n");
    }


    //Multyplying Arrays
    int result[row1][col2];
    for(int i = 0; i<row1; i++){
        for(int j = 0; j<col2; j++){
            result[i][j] = 0;
            for(int k = 0; k<col1; k++){
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    printf("\nthe Multiplication of array is: \n");
    for(int i = 0; i<row1; i++){
        for(int j = 0; j<col2; j++){
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }




    return 0;
}