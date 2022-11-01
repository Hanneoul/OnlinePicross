#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 7
#define HEIGHT 6

void gotoxy(int x, int y) {
	//x, y 좌표 설정
	COORD pos = { x,y };
	//커서 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void prtreversedString(char str[]) {
	int i, len = 0;
	while (str[len] != 0) {
		len++;
	}
	for (i = len - 1; i >= 0; i--) {
		printf("%c", str[i]);
	}
}

void DimensionalArray() {
	int i, j;
	int ary1[][3] = { 0 };

	int arr_wid_len = sizeof(ary1[0]) / sizeof(ary1[0][0]);
	int arr_hei_len = (sizeof(ary1) / arr_wid_len) / sizeof(ary1[0][0]);


	for (i = 0; i < HEIGHT; i++) {
		printf("\n");
		for (j = 0; j < WIDTH; j++) {
			int* ptr = *ary1;
			printf(" %d", *ptr);

		}
	}
}

int main(int argc, char* argv[])
{
	/*DimensionalArray();*/
	while (1) {

	}
	int Image[WIDTH * HEIGHT] = {
	   0,1,0,1,0,1,0,
	   0,0,1,1,1,0,0,
	   0,1,1,1,1,1,0,
	   1,1,1,1,1,1,1,
	   0,0,0,1,0,0,0,
	   0,0,0,1,0,0,0,
	};

	int i = 0;
	int j = 0;
	for (i = 0; i < WIDTH+2; i++)
		for (j = 0; j < HEIGHT + 2; j++)
		{
			gotoxy(i*2, j);
			
			if (j == 0 || j == HEIGHT + 1)
				printf("--");
			else if (i == 0)
				printf("|");
			else if(i == WIDTH + 1)
				printf(" |"); 
			else
			{
				if (Image[WIDTH * (j - 1) + (i - 1)] == 0)
					printf("□");
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
					printf("■");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
			}

		}
	
	
	
	return 0;
}