#include <stdio.h>
#include<stdlib.h>
#include "queue.h"
int main(void)
{
    Queue Q;
    //int maxElements = 10;

    Q = CreateQueue();
    if (IsEmpty(Q))
        printf("�����˿ն��У�");

    int value = 0;
    printf("�����е�����Ϊ(front->rear)��\n");
    while (value<=1000)
    {
        Enqueue(value*value, Q);  // ���
        printf("%d ", value*value);
        value++;
    }
    printf("��������\n");


    ElementType frontQueue;
    frontQueue = Front(Q);
    printf("��ͷԪ��Ϊ��%d\n", frontQueue);

    Dequeue(Q);
    frontQueue = Front(Q);
    printf("ִ�г��Ӳ���Dequeue֮�󣬶�ͷԪ���ǣ�%d\n", frontQueue);
    DisposeQueue(Q);

    system("pause");
    return 0;
}
