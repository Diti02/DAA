#include <stdio.h>
#include <stdbool.h>
int q=1;

bool isValid(int n, int g[n][n], int color[], int c, int v) {
    for (int i = 0; i < n; i++) {
        if (g[v][i] && (color[i] == c))
            return false;
    }
    return true;
}

bool graphcoloring(int n, int g[n][n], int m, int color[], int v) {
    if (v == n) {
        printf("Solution %d : ",q++);
        for (int i = 0; i < n; i++) {
            printf(" %d ", color[i]);
        }
        printf("\n");
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isValid(n, g, color, c, v)) {
            color[v] = c;
            graphcoloring(n, g, m, color, v + 1);
            color[v] = 0;
        }
    }

    return false;
}

int main() {
    FILE *fp;
    int n, m;

    fp = fopen("a.txt", "r");
    if (fp == NULL) {
        printf("File cannot be opened");
        return 1;
    }

    fscanf(fp, "%d", &n);
    int g[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fp, "%d", &g[i][j]);
        }
    }


    printf("Enter the number of colors: ");
    scanf("%d", &m);

    int color[n];
    for (int i = 0; i < n; i++)
        color[i] = 0;

    graphcoloring(n, g, m, color, 0);

    return 0;
}

