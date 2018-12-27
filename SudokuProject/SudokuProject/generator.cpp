#include"generator.h"
#pragma warning(disable : 4996)


char finals_buffer[163000000];
int cnt = 0;
int rest = 0;
int remv[144][9] = { 0,3,6,1,4,7,2,5,8,  0,3,6,2,5,8,1,4,7,  0,3,6,1,4,7,2,8,5,  0,3,6,2,8,5,1,4,7,
					 0,3,6,1,4,7,5,2,8,  0,3,6,5,2,8,1,4,7,  0,3,6,1,4,7,5,8,2,  0,3,6,5,8,2,1,4,7,
					 0,3,6,1,4,7,8,2,5,  0,3,6,8,2,5,1,4,7,  0,3,6,1,4,7,8,5,2,  0,3,6,8,5,2,1,4,7,
					 0,3,6,1,7,4,2,5,8,  0,3,6,2,5,8,1,7,4,  0,3,6,1,7,4,2,8,5,  0,3,6,2,8,5,1,7,4,
					 0,3,6,1,7,4,5,2,8,  0,3,6,5,2,8,1,7,4,  0,3,6,1,7,4,5,8,2,  0,3,6,5,8,2,1,7,4,
					 0,3,6,1,7,4,8,2,5,  0,3,6,8,2,5,1,7,4,  0,3,6,1,7,4,8,5,2,  0,3,6,8,5,2,1,7,4,
					 0,3,6,4,1,7,2,5,8,  0,3,6,2,5,8,4,1,7,  0,3,6,4,1,7,2,8,5,  0,3,6,2,8,5,4,1,7,
					 0,3,6,4,1,7,5,2,8,  0,3,6,5,2,8,4,1,7,  0,3,6,4,1,7,5,8,2,  0,3,6,5,8,2,4,1,7,
					 0,3,6,4,1,7,8,2,5,  0,3,6,8,2,5,4,1,7,  0,3,6,4,1,7,8,5,2,  0,3,6,8,5,2,4,1,7,
					 0,3,6,4,7,1,2,5,8,  0,3,6,2,5,8,4,7,1,  0,3,6,4,7,1,2,8,5,  0,3,6,2,8,5,4,7,1,
					 0,3,6,4,7,1,5,2,8,  0,3,6,5,2,8,4,7,1,  0,3,6,4,7,1,5,8,2,  0,3,6,5,8,2,4,7,1,
					 0,3,6,4,7,1,8,2,5,  0,3,6,8,2,5,4,7,1,  0,3,6,4,7,1,8,5,2,  0,3,6,8,5,2,4,7,1,
					 0,3,6,7,1,4,2,5,8,  0,3,6,2,5,8,7,1,4,  0,3,6,7,1,4,2,8,5,  0,3,6,2,8,5,7,1,4,
					 0,3,6,7,1,4,5,2,8,  0,3,6,5,2,8,7,1,4,  0,3,6,7,1,4,5,8,2,  0,3,6,5,8,2,7,1,4,
					 0,3,6,7,1,4,8,2,5,  0,3,6,8,2,5,7,1,4,  0,3,6,7,1,4,8,5,2,  0,3,6,8,5,2,7,1,4,
					 0,3,6,7,4,1,2,5,8,  0,3,6,2,5,8,7,4,1,  0,3,6,7,4,1,2,8,5,  0,3,6,2,8,5,7,4,1,
					 0,3,6,7,4,1,5,2,8,  0,3,6,5,2,8,7,4,1,  0,3,6,7,4,1,5,8,2,  0,3,6,5,8,2,7,4,1,
					 0,3,6,7,4,1,8,2,5,  0,3,6,8,2,5,7,4,1,  0,3,6,7,4,1,8,5,2,  0,3,6,8,5,2,7,4,1,
					 0,6,3,1,4,7,2,5,8,  0,6,3,2,5,8,1,4,7,  0,6,3,1,4,7,2,8,5,  0,6,3,2,8,5,1,4,7,
					 0,6,3,1,4,7,5,2,8,  0,6,3,5,2,8,1,4,7,  0,6,3,1,4,7,5,8,2,  0,6,3,5,8,2,1,4,7,
					 0,6,3,1,4,7,8,2,5,  0,6,3,8,2,5,1,4,7,  0,6,3,1,4,7,8,5,2,  0,6,3,8,5,2,1,4,7,
					 0,6,3,1,7,4,2,5,8,  0,6,3,2,5,8,1,7,4,  0,6,3,1,7,4,2,8,5,  0,6,3,2,8,5,1,7,4,
					 0,6,3,1,7,4,5,2,8,  0,6,3,5,2,8,1,7,4,  0,6,3,1,7,4,5,8,2,  0,6,3,5,8,2,1,7,4,
					 0,6,3,1,7,4,8,2,5,  0,6,3,8,2,5,1,7,4,  0,6,3,1,7,4,8,5,2,  0,6,3,8,5,2,1,7,4,
					 0,6,3,4,1,7,2,5,8,  0,6,3,2,5,8,4,1,7,  0,6,3,4,1,7,2,8,5,  0,6,3,2,8,5,4,1,7,
					 0,6,3,4,1,7,5,2,8,  0,6,3,5,2,8,4,1,7,  0,6,3,4,1,7,5,8,2,  0,6,3,5,8,2,4,1,7,
					 0,6,3,4,1,7,8,2,5,  0,6,3,8,2,5,4,1,7,  0,6,3,4,1,7,8,5,2,  0,6,3,8,5,2,4,1,7,
					 0,6,3,4,7,1,2,5,8,  0,6,3,2,5,8,4,7,1,  0,6,3,4,7,1,2,8,5,  0,6,3,2,8,5,4,7,1,
					 0,6,3,4,7,1,5,2,8,  0,6,3,5,2,8,4,7,1,  0,6,3,4,7,1,5,8,2,  0,6,3,5,8,2,4,7,1,
					 0,6,3,4,7,1,8,2,5,  0,6,3,8,2,5,4,7,1,  0,6,3,4,7,1,8,5,2,  0,6,3,8,5,2,4,7,1,
					 0,6,3,7,1,4,2,5,8,  0,6,3,2,5,8,7,1,4,  0,6,3,7,1,4,2,8,5,  0,6,3,2,8,5,7,1,4,
					 0,6,3,7,1,4,5,2,8,  0,6,3,5,2,8,7,1,4,  0,6,3,7,1,4,5,8,2,  0,6,3,5,8,2,7,1,4,
					 0,6,3,7,1,4,8,2,5,  0,6,3,8,2,5,7,1,4,  0,6,3,7,1,4,8,5,2,  0,6,3,8,5,2,7,1,4,
					 0,6,3,7,4,1,2,5,8,  0,6,3,2,5,8,7,4,1,  0,6,3,7,4,1,2,8,5,  0,6,3,2,8,5,7,4,1,
					 0,6,3,7,4,1,5,2,8,  0,6,3,5,2,8,7,4,1,  0,6,3,7,4,1,5,8,2,  0,6,3,5,8,2,7,4,1,
					 0,6,3,7,4,1,8,2,5,  0,6,3,8,2,5,7,4,1,  0,6,3,7,4,1,8,5,2,  0,6,3,8,5,2,7,4,1 };


void Secq2Final(int seq[])
{
	for (int i = 0; i < 144; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				finals_buffer[cnt++] = seq[(k + remv[i][j]) % 9] + '0';
				if (k < 8)finals_buffer[cnt++] = ' ';
				else if (k == 8)finals_buffer[cnt++] = '\n';
			}
		}
		rest--;
		if (rest == 0) {
			finals_buffer[cnt++] = '\0';
			return;
		}
		finals_buffer[cnt++] = '\n';
	}

}

void Write2File()
{
	FILE *fp;
	fp = fopen("sudoku.txt", "w");
	if (fp == NULL)
	{
		cout << "Open File sudoku.txt Failed!" << endl;
		return;
	}
	fputs(finals_buffer, fp);
	fclose(fp);

}


void Generate_Sudoku(int finals_num)
{
	int sequence[9] = { 1,2,3,4,5,6,7,8,9 };
	rest = finals_num;

	while (1) {
		Secq2Final(sequence);
		if (rest == 0)break;
		next_permutation(sequence + 1, sequence + 8);
	}
	Write2File();
}
