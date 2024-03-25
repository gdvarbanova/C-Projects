/*#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void input(int *array, unsigned len){
    for(int i=0;i<len;++i){
        array[i] = rand()%50-10;
    }
}

void output(int array[], unsigned len){
    for(int i=0;i<len;++i){
        printf("%d ",array[i]);
    }
    printf("\n");
}

void move(int *array, unsigned len, int start){
    for(int i=len;i>start;--i){
        array[i] = array[i-1];
    }
}

unsigned extend(int *array, unsigned len){
    for(int i=0;i<len;++i){
        if(array[i]%2==0){
            array = (int*)realloc(array, (len+1)*sizeof(int));
            if(array==NULL){
                perror("Realloc error: ");
                exit(EXIT_FAILURE);
            }
            move(array,len,i);
            array[i+1] = array[i]+1;
            len++;i++;
        }
    }
    return len;
}
int main()
{
    int *array;
    unsigned len;

    srand(time(NULL));

    array = (int*)malloc(SIZE*sizeof(int));
    if(array==NULL){
        perror(NULL);
        exit(EXIT_FAILURE);
    }

    input(array,SIZE);
    output(array,SIZE);
    len = extend(array,SIZE);
    output(array,len);

    free(array);


    /*int *p, *q;
    p = (int *) malloc (5 * sizeof (int));
    p[0] = 2;
    p[1] = 4;
    p[2] = 6;
    p[3] = 8;
    p[4] = 10;
    q = (int *) malloc (10 * sizeof (int));
    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }
    free (p);
    p = q;
    q = NULL;
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", p[i]);
    }
    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char names[50];
    int id;
    double price;
    int lockerCode;
} Member;

void addMemberToFile(Member** members, int* size, FILE* file) {
    *size = *size + 1;
    Member* tmp = realloc(*members, *size * sizeof(Member));

    if (tmp == NULL) {
        printf("Err.\n");
        exit(1);
    }

    *members = tmp;

    Member* member = &(*members)[*size - 1];

    printf("Name: ");
    scanf("%s", member->names);

    printf("ID: ");
    scanf("%d", &(member->id));

    printf("Price: ");
    scanf("%lf", &(member->price));

    printf("Code: ");
    scanf("%d", &(member->lockerCode));

    int namesLength = strlen(member->names);
    fprintf(file, "%d%s;%d;%.2lf;%d;\n", namesLength, member->names, member->id, member->price, member->lockerCode);
}

int main() {
    FILE* file = fopen("membersText.txt", "w");

    if (file == NULL) {
        printf("Err.\n");
        return 1;
    }

    Member* members = NULL;
    int size = 0;

    int numMembers;
    printf("Num: ");
    scanf("%d", &numMembers);

    for (int i = 0; i < numMembers; i++) {
        addMemberToFile(&members, &size, file);

        // Check if size has changed after realloc
        if (members != NULL) {
            printf("Size of members: %d\n", size);
        }
    }

    free(members);
    fclose(file);

    return 0;
}

