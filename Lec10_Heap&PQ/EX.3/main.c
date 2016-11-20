#include<stdio.h>
#include<stdlib.h>
#include "binheap.h"
  int main(void)
  {
     PriorityQueue Heap,Heap_2;
     int i=1,j;
     int min;
     int Tmp[20]={0};
     //int size=Lenof(Heap);
     Heap=Initialize(20);
     Heap_2=Initialize(20);
     printf("The answer to Ex3.d is as follows\n");
     Insert(4,Heap);
     Insert(16,Heap);
     Insert(31,Heap);
     Insert(21,Heap);
     Insert(32,Heap);
     Insert(66,Heap);
     Insert(67,Heap);  
     Preorder(Heap);
     Inorder(Heap);
     Postorder(Heap);
      puts("");
     printf("The answer to Ex3.e is as follows:\n"); 
     printf("If we use another array Tmp to store data, then the result of heap sort is:\n");   
     while(1)
     {
       Tmp[i]=DeleteMin(Heap);    
       i++;
       if (IsEmpty(Heap))
          break; 
     } 
//     for(j=1;j<i;j++)  
//       printf("%d ",Tmp[j]);
     Copy(Heap,Tmp,i);
     PrintHeap(Heap);
     MakeEmpty(Heap);
     puts(""); 
     puts(""); 
     printf("The answer to Ex3.f is as follows:\n");
     printf("If we do not use extra array to store data, then the result of heap sort is:\n");  
      Insert(4,Heap);
     Insert(16,Heap);
     Insert(31,Heap);
     Insert(21,Heap);
     Insert(32,Heap);
     Insert(66,Heap);
     Insert(67,Heap); 
     HeapSort(Heap);       
     system("pause");
     //for(i=1;i<=size;i++) 
       
      return 0;
  }
