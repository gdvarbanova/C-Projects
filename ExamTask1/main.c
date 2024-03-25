#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define NAME_LEN 31
#define CHIP_LEN 8

typedef struct{
    char name[NAME_LEN];
    char chip[CHIP_LEN];
    float price;
}Pet;

Pet petInput(void){
    Pet pet;
    FILE *f;

    printf("Name: ");
    fgets(pet.name,NAME_LEN,stdin);
    fflush(stdin);
    pet.name[strlen(pet.name)-1]='\0';
    printf("Chip: ");
    fgets(pet.chip,CHIP_LEN,stdin);
    fflush(stdin);
    printf("Price: ");
    scanf("%f",&pet.price);
    fflush(stdin);
    if((f=fopen("animalsText.txt","a"))==NULL) {
        perror("Open error: ");
        exit(1);
    }
    fprintf(f,"%s,%.2f\n",pet.name,pet.price);
    fclose(f);
    return pet;
}

void findPetPrice(Pet pets[],unsigned arr_len,float price)
{
    bool flag = false;

    for(int i=0;i<arr_len;++i){
        if(pets[i].price==price){
            flag = true;
            printf(" %s - %s\n",pets[i].name,pets[i].chip);
        }
    }
    if(!flag){
        puts("Not found!\n");
    }
}

void printPets(float price)
{
    FILE *f;
    unsigned len;
    Pet pet;
    bool isFirst = true;

    if((f=fopen("animalsBin.bin","rb"))==NULL){
        perror("Open Bin error: ");
        exit(2);
    }

    while(true){
        if(fread(&len,sizeof(unsigned),1,f)!=1){
            if(!feof(f)){
                perror("Reading bin error: ");
                fclose(f);
                exit(1);
            }else
                break;
        }
        if(fread(&pet.name,sizeof(char),len,f)!=len){
            perror("Reading bin error: ");
            fclose(f);
            exit(1);
        }
        pet.name[len]='\0';
        if(fread(&pet.chip,sizeof(char),CHIP_LEN-1,f)!=CHIP_LEN-1){
            perror("Reading bin error: ");
            fclose(f);
            exit(1);
        }
        pet.chip[CHIP_LEN-1]='\0';
        if(fread(&pet.price,sizeof(float),1,f)!=1){
            perror("Reading bin error: ");
            fclose(f);
            exit(13);
        }
        if(pet.price>=price){
            if(!isFirst){
                puts("----------\n");
            }
            else{
                isFirst=false;
                printf("Bin Owner Name: %s\n",pet.name);
                printf("Bin Chip: %s\n",pet.chip);
                printf("Bin Price: %.2f\n",pet.price);
            }
        }
    }
    fclose(f);
}


int main()
{
    Pet pets[NAME_LEN];
    const unsigned SIZE = 3;
    for(int i = 0;i<SIZE;++i){
        pets[i] = petInput();
    }
    findPetPrice(pets,SIZE,22.22);
    writeToBin(pets,SIZE);
    printPets(25);
    return 0;
}

void writeToBin(Pet pets[],unsigned len)
{
    FILE *f = fopen("animalsBin.bin","wb");
    unsigned size;

    if(f==NULL){
        perror("Write error: ");
        exit(3);
    }
    for(int i=0;i<len;++i){
        size = strlen(pets[i].name);
        fwrite(&size,sizeof(unsigned),1,f);
        fwrite(pets[i].name,sizeof(char),size,f);
        fwrite(pets[i].chip,sizeof(char),CHIP_LEN-1,f);
        fwrite(&pets[i].price,sizeof(float),1,f);
    }
    fclose(f);
}
