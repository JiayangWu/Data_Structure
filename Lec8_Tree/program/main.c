 #include<stdio.h>
 #include<stdlib.h>
 #include "tree.h"
  
  int main(void)
    {
        SearchTree T=NULL;
        T=MakeEmpty(T);
 
        T=Insert(3,T);
      	T=Insert(1,T);
    	T=Insert(4,T);
	    T=Insert(6,T);
	    T=Insert(9,T);
	    T=Insert(2,T);
	    T=Insert(7,T);
     	T=Insert(5,T);
     	
        printf("Min is %d\n",FindMin(T)->Element);
        printf("Max is %d\n",FindMax(T)->Element);
        printf("How many leaves are there in the tree?");
        puts("");
        printf("%d",leaf(T));
        puts("");
        printf("Its preorder traversal is :\n");
        Preorder(T);
        puts("");
        printf("Its inorder traversal is :\n");
        Inorder(T);
        puts("");
        printf("Its postorder traversal is :\n");
        Postorder(T);
        puts("");
        Delete(3,T);
        printf("After removing the root, its inorder traversal is :\n");
        Inorder(T);
        puts("");
        printf("How many leaves are there in the tree?");
        puts("");
        printf("%d\n",leaf(T));
        
        system("pause");
  	return 0;
    }
