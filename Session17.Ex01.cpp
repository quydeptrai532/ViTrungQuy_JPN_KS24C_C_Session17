#include <stdio.h>
#include <stdlib.h>

int n = 0;
int *arr = NULL;

void insertNumber();
void showNumber();
void numberLength();
void numberSum();
void biggestNum();

int main() {
    int choice;
    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertNumber();
                break;
            case 2:
                showNumber();
                break;
            case 3:
                numberLength();
                break;
            case 4:
                numberSum();
                break;
            case 5:
                biggestNum();
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                if (arr != NULL) free(arr);
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    }
}

void insertNumber() {
    if (arr != NULL) {
        free(arr);
    }

    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void showNumber() {
    if (arr == NULL) {
        printf("Mang chua duoc khoi tao!\n");
        return;
    }

    printf("Cac phan tu cua mang la:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

void numberLength() {
    if (arr == NULL) {
        printf("Mang chua duoc khoi tao!\n");
        return;
    }
    printf("Do dai mang: %d\n", n);
}

void numberSum() {
    if (arr == NULL) {
        printf("Mang chua duoc khoi tao!\n");
        return;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("Tong cac phan tu trong mang: %d\n", sum);
}

void biggestNum() {
    if (arr == NULL) {
        printf("Mang chua duoc khoi tao!\n");
        return;
    }

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Phan tu lon nhat trong mang: %d\n", max);
}

