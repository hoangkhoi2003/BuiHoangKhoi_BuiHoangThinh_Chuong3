#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 1000

void xoaTu(char* chuoi, const char* tucanXoa) {
	char* viTri;
	int lenTuCanXoa = strlen(tucanXoa);

	while ((viTri = strstr(chuoi, tucanXoa)) != NULL) {
		memmove(viTri, viTri + lenTuCanXoa, strlen(viTri + lenTuCanXoa) + 1);

		if (viTri > chuoi && viTri[-1] == ' ' && viTri[0] == ' ') {
			memmove(viTri, viTri + 1, strlen(viTri) + 1);
		}
	}

	while (chuoi[0] == ' ') {
		memmove(chuoi, chuoi + 1, strlen(chuoi));
	}

	while (chuoi[strlen(chuoi) - 1] == ' ') {
		chuoi[strlen(chuoi) - 1] = '\0';
	}
}

int main() {
	char chuoi[MAX_LENGTH], tuCanXoa[MAX_LENGTH];

	printf("Nhap chuoi:");
	fgets(chuoi, MAX_LENGTH, stdin);
	chuoi[strcspn(chuoi, "\n")] = 0;

	printf("Nhap tu can xoa:");
	fgets(tuCanXoa, MAX_LENGTH, stdin);
	tuCanXoa[strcspn(tuCanXoa, "\n")] = 0;

	xoaTu(chuoi, tuCanXoa);

	printf("Chuoi sau khi xoa: \"%s\"\n", chuoi);
}