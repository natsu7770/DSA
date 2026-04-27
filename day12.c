#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int a[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    if (m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }

    int isSymmetric = 1;
    for (int i = 0; i < n && isSymmetric; i++) {
        for (int j = i + 1; j < n && isSymmetric; j++) {
            if (a[i][j] != a[j][i])
                isSymmetric = 0;
        }
    }

    printf("%s\n", isSymmetric ? "Symmetric Matrix" : "Not a Symmetric Matrix");
    return 0;
}