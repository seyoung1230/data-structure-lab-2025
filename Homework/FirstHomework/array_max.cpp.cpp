#include <cstdio>
#include <climits>

int main() {
    int n;

    printf("�Է��� ������ ������ �Է��ϼ���: ");
    if (scanf_s("%d", &n) != 1 || n < 1 || n > 100) {
        return 1;
    }

    int arr[100];

    printf("%d���� ������ �Է��ϼ���:\n", n);
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

    printf("�ִ���: %d\n", maxValue);

    return 0;
}