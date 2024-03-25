#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    /*double a = 10, b = 5;
    printf("a = %f",a);
    printf("\n""b = %f",b);*/

    /*int c, d;
    printf("c = ");
    scanf("%d", &c);
    printf("d = ");
    scanf("%d", &d);*/

    /*char h [50];
    printf("h = ");
    scanf("%s", &h);*/

    /*int x, y;
    printf("x = ");
    scanf("%d", &x);
    printf("y = ");
    scanf("%d", &y);
    printf("x + y = %d",x + y);
    printf("\n""x - y = %d",x - y);
    printf("\n""x * y = %d",x * y);
    printf("\n""x / y = %d",x / y);
    printf("\n""x %% y = %d",x % y);*/

    /*int a = 7, b = 23;
    printf("\n""dec a = %d", --a);
    printf("\n""inc a = %d", ++a);
    printf("\n""dec b = %d", --b);
    printf("\n""inc b = %d", ++b);*/


    /*char sym;
    printf("\n""sym = ");
    scanf("%c", &sym);
    printf("ascii = %d", (int)sym);
    int num;
    printf("\n""num = ");
    scanf("%d", &num);
    printf("ascii = %c", (char)num);*/

    //getchar();
    //putchar();
    //sizeof

    /*int x, y;
    printf("x = ");
    scanf("%d", &x);
    if(x>0) {
        y = 2*(x*x)+10;
        printf("y = %d", y);
    }
        if(x<0){
            y = 2*x;
            printf("y = %d", y);
        }
    else printf("x = 0, no operation");*/


    /*
    int -> %d
    float -> %f
    double -> %lf
    char -> %c
    string -> %s
    osmichno chislo -> %o
    shestnadesettichno chislo -> %x
    */

    float a, b, c, P, S;
    printf("a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);
    printf("c = ");
    scanf("%f", &c);
    P = a + b + c;
    float p = P/2;
    S = sqrt(p*(p-a)*(p-b)*(p-c));
    if(S == 0){
        printf("Invalid sides of a triangle.");
        if(a == 0 || b == 0 || c == 0)
            {
            printf("Invalid sides of a triangle.");
            if((a+b)<c || (a+c)<b || (b+c)<a) printf("Invalid sides of a triangle.");
        }
    }
    else{
        printf("P = %.2f %s", P, "cm");
        printf("\n""S = %.2f %s", S, "cm");
        if(a == b && b == c && c == a) printf("\n""You have an acute equilateral triangle (ostrougulen ravnostranen).");
        else if (((a == b)&&(c!=a)&&(c!=b)) || ((b == c)&&(a!=b)&&(a!=c)) || ((a == c)&&(b!=a)&&(b!=c))){
             if (a*a + b*b == c*c) printf("\n""You have a right isosceles triangle (pravougulen ravnobedren).");
             else if(a*a + b*b < c*c) printf("\n""You have an obtuse isosceles triangle (tupougulen ravnobedren).");
        }
        else{
            printf("\n""You have an acute isosceles triangle (ostrougulen ravnobedren).");
            if((a!=b) && (b!=c) && (a!=c)){
                if(a*a + b*b == c*c)printf("\n""You have a right scalene triangle (pravougulen raznostranen).");
                if(a*a + b*b < c*c) printf("\n""You have an obtuse scalene triangle (tupougulen raznostranen).");
            }
            else printf("\n""You have an acute scalene triangle (ostrougulen raznostranen).");
        }
    }
    //printf("\n" "%lu\n", sizeof(float));

    //display numbers between two numbers
    /*int a, b, i;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    printf("numbers between %d and %d: ", a, b);
    for(i=a+1; i<b; ++i){
        printf("%d ", i);
    }*/


    return 0;
}
