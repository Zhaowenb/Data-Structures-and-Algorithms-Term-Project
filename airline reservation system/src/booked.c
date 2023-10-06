#include"../include/booked.h"

/*
初始化booked链表
函数名：InitBookedList
参数：无
返回值：空单链表
*/
Booked *InitBookedList()
{
    Booked *head = (Booked *)malloc(sizeof(Booked));
    head->next = NULL;
    return head;
}

/*
判断booked链表是否为空
函数名：isEmptyBookedList
参数：Booked *L
返回值：1为空，0为非空
*/
int isEmptyBookedList(Booked *L)
{
    if(L->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
在booked链表打印所有订单信息
函数名：PrintBookedList
参数：Booked *L
返回值：无
*/
void PrintBookedList(Booked *L)
{
    Booked *p = L->next;
    while(p != NULL)
    {
        printf("订单号：%lu\t姓名：%s\t身份证号：%lu\t购买票数：%d\t座位号：%d\n",p->orderform_no,p->name,p->certificate_no,p->amount,p->seat_no);
        p = p->next;
    }
}

/*
打印booked
函数名：PrintBooked
参数：Booked *b
返回值：无
*/
void PrintBooked(Booked *b)
{
    printf("订单号：%lu\t姓名：%s\t身份证号：%lu\t购买票数：%d\t座位号：%d\n",b->orderform_no,b->name,b->certificate_no,b->amount,b->seat_no);
}

/* 
booked链表长度
函数名：LengthBookedList
参数：Booked *L
返回值：链表长度
*/
int LengthBookedList(Booked *L)
{
    Booked *p = L->next;
    int length = 0;
    while(p != NULL)
    {
        length++;
        p = p->next;
    }
    return length;
}

/*
在booked链表中按值查找
函数名：GetBooked
参数：Booked *L, double orderform_no
返回值：元素所在位置，若不存在则返回0
*/
int GetBooked(Booked *L, long orderform_no)
{
    Booked *p = L->next;
    int i = 1;
    while(p != NULL && p->orderform_no != orderform_no)
    {
        p = p->next;
        i++;
    }
    if(p == NULL)
    {
        return 0;
    }
    else
    {
        return i;
    }
}

/*
在booked链表中按位查找
函数名：getBookedByIndex
参数：Booked *L, int index
返回值：Booked指针
*/
Booked *getBookedByIndex(Booked *L, int index)
{
    if(index < 0 || index > LengthBookedList(L))
    {
        printf("查找位置有误！\n");
        return NULL;
    }
    Booked *p = L->next;
    int i = 1;
    while(p != NULL && i < index)
    {
        p = p->next;
        i++;
    }
    if(p == NULL)
    {
        return NULL;
    }
    else
    {
        return p;
    }
}

/*
在booked链表中插入元素
函数名：InsertBookedList
参数：Bo0ked *L, int index, Booked *b
返回值：成功返回1，失败返回0
*/
int InsertBookedList(Booked *L, int index, Booked *b)
{
    if(index < 1 || index > LengthBookedList(L) + 1)
    {
        printf("插入位置有误！\n");
        return 0;
    }
    Booked *p = L;
    int i = 1;
    while(p != NULL && i < index)
    {
        p = p->next;
        i++;
    }
    if(p == NULL)
    {
        return 0;
    }
    else
    {
        Booked *b_new = (Booked *)malloc(sizeof(Booked));
        b_new->orderform_no = b->orderform_no;
        strcpy(b_new->name,b->name);
        b_new->certificate_no = b->certificate_no;
        b_new->amount = b->amount;
        b_new->seat_no = b->seat_no;
        b_new->next = p->next;
        p->next = b_new;
        return 1;
    }
}

/*
创建booked链表
函数名：CreateBookedList
参数：csv文件地址, int n
返回值：单链表
*/
Booked *CreateBookedList(char *filename, int n)
{
    Booked *L = InitBookedList();
    FILE *fp = fopen(filename,"r");
    if(fp == NULL)
    {
        printf("文件打开失败！\n");
        return NULL;
    }
    Booked *p = L;
    for(int i = 0; i < n; i++)
    {
        Booked *b_new = (Booked *)malloc(sizeof(Booked));
        fscanf(fp,"%lu,%[^,],%lu,%d,%d\n",&b_new->orderform_no,b_new->name,&b_new->certificate_no,&b_new->amount,&b_new->seat_no);
        b_new->next = NULL;
        p->next = b_new;
        p = p->next;
    }
    fclose(fp);
    return L;
}

/*
更新csv文件
函数名：UpdateBookedList
参数：Booked *L, char *filename
返回值：无
*/
void UpdateBookedList(Booked *L, char *filename)
{
    FILE *fp = fopen(filename,"w");
    if(fp == NULL)
    {
        printf("文件打开失败！\n");
        return;
    }
    Booked *p = L->next;
    while(p != NULL)
    {
        fprintf(fp,"%lu,%s,%lu,%d,%d\n",p->orderform_no,p->name,p->certificate_no,p->amount,p->seat_no);
        p = p->next;
    }
    fclose(fp);
}

/*
在booked链表中删除元素
函数名：DeleteBookedList
参数：Booked *L, int index
返回值：成功返回1，失败返回0
*/
int DeleteBookedList(Booked *L, int index)
{
    if(index < 1 || index > LengthBookedList(L))
    {
        printf("删除位置有误！\n");
        return 0;
    }
    Booked *p = L;
    int i = 1;
    while(p != NULL && i < index)
    {
        p = p->next;
        i++;
    }
    if(p == NULL)
    {
        return 0;
    }
    else
    {
        Booked *q = p->next;
        p->next = q->next;
        free(q);
        return 1;
    }
}

/*
销毁booked链表
函数名：DestroyBookedList
参数：Booked *L
返回值：无
*/
void DestroyBookedList(Booked *L)
{
    Booked *p = L;
    while(p != NULL)
    {
        Booked *q = p->next;
        free(p);
        p = q;
    }
}

// // 测试函数
// int main()
// {
//     Booked *L = InitBookedList();
//     printf("是否为空：%d\n",isEmptyBookedList(L));
//     printf("长度：%d\n",LengthBookedList(L));
//     Booked b1 = {1,"张三",123456789,1,1,NULL};
//     Booked b2 = {2,"李四",987654321,2,2,NULL};
//     Booked b3 = {3,"王五",123456789,3,3,NULL};
//     Booked b4 = {4,"赵六",987654321,4,4,NULL};
//     InsertBookedList(L,1,&b1);
//     InsertBookedList(L,2,&b2);
//     InsertBookedList(L,3,&b3);

//     InsertBookedList(L,4,&b4);
//     PrintBookedList(L);
//     printf("是否为空：%d\n",isEmptyBookedList(L));
//     printf("长度：%d\n",LengthBookedList(L));
//     printf("第2个元素：%d\n",GetBooked(L,2));
//     PrintBooked(getBookedByIndex(L,2));
//     printf("第3个元素：%d\n",GetBooked(L,3));
//     printf("第4个元素：%d\n",GetBooked(L,4));
//     return 0;
// }









