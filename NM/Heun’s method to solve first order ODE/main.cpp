#include <stdio.h>
#include <math.h>
#include <conio.h>
float f(float x, float y){
return 3*x*x + 1;
}
int main(){
int i, n;
float x, y, xp, h, m1, m2;
printf("\nInput initial values of x and y: ");
scanf("%f%f", &x, &y);
printf("\nInput x at which y is required: ");
scanf(" %f", &xp);
printf("\nInput step-size h: ");
scanf("%f", &h);
n=(int)((xp-x)/h+0.5);
for(i=1;i<=n;i++){
  m1=f(x,y);
  m2=f(x+h, y+m1*h);
  x=x+h;
  y=y+0.5*h*(m1+m2);
  printf("\n%d \t %f \t %f\n", i, x, y);
}
printf("\nValue of y at x = %f is %f", x, y);
getch();
return 0;
}
