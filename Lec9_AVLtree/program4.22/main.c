#include<stdio.h>
#include<stdlib.h>
#include"avltree.h"
  int main(void)
    {
        AvlTree T=NULL;
 	T=MakeEmpty(T);
	T=Insert(2,T);
	T=Insert(1,T);
	T=Insert(3,T);
	T=Insert(5,T);
	T=Insert(9,T);
	T=Insert(6,T);
	T=Insert(7,T);
	T=Insert(8,T);
	T=Insert(11,T);
	T=Insert(4,T);
	Inorder(T);
	system("pause");
	return 0;
}
