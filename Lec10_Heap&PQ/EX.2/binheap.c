        #include "binheap.h"
        #include "fatal.h"
        #include <stdlib.h>

        #define MinPQSize (10)
        #define MinData (-32767)

        struct HeapStruct
        {
            int Capacity;
            int Size;
            ElementType *Elements;
        };

/* START: fig6_0.txt */
        PriorityQueue
        Initialize( int MaxElements )
        {
            PriorityQueue H;

/* 1*/      if( MaxElements < MinPQSize )
/* 2*/          Error( "Priority queue size is too small" );

/* 3*/      H = malloc( sizeof( struct HeapStruct ) );
/* 4*/      if( H ==NULL )
/* 5*/          FatalError( "Out of space!!!" );

            /* Allocate the array plus one extra for sentinel */
/* 6*/      H->Elements = malloc( ( MaxElements + 1 )
                                    * sizeof( ElementType ) );
/* 7*/      if( H->Elements == NULL )
/* 8*/          FatalError( "Out of space!!!" );

/* 9*/      H->Capacity = MaxElements;
/*10*/      H->Size = 0;
/*11*/      H->Elements[ 0 ] = MinData;

/*12*/      return H;
        }
/* END */

        void
        MakeEmpty( PriorityQueue H )
        {
            H->Size = 0;
        }

/* START: fig6_8.txt */
        /* H->Element[ 0 ] is a sentinel */

        void
        Insert( ElementType X, PriorityQueue H )
        {
            int i;

            if( IsFull( H ) )
            {
                Error( "Priority queue is full" );
                return;
            }

            for( i = ++H->Size; H->Elements[ i / 2 ] > X; i /= 2 )
                H->Elements[ i ] = H->Elements[ i / 2 ];
            H->Elements[ i ] = X;
        }
/* END */

/* START: fig6_12.txt */
        ElementType
        DeleteMin( PriorityQueue H )
        {
            int i, Child;
            ElementType MinElement, LastElement;

/* 1*/      if( IsEmpty( H ) )
            {
/* 2*/          Error( "Priority queue is empty" );
/* 3*/          return H->Elements[ 0 ];
            }
/* 4*/      MinElement = H->Elements[ 1 ];
/* 5*/      LastElement = H->Elements[ H->Size-- ];

/* 6*/      for( i = 1; i * 2 <= H->Size; i = Child )
            {
                /* Find smaller child */
/* 7*/          Child = i * 2;
/* 8*/          if( Child != H->Size && H->Elements[ Child + 1 ]
/* 9*/                                < H->Elements[ Child ] )
/*10*/              Child++;

                /* Percolate one level */
/*11*/          if( LastElement > H->Elements[ Child ] )
/*12*/              H->Elements[ i ] = H->Elements[ Child ];
                else
/*13*/              break;
            }
/*14*/      H->Elements[ i ] = LastElement;
/*15*/      return MinElement;
        }
/* END */

        ElementType
        FindMin( PriorityQueue H )
        {
            if( !IsEmpty( H ) )
                return H->Elements[ 1 ];
            Error( "Priority Queue is Empty" );
            return H->Elements[ 0 ];
        }

        int
        IsEmpty( PriorityQueue H )
        {
            return H->Size == 0;
        }

        int
        IsFull( PriorityQueue H )
        {
            return H->Size == H->Capacity;
        }

        void
        Destroy( PriorityQueue H )
        {
            free( H->Elements );
            free( H );
        }

        
        void
        Preorder( PriorityQueue H)
        {
            printf("The Preorder  traversal of the Heap is : ");
            PreorderHelper(&H->Elements[0],H->Size,1);
            puts("");
        }
        
        void
        PreorderHelper(ElementType a[] , int Size, int i)
        {          
            if (i>Size) return ;
                printf("%d ",a[i]);
                PreorderHelper(&a[0],Size, 2*i);
                PreorderHelper(&a[0],Size, 2*i+1);
        }
        
        void
        Inorder( PriorityQueue H)
        {
            printf("The Inorder   traversal of the Heap is : ");
            InorderHelper(&H->Elements[0],H->Size,1);
            puts("");
        }
        
        void
        InorderHelper(ElementType a[] , int Size, int i)
        {          
            if (i>Size) return ;
            
            InorderHelper(&a[0],Size, 2*i);
            printf("%d ",a[i]);
            InorderHelper(&a[0],Size, 2*i+1);
        }
        
        void
        Postorder( PriorityQueue H)
        {
            printf("The Postorder traversal of the Heap is : ");
            PostorderHelper(&H->Elements[0],H->Size,1);
             puts("");
        }
        
        void
        PostorderHelper(ElementType a[] , int Size, int i)
        {          
            if (i>Size) return ;
            
            PostorderHelper(&a[0],Size, 2*i);
            PostorderHelper(&a[0],Size, 2*i+1);
            printf("%d ",a[i]);
        }
             
        
        void
        PercDown( ElementType A[], int N)
        {
           int Child,i=1;
           ElementType Tmp; 
           for( Tmp=A[i];(2*i+1)<N;i=Child)
            {
           	  Child=2*i;
           	  if(Child!=N-1 && A[Child+1]<A[Child])
           	    Child++;
           	  if(Tmp>A[Child])
                A[i]=A[Child];
              else
                break;
            }  
            A[i]=Tmp;
        }

        void
        PercUp( ElementType A[], int N)
        {
           ElementType Tmp;
           for(Tmp=A[N];Tmp<A[N/2];N/=2)
           {
          	 if (N<1) break;
	         A[N]=A[N/2];
           }
          A[N]=Tmp;
        }
        
        void
        Insert_2( ElementType X, PriorityQueue H )
        {
            int i;

            if( IsFull( H ) )
            {
                Error( "Priority queue is full" );
                return;
            }
            H->Elements[++H->Size]=X;
            PercUp(&H->Elements[0], H->Size);
        }
        
        void
        DeleteMin_2(PriorityQueue H)
        {
           if( IsEmpty( H ) )
            {
                Error( "Priority queue is empty" );
                return;
            }
           H->Elements[1]=H->Elements[H->Size--];
           PercDown(&H->Elements[0],H->Size);
           }
        #if 0
/* START: fig6_14.txt */
        for( i = N / 2; i > 0; i-- )
            PercolateDown( i );
/* END */
        #endif
