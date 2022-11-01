#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 7
#define HEIGHT 6

void gotoxy(int x, int y) {
	//x, y ÁÂÇ¥ ¼³Á¤
	COORD pos = { x,y };
	//Ä¿¼­ ÀÌµ¿
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //Ä¿¼­ ±½±â (1 ~ 100)
	cursorInfo.bVisible = FALSE; //Ä¿¼­ Visible TRUE(º¸ÀÓ) FALSE(¼û±è)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int main(int argc, char* argv[])
{
	CursorView();

	int cursor[2] = { 0,0 };

	int Image[WIDTH * HEIGHT] = {
		   0,1,0,1,0,1,0,
		   0,0,1,1,1,0,0,
		   0,1,1,1,1,1,0,
		   1,1,1,1,1,1,1,
		   0,0,0,1,0,0,0,
		   0,0,0,1,0,0,0,
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

		//¼±ÅÃ!
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
					if (Image[WIDTH * (j - 1) + (i - 1)] == 0)
					{
						if (i - 1 == cursor[0] && j - 1 == cursor[1])
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
							printf("¡à");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						}
						else
						{
							printf("¡à");
						}
						
						
					}
					else
					{
						if (i - 1 == cursor[0] && j - 1 == cursor[1])
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
							printf("¡á");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						}
						else
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
							printf("¡á");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						}
					}
				}
			}

	}

	return 0;
}