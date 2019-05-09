/*堆栈（Strack）是指这样一段内存，它可以理解为一个筒结构，先放进筒中的数据被后放进筒中的数据“压住”，只有后放进筒中的数据都取出后，先放进去的数据才能被取出，称为“后进先出”。堆栈的长度可随意增加。堆栈结构可用链表实现。设计一个链表结构需包含两个成员：一个存放数据，一个为指向下一个节点的指针。当每次有一个新数据要放入堆栈时，称为“压入堆栈”，这时动态建立一个链表的节点，并连接到链表的结尾；当每次从堆栈中取出一个数据时，称为“弹出堆栈”，这意味着从链表的最后一个节点中取出该节点的数据成员，同时删除该节点，释放该节点所占的内存。
编程用链表方法实现堆栈数据结构。程序至少应该包含三个函数：
1、主函数
2、压栈操作：将5个数据依次压入堆栈
3、出栈操作：将5个数据依次弹出堆栈（注意：因为后进先出的原因，弹出时是逆序，另外，弹出后要删除该节点内存）;

**输入提示：printf("请输入要压栈的整数：");
**输入格式："%d"
**压栈后输出格示："Push %dth Data:%d\n"
**出栈后输出格式："Pop %dth Data:%d\n"

程序运行示例：
请输入要压栈的整数：1↙
Push 1th Data:1↙
请输入要压栈的整数：2↙
Push 2th Data:2↙
请输入要压栈的整数：3↙
Push 3th Data:3↙
请输入要压栈的整数：4↙
Push 4th Data:4↙
请输入要压栈的整数：5↙
Push 5th Data:5↙
Pop 5th Data:5↙
Pop 4th Data:4↙
Pop 3th Data:3↙
Pop 2th Data:2↙
Pop 1th Data:1↙
*/ 






#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{                    
    int data;
    struct stack *next;
}                     STACK;
STACK *head, *pr;
int nodeNum = 0;                            /* 堆栈节点数寄存器 */
STACK *CreateNode(int num);
STACK *PushStack(int num);
int PopStack(void);
int main()
{                    
    int pushNum[5] , popNum[5], i;
    for (i = 0; i < 5; i++)
    {                    
        printf("请输入要压栈的整数：");
        scanf("%d",&pushNum[i]);
        PushStack(pushNum[i]);
        printf("Push %dth Data:%d\n", i + 1, pushNum[i]);
    }
    for (i = 0; i < 5; i++)
    {                    
        popNum[i] = PopStack();
        printf("Pop %dth Data:%d\n", 5 - i, popNum[i]);
    }
    return 0;
}                    
/* 函数功能：生成一个新的节点，并为该节点赋初值，返回指向新的节点的指针 */
STACK *CreateNode(int num)
{                    
    STACK *p;
    p = (STACK *)malloc(sizeof(STACK));
    if (p == NULL)
    {                    
        printf("No enough memory!\n");
        exit(0);
    }
    p->next = NULL;              /* 为新建的节点指针域赋空指针 */
    p->data = num;                   /* 为新建的节点数据区赋值 */
    return p;
}                    
/*  函数功能：将整型变量num的值压入堆栈，返回指向链表新节点的指针 */
STACK *PushStack(int num)
{                    
    if (nodeNum == 0) /* 若为首节点，则保留该节点地址在head中*/
    {                    
        head = CreateNode(num);
        pr = head;
        nodeNum++;  /* 堆栈节点数寄存器+1 */
    }
    else             /* 若不是首节点，则将新建节点连到链表的结尾处 */
    {                    
        pr->next = CreateNode(num);
        pr = pr->next;
        nodeNum++;  /* 堆栈节点数寄存器+1 */
    }
    return pr;
}                    
/*  函数功能：将当前栈顶的数据弹出堆栈，返回从堆栈中弹出的数据 */
int PopStack(void)
{                    
    STACK *p = head;
    int result;
    for (;;)
    {                    
        if (p->next == NULL)     /* 查找最后一个节点 */
        {                    
            break;
        }
        else
        {                    
            pr = p;             /* 记录最后一个节点的前一个节点的地址 */
            p = p->next;
            nodeNum--;          /* 堆栈节点数寄存器-1 */
        }
    }
    pr->next = NULL;          /* 将末节点的前一个节点置成末节点 */
    result = p->data;
    free(p);
    return result;
}
