#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void inputString(char **str);
void reverseString(char *str);
void countWords(char *str);
void compareStrings(char *str1);
void toUpperCase(char *str);
void appendString(char **str1);

int main() {
    int choice;
    char *str = NULL;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. So sanh voi chuoi khac\n");
        printf("5. Chuyen chuoi sang in hoa\n");
        printf("6. Them chuoi khac vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                inputString(&str);
                break;
            case 2:
                reverseString(str);
                break;
            case 3:
                countWords(str);
                break;
            case 4:
                compareStrings(str);
                break;
            case 5:
                toUpperCase(str);
                break;
            case 6:
                appendString(&str);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                if (str != NULL) {
                    free(str);
                }
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    }

    return 0;
}

void inputString(char **str) {
    if (*str != NULL) {
        free(*str);
    }

    *str = (char *)malloc(100 * sizeof(char));
    if (*str == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }

    printf("Nhap vao chuoi: ");
    fgets(*str, 100, stdin);
    (*str)[strcspn(*str, "\n")] = 0;
}

void reverseString(char *str) {
    if (str == NULL) {
        printf("Chuoi chua duoc nhap!\n");
        return;
    }

    int length = strlen(str);
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void countWords(char *str) {
    if (str == NULL) {
        printf("Chuoi chua duoc nhap!\n");
        return;
    }

    int count = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    printf("So luong tu trong chuoi: %d\n", count);
}

void compareStrings(char *str1) {
    if (str1 == NULL) {
        printf("Chuoi chua duoc nhap!\n");
        return;
    }

    char *str2 = (char *)malloc(100 * sizeof(char));
    if (str2 == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }

    printf("Nhap chuoi khac de so sanh: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = 0;

    if (strlen(str2) < strlen(str1)) {
        printf("Chuoi thu 2 ngan hon chuoi thu 1.\n");
    } else if (strlen(str2) > strlen(str1)) {
        printf("Chuoi thu 2 dai hon chuoi thu 1.\n");
    } else {
        printf("Cung kich thuoc chuoi.\n");
    }

    free(str2);
}

void toUpperCase(char *str) {
    if (str == NULL) {
        printf("Chuoi chua duoc nhap!\n");
        return;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
    printf("Chuoi in hoa: %s\n", str);
}

void appendString(char **str1) {
    if (*str1 == NULL) {
        printf("Chuoi chua duoc nhap!\n");
        return;
    }

    char *str2 = (char *)malloc(100 * sizeof(char));
    if (str2 == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }

    printf("Nhap chuoi de them: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = 0;

    *str1 = (char *)realloc(*str1, (strlen(*str1) + strlen(str2) + 1) * sizeof(char));
    if (*str1 == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }

    strcat(*str1, str2);
    printf("Chuoi sau khi them: %s\n", *str1);

    free(str2);
}

