#include <stdio.h>

int main() {
    printf("Enter the NFL score (Enter 1 to stop): ");
    int target;
    scanf("%d", &target);

    int comboCount = 0;
    if (target == 1) {
        return 0;
    } else {
        printf("Possible combinations of scoring plays if a team’s score is %d", &target);
        calcCombo(target, 0,0,0,0,0,8, &comboCount);
    }

    return 0;
}

// recursive function to calculate and print all score combinations
void calcCombo(int remaining, int td8, int td7, int td6, int fg3, int safety2, int minScore, int* comboCount) {
    // no score remaining
    if (remaining == 0) {
        *comboCount++;
        printCombo(td8, td7, td6, fg3, safety2);
        return;
    }
    // overshot
    if (remaining < 0) {
        return;
    }

    // recursive steps
    // try adding td8
    if (remaining >= 8 && minScore >= 8) {
        calcCombo(remaining-8, td8+1, td7, td6, fg3, safety2, 8, comboCount);
    }
    // try adding td7
    if (remaining >= 7 && minScore >= 7) {
        calcCombo(remaining-7, td8, td7+1, td6, fg3, safety2, 7, comboCount);
    }
    // try adding td6
    if (remaining >= 6 && minScore >= 6) {
        calcCombo(remaining-6, td8, td7, td6+1, fg3, safety2, 6, comboCount);
    }
    // try adding fg3
    if (remaining >= 3 && minScore >= 3) {
        calcCombo(remaining-3, td8, td7, td6, fg3+1, safety2, 3, comboCount);
    }
    // try adding safety2
    if (remaining >= 2 && minScore >= 2) {
        calcCombo(remaining-2, td8, td7, td6, fg3, safety2+1, 2, comboCount);
    }

}

void printCombo(int td8, int td7, int td6, int fg3, int safety2) {
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety", &td8, &td7, &td6, &fg3, &safety2);
}