#include <stdio.h>
#include <math.h>
#include <conio.h>
#define MAX 10

// Function prototypes
void elim(int n, float a[MAX][MAX], float b[MAX]);
int pivot(int n, float a[MAX][MAX], float b[MAX], int k);
void bsub(int n, float a[MAX][MAX], float b[MAX], float x[MAX]);

int gauss2(int n, float a[MAX][MAX], float b[MAX], float x[MAX]) {
    elim(n, a, b);
    bsub(n, a, b, x);
    return 0;
}

void elim(int n, float a[MAX][MAX], float b[MAX]) {
    int i, j, k;
    float factor;
    for (k = 1; k <= n - 1; k++) {
        pivot(n, a, b, k);
        for (i = k + 1; i <= n; i++) {
            factor = a[i][k] / a[k][k];
            for (j = k + 1; j <= n; j++) {
                a[i][j] = a[i][j] - factor * a[k][j];
            }
            b[i] = b[i] - factor * b[k];
        }
    }
}

int pivot(int n, float a[MAX][MAX], float b[MAX], int k) {
    int p, i;
    float large, temp;
    p = k;
    large = fabs(a[k][k]);
    for (i = k + 1; i <= n; i++) {
        if (fabs(a[i][k]) > large) {
            large = fabs(a[i][k]);
            p = i;
        }
    }
    if (p != k) {
        for (i = k; i <= n; i++) {
            temp = a[p][i];
            a[p][i] = a[k][i];
            a[k][i] = temp;
        }
        temp = b[p];
        b[p] = b[k];
        b[k] = temp;
    }
    return 0;
}

void bsub(int n, float a[MAX][MAX], float b[MAX], float x[MAX]) {
    int i, j;
    float sum;
    x[n] = b[n] / a[n][n];
    for (i = n - 1; i >= 1; i--) {
        sum = 0.0;
        for (j = i + 1; j <= n; j++)
            sum = sum + a[i][j] * x[j];
        x[i] = (b[i] - sum) / a[i][i];
    }
}

int main() {
    int i, j, n;
    float a[MAX][MAX], b[MAX], x[MAX];

    printf("\nInput the number of variables: ");
    scanf("%d", &n);

    printf("\nInput coefficients a(i,j), row-wise (one row on each line):\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%f", &a[i][j]);

    printf("\nEnter vector b:\n");
    for (i = 1; i <= n; i++)
        scanf("%f", &b[i]);

    gauss2(n, a, b, x);

    printf("\nSolution vector x:\n");
    for (i = 1; i <= n; i++)
        printf("\t%f\n", x[i]);

    getch();
    return 0;
}
