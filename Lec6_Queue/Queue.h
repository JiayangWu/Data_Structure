  
  
  typedef int ElementType;
  struct Node{
   	  ElementType data;
	  struct Node *next;
  };
  typedef struct Node *PtrToNode;

  struct QueueRecord{
	  PtrToNode Front;
   	  PtrToNode Rear;
	  int Size;
  };
  typedef struct QueueRecord *Queue;
  
  int IsEmpty(Queue Q);
  //int IsFull(Queue Q);
  Queue CreateQueue(void);
  void DisposeQueue(Queue Q);
  void MakeEmpty(Queue Q);
  void Enqueue(ElementType x, Queue Q);
  ElementType Front(Queue Q);
  void Dequeue(Queue Q);
  ElementType FrontAndDequeue(Queue Q);
