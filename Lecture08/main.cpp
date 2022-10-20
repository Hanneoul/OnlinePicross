#include <stdio.h>

int main(int argc, char* argv[])
{
	int i = 0;
	for (i = 0; i < argc; i++)
		printf("%d¹ø ÇÐ»ý : %s\n",i, argv[i]);
	return 0;
}