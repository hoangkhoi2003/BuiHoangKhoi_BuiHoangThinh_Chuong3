#include<stdio.h>
#include<string.h>

void demChuoi(char* str, int chuoi[]) {
	for (int i = 0; str[i] != '\0'; i++) {
		chuoi[(unsigned char)str[i]]++;
	}
}

void xuatChuoi(int chuoi[]) {
	printf("So lan xuat hien la:\n");
	for (int i = 0; i < 256; i++) {
		if (chuoi[i] != 0) {
			printf("%c : %d \n", i, chuoi[i]);
		}
	}
}

int main() {
	char str[100];
	int chuoi[256] = { 0 };

	printf("Nhap chuoi:");
	fgets(str, sizeof(str), stdin);

	str[strcspn(str, "\n")] = '\0';

	demChuoi(str, chuoi);

	xuatChuoi(chuoi);

	return 0;
}