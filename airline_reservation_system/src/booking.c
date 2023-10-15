#include"../include/booking.h"

/*
初始化booking队列
函数名：InitBookingList
参数：BookingList *L
返回值：无
*/
void InitBookingList(BookingList *L)
{
        //头结点的指针域置空
        Booking *head = (Booking *)malloc(sizeof(Booking));   
        head->next = NULL;
        L->booking_head = head;
        L->booking_tail = head;
}

/*
判断Booking队列是否为空
函数名：IsEmptyBookingList
参数：BookingList L
返回值：1为空，0为非空
*/
int IsEmptyBookingList(BookingList *L)
{
    if(L->booking_head == L->booking_tail)
        return 1;
    else
        return 0;
}

/*
Booking销毁
函数名：DestroyBookingList
参数：BookingList *L
返回值：无
*/
void DestroyBookingList(BookingList *L)
{
    Booking *p = L->booking_head;
    Booking *q = p->next;
    while(q != NULL)
    {
        free(p);
        p = q;
        q = p->next;
    }
    free(p);
    L->booking_head = NULL;
    L->booking_tail = NULL;
}

/*
Booking入队
函数名：EnBookingList
参数：BookingList *L,Booking *e
返回值：无
*/
void EnBookingList(BookingList *L,Booking *e)
{
    Booking *p = (Booking *)malloc(sizeof(Booking));
    if(p == NULL)
    {
        printf("内存分配失败\n");
        return;
    }
    p->next = NULL;
    strcpy(p->name,e->name);
    p->certificate_no = e->certificate_no;
    p->line_no = e->line_no;
    p->date[0] = e->date[0];
    p->date[1] = e->date[1];
    p->date[2] = e->date[2];
    p->time[0] = e->time[0];
    p->time[1] = e->time[1];
    p->amount = e->amount;
    if(L->booking_head == NULL||L->booking_tail == NULL)
    {
        L->booking_head = p;
        L->booking_tail = p;
        // printf("入队成功1\n");
        return;
    }
    else if(L->booking_head == L->booking_tail)
    {
        L->booking_head->next = p;
        L->booking_tail = p;
        // printf("入队成功2\n");
        return;
    }
    else if (L->booking_head != L->booking_tail && L->booking_tail != NULL)
    {
        L->booking_tail->next = p;
        L->booking_tail = p;
        // printf("入队成功3\n");
        return;
    }
}

/*
Booking出队
函数名：DeBookingList
参数：BookingList *L,Booking *e
返回值：无
*/
void DeBookingList(BookingList *L,Booking *e)
{
    Booking *p = L->booking_head->next;
    if(p == NULL)
        return;
    L->booking_head->next = p->next;
    strcpy(e->name,p->name);
    e->certificate_no = p->certificate_no;
    e->line_no = p->line_no;
    e->date[0] = p->date[0];
    e->date[1] = p->date[1];
    e->date[2] = p->date[2];
    e->time[0] = p->time[0];
    e->time[1] = p->time[1];
    e->amount = p->amount;
    free(p);
    if(L->booking_head->next == NULL)
        L->booking_tail = L->booking_head;
}

/*
Booking队列长度
函数名：LengthBookingList
参数：BookingList *L
返回值：Booking队列长度
*/
int LengthBookingList(BookingList *L)
{
    int i = 0;
    
    if (L->booking_head == L->booking_tail)
    {
        return 0;
    }
    Booking *p = L->booking_head->next;
    while(p != NULL)
    {
        i++;
        p = p->next;
    }
    return i;
}

/*
打印函数
函数名：PrintBooking
参数：Booking e
返回值：无
*/
void PrintBooking(Booking *e)
{
    printf("姓名：%s\t",e->name);
    printf("身份证号：%lu\t",e->certificate_no);
    printf("航班号：%llu\t",e->line_no);
    printf("出发日期：%d-%d-%d\t",e->date[0],e->date[1],e->date[2]);
    printf("出发时间：%d:%d\t",e->time[0],e->time[1]);
    printf("预定票数：%d\n",e->amount);
}

/*
Booking队列遍历，对每个元素调用visit回调函数，
函数名：TraverseBookingList
参数：BookingList *L,void (*visit)(Booking)
返回值：无
*/
void TraverseBookingList(BookingList *L,void (*visit)(Booking *b))
{
    Booking *p = L->booking_head->next;
    while(p != NULL)
    {
        visit(p);
        p = p->next;
    }
}

/*
Booking队列查找
函数名：LocateBookingList
参数：BookingList *L,int i,Booking *e
返回值：无
*/
void LocateBookingList(BookingList *L,int i,Booking *e)
{
    int j = 0;
    Booking *p = L->booking_head->next;
    while(p != NULL && j < i)
    {
        j++;
        p = p->next;
    }
    if(p == NULL)
        return;
    strcpy(e->name,p->name);
    e->certificate_no = p->certificate_no;
    e->line_no = p->line_no;
    e->date[0] = p->date[0];
    e->date[1] = p->date[1];
    e->date[2] = p->date[2];
    e->time[0] = p->time[0];
    e->time[1] = p->time[1];
    e->amount = p->amount;
}



/*
Booking取头元素
函数名：GetHeadBookingList
参数：BookingList *L,Booking *e
返回值：成功返回1，失败返回0
*/
int GetHeadBookingList(BookingList *L,Booking *e)
{
    if(L->booking_head->next == NULL)
        return 0;
    strcpy(e->name,L->booking_head->next->name);
    e->certificate_no = L->booking_head->next->certificate_no;
    e->line_no = L->booking_head->next->line_no;
    e->date[0] = L->booking_head->next->date[0];
    e->date[1] = L->booking_head->next->date[1];
    e->date[2] = L->booking_head->next->date[2];
    e->time[0] = L->booking_head->next->time[0];
    e->time[1] = L->booking_head->next->time[1];
    e->amount = L->booking_head->next->amount;
    return 1;
}

/*
Booking读取csv文件初始化
函数名：InputBookingList
参数：BookingList *L，char *filename
返回值：无
*/
void InputBookingList(BookingList *L,char *filename)
{
    FILE *fp;
    fp = fopen(filename,"r");
    if(fp == NULL)
    {
        printf("文件打开失败\n");
        return;
    }
    Booking *e = (Booking *)malloc(sizeof(Booking));
    while(!feof(fp))
    {
        
        fscanf(fp,"%[^,],%lu,%llu,%d-%d-%d,%d:%d,%d\n",e->name,&e->certificate_no,&e->line_no,&e->date[0],&e->date[1],&e->date[2],&e->time[0],&e->time[1],&e->amount);
        EnBookingList(L,e);
    }
    fclose(fp);
}

/*
Booking更新csv文件
函数名：DataupBookingList
参数：BookingList *L， char *filename
返回值：无
*/
void DataupBookingList(BookingList *L,char *filename)
{
    FILE *fp;
    fp = fopen(filename,"w");
    if(fp == NULL)
    {
        printf("文件打开失败\n");
        return;
    }
    Booking *p = L->booking_head->next;
    while(p != NULL)
    {
        fprintf(fp,"%s %lu %llu %d-%d-%d %d:%d %d\n",p->name,p->certificate_no,p->line_no,p->date[0],p->date[1],p->date[2],p->time[0],p->time[1],p->amount);
        p = p->next;
    }
    fclose(fp);
}

// //测试代码
// int main()
// {
//     BookingList L;
//     InitBookingList(&L);
  
    // Booking e;
    // e.certificate_no = 123456789;
    // e.line_no = 123;
    // e.date[0] = 2020;
    // e.date[1] = 12;
    // e.date[2] = 12;
    // e.time[0] = 12;
    // e.time[1] = 12;
    // e.amount = 1;
    // strcpy(e.name,"zhangsan");
    // EnBookingList(&L,&e);
    // e.certificate_no = 987654321;
    // e.line_no = 321;
    // e.date[0] = 2020;
    // e.date[1] = 12;
    // e.date[2] = 12;
    // e.time[0] = 12;
    // e.time[1] = 12;
    // e.amount = 1;
    // strcpy(e.name,"lisi");
    // EnBookingList(&L,&e);
    // TraverseBookingList(&L,PrintBooking);
    // printf("length:%d\n",LengthBookingList(&L));
    // DeBookingList(&L,&e);
    // TraverseBookingList(&L,PrintBooking);
    // printf("length:%d\n",LengthBookingList(&L));
    // DestroyBookingList(&L);
    // printf("length:%d\n",LengthBookingList(&L));
//   InputBookingList(&L,"../References/Booking/booking1.csv");
//     TraverseBookingList(&L,PrintBooking);

//     return 0;
// }