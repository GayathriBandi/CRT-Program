#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ------------------- 1. Power Functions -------------------

int power_naive(int x, int n) {
    int result = 1;
    for (int i = 0; i < n; i++)
        result *= x;
    return result;
}

int power_optimized(int x, int n) {
    if (n == 0) return 1;
    int half = power_optimized(x, n / 2);
    return (n % 2 == 0) ? half * half : x * half * half;
}

int power_binary(int x, int n) {
    int result = 1;
    while (n > 0) {
        if (n % 2 == 1)
            result *= x;
        x *= x;
        n /= 2;
    }
    return result;
}

// ------------------- 2. String Sorting -------------------

void sortStrings(char str[][100], int n) {
    char temp[100];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
}

// ------------------- 3. Integer Array Sorting -------------------

void sortAscending(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (arr[i] > arr[j]) {
                int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            }
}

void sortDescending(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (arr[i] < arr[j]) {
                int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            }
}

// ------------------- 4. String Structure -------------------

struct Student {
    char name[100];
    int age;
};

void printStudent(struct Student s) {
    printf("Name: %s, Age: %d\n", s.name, s.age);
}

// ------------------- 5. Happy Number -------------------

int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

int isHappy(int n) {
    int slow = n, fast = n;
    do {
        slow = sumOfSquares(slow);
        fast = sumOfSquares(sumOfSquares(fast));
    } while (slow != fast);
    return (slow == 1);
}

// ------------------- 6. Catalan Number -------------------

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

unsigned long long catalan(int n) {
    return factorial(2 * n) / (factorial(n + 1) * factorial(n));
}

// ------------------- Main -------------------

int main() {
    // 1. Power Function
    printf("Power Functions:\n");
    printf("Naive (2^5): %d\n", power_naive(2, 5));
    printf("Optimized (2^5): %d\n", power_optimized(2, 5));
    printf("Binary (2^5): %d\n\n", power_binary(2, 5));

    // 2. Sort Strings
    char words[3][100] = {"Amar", "Akbar", "Anthony"};
    int wordCount = 3;
    sortStrings(words, wordCount);
    printf("Sorted Strings:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s\n", words[i]);
    }
    printf("\n");

    // 3. Sort Integer Arrays
    int arr[] = {9, 3, 5, 1, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    sortAscending(arr, n);
    printf("Array in Ascending Order: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    sortDescending(arr, n);
    printf("Array in Descending Order: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n\n");

    // 4. String Structure
    struct Student s1 = {"Gayathri", 20};
    printf("Student Structure:\n");
    printStudent(s1);
    printf("\n");

    // 5. Happy Number
    int hn = 19;
    printf("Happy Number Check for %d: %s\n\n", hn, isHappy(hn) ? "Happy Number 😊" : "Not a Happy Number 😞");

    // 6. Catalan Number
    int c = 5;
    printf("Catalan Number C(%d) = %llu\n", c, catalan(c));

    return 0;
}
