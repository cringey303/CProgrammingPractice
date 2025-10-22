#include <stdio.h>

int isValidScale(char scale) {
    return (scale == 'C' || scale == 'F' || scale == 'K');
}

double toCels(double value, char from) {
    switch (from) {
        case 'C': return value;
        case 'F': return (value - 32.0) * (5.0 / 9.0); // F to C
        case 'K': return value - 273.15; // K to C
        default: return -1000.0; // Error value
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
    char from, to;
    int scanResult;

    while (1) {
        // get temp value
        printf("\nEnter the temperature value (or enter 'q' to quit): ");
        scanResult = scanf("%lf", &value);
        
        // Check for quit condition or invalid input
        if (scanResult != 1) {
            char check;
            scanf(" %c", &check);
            if (check == 'q' || check == 'Q') {
                printf("Exiting program.\n");
                return 0;
            }
            printf("Error: Invalid temperature value. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        // Get original scale
        printf("Enter the original scale (C, F, or K): ");
        scanf(" %c", &from);
        from = toupper(from); // Convert to uppercase for consistency

        if (!isValidScale(from)) {
            printf("Error: Invalid temperature scale. Please use C, F, or K.\n");
            while (getchar() != '\n');
            continue;
        }

        // Check for physically impossible temperatures
        if ((from == 'K' && value < 0) || 
            (from == 'C' && value < -273.15) || 
            (from == 'F' && value < -459.67)) {
            printf("Error: Temperature below absolute zero is physically impossible.\n");
            continue;
        }

        // Check for unreasonably high temperatures
        if (value > 1000000) { // arbitrary limit for demonstration
            printf("Error: Temperature value is unreasonably high.\n");
            continue;
        }

        // Get target scale
        printf("Enter the scale to convert to (C, F, or K): ");
        scanf(" %c", &to);
        to = toupper(to);

        if (!isValidScale(to)) {
            printf("Error: Invalid temperature scale. Please use C, F, or K.\n");
            while (getchar() != '\n');
            continue;
        }

        // convert to celsius
        double c = toCels(value, from);
        
        // Check for conversion error
        if (c == -1000.0) {
            printf("Error: Conversion failed.\n");
            continue;
        }
        
        // convert to target unit
        double target = fromCels(c, to);
        
        // print messages to console
        printf("\nConversion Results:\n");
        printf("Original temperature: %.2f %c\n", value, from);
        printf("Converted temperature: %.2f %c\n", target, to);
        categorize(c);
        printf("\n");
    }

    return 0;
}