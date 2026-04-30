#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sort(arr, n);

    int left = 0, right = n - 1;
    int bestL = left, bestR = right;
    int bestSum = abs(arr[left] + arr[right]);

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (abs(sum) < bestSum) {
            bestSum = abs(sum);
            bestL = left;
            bestR = right;
        }
        if (sum < 0)      left++;
        else if (sum > 0) right--;
        else              break;
    }

    printf("%d %d\n", arr[bestL], arr[bestR]);
    return 0;
}