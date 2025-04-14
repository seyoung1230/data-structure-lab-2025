#include <cstdio>
#include <climits>

int main() {
    int n;

    printf("입력할 정수의 개수를 입력하세요: ");
    if (scanf_s("%d", &n) != 1 || n < 1 || n > 100) {
        return 1;
    }

    int arr[100];

    printf("%d개의 정수를 입력하세요:\n", n);
    for (int i = 0; i < n; ++i) {
        if (scanf_s("%d", &arr[i]) != 1) {
            return 1;
        }
    }

    int maxValue = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    printf("최댓값은: %d\n", maxValue);

    return 0;
}