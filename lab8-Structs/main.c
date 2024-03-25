#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#define GROUP_NUM 5


//example 1
  /*struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};*/


//task 1

struct Point{
    int x, y, z;
};

float findSides(struct Point p1, struct Point p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}


//task 2

/*struct Vehicle{
    char brand[20];
    float price;
    int year;
};

struct Car{
    struct Vehicle veh;
    char colour[20];
};
struct Boat{
    struct Vehicle veh;
    char colour[20];
};
struct Plane{
    struct Vehicle veh;
    char colour[20];
};*/


//task 3
/*struct Student{
    char name[40];
    char group;
    int class_num;
    float score;
};

int num_st = 0;
struct Student stu[SIZE];

void input(){
    struct Student st;
    if(num_st>SIZE) printf("Full!");

    printf("Enter name: ");
    scanf("%s", st.name);
    printf("Enter group : ");
    scanf(" %c", &st.group);
    printf("Enter number in class: ");
    scanf("%d", &st.class_num);
    printf("Enter score: ");
    scanf("%f", &st.score);

    stu[num_st++] = st;
    printf("Success!");
}

void output(){
    struct Student st;
    for(int i = 0; i<num_st; i++){
        printf("Name: %s\n Group (a, b, c, d): %c\n Class Number: %d\n Score: %.2f\n", stu[i].name, stu[i].group, stu[i].class_num, stu[i].score);
    }
}

void average_group(char group_id){
    int counter = 0;
    float sum1 = 0.0;

    for (int i = 0; i < num_st; i++){
        if (stu[i].group == group_id){
            sum1 += stu[i].score;
            counter++;
        }
    }

    if (counter > 0){
        printf("Average score for group %c: %.2f\n", group_id, sum1/counter);
    }
    else{
        printf("No students found in group %c\n", group_id);
    }
}

void average_year(){
    float sum2 = 0.0;
    for(int i=0; i<num_st; ++i){
        sum2 += stu[i].score;
    }
    printf("Average score of all students: %.2f", sum2/num_st);
}*/

int main( ) {

   /*struct Books Book1;
   struct Books Book2;

   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Spiridon Haralampiev");
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;

   // book 2 specification
   strcpy( Book2.title, "BPE materials");
   strcpy( Book2.author, "Haralampi Spiridonov");
   strcpy( Book2.subject, "Materials for BPE subject");
   Book2.book_id = 6495700;

   // print Book1 info
   printf( "Book 1 title : %s\n", Book1.title);
   printf( "Book 1 author : %s\n", Book1.author);
   printf( "Book 1 subject : %s\n", Book1.subject);
   printf( "Book 1 book_id : %d\n", Book1.book_id);

   // print Book2 info
   printf( "Book 2 title : %s\n", Book2.title);
   printf( "Book 2 author : %s\n", Book2.author);
   printf( "Book 2 subject : %s\n", Book2.subject);
   printf( "Book 2 book_id : %d\n", Book2.book_id);*/

   //task 3

   /*int choice;
   char group_id;
    do {
        printf("\n");
        printf("1. Add student\n");
        printf("2. Display all students\n");
        printf("3. Average score for group\n");
        printf("4. Average score for the year\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1: input(); break;
            case 2: output(); break;
            case 3: {
                printf("Enter group identifier (a, b, c, d): ");
                scanf(" %c", &group_id);
                average_group(group_id);
                break;
            }
            case 4: average_year(); break;
            case 5: printf("Exiting.\n"); break;
            default: printf("Invalid choice.\n");
        }
      }
    while (choice != 5);*/


    //task 1

    struct Point points[4] = {{0, 0, 0}, {1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    struct Point p1 = points[0];
    struct Point p2 = points[1];
    struct Point p3 = points[2];
    printf("%.2f",findSides(p1, p2));
    printf("\n%.2f",findSides(p2, p3));

    //task 2

    /*struct Car car1 = {"Opel", 3000, 2010, "blue"};
    struct Plane plane1 = {"A2", 10000, 2000, "yellow"};
    struct Boat boat1 = {"A2", 4500, 2000, "white"};

    if(car1.veh.year == plane1.veh.year) printf("The same");
    else printf("Not the same");
    if(plane1.veh.year == boat1.veh.year) printf("\nThe same");
    else printf("\nNot the same");*/

    return 0;
}
