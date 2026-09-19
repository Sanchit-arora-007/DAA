#include <stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};

int main() {
    struct Item a[100], temp;
    int n, capacity, i, j;
    float totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight and profit of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &a[i].weight, &a[i].profit);
        a[i].ratio = (float)a[i].profit / a[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    // Sort according to profit/weight ratio
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i].ratio < a[j].ratio) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    // Select items
    for (i = 0; i < n; i++) {
        if (capacity >= a[i].weight) {
            capacity -= a[i].weight;
            totalProfit += a[i].profit;
        }
        else {
            totalProfit += a[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum Profit = %.2f", totalProfit);

    return 0;
}