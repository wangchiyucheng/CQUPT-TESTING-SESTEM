/*在一个有序(按非递减顺序)的链表中插入一个元素为x的结点，使插入后的链表仍然有序（链表数据域为整型数，N为6）。
**输入提示："输入数组6个元素的值。\n"
**输入格式："%d"
**输出提示："此链表各个结点的数据域为："
**输出格式："%d "
**输入提示："输入要插入的数据x:"
**输入格式："%d"
**输出提示："插入后链表各个结点的数据域为："
**输出格式："%d "*/
 
#include <stdio.h>
#include <stdlib.h>
 
#define N 6
 
struct LNode
{                   
    int data;
    struct LNode *next;
}                   ;
 
struct LNode* create_rear(int a[], int n);
void output(struct LNode *h) ;
struct LNode* insert_sort(struct LNode* h, int x);
 
int main(int argc, char *argv[])
{                   
    int a[N], i, x;
    struct LNode* head;
 
    printf("输入数组%d个元素的值。\n", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
 
    /*①创建链表head,其结点的值依次为数组a元素的值*/
    head = create_rear(a, N);
    /*②输出链表head*/
    printf("此链表各个结点的数据域为：");
    output(head);
 
    printf("输入要插入的数据x:");
    scanf("%d", &x);
    /*③调用函数insert_sort插入一个元素*/
    head = insert_sort(head, x);
    printf("插入后链表各个结点的数据域为：");
    /*④输出插入后的链表head*/
    output(head);
 
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
        s = (struct LNode *)malloc(sizeof(struct LNode));
        s->data = a[i];
        s->next = NULL;
        if (h == NULL)
            h = s;  /*如果链表为空，则头指针h指向s*/
        else
            r->next = s;    /*否则将s链接到尾结点r之后*/
        r = s;            /*将r指向尾结点*/
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
 
struct LNode* insert_sort(struct LNode* h, int x)
{                   
    /*在已经有序有链表h中，插入值为x的结点，插入后仍有序，并返回头指针。*/
    struct LNode *s, *pre, *p;/*用s表示插入结点，pre为p的前驱*/
    s = (struct LNode *)malloc(sizeof(struct LNode));
    s->data = x;
 
    if (h == NULL)
    {                   
        /*h为空链表*/
        s->next = NULL;
        h = s;
    }
    if (x <= h->data)
    {                   
        /*x不大于链表中第一个结点的数据域，将s插入链首*/
        s->next = h;
        h = s;
    }
    else
    {                   
        p = h;
        while (p && x > p->data)
        {                   
            /*如果p不空，且x不大于p所指结点的数据域,p后移，pre为p的前驱*/
            pre = p;
            p = p->next;
        }
        /*将s插入到pre所指结点之后。*/
        s->next = pre->next;
        pre->next = s;
    }
    return h;
}         
