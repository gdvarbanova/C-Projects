#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100


int main()
{
    // масив с 5 реда и 2 колони
   /*int a[5][2] = { {0,0}, {1,2}, {2,4}, {3,6},{4,8}};
   int i, j;

   // изкарване на всеки елемент
   for ( i = 0; i < 5; i++ ) {
      for ( j = 0; j < 2; j++ ) {
         printf("a[%d][%d] = %d\n", i,j, a[i][j] );
      }
   }*/


   //task 1
    /*int n;
    printf("Enter number of rows and columns: ");
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
          printf("arr %d, %d: ", i + 1, j + 1);
          scanf("%d", &arr[i][j]);
        }
    }

    printf("\nDisplaying values: \n\n");

      // Using nested loop to display vlues of a 2d array
      for (int i = 0; i < n; ++i)
      {
        for (int j = 0; j < n; ++j)
        {
          printf("%d, %d, %d\n", i + 1, j + 1, arr[i][j]);
        }
      }

      //principal diagonal
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
          if(i==j)
            printf("%d ", arr[i][j]);
        }
    }
    printf("\n");

    //secondary diagonal
    for( int i=0; i<n; i++){
        printf("%d ", arr[i][n-i-1]);
    }
    printf("\n");
    //under main diagonal
    printf("under main diagonal: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            printf("%d ", arr[i][j]);
        }
    }
    printf("\n");

    //above main diagonal
    printf("above main diagonal: ");
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
    }
    printf("\n");*/




//task 2
/*int n, i, j;

    int sum1 = 0, sum2 = 0;
    int row[MAX_SIZE] = {0};
    int col[MAX_SIZE] = {0};

    printf("Enter size: ");
    scanf("%d", &n);
    int arr[n][n];


    printf("Enter elements :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("arr [%d] [%d]: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
            row[i] += arr[i][j];
            col[j] += arr[i][j];
            if (i == j)
            {
                sum1 += arr[i][j];
            }
            if (i + j == n - 1)
            {
                sum2 += arr[i][j];
            }
        }
    }

    int magic_sum = sum1; // assume magic sum is diagonal sum1
    int is_magic = 1;

    // check if row sums, column sums, and diagonal sums are all equal to the magic sum
    for (i = 0; i < n; i++)
    {
        if (row[i] != magic_sum || col[i] != magic_sum)
        {
            is_magic = 0;
            break;
        }
    }

    if (sum2 != magic_sum)
    {
        is_magic = 0;
    }

    if (is_magic)
    {
        printf("The square is magic!\n");
    }

    else
    {
        printf("The square is not magic.\n");
    }*/





    //task 4
    /*char str[100];
    int counter = 0;
    printf("Enter string: ");
    scanf("%[^\n]", str);
    for(int i = 0; str[i] !='\0'; i++){
        if(str[i]==' ' && str[i+1]!=' ') counter++;
    }
    printf("%d", counter +1);*/


    //task 5

    /*char str[1000], symbol;
    int counter = 0;

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter a character: ");
    scanf("%c", &symbol);

    for (int i = 0; str[i] != '\0'; ++i) {
        if (symbol == str[i])
            ++counter;
    }

    printf("Frequency of %c = %d", symbol, counter);*/

    //find length
    char str[MAX_SIZE];
    int counter = 0;

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; ++i) {
        counter ++;
    }
    printf("%d", counter-1);


    //search vowels
    /*char str[1000];
    int vowels = 0;

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
        str[i] == 'o' || str[i] == 'u') {
            ++vowels;
        }
    }

    printf("Vowels: %d", vowels);*/

    //small letters to capital
    /*char str[MAX_SIZE];

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; ++i) {
        if(str[i] >= 'a' && str[i] <= 'z') {
         str[i] = str[i] - 32;
      }
    }
    printf("%s", str);*/

    //compare

    /*char str1[MAX_SIZE], str2[MAX_SIZE];
    int result;

    printf("Enter string: ");
    fgets(str1, sizeof(str), stdin);
    printf("Enter string: ");
    fgets(str2, sizeof(str), stdin);



      // comparing strings str1 and str2
      result = strcmp(str1, str2);
      if(result == 0){
        printf("Equal");
      }
      else{
        printf("Not equal");
      }*/


    return 0;
}
