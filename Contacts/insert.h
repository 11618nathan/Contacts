
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
