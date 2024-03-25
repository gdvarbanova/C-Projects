#include <stdio.h>
#include <stdlib.h>


void idk(int arr[], int len){
    int sum = 0;
    for(int i; i<len; ++i){
        sum += arr[i];
    }
    float result = sum/len;
    printf("Avarage: %.2f", result);
}



int main()
{
    //Task 1: print array nums 1-9 + 11
    /*int arr[10];
    for(int i = 0; i<10; ++i){
        arr[i] = i + 11;
        //printf("%d ",arr[i]);
    }
    for(int k = 0; k<10; ++k){
        printf("%d ",arr[k]);
    }*/


    //Task 2: get size of array and pointer array

    /*int arr[] = {10, 20, 30, 40, 50, 60};
    int *a = arr;
    printf("Array size: %ld", sizeof(arr));
    printf("\nPointer size: %ld", sizeof(*a));*/

    //Task 3: def array 2 elements

    //int arr[] = {10, 20, 30, 40, 50, 60};
    //int el2 = 20;
    //int *a = &el2;
    // !!!! arr = &el2; INCORRECT !!!

    //int *b = &arr;
    //printf("%d", *b);


    /*int arr1[] = {10, 20, 30, 40, 50, 60};
    int arr2[] = {2,5};
    idk(arr1, 6);
    int *a;*/

    /*int size, sum = 0;
    printf("Enter size: ");
    scanf("%d", &size);
    int array[size];
    //enter numbers in array
    printf("Enter elements: ");
    for(int i=0; i<size; ++i) {
        printf("num %d: ", i+1);
        scanf("%d", &array[i]);
        if(array[i] >= -5000 && array[i]<= 5000){
            sum+=array[i];
        }
        else printf("\nInvalid number!\n");
    }
    printf("Sum = %d", sum);*/

    //Task 2
    /*int max;
    int array[7];
    //enter numbers in array
    printf("Enter elements: ");
    for(int i=0; i<7; ++i) {
        printf("num %d: ", i+1);
        scanf("%d", &array[i]);
    }
    for(int i=0; i<7; ++i) {
        max = array[0];
        if(array[i]>max) max = array[i];
    }
    printf("max = %d", max);*/

    //Task 3
    /*float sum = 0;
    float array[7];
    //enter numbers in array
    printf("Enter elements: ");
    for(int i=0; i<7; ++i) {
        printf("num %d: ", i+1);
        scanf("%f", &array[i]);
        if(array[i] >= -5000 && array[i]<= 5000){
            sum+=array[i];
        }
        else printf("\nInvalid number!\n");
    }
    float avg = sum/7;
    printf("avg = %f", avg);*/

    //Task 4
    /*float sum = 0, sub, close_n;
    float array[7];
    //enter numbers in array
    printf("Enter elements: ");
    for(int i=0; i<7; ++i) {
        printf("num %d: ", i+1);
        scanf("%f", &array[i]);
        if(array[i] >= -5000 && array[i]<= 5000){
            sum+=array[i];
        }
        else printf("\nInvalid number!\n");
    }
    float avg = sum/7;
    printf("avg = %.2f", avg);
    float arr1[7];
    for(int i=0; i<7; ++i) {
        arr1[i] = avg-array[i];
    }
    for(int i=0; i<7; ++i) {
        close_n = arr1[0];
        if(arr1[i]>close_n || arr1[i]==close_n) close_n = array[i];
    }
    printf("\nClosest num = %.2f", close_n);*/


    //Task 6
    int nums, index[5000];
    printf("How many nums: ");
    scanf("%d", &nums);
    int arr[nums];
    for(int i; i<nums; ++i){
        printf("num %d: ", i+1);
        scanf("%f", &arr[i]);
    }
    for(int i; i<nums; i++){
        for(int j = i+1; j<nums; j++){
            if(arr[i] == arr[j]) printf("%d, %d", i, j);
        }
    }


    return 0;
}
