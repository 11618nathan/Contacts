
// ±âº» ÀÔÃâ·Â Çì´õ ÆÄÀÏ
#include <stdio.h>

//#include <insert.h>

// ¸Ş¸ğ¸® ±âº» ÇÔ¼ö Çì´õ ÆÄÀÏ
#include <string.h>


#define MAX 250

// ¿¬¶ôÃ³ °³ÀÎ ±¸Á¶Ã¼
typedef struct {
	char name[30];
	char number[30];
	char add[30];
	char bir[30];
}User;

// ÇÔ¼ö ¼±¾ğºÎ
void insert(User* ptr, int* num);
int deleted(User* ptr, int* num);
int search(User* ptr, int* num);
void printAll(User* ptr, int* num);

// main ÇÔ¼ö
int main(void)
{
	int input;
	User user[MAX];
	int person = 0;

	while (1)
	{
		printf("***** Menu ***** \n");
		printf("1.¸ñ·Ïº¸±â   2.Ãß°¡   3.°Ë»ö   4.»èÁ¦   5.Á¾·á\n");
		scanf_s("%d", &input);

		if (input == 1)
		{
			printAll(user, &person);

		}
		else if (input == 2)
		{
			insert(user, &person);

		}
		else if (input == 3)
		{
			search(user, &person);
		}
		else if (input == 4)
		{
			deleted(user, &person);
		}
		else if (input == 5)
		{
			return 0;
		}
		else
			printf("Erorr \n\n");
		puts("");
	}
	return 0;
}


<<<<<<< HEAD
// »èÁ¦
=======
// ì‚½ì…
void insert(User* ptr, int* num)
{Â 
    //ìœ ì €ì •ë³´ê°€ ê½‰ ì°¨ì§€ ì•Šìœ¼ë©´Â 
    if (*num < MAX)Â 
    {Â Â 
        printf("ì¶”ê°€í•  ì´ë¦„: ");
        scanf("%s", ptr[*num].name);
        printf("ì¶”ê°€í•  ì „í™”ë²ˆí˜¸: ");
        scanf("%s", ptr[*num].number);
        printf("ì¶”ê°€í•  ì£¼ì†Œ: ");
        scanf("%s", ptr[*num].add);
        printf("ì¶”ê°€í•  ìƒì¼: ");
        scanf("%s", ptr[*num].bir);Â 
        (*num)++;
        printf("------ ì¶”ê°€ ì™„ë£Œ ------ \n");
    }
 Â   // ê³µê°„XÂ 
    else
        printf("FULL \n");
}


// ì‚­ì œ
>>>>>>> c511de327f2d5b4d04d0acdd1a4ff7d6af713ced
int deleted(User* ptr, int* num)
{
	char name[30];
	int i, j;

	// 1°³ ÀÌ»ó
	if (*num > 0)
	{
		printf("»èÁ¦ÇÒ ÀÌ¸§: ");
		scanf("%s", name);

		for (i = 0; i < MAX; i++)
		{
			// ¹®ÀÚ¿­ ºñ±³ ÇÔ¼ö - strcmp
			if (strcmp(name, ptr[i].name) == 0)
			{
				(*num)--;
				printf("»èÁ¦ ¿Ï·á \n");

				// ¾øÀ» °æ¿ì
				if (i != MAX - 1)
				{
					for (j = i; j < MAX; j++)
					{
						// ¹®ÀÚ¿­ º¹»ç ÇÔ¼ö - strcpy
						strcpy(ptr[j].name, ptr[j + 1].name);
						strcpy(ptr[j].number, ptr[j + 1].number);
						strcpy(ptr[j].add, ptr[j + 1].add);
						strcpy(ptr[j].bir, ptr[j + 1].bir);
					}

					// ¸¶Áö¸· NULL
					*ptr[MAX - 1].name = NULL;
					*ptr[MAX - 1].number = NULL;
					*ptr[MAX - 1].add = NULL;
					*ptr[MAX - 1].bir = NULL;
				}

				// ÀÖÀ» °æ¿ì
				else
				{
					// ¸¶Áö¸· NULL
					*ptr[MAX - 1].name = NULL;
					*ptr[MAX - 1].number = NULL;
					*ptr[MAX - 1].add = NULL;
					*ptr[MAX - 1].bir = NULL;
				}
				return 0;
			}
		}
		printf("¾ø½À´Ï´Ù. \n");
		return 0;
	}
	// À¯Àú Á¤º¸X
	else
	{
		printf("µ¥ÀÌÅÍ ¾ø½À´Ï´Ù.\n");
		return 0;
	}
}

// °Ë»ö ÇÔ¼ö
int search(User* ptr, int* num)
{
	char name[30];
	int i;

	// 1°³ ÀÌ»ó
	if (*num > 0)
	{
		printf("°Ë»öÇÒ ÀÌ¸§: ");
		scanf("%s", name);

		for (i = 0; i < MAX; i++)
		{
			// ¹İÈ¯ °ªÀÌ 0 -> !=
			if (!strcmp(name, ptr[i].name))
			{
				printf("ÀÌ¸§: %s \n", ptr[i].name);
				printf("ÀüÈ­¹øÈ£: %s \n", ptr[i].number);
				printf("ÁÖ¼Ò: %s \n", ptr[i].add);
				printf("»ıÀÏ: %s \n", ptr[i].bir);
				printf("Ã£¾Ò½À´Ï´Ù.. \n");
				return 0;
			}
		}
		printf("Ãâ·Â ¿Ï·á \n");
		return 0;
	}
	else
	{
		printf("ÇØ´ç µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù. \n");
		return 0;
	}
}

// ¸ğµÎ Ãâ·Â
void printAll(User* ptr, int* num)
{
	int i = 0;

	if (*num > 0)
	{
		for (i = 0; i < *num; i++)
		{
			printf("ÀÌ¸§: %s \n", ptr[i].name);
			printf("ÀüÈ­¹øÈ£: %s \n", ptr[i].number);
			printf("ÁÖ¼Ò: %s \n", ptr[i].add);
			printf("»ıÀÏ: %s \n", ptr[i].bir);
			puts("");
		}
		printf("¸ğµÎ Ãâ·Â. \n");
	}
	else
		printf("ÇØ´ç µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù. \n");
}

