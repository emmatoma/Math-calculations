#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    double radius = 1.0;
    double hypervolume_prev = 0.0;
    double hypervolume_current = 0.0;
    
    for (int d = 2; d <= 22; d++) {
        hypervolume_current = pow(radius, d) * pow(PI, d/2.0) / tgamma(d/2.0 + 1);
        printf("Dimension: %d, Hypervolume: %lf\n", d, hypervolume_current);
        if (hypervolume_prev > hypervolume_current) {
            printf("Hypervolumen se reduce a apartir de la dimension %d\n", d);
            break;
        }
        hypervolume_prev = hypervolume_current;
    }
    
    return 0;
}