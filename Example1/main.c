#include <stdio.h>
#include <stdlib.h>

int main()
{
    //task 1
    /*int num, min, max;
    printf("Number of nums to enter: ");
    scanf("%d", &num);
    int array[num];

    //enter multiple numbers
    for(int i=0; i<num; ++i) {
        printf("num %d: ", i+1);
        scanf("%d", &array[i]);
    }

    //display numbers
    printf("Your numbers: ");
    for(int k; k<num; ++k){
        printf("%d ", array[k]);
    }

    //find min element
    for(int i; i<num; ++i){
        min = array[0];
        if(array[i]<min) array[i]=min;
    }
    printf("\n""min element: %d", min);

    //find max element
    for(int i=1; i<num; ++i){
        max = array[0];
        if(array[i]>max) max = array[i];
    }
    printf("\n""max element: %d", max);

    //sort numbers
    for(int i; i<num; ++i){
        for(int j = i+1; j<num; ++j){
            if(array[i]>array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    //display sorted numbers
    printf("\nSorted: ");
    for(int k; k<num; ++k){
        printf("%d ", array[k]);
    }*/




    //task 2
    int n;
    printf("How many letters: ");
    scanf("%d", &n);
    char letters[n];
    printf("Enter letters: ");

    //enter letters
    for(int i=0; i<n; ++i){
        scanf("%c", &letters[i]);
    }

    //display letters
    printf("Your letters: ");
    for(int k; k<n; ++k){
        printf("%c", letters[k]);
    }

    return 0;
}
