#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int write = 0;

    for (int read = 0; read < n; read++) {
        if (write == 0 || arr[read] != arr[write - 1]) {
            arr[write++] = arr[read];
        }
    }

    for (int i = 0; i < write; i++) {
        if (i > 0) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}