/*将一个链表中元素值为x的结点删除。（链表数据域为整数，初始长为6个元素）
**输入提示信息："输入数组%d个元素的值。\n"
**输入格式："%d"
**输出提示："此链表各个结点的数据域为："
**输出格式："%d "
**输入提示信息："输入要删除的数据x: "
**输入格式："%d"
**输出提示： "删除后链表各个结点的数据域为："
**输出格式："%d "
 

程序运行示例1：
输入数组6个元素的值。
11 22 33 44 55 66
此链表各个结点的数据域为：11 22 33 44 55 66 
输入要删除的数据x: 33
删除后链表各个结点的数据域为：11 22 44 55 66 

程序运行示例2：
输入数组6个元素的值。↙
6 2 7 4 5 9
此链表各个结点的数据域为：6 2 7 4 5 9 ↙
输入要删除的数据x: 8
删除后链表各个结点的数据域为：6 2 7 4 5 9 ↙*/ 





#include <stdio.h>
#include <stdlib.h>
 
#define N 6
 
struct LNode
{                 
    int data;
    struct LNode *next;
}                 ;
 
struct LNode* create_rear(int a[], int n);
void output(struct LNode *h) ;
struct LNode* delete_node(struct LNode* h, int x);
 
int main(int argc, char *argv[])
{                 
    int a[N], i, x;
    struct LNode* head;
 
    printf("输入数组%d个元素的值。\n", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
 
    /*创建链表head,其结点的值依次为数组a元素的值*/
    head = create_rear(a, N);
    /*删除前输出链表head*/
    printf("此链表各个结点的数据域为：");
    output(head);
 
    printf("输入要删除的数据x: ");
    scanf("%d", &x);
    head = delete_node(head, x);   /*调用删除函数*/
    printf("删除后链表各个结点的数据域为：");
    output(head);  /*删除后输出链表head*/
 
    return 0;
}                 
 
struct LNode* create_rear(int a[], int n)
{                 
    /*新建一个链表h，每个结点依次插入到链尾，将链表的头指针返回 */
    struct LNode *h = NULL;
    struct LNode *s, *r; /*用s指向要插入结点，r指向链表的尾结点*/
    int i;
 
    for (i = 0; i < n; i++)
    {                 
        s = (struct LNode *) malloc(sizeof(struct LNode));
        s->data = a[i];
        s->next = NULL;
        if (h == NULL)
            h = s;        /*如果链表为空，则头指针h指向s */
        else
            r->next = s;  /*否则将s链接到尾结点r之后     */
        r = s;                /*将r指向尾结点                */
    }
    return h;  /*返回链表的头指针*/
}                 
 
void output(struct LNode *h)
{                 
    /*将链表h的各个结点的数据域依次输出，即遍历该链表*/
    struct LNode *p = h;/*从第一个结点开始，用p依次指向各个结点*/
    while (p)
    {                 
        /*只要p是一个非空结点，则输出其数据域，然后将p后移*/
        printf("%d ", p->data);
        p = p->next;  //将p后移
    }
    printf("\n");
}                 
 
struct LNode* delete_node(struct LNode* h, int x)
{                 
    /*将链表h中值为x的结点第一个结点删除，并返回头指针。*/
    struct LNode *pre, *p;/*pre所指结点为p所指结点的前驱*/
 
    p = h;
    while (p && x != p->data)
    {                 
        /*如果p不空，且x不等于p所指结点的数据域,p后移，pre为p的前驱*/
        pre = p;
        p = p->next;
    }
    if (p)
    {                 
        /*在链表中找到了要删除的结点p，即p->data为x*/
        if (p == h)
        {                 
            /*p为链首结点，由于p没有前驱，删除后p的后继结点成为链首，需修改头指针*/
            h = p->next;
        }
        else
        {                 
            /*删除的p非链首结点，则p有前驱pre，删除时需将pre后面链接到p的后继结点*/
            pre->next = p->next;
        }
    }
 
    return h;
} 
