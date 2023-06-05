#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define NAME_LEN 56
#define ID_LEN 7

typedef struct{
    char name[NAME_LEN];
    char id[ID_LEN];
    float price;
    int code;
} Member;

void addMemberToFile(Member **members, unsigned *size) {
    // Expand the array by one element
    *size = *size + 1;
    *members = realloc(*members, *size * sizeof(Member));

    if (members == NULL) {
        printf("Error expanding.\n");
        exit(1);
    }

    // Get the reference to the new member
    Member *member = &(*members)[*size - 1];

    // member information
    printf("Name: ");
    fgets(member->name, NAME_LEN, stdin);
    fflush(stdin);
    member->name[strlen(member->name)-1] = '\0';

    printf("ID: ");
    fgets(member->id, ID_LEN, stdin);
    fflush(stdin);

    printf("Membership Price: ");
    scanf("%f", &(member->price));
    fflush(stdin);

    while (true) {
        printf("Locker code: ");
        scanf("%d", &(member->code));
        fflush(stdin);

        if (member->code > 99 && member->code < 1000) {
            break;
        }
        else {
            printf("Invalid input for locker code! Please enter a 3-digit number.\n");
        }
    }

    // Write to the file
    int nameLength = strlen(member->name);
    FILE *f;
    if((f=fopen("membersText.txt", "a"))==NULL){
        perror("Open file error.");
        exit(14);
    }
    fprintf(f, "%d; %s; %s; %.2f; %d\n", nameLength, member->name, member->id, member->price, member->code);
    fclose(f);
}

void average(Member members[], unsigned size){
    float sum = 0.00;
    bool flag = false;
    for(int i=0; i<size; ++i){
        sum += members[i].price;
    }
    float avg = sum/size;
    for(int i=0; i<size; ++i){
        if(members[i].price < avg){
            flag = true;
            printf("%s - %s - %.2f\n", members[i].name, members[i].id, members[i].price);
        }
    }
    if(!flag) printf("No such members!\n");
}

void writeToBin(Member members[],unsigned len)
{
    FILE *f = fopen("membersBin.bin","wb");
    unsigned size;

    if(f==NULL){
        perror("Write error: ");
        exit(3);
    }
    for(int i=0;i<len;++i){
        size = strlen(members[i].name);
        fwrite(&size,sizeof(unsigned),1,f);
        fwrite(members[i].name,sizeof(char),size,f);
        fwrite(members[i].id,sizeof(char),ID_LEN-1,f);
        fwrite(&members[i].price,sizeof(float),1,f);
        fwrite(&members[i].code, sizeof(int),1,f);

    }
    fclose(f);
}

void printMemberByID(char id[]){
    FILE *f;
    unsigned len;
    Member member;
    bool memberFound = false;

    if((f=fopen("membersBin.bin","rb"))==NULL){
        perror("Open Bin error: ");
        exit(2);
    }

    while(true){
         if(fread(&len,sizeof(unsigned),1,f)!=1){
            if(!feof(f)){
                perror("Reading bin error: ");
                fclose(f);
                exit(1);
            }
            else break;
        }
        if(fread(&member.name,sizeof(char),len,f)!=len){
            perror("Reading bin error: ");
            fclose(f);
            exit(1);
        }
        member.name[len]='\0';
        if(fread(&member.id,sizeof(char),ID_LEN-1,f)!=ID_LEN-1){
            perror("Reading bin error: ");
            fclose(f);
            exit(1);
        }
        member.id[ID_LEN-1]='\0';
        if(fread(&member.price,sizeof(float),1,f)!=1){
            perror("Reading bin error: ");
            fclose(f);
            exit(13);
        }
        if(fread(&member.code,sizeof(int),1,f)!=1){
            perror("Reading bin error: ");
            fclose(f);
            exit(3);
        }
        if(strncmp(member.id,id, ID_LEN-1)==0){
            memberFound = true;
            printf("Member with ID %s is:\n", id);
            printf("Bin Name: %s\nBin ID: %s\nBin M_Price: %.2f\nBin Locker code: %d\n", member.name, member.id, member.price, member.code);
            break;
        }
    }
    if (!memberFound) {
        printf("Member with ID %s not found.\n", id);
    }
    fclose(f);

}

void findMemberByPrice(Member members[], unsigned size, float price){
    bool flag = false;

    for(int i=0;i<size;++i){
        if(members[i].price==price){
            flag = true;
            printf("Member paying %.2f is:\n %s - %s\n",price, members[i].name,members[i].id);
        }
    }
    if(!flag){
        puts("Not found!\n");
    }
}

void sortByName(Member members[], unsigned size) {
    //bubble sort
    /*for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(members[j].name, members[j + 1].name) > 0) {
                // Swap members[j] and members[j + 1]
                Member temp = members[j];
                members[j] = members[j + 1];
                members[j + 1] = temp;
            }
        }
    }*/
    //selection sort
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (strcmp(members[j].name, members[i].name) < 0) {
                // Swap the current element with the next element
                Member temp = members[i];
                members[i] = members[j];
                members[j] = temp;
            }
        }
    }


    //print sorted
    printf("Sorted by name: \n\n");
    for(int i = 0; i < size; ++i) {
        printf("Name: %s\nID: %s\nMembership Price: %.2f\nLocker code: %d\n\n",
            members[i].name, members[i].id, members[i].price, members[i].code);
    }
}

void sortByPrice(Member members[], unsigned size){
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (members[j].price < members[i].price) {
                // Swap the current element with the next element
                Member temp = members[i];
                members[i] = members[j];
                members[j] = temp;
            }
        }
    }
    printf("Sorted by price: \n\n");
    for(int i = 0; i < size; ++i) {
        printf("Name: %s\nID: %s\nMembership Price: %.2f\nLocker code: %d\n\n",
            members[i].name, members[i].id, members[i].price, members[i].code);
    }
}

void sortByID(Member members[], unsigned size){
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (strncmp(members[j].id, members[i].id, ID_LEN-1)<0) {
                // Swap the current element with the next element
                Member temp = members[i];
                members[i] = members[j];
                members[j] = temp;
            }
        }
    }
    printf("Sorted by ID: \n\n");
    for(int i = 0; i < size; ++i) {
        printf("Name: %s\nID: %s\nMembership Price: %.2f\nLocker code: %d\n\n",
            members[i].name, members[i].id, members[i].price, members[i].code);
    }
}

void swapCode(Member members[], unsigned size){
    Member min = members[0];
    Member max = members[0];
    for(int i = 0; i<size; ++i){
        if(members[i].price<min.price) min = members[i];
    }
    for(int i = 0; i<size; ++i){
        if(members[i].price>max.price) max = members[i];
    }
    printf("Before swap:\n\n");
    printf("Highest price member:\n %s - %s - %.2f - %d\n", max.name, max.id, max.price, max.code);
    printf("Lowest price member:\n %s - %s -  %.2f - %d\n\n", min.name, min.id, min.price, min.code);

    Member temp = min;
    min.code = max.code;
    max.code = temp.code;
    printf("After swap:\n\n");
    printf("Highest price member:\n %s - %s - %.2f - %d\n", max.name, max.id, max.price, max.code);
    printf("Lowest price member:\n %s - %s -  %.2f - %d\n", min.name, min.id, min.price, min.code);
}

void changeCodeByName(Member members[], unsigned size, char name[]){
    bool flag = false;
    for(int i=0; i<size; ++i){
        if(strcmp(members[i].name, name)==0){
            printf("Enter a new locker code for %s: ", name);
            scanf("%d", &(members[i].code));
            fflush(stdin);
            flag = true;
            printf("%s - %s - %.2f - %d\n", members[i].name, members[i].id, members[i].price, members[i].code);
            break;
        }
    }
    if (!flag) printf("Member with name '%s' not found.\n", name);
}

int main()
{
    Member *members = malloc(sizeof(Member));
    unsigned size = 0;
    const unsigned NUM_MEMBERS = 3;

    for(int i=0; i<NUM_MEMBERS; ++i){
        addMemberToFile(&members, &size);
    }
    puts("---------------------------------\n");
    average(members, NUM_MEMBERS);
    puts("---------------------------------\n");
    writeToBin(members, NUM_MEMBERS);
    findMemberByPrice(members, NUM_MEMBERS, 30.50);
    puts("---------------------------------\n");
    printMemberByID("AA1234");
    puts("---------------------------------\n");
    sortByName(members, NUM_MEMBERS);
    puts("---------------------------------\n");
    sortByPrice(members, NUM_MEMBERS);
    puts("---------------------------------\n");
    sortByID(members, NUM_MEMBERS);
    puts("---------------------------------\n");
    swapCode(members, NUM_MEMBERS);
    puts("---------------------------------\n");
    char name[NAME_LEN];
    printf("Enter a name to change their locker code: ");
    fgets(name, NAME_LEN, stdin);
    fflush(stdin);
    name[strlen(name)-1] = '\0';
    changeCodeByName(members, NUM_MEMBERS,name);
    free(members);
    return 0;
}

