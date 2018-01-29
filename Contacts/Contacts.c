
// �⺻ ����� ��� ����
#include <stdio.h>

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

// ����
void insert(User* ptr, int* num)
{
	//���������� �� ���� ������
	if (*num < MAX)
	{
		printf("�߰��� �̸�: ");
		scanf("%s", ptr[*num].name);
		printf("�߰��� ��ȭ��ȣ: ");
		scanf("%s", ptr[*num].number);
		printf("�߰��� �ּ�: ");
		scanf("%s", ptr[*num].add);
		printf("�߰��� ����: ");
		scanf("%s", ptr[*num].bir);
		(*num)++;
		printf("------ �߰� �Ϸ� ------ \n");
	}

	// ����X
	else
		printf("FULL \n");
}

// ����
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
		}
		printf("��� ���. \n");
	}
	else
		printf("�ش� �����Ͱ� �����ϴ�. \n");
}

