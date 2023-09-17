#include <stdio.h>
#include <math.h>
#include <conio.h>

float f(float x)
{
    return 3 * x * exp(x) - cos(x);
}

 int main()
 {
     float a,h,fd1,fd2;
     char q;
     do{
        printf("\nEnter the point at which derivatives are required: ");
        scanf("%f",&a);
        printf("\nEnter the value of h: ");
        scanf("%f",&h);
        fd1= (f(a+h)-f(a-h))/(2*h);
        fd2=(f(a+h)-2*f(a)+f(a-h))/(h*h);
        printf("\nTHe first and second derivative at x=%f are %f and %f respectively",a,fd1,fd2);
        printf("\nDo you want to input another values?(y/n)");
        scanf("%c",&q);
     }
     while(q=='y');
     getch();
     return 0;
 }
