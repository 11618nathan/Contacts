
// 기본 입출력 헤더 파일
#include <stdio.h>

// 메모리 기본 함수 헤더 파일
#include <string.h>


#define MAX 250

// 연락처 개인 구조체
typedef struct {
	char name[30];
	char number[30];
	char add[30];
	char bir[30];
}User;

// 함수 선언부
void insert(User* ptr, int* num);
int deleted(User* ptr, int* num);
int search(User* ptr, int* num);
void printAll(User* ptr, int* num);

// main 함수
int main(void)
{
	int input;
	User user[MAX];
	int person = 0;

	while (1)
	{
		printf("***** Menu ***** \n");
		printf("1.목록보기   2.추가   3.검색   4.삭제   5.종료\n");
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
int deleted(User* ptr, int* num)
{
	char name[30];
	int i, j;

	// 1개 이상
	if (*num > 0)
	{
		printf("삭제할 이름: ");
		scanf("%s", name);

		for (i = 0; i < MAX; i++)
		{
			// 문자열 비교 함수 - strcmp
			if (strcmp(name, ptr[i].name) == 0)
			{
				(*num)--;
				printf("삭제 완료 \n");

				// 없을 경우
				if (i != MAX - 1)
				{
					for (j = i; j < MAX; j++)
					{
						// 문자열 복사 함수 - strcpy
						strcpy(ptr[j].name, ptr[j + 1].name);
						strcpy(ptr[j].number, ptr[j + 1].number);
						strcpy(ptr[j].add, ptr[j + 1].add);
						strcpy(ptr[j].bir, ptr[j + 1].bir);
					}

					// 마지막 NULL
					*ptr[MAX - 1].name = NULL;
					*ptr[MAX - 1].number = NULL;
					*ptr[MAX - 1].add = NULL;
					*ptr[MAX - 1].bir = NULL;
				}

				// 있을 경우
				else
				{
					// 마지막 NULL
					*ptr[MAX - 1].name = NULL;
					*ptr[MAX - 1].number = NULL;
					*ptr[MAX - 1].add = NULL;
					*ptr[MAX - 1].bir = NULL;
				}
				return 0;
			}
		}
		printf("없습니다. \n");
		return 0;
	}
	// 유저 정보X
	else
	{
		printf("데이터 없습니다.\n");
		return 0;
	}
}

// 검색 함수
int search(User* ptr, int* num)
{
	char name[30];
	int i;

	// 1개 이상
	if (*num > 0)
	{
		printf("검색할 이름: ");
		scanf("%s", name);

		for (i = 0; i < MAX; i++)
		{
			// 반환 값이 0 -> !=
			if (!strcmp(name, ptr[i].name))
			{
				printf("이름: %s \n", ptr[i].name);
				printf("전화번호: %s \n", ptr[i].number);
				printf("주소: %s \n", ptr[i].add);
				printf("생일: %s \n", ptr[i].bir);
				printf("찾았습니다.. \n");
				return 0;
			}
		}
		printf("출력 완료 \n");
		return 0;
	}
	else
	{
		printf("해당 데이터가 없습니다. \n");
		return 0;
	}
}

// 모두 출력
void printAll(User* ptr, int* num)
{
	int i = 0;

	if (*num > 0)
	{
		for (i = 0; i < *num; i++)
		{
			printf("이름: %s \n", ptr[i].name);
			printf("전화번호: %s \n", ptr[i].number);
			printf("주소: %s \n", ptr[i].add);
			printf("생일: %s \n", ptr[i].bir);
		}
		printf("모두 출력. \n");
	}
	else
		printf("해당 데이터가 없습니다. \n");
}

