#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int a, b, c, Res;
    char continueFlag = 'y';
    
    do {
        printf("Input numbers:\n");
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        
        double x1, x2;
        Res = b * b - 4 * a * c;
        printf("Diskrimenant: %d\n", Res);
        
        if (Res < 0)
            printf("Korney net\n");
        else if (Res == 0) {
            x1 = (-b - sqrt(Res)) / (2 * a);
            printf("x1=%.2lf\n", x1);
        } else {
            x1 = (-b - sqrt(Res)) / (2 * a);
            x2 = (-b + sqrt(Res)) / (2 * a);
            printf("x1=%.2lf\nx2=%.2lf\n", x1, x2);
        }
        
        printf("Continue? (y/n): ");
        scanf(" %c", &continueFlag);
    } while (continueFlag == 'y');
    
    return 0;
}
