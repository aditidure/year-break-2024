#include <stdio.h>

//#define MAX_SIZE 20 // Maximum size of the input array

void printCombination(int arr[], int data[], int start, int end, int index, int r) {
    // Current combination is ready to be printed, print it
    if (index == r) {
        for (int i = 0; i < r; ++i)
            printf("arr[%d] = %d ", data[i],arr[data[i]]);
        printf("\n");
        return;
    }

    // Replace index with all possible elements. The condition end-i+1 >= r-index
    // makes sure that including one element at index will make a combination with
    // remaining elements at remaining positions
    for (int i = start; i <= end && end - i + 1 >= r - index; ++i) {
        data[index] = i;
        printCombination(arr, data, i+1, end, index+1, r);
    }
}

void generateCombinations(int arr[], int n, int r) {
    int data[r]; // Temporary array to store the combination
    printCombination(arr, data, 0, n-1, 0, r);
}

int main() {
    
    int n, r;

    printf("Enter the number of elements (n): ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of elements to choose (r): ");
    scanf("%d", &r);

    printf("All possible combinations of %d elements taken %d at a time:\n", n, r);
    generateCombinations(arr, n, r);

    return 0;
}

