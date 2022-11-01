#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

#define WIDTH 7
#define HEIGHT 6
#define MAX_LENGTH 64



void prtreversedString(char str[]) {
	int i, len = 0;
	while (str[len] != 0) {
		len++;
	}
	for (i = len - 1; i >= 0; i--) {
		printf("%c", str[i]);
	}
}



int main() {
	int i, j;
	int ary1[][3]={0};

	int arr_wid_len = sizeof(ary1[0]) / sizeof(ary1[0][0]);
	int arr_hei_len = (sizeof(ary1) / arr_wid_len) / sizeof(ary1[0][0]);
	

	for (i = 0; i < HEIGHT; i++) {
		printf("\n");
		for (j = 0; j < WIDTH; j++) {
			int* ptr = *ary1;
			printf(" %d",*ptr);
			
		}
	}

	


	char str[]= {"string"};
	prtreversedString(str);
	return 0;
	

}

