<<<<<<< HEAD

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
=======
//
>>>>>>> c511de327f2d5b4d04d0acdd1a4ff7d6af713ced
