#include <stdio.h>


void Temperatures(double tem);

int main(void) {
    printf("Enter temp in C: \n");
    printf("Or press q to exit\n")
    double celc;
    int input=scanf("%lf", &celc);
    while (input==1) {
        Temperatures(celc);
        scanf("%lf", &celc);
    }
}

void Temperatures(double tem) {

    const double far = (tem*9/5)+32;
    const double kelv = tem+273.16;
    printf("temp F = %.2f\n", far);
    printf("temp K = %.2f\n", kelv);
    printf("Enter temp in F: \n");

}
