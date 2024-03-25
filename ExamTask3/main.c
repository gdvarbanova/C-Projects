#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define NAME_LEN 35
#define NUM_LEN 9

typedef struct{
    char name[NAME_LEN];
    char num[NUM_LEN];
    float price;
    int priority;
}Car;

void inputCar(Car **cars_arr, unsigned *size){
    *size = *size + 1;
    *cars_arr = realloc(*cars_arr, *size * sizeof(Car));
    if(cars_arr==NULL){
        perror("Error expanding");
        exit(1);
    }
    Car *car = &(*cars_arr)[*size-1];
    printf("Name: ");
    fgets(car->name, NAME_LEN, stdin);
    fflush(stdin);
    car->name[strlen(car->name)-1]='\0';

    printf("Registration number: ");
    fgets(car->num, NUM_LEN, stdin);
    fflush(stdin);

    printf("Repair Price: ");
    scanf("%f", &(car->price));
    fflush(stdin);

    while(true){
        printf("Priority(1-5): ");
        scanf("%d", &(car->priority));
        fflush(stdin);

        if (car->priority > 0 && car->priority < 6) {
            break;
        }
        else {
            printf("Invalid input. Try again!\n");
        }
    }

    int nameLen = strlen(car->name);
    FILE *f;
    if((f=fopen("autoText.txt", "a")) == NULL){
        perror("Error opening file!");
        exit(2);
    }
    fprintf(f,"%d; %s; %s; %.2f; %d\n", nameLen, car->name, car->num, car->price, car->priority);
    fclose(f);
}

void aboveAverage(Car cars_arr[], unsigned size){
    float sum = 0.00;
    bool flag = false;

    for(int i = 0; i<size; ++i){
        sum+=cars_arr[i].price;
    }
    float avg = sum/size;
    for(int i=0; i<size; ++i){
        if(cars_arr[i].price>avg){
            flag = true;
            printf("%s - %.2f\n", cars_arr[i].name, cars_arr[i].price);
        }
    }
    if(!flag) puts("No car owners pay above average!\n");
}

void findCarByNum(char num[]){
    FILE *f;
    unsigned len;
    bool isFound = false;
    Car car;

    if((f=fopen("autoBin.bin", "rb"))==NULL){
        perror("Open bin error!");
        exit(3);
    }
    while(true){
        if(fread(&len, sizeof(unsigned),1,f)!=1){
            if(!feof(f)){
                perror("Reading error!");
                fclose(f);
                exit(4);
            }
        }
        if(fread(&car.name, sizeof(char), len, f)!=len){
            perror("Reading error!");
            fclose(f);
            exit(5);
        }
        car.name[len]='\0';
        if(fread(&car.num, sizeof(char), NUM_LEN-1, f)!=NUM_LEN-1){
            perror("Reading error!");
            fclose(f);
            exit(6);
        }
        car.num[NUM_LEN-1]='\0';
        if(fread(&car.price, sizeof(float),1,f)!=1){
            perror("Reading error!");
            fclose(f);
            exit(7);
        }
        if(fread(&car.priority, sizeof(int),1,f)!=1){
            perror("Reading error!");
            fclose(f);
            exit(8);
        }
        if(strncmp(car.num, num, NUM_LEN-1)==0){
            printf("Bin Name: %s\n", car.name);
            printf("Bin L_Plate: %s\n", car.num);
            printf("Bin Price: %.2f\n", car.price);
            printf("Bin Priority: %d\n", car.priority);
            isFound = true;
            break;
        }
    }
    if(!isFound) printf("No matches for: %s\n", num);
    fclose(f);
}

void writeToBin(Car cars_arr[], unsigned size){
    unsigned nameLen;
    FILE *f = fopen("autoBin.bin", "wb");
    if(f == NULL){
        perror("Writing bin error!");
        exit(9);
    }
    for(int i=0; i<size; ++i){
        nameLen = strlen(cars_arr[i].name);
        fwrite(&nameLen, sizeof(unsigned), 1, f);
        fwrite(cars_arr[i].name, sizeof(char), nameLen, f);
        fwrite(cars_arr[i].num, sizeof(char), NUM_LEN-1, f);
        fwrite(&cars_arr[i].price, sizeof(float), 1, f);
        fwrite(&cars_arr[i].priority, sizeof(int), 1, f);
    }
    fclose(f);
}

int main()
{
    srand(time(NULL));
    Car *cars_arr = malloc(sizeof(Car));
    unsigned size = 0;
    //const unsigned NUM_CARS = 2;
    int NUM_CARS = rand() % (5-2+1) + 2;
    printf("Number of cars: %d\n\n", NUM_CARS);
    for(int i=0; i<NUM_CARS; ++i){
        inputCar(&cars_arr, &size);
    }
    puts("------------------------------\n");
    aboveAverage(cars_arr, NUM_CARS);
    puts("------------------------------\n");
    writeToBin(cars_arr, NUM_CARS);
    findCarByNum("AB1234CD");
    free(cars_arr);
    return 0;
}
