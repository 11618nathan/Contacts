
// �⺻ ����� ��� ����
#include <stdio.h>

//#include <insert.h>

// �޸� �⺻ �Լ� ��� ����
#include <string.h>


#define MAX 250

// ����ó ���� ����ü
typedef struct {
	char name[30];
	char number[30];
	char add[30];
	char bir[30];
}User;

// �Լ� �����
void insert(User* ptr, int* num);
int deleted(User* ptr, int* num);
int search(User* ptr, int* num);
void printAll(User* ptr, int* num);

// main �Լ�
int main(void)
{
	int input;
	User user[MAX];
	int person = 0;

	while (1)
	{
		printf("***** Menu ***** \n");
		printf("1.��Ϻ���   2.�߰�   3.�˻�   4.����   5.����\n");
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
// ����
=======
// 삽입
void insert(User* ptr, int* num)
{ 
    //유저정보가 꽉 차지 않으면 
    if (*num < MAX) 
    {  
        printf("추가할 이름: ");
        scanf("%s", ptr[*num].name);
        printf("추가할 전화번호: ");
        scanf("%s", ptr[*num].number);
        printf("추가할 주소: ");
        scanf("%s", ptr[*num].add);
        printf("추가할 생일: ");
        scanf("%s", ptr[*num].bir); 
        (*num)++;
        printf("------ 추가 완료 ------ \n");
    }
    // 공간X 
    else
        printf("FULL \n");
}


// 삭제
>>>>>>> c511de327f2d5b4d04d0acdd1a4ff7d6af713ced
int deleted(User* ptr, int* num)
{
	char name[30];
	int i, j;

	// 1�� �̻�
	if (*num > 0)
	{
		printf("������ �̸�: ");
		scanf("%s", name);

		for (i = 0; i < MAX; i++)
		{
			// ���ڿ� �� �Լ� - strcmp
			if (strcmp(name, ptr[i].name) == 0)
			{
				(*num)--;
				printf("���� �Ϸ� \n");

				// ���� ���
				if (i != MAX - 1)
				{
					for (j = i; j < MAX; j++)
					{
						// ���ڿ� ���� �Լ� - strcpy
						strcpy(ptr[j].name, ptr[j + 1].name);
						strcpy(ptr[j].number, ptr[j + 1].number);
						strcpy(ptr[j].add, ptr[j + 1].add);
						strcpy(ptr[j].bir, ptr[j + 1].bir);
					}

					// ������ NULL
					*ptr[MAX - 1].name = NULL;
					*ptr[MAX - 1].number = NULL;
					*ptr[MAX - 1].add = NULL;
					*ptr[MAX - 1].bir = NULL;
				}

				// ���� ���
				else
				{
					// ������ NULL
					*ptr[MAX - 1].name = NULL;
					*ptr[MAX - 1].number = NULL;
					*ptr[MAX - 1].add = NULL;
					*ptr[MAX - 1].bir = NULL;
				}
				return 0;
			}
		}
		printf("�����ϴ�. \n");
		return 0;
	}
	// ���� ����X
	else
	{
		printf("������ �����ϴ�.\n");
		return 0;
	}
}

// �˻� �Լ�
int search(User* ptr, int* num)
{
	char name[30];
	int i;

	// 1�� �̻�
	if (*num > 0)
	{
		printf("�˻��� �̸�: ");
		scanf("%s", name);

		for (i = 0; i < MAX; i++)
		{
			// ��ȯ ���� 0 -> !=
			if (!strcmp(name, ptr[i].name))
			{
				printf("�̸�: %s \n", ptr[i].name);
				printf("��ȭ��ȣ: %s \n", ptr[i].number);
				printf("�ּ�: %s \n", ptr[i].add);
				printf("����: %s \n", ptr[i].bir);
				printf("ã�ҽ��ϴ�.. \n");
				return 0;
			}
		}
		printf("��� �Ϸ� \n");
		return 0;
	}
	else
	{
		printf("�ش� �����Ͱ� �����ϴ�. \n");
		return 0;
	}
}

// ��� ���
void printAll(User* ptr, int* num)
{
	int i = 0;

	if (*num > 0)
	{
		for (i = 0; i < *num; i++)
		{
			printf("�̸�: %s \n", ptr[i].name);
			printf("��ȭ��ȣ: %s \n", ptr[i].number);
			printf("�ּ�: %s \n", ptr[i].add);
			printf("����: %s \n", ptr[i].bir);
			puts("");
		}
		printf("��� ���. \n");
	}
	else
		printf("�ش� �����Ͱ� �����ϴ�. \n");
}

