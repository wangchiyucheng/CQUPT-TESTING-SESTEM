/*将一个链表按逆序排列，即将链头当链尾，链尾当链头。
**输入提示："\n请输入链表（非数表示结束）\n"
**输入提示："结点值："
**输出提示："\n原来表：\n"
**输出格式："%4d"
**输出提示："\n\n反转表：\n"
**输出格式："%4d"

程序的运行示例如下：
请输入链表（非数表示结束）
结点值：3
结点值：4
结点值：5
结点值：6
结点值：7
结点值：end
原来表：
   3   4   5   6   7

反转表：
   7   6   5   4   3*/





#include <stdio.h>
#include <stdlib.h> 
struct line
{                    
    int num;
    struct line *next;
}                     *p1, *p2;
 
struct line *creat()
{                    
    int temp;
    struct line *head = NULL;
 
    printf("\n请输入链表（非数表示结束）\n结点值：");
    while (scanf("%d", &temp))
    {                    
        p1 = (struct line *)malloc(sizeof(struct line));
        (head == NULL) ? (head = p1) : (p2->next = p1);
        p1->num = temp;
        printf("结点值：");
        p2 = p1;
    }
    p2->next = NULL;
 
    return head;
}                    
 
output(struct line *outhead)
{                    
    for (p1 = outhead; p1 != NULL; printf("%4d", p1->num), p1 = p1->next);
    {                    
    }
}                    
 
struct line *turnback(struct line *head)
{                    
    struct line *n, *newhead = NULL;
 
    do
    {                    
        p2 = NULL;
        p1 = head;
        while (p1->next != NULL)
        {                    
            p2 = p1;
            p1 = p1->next;
        }
        if (newhead == NULL)
        {                    
            newhead = p1;
            n = newhead->next = p2;
        }
        n = n->next = p2;
        p2->next = NULL;
    }
    while (head->next != NULL);
 
    return newhead;
}                    
 
int main(void)
{                    
    struct line *head;
 
    head = creat();
 
    printf("\n原来表：\n");
    output(head);
    head = turnback(head);
    printf("\n\n反转表：\n");
    output(head);
 
    return 0;
}
