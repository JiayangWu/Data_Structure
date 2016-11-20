#include "fatal.h"

typedef int ElementType;
struct QueueRecord;

  struct Node{
   	  ElementType Data;
	  struct Node *Next;
  };
  typedef struct Node *PtrToNode;

  struct QueueRecord{
	  PtrToNode Front;
   	  PtrToNode Rear;
	  int Size;
  };
  
  typedef struct QueueRecord *Queue;
  
int IsEmpty(Queue Q)
  {
    return Q->Size==0 ;
}

void Dequeue(Queue Q)
{
    PtrToNode Temp;
    if (IsEmpty(Q))
      {
        Error("This is an empty queue!!!");
    	return;
      }
    Temp=Q->Front;
    Q->Front=Q->Front->Next;
    Q->Size--;
    free(Temp);
    if (Q->Size==0)
        Q->Rear=NULL;
    return;
}

Queue CreateQueue(void)
{
    Queue Q;
    Q=malloc(sizeof(struct QueueRecord));
    if (Q==NULL)
 	    FatalError("Out of space!!!");
    Q->Front = (PtrToNode)malloc(sizeof(struct Node));
    if  (Q->Front==NULL)
	    FatalError("Out of space!!!");
	Q->Rear = (PtrToNode)malloc(sizeof(struct Node));
    if  (Q->Rear==NULL)
	   FatalError("Out of space!!!");
    
    Q->Size=0;

    return Q;
}

void MakeEmpty(Queue Q)
{
    if (Q==NULL)
	return ;
    while (!IsEmpty(Q))
	Dequeue(Q);
}

void DisposeQueue(Queue Q)
{
    MakeEmpty(Q);
    free(Q);
}

ElementType Front(Queue Q)
{
    if (!IsEmpty(Q))
        return Q->Front->Data;
    Error("Warning, this is an empty queue;\n");
}

ElementType Enqueue(ElementType n,Queue Q)
{
    PtrToNode  p;
    

    
    p=(PtrToNode)malloc(sizeof(struct Node));
    if (p==NULL)
	Error("Out of space!!!");

    p->Data=n;
    p->Next=NULL;
    
    if (IsEmpty(Q))
        Q->Front=p;
    else
       Q->Rear->Next=p;

    Q->Rear=p;
    Q->Size++;

    return;
}



ElementType FrontAndDequeue(Queue Q)
{
   ElementType x=-1;
   
   if(IsEmpty(Q))
    	Error("This is an empty queue");
   else
   {
	Q->Size--;
	x=Q->Front->Data;
	Q->Front=Q->Front->Next;
    }
    return x;
}
     
