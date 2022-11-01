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

void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void prtreversedString(char str[]) { //문자열 거꾸로 돌리기
	int i, len = 0;
	while (str[len] != 0) {
		len++;
	}
	for (i = len - 1; i >= 0; i--) {
		printf("%c", str[i]);
	}
}

void DimensionalArray() { //2차원 배열 생성 테스트
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

void ArrayReview(int arr[HEIGHT][WIDTH]) {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			printf(" %d", arr[i][j]);
		}
		printf(" %s", "/");
	}
}

int main(int argc, char* argv[])
{
	CursorView();

	int cursor[2] = { 0,0 };

	int Image2[WIDTH * HEIGHT] = {
		   0,1,0,1,0,1,0,
		   0,0,1,1,1,0,0,
		   0,1,1,1,1,1,0,
		   1,1,1,1,1,1,1,
		   0,0,0,1,0,0,0,
		   0,0,0,1,0,0,0,
	};

	int Image[HEIGHT][WIDTH] = {
		{0,1,0,1,0,1,0},
		{0,0,1,1,1,0,0},
		{0,1,1,1,1,1,0},
		{1,1,1,1,1,1,1},
		{0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0}
	};
	


	while (1)
	{
		if (GetKeyState(VK_ESCAPE) & 0x8000)
		{
			break;
		}
		if (GetKeyState(VK_LEFT) & 0x8000)
		{
			if (0 <= (cursor[0] - 1))
			{
				cursor[0]--;
			}
		}
		if (GetKeyState(VK_RIGHT) & 0x8000)
		{
			if (WIDTH - 1 >= (cursor[0] + 1))
			{
				cursor[0]++;
			}
		}
		if (GetKeyState(VK_UP) & 0x8000)
		{
			if (0 <= (cursor[1] - 1))
			{
				cursor[1]--;
			}
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			if (HEIGHT - 1 >= (cursor[1] + 1))
			{
				cursor[1]++;
			}
		}

		//선택!
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			
		}
		

		int i = 0;
		int j = 0;
		for (i = 0; i < WIDTH + 2; i++)
			for (j = 0; j < HEIGHT + 2; j++)
			{
				gotoxy(i * 2, j);

				if (j == 0 || j == HEIGHT + 1)
					printf("--");
				else if (i == 0)
					printf("|");
				else if (i == WIDTH + 1)
					printf(" |");
				else
				{
					if (Image[(j + 4) - HEIGHT][WIDTH + (i - 1)] == 0)
					{
						if (i - 1 == cursor[0] && j - 1 == cursor[1])
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
							printf("□");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						}
						else
						{
							printf("□");
						}
					}
					else
					{
						if (i - 1 == cursor[0] && j - 1 == cursor[1])
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
							printf("■");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						}
						else
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
							printf("■");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						}
					}
				}
			}

	}

	return 0;
}