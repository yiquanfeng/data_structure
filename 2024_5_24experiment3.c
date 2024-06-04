#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int ascii;
	int weight;
	int Parent, LeftChild, RightChild;
} HTNode, *HuffmanTree;

struct leaf
{
	int ASCII;
	char code[20];
}; 
struct leaf leaves[30];

FILE *file2 = NULL;
void Select(HuffmanTree HT, int range, int *index1, int *index2)
{
	int min1 = 1000, min2 = 1000;
	*index1 = 0;
	*index2 = 0;

	for (int i = 1; i <= range; i++)
	{
		if (HT[i].Parent == 0)
		{
			if (HT[i].weight < min1)
			{
				min2 = min1;
				*index2 = *index1;
				min1 = HT[i].weight;
				*index1 = i;
			}
			else if (HT[i].weight < min2)
			{
				min2 = HT[i].weight;
				*index2 = i;
			}
		}
	}
	if (HT[*index1].weight >= HT[*index2].weight)
	{
		int buffer;
		buffer = *index1;
		*index1 = *index2;
		*index2 = buffer;
	}
}
void CreateHuffmanTree(HuffmanTree *HT, int n, int frq[])
{
	if (n <= 1)
	{
		return;
	}
	*HT = (HuffmanTree)malloc((2 * n) * sizeof(HTNode));
	if (*HT == NULL)
	{
		fprintf(stderr, "Memory allocation error.\n");
		exit(1);
	}
	for (int i = 1; i <= 2 * n - 1; i++)
	{
		(*HT)[i].ascii = -1;
		(*HT)[i].Parent = 0;
		(*HT)[i].LeftChild = 0;
		(*HT)[i].RightChild = 0;
		(*HT)[i].weight = 0;
	}
	int j = 1;
	for (int i = 1; i <= 256; i++)
	{

		if (frq[i] > 0)
		{
			(*HT)[j].ascii = i;
			(*HT)[j].weight = frq[i];
			j++;
		}
		// printf("%d\n",j-1);
	}
	int index1 = 0;
	int index2 = 0;
	for (int i = n + 1; i <= 2 * n - 1; i++)
	{
		Select(*HT, i - 1, &index1, &index2);
		// printf("%d\t%d\n",(*HT)[index1].weight,(*HT)[index2].weight);
		(*HT)[index1].Parent = i;
		(*HT)[index2].Parent = i;
		(*HT)[i].LeftChild = index1;
		(*HT)[i].RightChild = index2;
		(*HT)[i].weight = (*HT)[index1].weight + (*HT)[index2].weight;
	}
}
void HuffmanEncode(HuffmanTree *HT, int n)
{
	char cd[n];
	cd[n - 1] = '\0';

	for (int i = 1; i <= n; i++)
	{
		int j = (*HT)[i].Parent;
		int c = i;
		int start = n - 1;

		while (j != 0)
		{
			--start;
			if ((*HT)[j].LeftChild == c)
				cd[start] = '0';
			else if ((*HT)[j].RightChild == c)
				cd[start] = '1';
			c = j;
			j = (*HT)[j].Parent;
		}
		// strcpy(leaves[(*HT)[i].ascii].code, &cd[start]); // 将生成的编码字符串复制到叶节点数组中
		// leaves[(*HT)[i].ascii].ASCII = (*HT)[i].ascii; // 存储ASCII值
		int index = start;
		for (int m = 0; m <= n - 1 - start; m++)
		{
			leaves[i].code[m] = cd[index];
			index++;
			// printf("%c\n",leaves[i].code[m]);
		}
	}
}
void Translate(FILE *file)
{
	char ch;
	file2 = fopen("file2.txt", "w");
	file = fopen("file1.txt", "r");
	while ((ch = fgetc(file)) != EOF)
	{
		for (int i = 1; i <= 26; i++)
		{
			if (ch == leaves[i].ASCII)
			{
				fprintf(file2, "%s", leaves[i].code);
				// printf("%s",leaves[i].code);
			}
		}
	}
	fclose(file);
	fclose(file2);
}
void Decode(HuffmanTree *HT)
{
	char ch;
	FILE *file3;
	file2 = fopen("file2.txt", "r");
	file3 = fopen("file3.txt", "w");
	int c = 51;
	while ((ch = fgetc(file2)) != EOF)
	{
		if (ch == '1')
		{
			c = (*HT)[c].RightChild;
		}
		else if (ch == '0')
		{
			c = (*HT)[c].LeftChild;
			// printf("%d\n",c);
		}
		// (*HT)[c].LeftChild == 0 && (*HT)[c].RightChild == 0
		if (c <= 26 && c > 0)
		{
			fprintf(file3,"%c",(*HT)[c].ascii);
			c = 51;
		}
		
	}
	fclose(file2);
	fclose(file3);
}
int main()
	{
		FILE *file1 = NULL;
		char ch;
		HuffmanTree HT;
		FILE *letter_frq = NULL;
		int frequency[256] = {0};
		// LinkHTStr leaf[27];

		char name[20] = "yiquanfeng";
		char gender[20] = "male";
		char school[60] = "beijing university of post and telecommunications";
		char academy[40] = "electronical enginering academy";
		char major[30] = "electronical enginering";
		char hobby[10] = "running";

		file1 = fopen("file1.txt", "w");
		fprintf(file1, "name:%s\r\ngender:%s\r\nschool:%s\r\n", name, gender, school);
		fprintf(file1, "academy:%s\r\nmajor:%s\r\nhobby:%s\r\n", academy, major, hobby);
		fclose(file1);

		file1 = fopen("file1.txt", "r");
		while ((ch = fgetc(file1)) != EOF)
		{
			frequency[(unsigned char)ch]++;
		}
		fclose(file1);
		
		CreateHuffmanTree(&HT, 26, frequency);
		int j = 1;
		for (int i = 1; i <= 256; i++)
		{
			if (frequency[i] > 0)
			{
				leaves[j++].ASCII = i;
				// printf("%d\n",leaves[j-1].ASCII);
			}
		}
		HuffmanEncode(&HT, 27);
		int q = 4;
		letter_frq = fopen("letter_frq.txt", "w");
		for (int i = 0; i < 256; i++)
		{
			if (frequency[i] > 0)
				if (i == ' ')
				{
					fprintf(letter_frq, "' '                       : %d\t%s\n", frequency[i], leaves[3].code);
				}
				else if (i == '\n')
				{
					fprintf(letter_frq, "'\\n'                     : %d\t%s\n", frequency[i], leaves[1].code);
				}
				else if (i == '\r')
				{
					fprintf(letter_frq, "'\\r'                     : %d\t%s\n", frequency[i], leaves[2].code);
				}
				else
				{
					fprintf(letter_frq, "'%c'                      : %d\t%s\n", i, frequency[i], leaves[q++].code);
				}
		}
		fclose(letter_frq);
		Translate(file1);
		Decode(&HT);

		free(HT);

		return 0;
	}