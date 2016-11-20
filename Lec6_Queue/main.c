#include <stdio.h>
#include<stdlib.h>
#include "queue.h"
int main(void)
{
    Queue Q;
    //int maxElements = 10;

    Q = CreateQueue();
    if (IsEmpty(Q))
        printf("创建了空队列！");

    int value = 0;
    printf("队列中的数据为(front->rear)：\n");
    while (value<=1000)
    {
        Enqueue(value*value, Q);  // 入队
        printf("%d ", value*value);
        value++;
    }
    printf("队列已满\n");


    ElementType frontQueue;
    frontQueue = Front(Q);
    printf("对头元素为：%d\n", frontQueue);

    Dequeue(Q);
    frontQueue = Front(Q);
    printf("执行出队操作Dequeue之后，对头元素是：%d\n", frontQueue);
    DisposeQueue(Q);

    system("pause");
    return 0;
}
