
        typedef int ElementType;

/* START: fig6_4.txt */
        #ifndef _BinHeap_H
        #define _BinHeap_H

        struct HeapStruct;
        typedef struct HeapStruct *PriorityQueue;

        PriorityQueue Initialize( int MaxElements );
        void Destroy( PriorityQueue H );
        void MakeEmpty( PriorityQueue H );
        void Insert( ElementType X, PriorityQueue H );
        ElementType DeleteMin( PriorityQueue H );
        ElementType FindMin( PriorityQueue H );
        int IsEmpty( PriorityQueue H );
        int IsFull( PriorityQueue H );
        void Preorder( PriorityQueue H);
        void PreorderHelper(ElementType a[], int Size,int i);
        void Inorder( PriorityQueue H);
        void InorderHelper(ElementType a[], int Size,int i);
        void Postorder( PriorityQueue H);
        void PostorderHelper(ElementType a[], int Size,int i);
        void
        PercDown( ElementType A[], int i);
        void
        PercUp( ElementType A[], int N);
        void
        Insert_2( ElementType X, PriorityQueue H );
        void
        DeleteMin_2(PriorityQueue H);
        int
        Lenof(PriorityQueue H);
        void
        HeapSort(PriorityQueue H);
        void
        PrintHeap(PriorityQueue H);
        void
        Copy(PriorityQueue H, ElementType a[],int Len);

        #endif

/* END */
