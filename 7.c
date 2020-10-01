#include <stdio.h>
#include <string.h>

int main() {
    int a[] = { 5, 10, 12, 13, 15, 18 };
    int i, sum, p = 30, sizeofa = sizeof(a) / sizeof(int), sizepow = 1 << sizeofa;
    char b[sizeofa * 7 + 1], temp[7];
    printf("Initial array is: ");
    for (i = 0; i < sizeofa; i++) { printf("%d ", a[i]); }
    printf("\nThe pairs whose sum is 30 are:\n", p);
    for (i = 0; i < sizepow; i++) {
        sum = 0;
        b[0] = '\0';
        for (int j = 0; j < sizeofa; j++) {
            if (i & (1 << j)) {
                sum = sum + a[j];
                temp[0] = '\0';
                sprintf(temp, "%d ", a[j]);
                strcat(b, temp);
                if (sum > p) { continue; }
            }
        }
        if (sum == p) {
            puts(b);
        }
    }
    return 0;
}