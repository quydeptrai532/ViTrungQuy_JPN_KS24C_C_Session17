#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inputArray(int **arr, int *n);
void printEvenNumbers(int *arr, int n);
int isPrime(int num);
void printPrimeNumbers(int *arr, int n);
void reverseArray(int *arr, int n);
void sortArray(int *arr, int n);
void sortAscending(int *arr, int n);
void sortDescending(int *arr, int n);
int searchElement(int *arr, int n, int element);

int main() {
    int choice, n;
    int *arr = NULL;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("    1. Tang dan\n");
        printf("    2. Giam dan\n");
        printf("6. Nhap vao mot phan tu va tim kiem trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(&arr, &n);
                break;
            case 2:
                printEvenNumbers(arr, n);
                break;
            case 3:
                printPrimeNumbers(arr, n);
                break;
            case 4:
                reverseArray(arr, n);
                break;
            case 5:
                printf("Chon 1. Tang dan\n");
                printf("Chon 2. Giam dan\n");
                int sortChoice;
                scanf("%d", &sortChoice);
                if (sortChoice == 1) {
                    sortAscending(arr, n);
                } else if (sortChoice == 2) {
                    sortDescending(arr, n);
                } else {
                    printf("Lua chon sai\n");
                }
                break;
            case 6:
                {
                    int element;
                    printf("Nhap vao phan tu can tim: ");
                    scanf("%d", &element);
                    int index = searchElement(arr, n, element);
                    if (index != -1) {
                        printf("Phan tu %d duoc tim thay tai vi tri %d\n", element, index);
                    } else {
                        printf("Phan tu %d khong ton tai trong mang\n", element);
                    }
                }
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                if (arr != NULL) {
                    free(arr);
                }
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    }

    return 0;
}

void inputArray(int **arr, int *n) {
    printf("Nhap vao so phan tu cua mang: ");
    scanf("%d", n);

    *arr = (int *)malloc(*n * sizeof(int));
    if (*arr == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }

    for (int i = 0; i < *n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &(*arr)[i]);
    }
}

void printEvenNumbers(int *arr, int n) {
    printf("Cac phan tu la so chan: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void printPrimeNumbers(int *arr, int n) {
    printf("Cac phan tu la so nguyen to: ");
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void reverseArray(int *arr, int n) {
    printf("Mang dao nguoc: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sortArray(int *arr, int n) {
    int choice;
    printf("Chon 1. Tang dan\n");
    printf("Chon 2. Giam dan\n");
    scanf("%d", &choice);

    if (choice == 1) {
        sortAscending(arr, n);
    } else if (choice == 2) {
        sortDescending(arr, n);
    } else {
        printf("Lua chon sai\n");
    }
}

void sortAscending(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Mang sau khi sap xep tang dan: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sortDescending(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Mang sau khi sap xep giam dan: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int searchElement(int *arr, int n, int element) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i; // Return index if element is found
        }
    }
    return -1; // Return -1 if element is not found
}

