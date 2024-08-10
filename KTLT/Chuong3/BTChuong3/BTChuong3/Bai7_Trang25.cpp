#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void chenTu(char* chuoi, const char* tu, int viTri) {
    int lenChuoi = strlen(chuoi);
    int lenTu = strlen(tu);

    if (viTri < 0 || viTri > lenChuoi) {
        printf("Vi tri chen khong hop le!\n");
        return;
    }

    for (int i = lenChuoi; i >= viTri; i--) {
        chuoi[i + lenTu] = chuoi[i];
    }

    for (int i = 0; i < lenTu; i++) {
        chuoi[viTri + i] = tu[i];
    }

    if (viTri > 0 && chuoi[viTri - 1] != ' ') {
        for (int i = lenChuoi + lenTu; i > viTri; i--) {
            chuoi[i] = chuoi[i - 1];
        }
        chuoi[viTri] = ' ';
    }
}

int main() {
    char chuoi[MAX_LENGTH], tu[MAX_LENGTH];
    int viTri;

    printf("Nhap chuoi: ");
    fgets(chuoi, MAX_LENGTH, stdin);
    chuoi[strcspn(chuoi, "\n")] = 0;  

    printf("Nhap tu can chen: ");
    fgets(tu, MAX_LENGTH, stdin);
    tu[strcspn(tu, "\n")] = 0;  

    printf("Nhap vi tri can chen (bat dau tu 0): ");
    scanf("%d", &viTri);

    chenTu(chuoi, tu, viTri);

    printf("Chuoi sau khi chen: %s\n", chuoi);

    return 0;
}