#include <stdio.h>
#include <Windows.h>

#define WIDTH 7
#define HEIGHT 6

void gotoxy(int x, int y) {
	//x, y 좌표 설정
	COORD pos = { x,y };
	//커서 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Draw() {

	system("cls");
	int Image[WIDTH * HEIGHT] = {
		0,1,0,1,0,1,0,
		0,0,1,1,1,0,0,
		0,1,1,1,1,1,0,
		1,1,1,1,1,1,1,
		0,0,0,1,0,0,0,
		0,0,0,1,0,0,0
	};

	int i = 0;
	int j = 0;
	printf("---------------");
	for (i = 0; i < WIDTH * HEIGHT; i++) {
		//char* arr = (char*)malloc(sizeof(char) * WIDTH);
		//char* arr = (char*)malloc(sizeof(char) * HEIGHT);

		if (i % WIDTH == 0) {
			printf("%s", "|");
			printf("%s\n", "");
			printf("%s", "|");
		}

		if (Image[i] == 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			printf("%s", "■");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else {
			printf("%s", "□");
		}


	}
	printf("%s\n", "|");
	printf("---------------");
}

void Viewport() {
	int cursor[2] = { 0,0 };
	

	while (1) {
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			exit(0);
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			if (0 <= (cursor[0] - 1)) {
				
				if (cursor[0] < 16) {
					cursor[0] --;
					gotoxy(cursor[0], cursor[1]);
					Draw();
				}
				else {
					cursor[0] = 0;
					cursor[1] = 0;
					gotoxy(cursor[0], cursor[1]);
					Draw();
				}
				
			}
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			if (0 <= (cursor[0] + 1)) {
				
				if (cursor[0] < 16) {
					cursor[0] ++;
					gotoxy(cursor[0], cursor[1]);
					Draw();
				}
				else {
					cursor[0] = 0;
					cursor[1] = 0;
					gotoxy(cursor[0], cursor[1]);
					Draw();
				}
				

			}
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			if (0 < (cursor[1] - 1)) {
				
				if (cursor[1] < 0) {
					cursor[1] --;
					gotoxy(cursor[0], cursor[1]);
					Draw();
				}
				else {
					cursor[0] = 0;
					cursor[1] = 0;
					gotoxy(cursor[0], cursor[1]);
					Draw();
				}
				

			}
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			if (0 < (cursor[1] + 1)) {
				
				if (cursor[1] < 8) {
					cursor[1] ++;
					gotoxy(cursor[0], cursor[1]);
					Draw();
				}
				else {
					cursor[0] = 0;
					cursor[1] = 0;
					gotoxy(cursor[0], cursor[1]);
					Draw();
				}

			}
		}
	}
}

int main(int argc, char* argv[])
{

	Draw();

	Viewport();
	
	return 0;
}