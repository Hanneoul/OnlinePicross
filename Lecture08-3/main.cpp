#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <list>
using namespace std;

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
		printf("\n");
	}
}

typedef struct VH_Array{

	int Horizontal_1[WIDTH];
	int Horizontal_2[WIDTH];
	int Horizontal_3[WIDTH];
	int Horizontal_4[WIDTH];
	int Horizontal_5[WIDTH];
	int Horizontal_6[WIDTH];

	int Vertical_1[HEIGHT];
	int Vertical_2[HEIGHT];
	int Vertical_3[HEIGHT];
	int Vertical_4[HEIGHT];
	int Vertical_5[HEIGHT];
	int Vertical_6[HEIGHT];
	int Vertical_7[HEIGHT];

	list<int> Horizontal_1_Result;
	list<int> Horizontal_2_Result;
	list<int> Horizontal_3_Result;
	list<int> Horizontal_4_Result;
	list<int> Horizontal_5_Result;
	list<int> Horizontal_6_Result;

	list<int> Vertical_1_Result;
	list<int> Vertical_2_Result;
	list<int> Vertical_3_Result;
	list<int> Vertical_4_Result;
	list<int> Vertical_5_Result;
	list<int> Vertical_6_Result;
	list<int> Vertical_7_Result;
};

void Horizontal_ResultArray(struct VH_Array* vh_array, int num) {

	int size = (sizeof(vh_array->Horizontal_1) / sizeof(*vh_array->Horizontal_1));
	int count = 0;

	if (num == 1) {
		for (int i = 0; i < size; i++) {
			if (vh_array->Horizontal_1[i] == 1) {
				count += 1;
			}
			else if (vh_array->Horizontal_1[i] == 0 && count != 0) {
				vh_array->Horizontal_1_Result.push_back(count);
				count = 0;
			}
			else {
				count = 0;
			}
		}

		if (count != 0) {
			vh_array->Horizontal_1_Result.push_back(count);
		}
	}
	else if (num == 2) {
		for (int i = 0; i < size; i++) {
			if (vh_array->Horizontal_2[i] == 1) {
				count += 1;
			}
			else if (vh_array->Horizontal_2[i] == 0 && count != 0) {
				vh_array->Horizontal_2_Result.push_back(count);
				count = 0;
			}
			else {
				count = 0;
			}
		}

		if (count != 0) {
			vh_array->Horizontal_2_Result.push_back(count);
		}
	}
	else if (num == 3) {
		for (int i = 0; i < size; i++) {
			if (vh_array->Horizontal_3[i] == 1) {
				count += 1;
			}
			else if (vh_array->Horizontal_3[i] == 0 && count != 0) {
				vh_array->Horizontal_3_Result.push_back(count);
				count = 0;
			}
			else {
				count = 0;
			}
		}

		if (count != 0) {
			vh_array->Horizontal_3_Result.push_back(count);
		}
	}
	else if (num == 4) {
		for (int i = 0; i < size; i++) {
			if (vh_array->Horizontal_4[i] == 1) {
				count += 1;
			}
			else if (vh_array->Horizontal_4[i] == 0 && count != 0) {
				vh_array->Horizontal_4_Result.push_back(count);
				count = 0;
			}
			else {
				count = 0;
			}
		}

		if (count != 0) {
			vh_array->Horizontal_4_Result.push_back(count);
		}
	}
	else if (num == 5) {
		for (int i = 0; i < size; i++) {
			if (vh_array->Horizontal_5[i] == 1) {
				count += 1;
			}
			else if (vh_array->Horizontal_5[i] == 0 && count != 0) {
				vh_array->Horizontal_5_Result.push_back(count);
				count = 0;
			}
			else {
				count = 0;
			}
		}

		if (count != 0) {
			vh_array->Horizontal_5_Result.push_back(count);
		}
	}
	else if (num == 6) {
		for (int i = 0; i < size; i++) {
			if (vh_array->Horizontal_6[i] == 1) {
				count += 1;
			}
			else if (vh_array->Horizontal_1[i] == 0 && count != 0) {
				vh_array->Horizontal_6_Result.push_back(count);
				count = 0;
			}
			else {
				count = 0;
			}
		}

		if (count != 0) {
			vh_array->Horizontal_6_Result.push_back(count);
		}
	}
	
}

void CheckNemoCount_Horizontal(struct VH_Array *vh_array, int InputArr[HEIGHT][WIDTH]) { 


	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (i == 0) {
				vh_array->Horizontal_1[j] = InputArr[0][j];
			}
			else if (i == 1) {
				vh_array->Horizontal_2[j] = InputArr[1][j];
			}
			else if (i == 2) {
				vh_array->Horizontal_3[j] = InputArr[2][j];
			}
			else if (i == 3) {
				vh_array->Horizontal_4[j] = InputArr[3][j];
			}
			else if (i == 4) {
				vh_array->Horizontal_5[j] = InputArr[4][j];
			}
			else if (i == 5) {
				vh_array->Horizontal_6[j] = InputArr[5][j];
			}

		}
		printf("\n");
	}
	
	for (int j = 1; j < HEIGHT + 1; j++) {
		Horizontal_ResultArray(vh_array, j);
	}
	
	
}


void Vertical_ResultArray(struct VH_Array* vh_array, int num) {

	int size = (sizeof(vh_array->Vertical_1) / sizeof(*vh_array->Vertical_1));
	int count = 0;

	if (num == 1) {
		for (int i = 0; i < size; i++) {
			if (vh_array->Vertical_1[i] == 1) {
				count += 1;
			}
			else if (vh_array->Vertical_1[i] == 0 && count != 0) {
				vh_array->Vertical_1_Result.push_back(count);
				count = 0;
			}
			else {
				count = 0;
			}
		}

		if (count != 0) {
			vh_array->Vertical_1_Result.push_back(count);
		}
	}
	else if (num == 2) {
		for (int i = 0; i < size; i++) {
			if (vh_array->Vertical_2[i] == 1) {
				count += 1;
			}
			else if (vh_array->Vertical_2[i] == 0 && count != 0) {
				vh_array->Vertical_2_Result.push_back(count);
				count = 0;
			}
			else {
				count = 0;
			}
		}

		if (count != 0) {
			vh_array->Vertical_2_Result.push_back(count);
		}
	}
	else if (num == 3) {
		for (int i = 0; i < size; i++) {
			if (vh_array->Vertical_3[i] == 1) {
				count += 1;
			}
			else if (vh_array->Vertical_3[i] == 0 && count != 0) {
				vh_array->Vertical_3_Result.push_back(count);
				count = 0;
			}
			else {
				count = 0;
			}
		}

		if (count != 0) {
			vh_array->Vertical_3_Result.push_back(count);
		}
	}
	else if (num == 4) {
		for (int i = 0; i < size; i++) {
			if (vh_array->Vertical_4[i] == 1) {
				count += 1;
			}
			else if (vh_array->Vertical_4[i] == 0 && count != 0) {
				vh_array->Vertical_4_Result.push_back(count);
				count = 0;
			}
			else {
				count = 0;
			}
		}

		if (count != 0) {
			vh_array->Vertical_4_Result.push_back(count);
		}
	}
	else if (num == 5) {
		for (int i = 0; i < size; i++) {
			if (vh_array->Vertical_5[i] == 1) {
				count += 1;
			}
			else if (vh_array->Vertical_5[i] == 0 && count != 0) {
				vh_array->Vertical_5_Result.push_back(count);
				count = 0;
			}
			else {
				count = 0;
			}
		}

		if (count != 0) {
			vh_array->Vertical_5_Result.push_back(count);
		}
	}
	else if (num == 6) {
		for (int i = 0; i < size; i++) {
			if (vh_array->Vertical_6[i] == 1) {
				count += 1;
			}
			else if (vh_array->Vertical_6[i] == 0 && count != 0) {
				vh_array->Vertical_6_Result.push_back(count);
				count = 0;
			}
			else {
				count = 0;
			}
		}

		if (count != 0) {
			vh_array->Vertical_6_Result.push_back(count);
		}
	}
	else if (num == 7) {
	for (int i = 0; i < size; i++) {
		if (vh_array->Vertical_7[i] == 1) {
			count += 1;
		}
		else if (vh_array->Vertical_7[i] == 0 && count != 0) {
			vh_array->Vertical_7_Result.push_back(count);
			count = 0;
		}
		else {
			count = 0;
		}
	}

	if (count != 0) {
		vh_array->Vertical_7_Result.push_back(count);
	}
	}

}


void CheckNemoCount_Vertical(struct VH_Array* vh_array, int InputArr[HEIGHT][WIDTH]) {


	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			if (i == 0) {
				vh_array->Vertical_1[j] = InputArr[j][0];
			}
			else if (i == 1) {
				vh_array->Vertical_2[j] = InputArr[j][1];
			}
			else if (i == 2) {
				vh_array->Vertical_3[j] = InputArr[j][2];
			}
			else if (i == 3) {
				vh_array->Vertical_4[j] = InputArr[j][3];
			}
			else if (i == 4) {
				vh_array->Vertical_5[j] = InputArr[j][4];
			}
			else if (i == 5) {
				vh_array->Vertical_6[j] = InputArr[j][5];
			}
			else if (i == 6) {
				vh_array->Vertical_7[j] = InputArr[j][6];
			}

		}
		printf("\n");
	}

	for (int j = 1; j < WIDTH + 1; j++) {
		Vertical_ResultArray(vh_array, j);
	}


}

list<int> Vertical_Sort(struct VH_Array* vh_array) {
	list<int> Sort_List;
	
	if (vh_array->Vertical_1_Result.size() > 0) {
		Sort_List.push_back(vh_array->Vertical_1_Result.front());
		vh_array->Vertical_1_Result.pop_front();
	}

	if (vh_array->Vertical_2_Result.size() > 0) {
		Sort_List.push_back(vh_array->Vertical_2_Result.front());
		vh_array->Vertical_2_Result.pop_front();
	}

	if (vh_array->Vertical_3_Result.size() > 0) {
		Sort_List.push_back(vh_array->Vertical_3_Result.front());
		vh_array->Vertical_3_Result.pop_front();
	}

	if (vh_array->Vertical_4_Result.size() > 0) {
		Sort_List.push_back(vh_array->Vertical_4_Result.front());
		vh_array->Vertical_4_Result.pop_front();
	}

	if (vh_array->Vertical_5_Result.size() > 0) {
		Sort_List.push_back(vh_array->Vertical_5_Result.front());
		vh_array->Vertical_5_Result.pop_front();
	}

	if (vh_array->Vertical_6_Result.size() > 0) {
		Sort_List.push_back(vh_array->Vertical_6_Result.front());
		vh_array->Vertical_6_Result.pop_front();
	}
	
	if (vh_array->Vertical_7_Result.size() > 0) {
		Sort_List.push_back(vh_array->Vertical_7_Result.front());
		vh_array->Vertical_7_Result.pop_front();
	}
	
	
	
	
	

	return Sort_List;
}


int main(int argc, char* argv[])
{
	VH_Array vh_Array;


	CursorView();

	int cursor[2] = { 0,0 };

	int Image[HEIGHT][WIDTH] = {
		{0,1,0,1,0,1,0},
		{0,0,1,1,1,0,0},
		{0,1,1,1,1,1,0},
		{1,1,1,1,1,1,1},
		{0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0}
	};

	//ArrayReview(Image);
	int Num = 0;
	list<int> Vertical_Number1; // 맨아래
	list<int> Vertical_Number2; // 중간
	list<int> Vertical_Number3; // 상단 세로줄 출력문



	CheckNemoCount_Horizontal(&vh_Array, Image);
	CheckNemoCount_Vertical(&vh_Array, Image);

	
	Vertical_Number1 = Vertical_Sort(&vh_Array);
	Vertical_Number2 = Vertical_Sort(&vh_Array);



	while (1)
	{



		if (GetAsyncKeyState(VK_ESCAPE) && 0x0001)
		{
			break;
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			if (0 <= (cursor[0] - 1))
			{
				cursor[0]--;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			if (WIDTH - 1 >= (cursor[0] + 1))
			{
				cursor[0]++;
			}
		}
		if (GetAsyncKeyState(VK_UP) & 0x0001)
		{
			if (0 <= (cursor[1] - 1))
			{
				cursor[1]--;
			}
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x0001)
		{
			if (HEIGHT - 1 >= (cursor[1] + 1))
			{
				cursor[1]++;
			}
		}

		//선택!
		if (GetAsyncKeyState(VK_SPACE) & 0x0001)
		{
			CONSOLE_SCREEN_BUFFER_INFO presentCur;
			GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
			printf("%d, %d\n", presentCur.dwCursorPosition.X, presentCur.dwCursorPosition.Y);

		}
		

		int i = 0;
		int j = 0;
		for (i = 0; i < WIDTH + 3 + 3; i++) //2
			for (j = 0; j < HEIGHT + 3 + 3; j++) //2
			{
				gotoxy(i * 2 + 10, j + 10);

				if (j == 1 + 3 || j == HEIGHT + 2 + 3) //0 1
				{
					printf("--");
				}
				else if (i == 1 + 3) { //0
					
					printf("|");
				}
				else if (i == WIDTH + 2 + 3) { //1
					printf(" |");
				}
				else if (j == 3 && i == 5) { // 세로 부분 힌트 표기
					for (int data : Vertical_Number1) {
						printf("%d ", data);
					}
				}
				else if (j == 2 && i == 6) { 
					for (int data : Vertical_Number2) {
						printf("%d       ", data);
					}
				}
				else if (i == 0&& j == 2 + 3) { // 가로 부분 힌트 표기
					printf("  ");
					for (int data : vh_Array.Horizontal_1_Result) {
						printf("%d ", data);
					}
				}
				else if (i == 0 && j == 3 + 3) {
					printf("  ");
					for (int data : vh_Array.Horizontal_2_Result) {
						printf("%5d ", data);
					}
				}
				else if (i == 0 && j == 4 + 3) {
					printf("  ");
					for (int data : vh_Array.Horizontal_3_Result) {
						printf("%5d ", data);
					}
				}
				else if (i == 0 && j == 5 + 3) {
					printf("  ");
					for (int data : vh_Array.Horizontal_4_Result) {
						printf("%5d ", data);
					}
				}
				else if (i == 0 && j == 6 + 3) {
					printf("  ");
					for (int data : vh_Array.Horizontal_5_Result) {
						printf("%5d ", data);
					}
				}
				else if (i == 0 && j == 7 + 3) {
					printf("  ");
					for (int data : vh_Array.Horizontal_6_Result) {
						printf("%5d ", data);
					}
				}

				else
				{
					if (Image[(j) - HEIGHT][WIDTH + (i - 2 - 3)] == 0) //4 1
					{
						if (i - 2 - 3 == cursor[0] && j - 2 - 3 == cursor[1])
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
							printf("□");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						}
						else if (i > 3 && j > 3)
						{
							printf("□");
						}
					}
					else
					{
						if (i - 2  - 3 == cursor[0] && j - 2 - 3 == cursor[1]) // 1 
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
							printf("□");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						}
						else if (i > 3 && j > 3)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							printf("□");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						}
					}
				}
			}


	}

	return 0;
}