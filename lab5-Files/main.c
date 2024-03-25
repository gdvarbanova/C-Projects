#include <stdio.h>
#include <stdlib.h>


double d[10] = {10.23, 19.87, 1002.23, 12.9, 0.897, 11.45, 75.34,
0.0, 1.01, 875.875};

int main(void)
{

    //Task 1

    /*char str[80] = "This is a file system test. \n";
    FILE *fp;
    char *p;
    int i;*/

    /* отваря myfile за изход */
    /*if((fp = fopen("myfile", "w"))==NULL){
        printf("Cannot open file. \n");
        exit(1);
    }*/

    /* записва str на диска */
    /*p = str;
    while(*p){
        if(fputc(*p, fp)==EOF){
        printf("Error writing file. \n");
        exit(1);
        }
        p++;
    }
    fclose(fp);*/

    /* отваря myfile за вход */
    /*if((fp = fopen("myfile", "r"))==NULL){
        printf("Cannot open file. \n");
        exit(1);
    }*/

    /* чете отново файла */
    /*for(;;)
    {
    i = getc(fp);
    if(i == EOF) break;
    putchar(i);
    }
    fclose(fp);*/




    //Task 2
    //int main(int argc, char *argv[])

    /*FILE *fp;
    double ld;
    int d;
    char str[80];*/

    /* проверка за аргумент от командния ред */
    /*if(argc!=2){
        printf("Specify file name. \n");

        exit(1);
    }*/

    /* отваряне на файл за изход */
    /*if((fp = fopen(argv[1], "w"))==NULL){
        printf("Cannot open file. \n");

        exit(1);
    }

    fprintf(fp, "%f %d %s", 12345.342, 1908, "hello");
    fclose(fp);*/

    /* отваряне на файл за вход */
    /*if((fp = fopen(argv[1], "r"))==NULL){
        printf("Cannot open file. \n");
        exit(1);
    }*/

    /*fscanf(fp, "%lf%d%s", &ld, &d, str);
    printf("%f %d %s", ld, d, str);
    fclose(fp);*/


    //Task 3

    /*FILE *fp;
    int i;*/

    /* отваряне на файл за изход */
    /*if((fp = fopen("myBinFile", "wb"))==NULL){
    printf("Cannot open file. \n");
    exit(1);
    }
    //i = ASCII code number
    i = 80;

    if(fwrite(&i, 2, 1, fp) != 1){
        printf("Write error occured. \n");
        exit(1);
    }
    fclose(fp);*/

    /* отваряне на файл за вход */
    /*if((fp = fopen("myBinFile", "rb"))==NULL){
    printf("Cannot open file. \n");
    exit(1);
    }

    if(fread(&i, 2, 1, fp) != 1){
    printf("Read error occured. \n");
    exit(1);
    }
    printf("i is %d", i);
    fclose(fp);*/


    //-------

    /*if((fp = fopen("myfile", "w"))==NULL){
    printf("Cannot open file. \n");
    exit(1);
    }*/
    //i = ASCII code number
    /*i = 80;

    if(fwrite(&i, 2, 1, fp) != 1){
    printf("Write error occured. \n");
    exit(1);
    }
    fclose(fp);*/

    /* отваряне на файл за вход */
    /*if((fp = fopen("myfile", "r"))==NULL){
    printf("Cannot open file. \n");
    exit(1);
    }

    if(fread(&i, 2, 1, fp) != 1){
    printf("Read error occured. \n");
    exit(1);
    }
    printf("i is %d", i);
    fclose(fp);*/


    //Task 4
    /*long loc;
    double value;
    FILE *fp;

    if((fp = fopen("myBinFile", "wb"))==NULL){
        printf("Cannot open file. \n");
        exit(1);
    }*/

    /* записване на целия масив в една стъпка */
    /*if(fwrite(d, sizeof d, 1, fp) != 1){
        printf("Write error. \n");
        exit(1);
    }
    fclose(fp);

    if((fp = fopen("myBinFile", "rb"))==NULL){
        printf("Cannot open file. \n"); exit(1);
    }
    printf("Which element? ");
    scanf("%ld", &loc);
    if(fseek(fp, loc*sizeof(double), SEEK_SET)){
        printf("Seek error. \n");
        exit(1);
    }

    fread(&value, sizeof(double), 1, fp);
    printf("Element %ld is %f", loc, value);
    fclose(fp);*/
//------------------------------------------------------------------------------------------------------------------------------------------

    FILE *fp;
    int n, even, uneven;

    printf("Choose a number: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter numbers: ");
    for(int i=0; i<n; i++) {
        scanf("%d ", &nums[i]);
    }

    /* отваряне на файл за изход */
    if(fp = fopen("binEx.bin", "wb")==NULL){
        printf("Cannot open file. \n");
        exit(1);
    }

    //записва n във файла
    fwrite(&n,sizeof(int),1,fp);

    //записва nums във файла
    fwrite(nums,sizeof(int),n,fp);

    fclose(fp);


    for(int i=0;i<n;i++){
        if(nums[i]%2==0) even+=1;
    }
    printf("Even: %d", even);

    for(int i=0;i<n;i++){
        if(nums[i]%2==1) uneven+=1;
    }
    printf("Even: %d",even);
    //---------------

    /*чете от файла и записва в b */
    /*if(fread(&b,sizeof(int),1,fp)!=1){
        printf("read error occurred");
        exit(7);
    }*/

    /* чете от файла и записва в масива nums1 */
    /*if(fread(nums1,1,(sizeof nums1)-1,fp)!=((sizeof nums1)-1)){
        printf("read error occurred");
        exit(6);
    }
    fclose(fp);*/

     /* отпечатва информацията последователно на екрана*/
    /*for(i=0; i<(sizeof mas1)-1; i++)
    printf("%c",nums1[i]);
    printf("%d",b);
    for(i=0; i<(sizeof mas3)-1; i++) printf("%c",mas3[i]);*/
//-----------




    return 0;
}


