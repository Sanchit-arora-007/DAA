#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {

    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;

    if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);
1qa
    return binarySearch(arr, mid + 1, high, key);
}

int main() {

    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements in sorted order:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
        printf("%d found at index %d.\n", key, result);
    else
        printf("%d not found in the array.\n", key);

    return 0;
}