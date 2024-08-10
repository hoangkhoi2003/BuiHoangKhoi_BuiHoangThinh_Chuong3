#include<stdio.h>
#include<string.h>

void demKyTu(char* str, int so[]) {
	for (int i = 0; str[i] != '\0'; i++) {
		so[(unsigned char)str[i]]++;

	}
}

char timKTXuatHien(int so[]) {
	int max = 0;
	char kyTuMax = '\0';

	for (int i = 0; i < 256; i++) {
		if (so[i] > max) {
			max = so[i];
			kyTuMax = i;
		}
	}

	return kyTuMax;
}

int main() {
	char chuoi[100];
	int so[256] = { 0 };

	printf("Nhap chuoi:");
	fgets(chuoi, sizeof(chuoi), stdin);

	chuoi[strcspn(chuoi, "\n")] = '\0';

	demKyTu(chuoi, so);

	char kyTyMax = timKTXuatHien(so);

	printf("Ky tu xuat hien nhieu nhat la: '%c'\n", kyTyMax);

	return 0;
}
