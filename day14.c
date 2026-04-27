#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    int isIdentity = 1;
    for (int i = 0; i < n && isIdentity; i++) {
        for (int j = 0; j < n && isIdentity; j++) {
            if (i == j && a[i][j] != 1) isIdentity = 0;
            if (i != j && a[i][j] != 0) isIdentity = 0;
        }
    }

    printf("%s\n", isIdentity ? "Identity Matrix" : "Not an Identity Matrix");
    return 0;
}