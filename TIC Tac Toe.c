#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>





#define SIZE_OF_BORD 3

int PrintBord(int mat[SIZE_OF_BORD][SIZE_OF_BORD], int size);
int* Print_CHAR_Bord(char mat[SIZE_OF_BORD][SIZE_OF_BORD], int size);
int ComputerGamePoot_X(char* str, int index);
int ComputerGamePoot_O(char* str, int index);
int WiningYet(char str[][SIZE_OF_BORD]);
int* ComputerTurn(char(*str)[SIZE_OF_BORD], char usertool);
int ChakSum(char str[SIZE_OF_BORD][SIZE_OF_BORD]);
int WiningYetAstrtgi(char(*str)[SIZE_OF_BORD], int p1, int p2);
int* ComputerAstrtegiTorn(char(*mat)[SIZE_OF_BORD], char usertool);
char ComputerFinalTurn(char(*mat)[SIZE_OF_BORD], char usertool);
int Randomali1_4(char(*mat)[SIZE_OF_BORD], int thenum, char usertool);
int* UserFriendTurn(char(*str)[SIZE_OF_BORD], char usertool);
int* UserTurn(char(*str)[SIZE_OF_BORD], char usertool, char str1[10]);


int main()
{
	
	srand((unsigned int)time(NULL));
	int Firstbord[SIZE_OF_BORD][SIZE_OF_BORD] = { { 1,2,3}, {4, 5, 6}, {7, 8, 9} },whoplay=0,position = 0, thelevel ;
	char bord[SIZE_OF_BORD][SIZE_OF_BORD] = { {"   "}, {"   "}, {"   "}},usertool;
	int  randomalnumber = rand() % 10, str1[10];

	
	
	printf("\n\n\033[1;31mTIC_Tac_Toe\033[0m\n\n\nplease type your name:\n");

	scanf("%s",str1);
	printf("you will want to play against the computer or against a friend?\nto play against the computer press 1\nto play against a friend press 2\n");
	scanf("%d", &whoplay);
	if (whoplay == 1)
	{
	printf("\n\tAt what level would you like to play?\n\n");
	printf("-to a difficut level anter 1\n-to a medium level anter 2\n-to a low level anter 3\n");
	scanf("%d", &thelevel);
	}
	printf("\n %s please choose X or O:\n",str1);  
	getchar();
	scanf("%c", &usertool);
	PrintBord(Firstbord, 3);
	if (whoplay == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			printf("\n");
			UserTurn(bord, usertool,str1);
			if (WiningYet(bord))
			{
				printf("\n\t\033[1;32mwell done %s you won!\033[0m   \n", str1);

				return;
			}
			Print_CHAR_Bord(bord, 3);
			system("cls");
			if (thelevel == 1)
				ComputerAstrtegiTorn(bord, usertool);
		
			if (thelevel == 2)
				ComputerFinalTurn(bord, usertool);
		
			if (thelevel == 3)
				ComputerTurn(bord, usertool);
		
			printf("\n");
			Print_CHAR_Bord(bord, 3);
			if (WiningYet(bord)){
				printf("\n\t you lose!\tmaybe next time..");
				return;
			}
		}
		printf("\t it's a tie!!!");
	}
	if (whoplay == 2)
	{
			for (int i = 0; i < 4; i++)
			{
			printf("\n");
			UserFriendTurn(bord, usertool);
			if (WiningYet(bord))
			{
				printf("\n\twell done user 2 you won!\n");
				
				return;
			}
			system("cls");
			Print_CHAR_Bord(bord, 3);
			UserTurn(bord, usertool,str1);
			system("cls");
			printf("\n");
			Print_CHAR_Bord(bord, 3);
			if (WiningYet(bord)) {
				printf("\n\t\033[1;32mwell done %s you won!\033[0m   \n", str1);
				return;
			}
		}
			printf("\t it's a tie!!!");
	}
}		

 int* ComputerAstrtegiTorn(char(*mat)[SIZE_OF_BORD], char usertool)
 {
	int randomal1to4 = rand() % 3+1,flag=0 ;
	int sumofbord = ChakSum(mat);
	int finelindex, count = 0;
	if (!count)					//chake if user start in the midel!
	{
		if (mat[1][1] != ' ' && mat[0][0] == ' ' && mat[0][1] == ' ' && mat[0][2] == ' ' && mat[1][0] == ' ' && mat[1][2] == ' ' && mat[2][0] == ' ' && mat[2][1] == ' ' && mat[2][2] == ' ')
		{
				Randomali1_4(mat, randomal1to4,usertool);
		}
			if (usertool == 'x' || usertool == 'X')
			{
				ComputerGamePoot_O((char*)(mat), 5);
			}
			else
			{
				ComputerGamePoot_X((char*)(mat), 5);
			}
				count++; 
	}					
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (WiningYetAstrtgi(mat, i, j))
				{
					finelindex = (3 * i) + (j + 1);
					if (usertool == 'x' || usertool == 'X') {
						ComputerGamePoot_O((char*)(mat), finelindex );
						flag = 1;
					}
					else
					{
						ComputerGamePoot_X((char*)(mat), finelindex);
						flag = 1;
					}
				}
				if (flag)
				{
					break;
				}
			}
				if (flag)
				{
					break;
				}
		}
	
	for (int i = 0; i < 9; i++)
	{
		if (ChakSum(mat) == sumofbord)
		{
			int randomalnumber = rand() % 10;
			if (usertool == 'x' || usertool == 'X')
			{

			ComputerGamePoot_O((char*)(mat), randomalnumber);
			}
			else
			{
				ComputerGamePoot_X((char*)(mat), randomalnumber);
			}
		}
		 if (ChakSum(mat) != sumofbord)
		{
			break;
		}
	}
	return 0;
}		
char ComputerFinalTurn(char(*mat)[SIZE_OF_BORD],char usertool)
{
	int randOmali = rand() % 2;

	if (randOmali)
	{
		ComputerAstrtegiTorn(mat, usertool);
	}
	else
	{
		ComputerTurn(mat, usertool);
	}
	return 0;
}			
int* ComputerTurn(char(*mat2)[SIZE_OF_BORD],char usertool)
{
	int randomalnumber = rand() % 10, sumofbord = ChakSum(mat2),flag = 0;

	if (usertool == 'x' || usertool == 'X')
	{
		ComputerGamePoot_O((char*)(mat2), randomalnumber); //ddd
		flag = 1;
	}
	else
	{
		ComputerGamePoot_X((char*)(mat2), randomalnumber);
		flag = 2;
	}
	for (int i = 0; i < 9; i++)
	{
		if (ChakSum(mat2) == sumofbord)
		{
			randomalnumber  = rand() % 10;
			if (flag == 1)
			{
			ComputerGamePoot_O((char*)(mat2), randomalnumber);
			}
			if (flag == 2) {
				ComputerGamePoot_X((char*)(mat2), randomalnumber);
			}
		}
		if (ChakSum(mat2) == sumofbord)
		{
			break;
		}
	}
	return 0;
}
int* UserTurn(char(*str)[SIZE_OF_BORD],char usertool,char str1[10])
{
	int position;

	printf("%s type the number where you want to put the %c -:\n",str1,usertool);
	scanf("%d", &position);
	if (usertool == 'x' || usertool == 'X')
	{
		if (position < 0 || position > 9)
		{
			printf("Invalid number\n Try again\n");
			UserTurn(str, usertool, str1);
		}
		ComputerGamePoot_X((char*)(str), position);
	}
	else
	{
		if (position < 0 || position > 9)
		{
			printf("Invalid number\n Try again\n");
			UserTurn(str, usertool, str1);
		}
		ComputerGamePoot_O((char*)(str), position);
	}
	return 0;
}
int* UserFriendTurn(char(*str)[SIZE_OF_BORD], char usertool)
{
	int position;
		char friendtool = 'X';

	if (usertool == 'x' || usertool == 'X')
	{
		friendtool = 'O';
	}
	printf("\t user 2 pleasee type the number where you want to put the %c -:\n",friendtool);
	scanf("%d", &position);
	if (usertool == 'x' || usertool == 'X')
	{
		if (position > 9 || position < 0)
		{
			printf("Invalid number\n Try again\n");
			UserFriendTurn(str, usertool);
		}
		ComputerGamePoot_O((char*)(str), position);
	}
	else
	{

		ComputerGamePoot_X((char*)(str), position);	
	}
	return 0;
}
int ComputerGamePoot_X(char* str, int index)
{	
	if (index > 0 && index < 10) {

		if (*(str + index - 1) == ' ')
		{
			*(str + index - 1) = 'X';
			return 1;
		}

	}
	else {
		return 0;
	}

	return 0;
}
int ComputerGamePoot_O(char* str, int index)
{
	if (index > 0 && index < 10) {
	if (*(str + index - 1) == ' ')
	{
		*(str + index - 1) = 'O';

		return 1;
	}
	}
	else {
		return 0;
	}
	return 0;
}
int WiningYet(char(*str)[SIZE_OF_BORD])
{
	if (str[0][0] == str[0][1]&& str[0][0] == str[0][2]&& str[0][0]!=' ')
	{
		return 1;
	}
	if (str[1][0] == str[1][1] && str[1][0] == str[1][2] && str[1][0] != ' ')
	{
		return 1;
	}
	if (str[2][0] == str[2][1] && str[2][0] == str[2][2] && str[2][0] != ' ')
	{
		return 1;
	}
	if (str[0][0] == str[1][0] && str[0][0] == str[2][0] && str[0][0] != ' ')
	{
		return 1;
	}
	if (str[0][1] == str[1][1] && str[0][1] == str[2][1] && str[0][1] != ' ')
	{
		return 1;
	}
	if (str[0][2] == str[1][2] && str[0][2] == str[2][2] && str[0][2] != ' ')
	{
		return 1;
	}
	if (str[0][0] == str[1][1] && str[0][0] == str[2][2] && str[0][0] != ' ')
	{
		return 1;
	}
	if (str[0][2] == str[1][1] && str[0][2] == str[2][0] && str[0][2] != ' ')
	{
		return 1;
	}
	return 0;
}
int WiningYetAstrtgi(char(*str)[SIZE_OF_BORD], int p1, int p2)
{
	if (p1 == 0 && p2 == 0)
	{
		if (str[0][1] == str[0][2] && str[p1][p2] == ' ')
		{
			if (str[0][1] != ' ' || str[0][2] != ' ')
				return 1;

		}
		if (str[1][0] == str[2][0] && str[p1][p2] == ' ')
		{
			if (str[1][0] != ' ' || str[2][0] != ' ')
				return 1;
		}
		if (str[1][1] == str[2][2] && str[p1][p2] == ' ')
		{
			if (str[1][1] != ' ' || str[2][2] != ' ')
				return 1;
		}
	}
	if (p1 == 0 && p2 == 1)
	{
		if (str[1][1] == str[2][1] && str[p1][p2] == ' ')
		{
			if (str[1][1] != ' ' || str[2][1] != ' ')
				return 1;
		}
		if (str[0][0] == str[0][2] && str[p1][p2] == ' ')
		{
			if (str[0][0] != ' ' || str[0][2] != ' ')
				return 1;
		}
	}
	if (p1 == 0 && p2 == 2)
	{
		if (str[0][0] == str[0][1] && str[p1][p2] == ' ')
		{
			if (str[0][0] != ' ' || str[0][1] != ' ')
				return 1;
		}
		if (str[1][1] == str[2][0] && str[p1][p2] == ' ')
		{
			if (str[1][1] != ' ' || str[2][0] != ' ')
				return 1;
		}
		if (str[1][2] == str[2][2] && str[p1][p2] == ' ')
		{
			if (str[1][2] != ' ' || str[2][2] != ' ')
				return 1;
		}
	}
	if (p1 == 1 && p2 == 0)
	{
		if (str[0][0] == str[2][0] && str[p1][p2] == ' ')
		{
			if (str[0][0] != ' ' || str[2][0] != ' ')
				return 1;
		}
		if (str[1][1] == str[1][2] && str[p1][p2] == ' ')
		{
			if (str[1][1] != ' ' || str[1][2] != ' ')
				return 1;
		}
	}
	if (p1 == 1 && p2 == 1)
	{
		if (str[0][1] == str[2][1] && str[p1][p2] == ' ')
		{
			if (str[0][1] != ' ' || str[2][1] != ' ')
				return 1;
		}
		if (str[1][0] == str[1][2] && str[p1][p2] == ' ')
		{
			if (str[1][0] != ' ' || str[1][2] != ' ')
				return 1;
		}
		if (str[0][0] == str[2][2] && str[p1][p2] == ' ')
		{
			if (str[0][0] != ' ' || str[2][2] != ' ')
				return 1;
		}
		if (str[2][0] == str[0][2] && str[p1][p2] == ' ')
		{
			if (str[2][0] != ' ' || str[0][2] != ' ')
				return 1;
		}
	}
	if (p1 == 1 && p2 == 2)
	{
		if (str[0][2] == str[2][2] && str[p1][p2] == ' ')
		{
			if (str[0][2] != ' ' || str[2][2] != ' ')
				return 1;
		}
		if (str[1][0] == str[1][1] && str[p1][p2] == ' ')
		{
			if (str[1][0] != ' ' || str[1][1] != ' ')
				return 1;
		}
	}
	if (p1 == 2 && p2 == 0)
	{
		if (str[0][0] == str[1][0] && str[p1][p2] == ' ')
		{
			if (str[0][0] != ' ' || str[1][0] != ' ')
				return 1;
		}
		if (str[2][1] == str[2][2] && str[p1][p2] == ' ')
		{
			if (str[2][1] != ' ' || str[2][2] != ' ')
				return 1;
		}
		if (str[1][1] == str[0][2] && str[p1][p2] == ' ')
		{
			if (str[1][1] != ' ' || str[0][2] != ' ')
				return 1;
		}
	}
	if (p1 == 2 && p2 == 1)
	{
		if (str[0][1] == str[1][1] && str[p1][p2] == ' ')
		{
			if (str[0][1] != ' ' || str[1][1] != ' ')
				return 1;
		}
		if (str[2][0] == str[2][2] && str[p1][p2] == ' ')
		{
			if (str[2][0] != ' ' || str[2][2] != ' ')
				return 1;
		}
	}
	if (p1 == 2 && p2 == 2)
	{
		if (str[0][2] == str[1][2] && str[p1][p2] == ' ')
		{
			if (str[0][2] != ' ' || str[1][2] != ' ')
				return 1;
		}
		if (str[2][0] == str[2][1] && str[p1][p2] == ' ')
		{
			if (str[2][0] != ' ' || str[2][1] != ' ')
				return 1;
		}
		if (str[0][0] == str[1][1] && str[p1][p2] == ' ')
		{
			if (str[0][0] != ' ' || str[1][1] != ' ')
				return 1;
		}
	}
	return 0;
}
int* Print_CHAR_Bord(char mat[SIZE_OF_BORD][SIZE_OF_BORD], int size)
{
	printf("\n");
	printf(" TIC Tac Toe");

	for (int i = 0; i < size; i++)
	{
		printf("\n");
		printf("%s", "----------------------");
		printf("\n");
		printf("%c", '|');

		for (int j = 0; j < size; j++)
		{
			printf("%3c %c %c", mat[i][j], ' ', '|');
		}
	}
	printf("\n");
	printf("%s", "----------------------");
	printf("\n\n");
	return 0;
}
int PrintBord(int mat[SIZE_OF_BORD][SIZE_OF_BORD], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("\n");
		printf("%s", "----------------------");
		printf("\n");
		printf("%c", '|');

		for (int j = 0; j < size; j++)
		{
			printf("%3d %c %c", mat[i][j], ' ', '|');
		}
	}
	printf("\n");
	printf("%s", "----------------------");
	printf("\n");
	return 0;
}
int ChakSum(char str[SIZE_OF_BORD][SIZE_OF_BORD])
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(str[i][j] != ' ')
			{
				sum++;
			}
		}
	}
	return sum;
}
int Randomali1_4(char(*mat)[SIZE_OF_BORD], int thenum, char usertool)
{
	if (thenum == 1)
	{
		if (usertool == 'x' || usertool == 'X') {
			ComputerGamePoot_O((char*)(mat), 1);
		}
		else
		{
			ComputerGamePoot_X((char*)(mat), 1);
		}
	}
	if (thenum == 2)
	{
		if (usertool == 'x' || usertool == 'X') {
			ComputerGamePoot_O((char*)(mat), 3);
		}
		else
		{
			ComputerGamePoot_X((char*)(mat), 3);
		}
	}
	if (thenum == 3)
	{
		if (usertool == 'x' || usertool == 'X') {
			ComputerGamePoot_O((char*)(mat), 7);
		}
		else
		{
			ComputerGamePoot_X((char*)(mat), 7);
		}
	}
	if (thenum == 4)
	{
		if (usertool == 'x' || usertool == 'X') {
			ComputerGamePoot_O((char*)(mat), 9);

		}
		else
		{
			ComputerGamePoot_X((char*)(mat), 9);

		}
	}
	return 0;
}