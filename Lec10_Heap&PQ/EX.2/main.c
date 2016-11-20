#include<stdio.h>
#include<stdlib.h>
#include "binheap.h"
  int main(void)
  {
     PriorityQueue Heap,Heap_2;
     int min;
     Heap=Initialize(20);
     Heap_2=Initialize(20);
     printf("Firstly let's use the Insert function provided by our textbook\n");
     Insert(10,Heap);
     Insert(12,Heap);
     Insert(1,Heap);
     Insert(14,Heap);
     Insert(6,Heap);
     Insert(5,Heap);
     Insert(8,Heap);
     Insert(15,Heap);
     Insert(3,Heap);
     Insert(9,Heap);
     Insert(7,Heap);
     Insert(4,Heap);
     Insert(11,Heap);
     Insert(13,Heap);
     Insert(2,Heap);
     Preorder(Heap);
     Inorder(Heap);
     Postorder(Heap);
     DeleteMin(Heap);
     DeleteMin(Heap);
     DeleteMin(Heap);
     printf("\nAfter deleting the minimum three elements in the Min-Heap\n");
     Preorder(Heap);
     Inorder(Heap);
     Postorder(Heap);
     printf("\nNow,If we use PercUp to do the Insertion:\n");
     Insert_2(10,Heap_2);
     Insert_2(12,Heap_2);
     Insert_2(1,Heap_2);
     Insert_2(14,Heap_2);
     Insert_2(6,Heap_2);
     Insert_2(5,Heap_2);
     Insert_2(8,Heap_2);
     Insert_2(15,Heap_2);
     Insert_2(3,Heap_2);
     Insert_2(9,Heap_2);
     Insert_2(7,Heap_2);
     Insert_2(4,Heap_2);
     Insert_2(11,Heap_2);
     Insert_2(13,Heap_2);
     Insert_2(2,Heap_2);
     Preorder(Heap_2);
     Inorder(Heap_2);
     Postorder(Heap_2);
     DeleteMin_2(Heap_2);
     DeleteMin_2(Heap_2);
     DeleteMin_2(Heap_2); 
      printf("\nAnd using the DeleteMin with PercDown three times:\n");
     Preorder(Heap_2);
     Inorder(Heap_2);
     Postorder(Heap_2);
      
      
      system("pause");
      return 0;
  }
