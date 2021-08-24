#include <stdio.h>


void Temperatures(double tem);

int main(void) {
    printf("Enter temp in F: \n");
    double far;
    int input=scanf("%lf", &far);
    while (input==1) {
        Temperatures(far);
        scanf("%lf", &far);
    }
}

void Temperatures(double tem) {

    const double celc = 5.0/9.0*(tem-32.0);
    const double kelv = celc+273.16;
    printf("temp C = %.2f\n", celc);
    printf("temp K = %.2f\n", kelv);
    printf("Enter temp in F: \n");

}
