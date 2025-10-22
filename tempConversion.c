#include <stdio.h>

double toCels(double value, char from) {
    switch (from) {
        case 'C': return value;
        case 'F': return (value - 32.0) * (5.0 / 9.0); // F to C
        case 'K': return value - 273.15; // K to C
    }
}

double fromCels(double c, char to) {
    switch (to) {
        case 'C': return c;
        case 'F': return c * 9.0 / 5.0 + 32.0; // C to F
        case 'K': return c + 273.15; // K to F
    }
}

void categorize(double c) {
    // categorize the temperature in celsius with a message
    if (c < 0.0) {
        printf("Temperature Category: Freezing\n");
        printf("Weather Advisory: Wear winter clothing\n");
    } else if (c < 10.0) {
        printf("Temperature Category: Cold\n");
        printf("Weather Advisory: Wear a jacket.\n");
    } else if (c < 25.0) {
        printf("Temperature Category: Comfortable\n");
        printf("Weather Advisory: Wear a T-shirt and shorts\n");
    } else if (c < 35.0) {
        printf("Temperature Category: Hot\n");
        printf("Weather Advisory: Drink water and stay cool.\n");
    } else {
        printf("Temperature Category: Extreme Heat\n");
        printf("Weather Advisory: Stay in the shade or indoors, make sure to stay hydrated\n");
    }
}

int main() {
    double value;
    char from;
    char to;

    // get temp value and fromScale and toScale from user
    printf("\nEnter the temperature value: ");
    scanf("%lf", &value);
    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &from);
    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &to);

    // convert to celsius
    double c = toCels(value, from);
    // then convert to target unit
    double target = fromCels(c, to);
    // print messages to console
    printf("Converted temperature: %.2f %c\n", target, to);
    categorize(c);

    return 0;
}