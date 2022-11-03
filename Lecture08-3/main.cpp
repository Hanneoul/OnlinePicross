#define _CRT_SECURE_NO_WARNINGS

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


void DrawCursor(int coordX, int coordY)
{
}

void DrawGamePlayMap(int width, int height, int coordX, int coordY, int* image, int cursorX, int cursorY)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	int i = 0;
	int j = 0;

	for (i = 0; i < width + 2; i++)
		for (j = 0; j < height + 2; j++)
		{
			gotoxy(coordX + i * 2, coordY + j);

			if (j == 0 || j == height + 1)
				printf("--");
			else if (i == 0)
				printf("|");
			else if (i == width + 1)
				printf(" |");
			else
			{
				if (image[WIDTH * (j - 1) + (i - 1)] == 0)
				{
					if (i - 1 == cursorX && j - 1 == cursorY)
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
					if (i - 1 == cursorX && j - 1 == cursorY)
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

void DrawClearMap(int width, int height, int coordX, int coordY, int* image)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
	int i = 0;
	int j = 0;

	for (i = 0; i < width + 2; i++)
		for (j = 0; j < height + 2; j++)
		{
			gotoxy(coordX + i * 2, coordY + j);

			if (j == 0 || j == height + 1)
				printf("--");
			else if (i == 0)
				printf("|");
			else if (i == width + 1)
				printf(" |");
			else
			{
				if (image[WIDTH * (j - 1) + (i - 1)] == 0)
				{
					printf("¡à");
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

struct vec2
{
	int x;
	int y;
};

vec2 DrawNumbers(int width, int height, int* image, char** wText, char** hText)
{
	vec2 MapStartPos;
	MapStartPos.x = 0;
	MapStartPos.y = 0;

	int continuityCount = 0;
	int indexX = 0;
	int indexY = 0;
	int MaxlineXStartPos = 0;
	
	continuityCount = 0;

	
	if (width == 1)
	{
	}		
	
	for (indexY = 0; indexY < height; indexY++)
	{
		continuityCount = 0;
		wText[indexY] = (char*)"";

		for (indexX = 0; indexX < width - 1; indexX++)
		{
			if (image[(indexY * width) + indexX] == 1 && image[(indexY * width) + indexX + 1] == 1)
				continuityCount++;
			else
			{
				char buffer[35];
				char* a = _itoa(continuityCount, buffer, 10);
				wText[indexY] = strcat(a, wText[indexY]);
								
				continuityCount = 0;
				MaxlineXStartPos += 2;
			}
		}
	}

	for (indexY = 0; indexY < height; indexY++)
	{
		gotoxy(0, indexY);
		printf("%s\n", wText[indexY]);
	}



	return MapStartPos;
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

	char* wText[HEIGHT];
	char* hText[WIDTH];

	int cw = 0;
	int ch = 0;
	int maxWSpace = 0;
	int maxHSpace = 0;

	/*for(ch=0;ch<HEIGHT; ch++)
	{
		int wCount = 0;
		for (cw = 0; cw < WIDTH-1; cw++)
		{
			if (image[ch * WIDTH + cw] == 1)
			{
				
				if (image[ch * WIDTH + cw + 1] == 1)
				{
					wCount++;
				}
				if (image[ch * WIDTH + cw + 1] == 1)
				{
					wCount++;
				}
			}
			if (image[ch * WIDTH + cw] == 1 && image[ch * WIDTH + cw] == 0)
			{ }
			if (Image[ch * WIDTH + cw] == 1)
			{
				wText[ch] += ' ';
			}
		}
	}*/


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
			

		//DrawClearMap(WIDTH, HEIGHT, 0, 0, Image);
		//DrawGamePlayMap(WIDTH, HEIGHT, 0, 0, Image, cursor[0], cursor[1]);
		
		DrawNumbers(WIDTH, HEIGHT, Image, wText, hText);
		
	}

	return 0;
}