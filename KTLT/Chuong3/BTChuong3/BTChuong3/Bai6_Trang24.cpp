#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void catHoTen(char* hoTen, char* hoLot, char* ten) {
    int len = strlen(hoTen);
    int i;
    int viTriKhoangTrangCuoi = -1;

    for (i = len - 1; i >= 0; i--) {
        if (hoTen[i] == ' ') {
            viTriKhoangTrangCuoi = i;
            break;
        }
    }

    if (viTriKhoangTrangCuoi == -1) {
        strcpy(ten, hoTen);
        hoLot[0] = '\0';
    }
    else {
        strncpy(hoLot, hoTen, viTriKhoangTrangCuoi);
        hoLot[viTriKhoangTrangCuoi] = '\0';
        strcpy(ten, &hoTen[viTriKhoangTrangCuoi + 1]);
    }
}

int main() {
    char hoTen[MAX_LENGTH], hoLot[MAX_LENGTH], ten[MAX_LENGTH];

    printf("Nhap ho ten: ");
    fgets(hoTen, MAX_LENGTH, stdin);

    hoTen[strcspn(hoTen, "\n")] = 0;

    catHoTen(hoTen, hoLot, ten);

    printf("Ho lot: %s\n", hoLot);
    printf("Ten: %s\n", ten);

    return 0;
}