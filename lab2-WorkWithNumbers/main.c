#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Task 1: check if a num is greater than 12
    /*int num;
    printf("Your number: ");
    scanf("%d", &num);
    if(num>12) printf("Your number is greater than 12!");
    else if(num == 12) printf("Your number is 12.");
    else printf("Your number is smaller than 12!");*/





    //Task 2: ako ostatuka pri delenie s 8 - print mod else invalid input
    /*int num;
    printf("Your number: ");
    scanf("%d", &num);
    if(num == 8) printf("No mod!");
    else{
        if((num%8)<4) printf("mod: %d", num%8);
        else printf("Your number does not meet requirements!");
    }*/




    //Task 3: find min among 3 nums
    /*int n1, n2, n3;
    printf("num 1: ");
    scanf("%d", &n1);
    printf("num 2: ");
    scanf("%d", &n2);
    printf("num 3: ");
    scanf("%d", &n3);
    int min = n1;
    if(n2<n1) min = n2;
    else if(n3<n1) min = n3;
    printf("Min: %d", min);
    int max = n1;
    if(n2>n1) min = n2;
    else if(n3>n1) min = n3;
    printf("\nMax: %d", min);*/




    //Task 4: print numbers 0-9
    /*int num;
    printf("num: ");
    scanf("%d", &num);
    switch(num){
        case 0: printf("zero"); break;
        case 1: printf("one"); break;
        case 2: printf("two"); break;
        case 3: printf("three"); break;
        case 4: printf("four"); break;
        case 5: printf("five"); break;
        case 6: printf("six"); break;
        case 7: printf("seven"); break;
        case 8: printf("nine"); break;
        case 9: printf("nine"); break;
        default: printf("Your number is not between 0 and 9.");
    }*/




    //Task 5: num 1-7; which week day
    /*int num;
    printf("num: ");
    scanf("%d", &num);
    switch(num){
        case 1: printf("It's Monday!"); break;
        case 2: printf("It's Tuesday!"); break;
        case 3: printf("It's Wednesday!"); break;
        case 4: printf("It's Thursday!"); break;
        case 5: printf("It's Friday!"); break;
        case 6: printf("It's Saturday!"); break;
        case 7: printf("It's Sunday!"); break;
        default: printf("You live in a parallel universe!");
    }*/



    //Task 6: enter num and find avarage the last two didgits; if avarage > 5 -> greater else ->smaller
    /*int num, avrg;
    printf("num: ");
    scanf("%d", &num);
    if(num>99 && num <1000){
        avrg = ((num/10%10) + (num%10))/2;
        if(avrg>5) printf("Avarage greater than 5!");
        else if(avrg == 5) printf("Avarage is 5!");
        else printf("Avarage less than 5!");
    }
    else printf("Invalid number, should be a three-digit number!");*/







    //Task 7: 1-10 while
    /*int num = 1;
    while(num<11){
        printf("%d\n",num);
        num+=1;
    }*/

    /*int num;
    printf("num: ");
    scanf("%d", &num);
    for(int i = 0; i<=num; i++){
        for(int j = 0; j<i; j++){
            printf("%d ", i);
        }
        printf("\n");
    }*/



    //Task 8: 2 celi chisla, sum between tezi chisla

    /*int n1, n2, sum = 0;
    printf("num 1: ");
    scanf("%d", &n1);
    printf("num 2: ");
    scanf("%d", &n2);
    if(n1<n2){
        for(int i = n1+1; i<n2; i++){
            sum += i;
        }
    }
    else{
        for(int i = n2+1; i<n1; i++){
            sum += i;
        }
    }
    printf("Sum = %d", sum);*/



    //Task 9: find sum even nums and prod uneven nums
    /*int n1, n2, sum = 0, prod =1;
    printf("num 1: ");
    scanf("%d", &n1);
    printf("num 2: ");
    scanf("%d", &n2);
    for(int i = n1+1; i<n2; i++){
        if(i%2 == 0) sum += i;
        else prod *= i;
    }
    printf("Sum even numbers = %d", sum);
    printf("\nProd uneven numbers = %d", prod);*/



    //Task 10: enter n, k, enter n nums, find number of nums greater than k and %3 ==0

    /*int n, k, counter = 0;
    printf("n: ");
    scanf("%d", &n);
    printf("k: ");
    scanf("%d", &k);
    int nums[n];
    for(int i = 0; i<n; i++){
        printf("num %d: ", i+1);
        scanf("%d", &nums[i]);
    }
    for(int i = 0; i<n; i++){
        if(nums[i]>k){
        if(nums[i]%3 == 0) counter += 1;
        }
    }
    printf("Number of numbers greater than %d and divisnible by 3: %d", k,counter);*/


    //Task 11: write a program to enter nums until 0 input and find sum
    /*int num, sum = 0;
    printf("Enter a numbers, 0 to stop: ");
    scanf("%d", &num);
    while(num != 0){
        sum += num;
        scanf("%d", &num);
    }
    printf("\nSum of entered numbers: %d: ", sum);*/




    //Task 12: two float nums from console; print f(x) = x*x-4 in the interval
    //stupka na obhojdane ne i++, a 0.01
    float n1, n2, prod;
    printf("Enter restrainer 1: ");
    scanf("%f", &n1);
    printf("Enter restrainer 2: ");
    scanf("%f", &n2);
    for (float i = n1; i <= n2; i+= 0.01){
        prod = i*i - 4;
        printf("f(x)= x*x-4: %.2f\n", prod);
    }



    return 0;
}
