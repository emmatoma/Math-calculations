#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to check if a point (x, y) is inside the circle defined by the equation (x-6)^2 + (y-2)^2 < 9
bool isInCircle1(double x, double y) {
    double equation1 = pow(x - 6, 2) + pow(y - 2, 2);
    return equation1 < 9;
}

// Function to check if a point (x, y) is inside the circle defined by the equation (x-2)^2 + (y-2)^2 < 16
bool isInCircle2(double x, double y) {
    double equation2 = pow(x - 2, 2) + pow(y - 2, 2);
    return equation2 < 16;
}

int main() {
    double puntos = 1000000, puntosDentro = 0; // Number of points and points inside the desired region
    double max = 20, min = -20, x, y, area; // Maximum and minimum values for generating random points
    srand(time(NULL)); // Seed the random number generator using the current time

    // Loop to generate random points and count the number of points inside the desired region
    for (int i = 0; i < puntos; i++) {
        // Generate random x and y coordinates within the specified range
        x = (double)rand() / RAND_MAX * (max - min) + min;
        y = (double)rand() / RAND_MAX * (max - min) + min;

        // Check if the point (x, y) is inside the circle of equation 1 and not inside the circle of equation 2
        if (isInCircle1(x, y) && !isInCircle2(x, y)) {
            puntosDentro++; // Increment the count of points inside the desired region
        }
    }

    // Calculate the area using the ratio of points inside the desired region to total points
    // and multiplying it by the area of the entire region
    area = (puntosDentro / puntos) * ((max - min) * (max - min));

    // Print the calculated area
    printf("\nEl area es: %f", area);

    return 0;
}
