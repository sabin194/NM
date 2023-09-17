#include<stdio.h>
#include<math.h>
#include<conio.h>
#define EPS 0.00001

float f(float x){
    return sin(x) - 2*x + 1;
}

int main(){
    float a,b,c;
    int n=0;
    do{
        printf("Enter two valid initial points a and b:\n");
        scanf("%f%f",&a,&b);
    }
    while (f(a)*f(b)>=0);

    do{
        n++;
        c=(a+b)/2;
        if(f(c)==0)break;
        if(f(a)*f(c)<0)b=c;
        else a=c;
    }

    while (fabs((b-a)/a)>EPS);
    printf("The approximate root of given function is %f with %d number of iterations.",c,n);
    getch();
    return 0;
}
