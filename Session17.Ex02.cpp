#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


void inputString(char **str);
void printString(char *str);
void countLetters(char *str);
void countDigits(char *str);
void countSpecialChars(char *str);

int main() {
    int choice;
    char *str = NULL;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi\n");
        printf("4. Dem so luong chu so trong chuoi\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                inputString(&str);
                break;
            case 2:
                printString(str);
                break;
            case 3:
                countLetters(str);
                break;
            case 4:
                countDigits(str);
                break;
            case 5:
                countSpecialChars(str);
                break;
            case 6:
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

void printString(char *str) {
    if (str == NULL) {
        printf("Chuoi chua duoc nhap!\n");
        return;
    }
    printf("Chuoi ban nhap: %s\n", str);
}

void countLetters(char *str) {
    if (str == NULL) {
        printf("Chuoi chua duoc nhap!\n");
        return;
    }

    int count = 0;
    while (*str) {
        if (isalpha(*str)) {
            count++;
        }
        str++;
    }
    printf("So luong chu cai trong chuoi: %d\n", count);
}

void countDigits(char *str) {
    if (str == NULL) {
        printf("Chuoi chua duoc nhap!\n");
        return;
    }

    int count = 0;
    while (*str) {
        if (isdigit(*str)) {
            count++;
        }
        str++;
    }
    printf("So luong chu so trong chuoi: %d\n", count);
}

void countSpecialChars(char *str) {
    if (str == NULL) {
        printf("Chuoi chua duoc nhap!\n");
        return;
    }

    int count = 0;
    while (*str) {
        if (!isalnum(*str) && !isspace(*str)) {
            count++;
        }
        str++;
    }
    printf("So luong ky tu dac biet trong chuoi: %d\n", count);
}

