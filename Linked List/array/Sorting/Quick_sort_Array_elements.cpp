// #include<iostream>
// using namespace std;

// int partition(int array[], int low, int high) {
//     int pivot = array[high];
//     int i = low - 1;

//     for(int j = low; j <= high - 1; j++) {
        
//         if(array[j] < pivot) {
//             i++;
//             int temp = array[i];
//             array[i] = array[j];
//             array[j] = temp;
//         }
//     }
//     i++;
//     int temp = array[i];
//     array[i] = array[high];
//     array[high] = temp;

//     return i;
// }

// void quickSort(int array[], int low, int high) {
//     if(high <= low) return; // Base case

//     int pi = partition(array, low, high);

//     quickSort(array, low, pi - 1);
//     quickSort(array, pi + 1, high);
// }

// int main() {
//     int array[] = {44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66};
//     int n = sizeof(array) / sizeof(array[0]);

//     cout << "The indax of the elements before sorting is: " << endl;
//     for(int i = 0; i<n; i++){
//         cout<<array[i]<<"'s indax is: "<<i<<endl;
//     }

//     quickSort(array, 0, n-1);

//     cout<<endl;
//     cout << "The array after sorting is: " << endl;
//     for(int i = 0; i < n; i++) {
//         cout << array[i] << " ";
//     }
//     cout<<endl;

//     cout << "The indax of the elements after sorting is: " << endl;
//     for(int i = 0; i<n; i++){
//         cout<<"Element "<<array[i]<<"'s indax is: "<<i<<endl;
//     }

//     return 0;
// }



#include <stdio.h>

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    i++;
    int temp = array[i];
    array[i] = array[high];
    array[high] = temp;

    return i;
}

void quickSort(int array[], int low, int high) {
    if (high <= low)
        return; // Base case

    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
}

int main() {
    int P[] = {44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66};
    int n = sizeof(P) / sizeof(P[0]);

    printf("The index of the elements before sorting is:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d's index is: %d\n", P[i], i);
    }

    quickSort(P, 0, n - 1);

    printf("\nThe array after sorting is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", P[i]);
    }
    printf("\n");

    printf("\nThe index of the elements after sorting is:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d's index is: %d\n", P[i], i);
    }

    return 0;
}
