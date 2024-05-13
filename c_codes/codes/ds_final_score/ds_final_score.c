#include <stdio.h>

int main() {
    /*int num1, num2, sum;
    
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    sum = num1 + num2;
    
    printf("Sum: %d\n", sum);
    
    return 0;*/
    float a, b, c, d, e, f;
    printf("Enter the marks: (final exam)");
    scanf("%f",&a);
    printf("Enter the marks: (quiz)");
    scanf("%f %f",&b,&c);
    printf("Enter the marks: (ass(scaled))");
    scanf("%f %f %f",&d,&e,&f);
    
    a = a/120*0.5;
    b = b/120*0.1;
    c = c/120*0.1;
    d = d*0.01;
    e = e*0.01;
    f = f*0.01;
    printf("Final marks are %f",(a+b+c+d+e+f));
    return 0;
}

