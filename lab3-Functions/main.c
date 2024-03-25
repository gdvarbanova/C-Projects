#include <stdio.h>
#include <stdlib.h>


//Task1
/*int greater(x, y){
    if(x>y) printf("Greater is %d", x);
    else printf("Greater is %d", y);
}*/

//Task2
/*void square(float a){
    float S = a*a;
    printf("This is a square. S = %f", S);
}

void rectangle(float a, float b){
    float S = a*b;
    printf("This is a rectangle. S = %f", S);
}

void triangle(float a, float b){
    float S = (a*b)/2;
    printf("This is a right triangle. S = %f", S);
}

void circle(float r){
    float S = 3.14*(r*r);
    printf("This is a circle. S = %f", S);
}*/



//Task3
/*void swap(int x, int y){
    int temp = x;
    x = y;
    y = temp;
    printf("Updated: x = %d y = %d ", x, y);
}*/


//Task 4
/*int sum(a, b, c){
        return a + b + c;
}

int max(int a, int b, int c){
    int max = a;
    if(b>a) max = b;
    if(c>a) max = c;
    return max;
}

int min(int a, int b, int c){
    int min = a;
    if(b<a) min = b;
    if(c<a) min = c;
    return min;
}

float avg(int a, int b, int c){
    return (a + b + c)/3;
}*/


int sum_point(int *a, int *b){
    return *a + *b;
}

int div(int *a, int *b){
    return *a - *b;
}

float sub(int *a, int *b){
    return *a / *b;
}

int mult(int *a, int *b){
    return *a * *b;
}





int main()
{
    //Task 1: func greater than 2 nums
    /*int x, y;
    printf("Enter num1: ");
    scanf("%d", &x);
    printf("Enter num2: ");
    scanf("%d", &y);
    greater(x, y);*/


    //Task 2: figures
    //printf("Enter num2: ");
    //scanf("%d", &y);
    /*int choice;
    float a1, a2,a3, b1,b2, r;
    printf("Enter choice 1-4: ");
    scanf("%d", &choice);
    switch(choice){
        case 1: {
            printf("This is a square. \nEnter square side: ");
            scanf("%f", &a1);
            square(a1); break;
            }
        case 2: {
            printf("This is a rectangle. \nEnter side1: ");
            scanf("%f", &a2);
            printf("Enter side2: ");
            scanf("%f", &b1);
            rectangle(a2, b1); break;
            }
        case 3:{
            printf("Enter side1: ");
            scanf("%f", &a3);
            printf("Enter side2: ");
            scanf("%f", &b2);
            triangle(a3, b2); break;
            }
        case 4: {
            printf("Enter radius: ");
            scanf("%f", &r);
            circle(r); break;
            }
    default: printf("Invalid choice!");

    }*/


    //Task 3: swap two nums
    /*int n1, n2;
    printf("Enter num 1: ");
    scanf("%d", &n1);
    printf("Enter num 2: ");
    scanf("%d", &n2);
    swap(n1, n2);*/


    //Task 4: 3 int nums
    /*int a, b, c;
    printf("Enter num 1: ");
    scanf("%d", &a);
    printf("Enter num 2: ");
    scanf("%d", &b);
    printf("Enter num 3: ");
    scanf("%d", &c);
    printf("Sum = %d",sum(a, b, c));
    printf("\nMax: %d",max(a, b, c));
    printf("\nMin: %d",min(a, b, c));
    printf("\nAvarage: %.2f",avg(a, b, c));*/

    //type * name pointer AKA
    //int * p;
    //int a;
    //p = &a;
    //printf(" ", *p); -> stoinost
    //printf(" ", &p); -> mqsto
    //int *b;
    //int **b1;
    //**b1 = &b;

    //Task 5
    /*int * a;
    int b;
    printf("Enter num: ");
    scanf("%d", &b);
    a = &b;
    printf("Result: %d", *a);*/

    //stoinost na a, adress a, stoinost b, adress b

    /*Task 6
    int *a;
    int b;
    printf("Enter num: ");
    scanf("%d", &b);
    a = &b;
    printf("Stoinost pointer: %d", *a);
    printf("\nAddress pointer: %d", &a);
    printf("\nStoinost variable: %d", b);
    printf("\nAddress variable: %d", &b);*/

    //Task 7
    int x, y;
    int *a = &x;
    int *b = &y;
    printf("Enter num 1: ");
    scanf("%d", &x);
    printf("Enter num 2: ");
    scanf("%d", &y);
    printf("%d",sum_point(a, b));
    printf("%d",div(a, b));
    printf("%d",mult(a, b));
    printf("%f",sub(a, b));


    return 0;
}
