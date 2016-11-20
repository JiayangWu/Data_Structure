#include<stdlib.h>
#include<stdio.h>
typedef struct Node *PtrToNode;

struct Node
        {
            int Coef;
            int Exp;
            PtrToNode Next;
        };

typedef PtrToNode Poly;


void Combine(Poly C)
{
     Poly A=C,Temp;
     int n=0;
     for(A=C;A->Next;)
       if(A->Exp==A->Next->Exp)
      {
        A->Coef+=A->Next->Coef;
        Temp=A->Next;
        A->Next=A->Next->Next;
        free(Temp);
      }
      else
        A=A->Next;
}

void Rank(Poly C)
{
     Poly A,B,Temp;
     int t,m;

     B=C;
    for(B=C;B;B=B->Next)  
      for(A=B;A->Next;A=A->Next)
    {
     if(A->Exp<A->Next->Exp)
      {
        t=A->Exp;
        m=A->Coef;
        A->Coef=A->Next->Coef;
        A->Exp=A->Next->Exp;
        A->Next->Coef=m;
        A->Next->Exp=t;
      }
       
    }
    Combine(C); 
}


void Print_Poly(Poly A)
{
   Poly P = A;
   for (;P;P=P->Next)
   if (P->Coef!=0)
      {
        if (P->Coef>0) 
         printf(" +%dx^%d", P->Coef, P->Exp);
        if  (P->Coef<0)
         printf(" %dx^%d", P->Coef, P->Exp);
      }
   printf("\n");
}

Poly Create_Term(int Coef, int Exp)
{
  Poly T = (Poly)malloc(sizeof(*T));
  if ( T == NULL)
  {
       printf("Out of space!!!");
  }
   T->Coef = Coef;
   T->Exp = Exp;
   T->Next =0;
   return T;
}



void Destroy_Poly(Poly A)
  {
     Poly P = A, Q;
     while (P)
     {
       Q = P->Next;
       free(P);
       P=Q;
     }
  }

Poly *New_next(Poly *pp, int Coef, int Exp)
{
  *pp = (Poly) malloc(sizeof(**pp));
  if (*pp == NULL)
  {
     printf("Out of space!!!");
  }
  (*pp)->Coef = Coef;
  (*pp)->Exp = Exp;
 
   return &((*pp)->Next);
}



Poly Add_Poly(Poly A, Poly B)
{
   Poly C, *PC = &C;   
		
   Poly P = A, Q = B; 		
   while ( P && Q ) {  //not empty
      if ( P->Exp == Q->Exp ) { //case 2
        int S = P->Coef + Q->Coef; //add coefficients
        
	     if ( S != 0  ) //case 2.2
	        PC = New_next(PC, S, P->Exp);
        
	     P = P->Next, Q = Q->Next;
      } else {//case 1
          if ( P->Exp > Q->Exp ) { 
             PC = New_next(PC, P->Coef, P->Exp);
	          P = P->Next;
          } else {
             PC = New_next(PC, Q->Coef, Q->Exp); 
             Q = Q->Next;
            }
        }
   }
/* бнбн
бнбн Add_Poly continues */
 
     //case 3
    for ( ; P; P = P->Next )
        PC = New_next(PC, P->Coef, P->Exp);
 
    for ( ; Q; Q = Q->Next )
        PC = New_next(PC, Q->Coef, Q->Exp);
 
    *PC = 0; /* NULL */
    Rank(C);
    return C;
}

Poly Add_Poly_del(Poly A, Poly B)
{
  Poly C; 
  C=Add_Poly(A,B);
  //Destroy_Poly(A);
 // Destroy_Poly(B);
  return C;
}

Poly Sub_Poly(Poly A, Poly B)
{
   Poly C, *PC = &C;   
		
   Poly P = A, Q = B; 		
   while ( P && Q ) {  //not empty
      if ( P->Exp == Q->Exp ) { //case 2
        int S = P->Coef - Q->Coef; //add coefficients
        
	     if ( S != 0 )  //case 2.2
	        PC = New_next(PC, S, P->Exp);
        
	     P = P->Next, Q = Q->Next;
      } else {//case 1
           if ( P->Exp > Q->Exp ) { 
              PC = New_next(PC, P->Coef, P->Exp);
	          P = P->Next;
	          PC = New_next(PC, -1*(Q->Coef), Q->Exp);
	          Q = Q->Next;
          } else {
             PC = New_next(PC, -1*(Q->Coef), Q->Exp); 
             Q = Q->Next;
             PC = New_next(PC, (P->Coef), P->Exp);
             P = P->Next;
            }
        }
   }
/* бнбн
бнбн Add_Poly continues */
 
     //case 3
    for ( ; P; P = P->Next )
        PC = New_next(PC, P->Coef, P->Exp);
 
    for ( ; Q; Q = Q->Next )
        PC = New_next(PC, -1*(Q->Coef), Q->Exp);
 
    *PC = 0; /* NULL */
    Rank(C);
    return C;
}

Poly Sub_Poly_del(Poly A, Poly B)
{
  Poly C = Sub_Poly(A,B);
  //Destroy_Poly(A);
  //Destroy_Poly(B);
  return C;
}



Poly Mul_Poly(Poly A, Poly B)
{
   Poly C=NULL, *PC = &C;   
		
   Poly P = A, Q = B; 		
   while ( P && Q ) {  //not empty
      for ( ; P; P = P->Next )
       {
         Q=B;
        while (Q)
         {
           C=Add_Poly_del(Create_Term(P->Coef*Q->Coef, P->Exp+Q->Exp),C);
           Q=Q->Next;
         }
       }
   }
   return C;
}

Poly Mul_Poly_del(Poly A, Poly B)
{
  Poly C = Mul_Poly(A,B);
  //Destroy_Poly(A);
  //Destroy_Poly(B);
  return C;
}

Poly Create_Poly(Poly A)
{
   int C, E;   
  A=Create_Term(0,0);  
  puts("~~~~~~~~~Creating a new polynomial~~~~~~~");
  puts("Please type the coeffient and exponent of the new term you want to insert.");
        puts("Stop insertion with 0 0");
    scanf("%d%d",&C,&E);
   while(E>=0&&C)
     {
        A = Add_Poly_del(A, Create_Term(C,E));
        printf("Your current polynomial is :\n");
        Print_Poly(A);
        scanf("%d%d",&C,&E);
     }
   printf("Well, now your polynomial is :\n");
   Print_Poly(A);
   puts("");
   return A;
}
void Calculation(Poly A, Poly B){
   int n;  
   while(1){
   Poly C=NULL;
   printf("~~~~~~~~~~~~~~~~~~~\n");
   printf("Calculation options:\n");
   printf("1. A+B       2. A-B\n");
   printf("3. B-A       4. A*B\n");
   printf("5. Quit      6. NULL\n");
   printf("~~~~~~~~~~~~~~~~~~~\n");
   scanf("%d",&n);
    switch (n)
    {
        case 1:{
                 printf("You choose to calculate A+B:\n");
                 printf("Polynomial A : ");
                 Print_Poly(A);
                 printf("Polynomial B : ");
                 Print_Poly(B);
                 printf("Polynomial A+B : ");
                 C = Add_Poly_del(A, B);
                 Print_Poly(C);
               };break;
        case 2:{
                 printf("You choose to calculate A-B:\n");
                 printf("Polynomial A : ");
                 Print_Poly(A);
                 printf("Polynomial B : ");
                 Print_Poly(B);
                 printf("Polynomial A-B : ");
                 C = Sub_Poly_del(A, B);
                 Print_Poly(C);
               };break;
        case 3:{
                 printf("You choose to calculate B-A:\n");
                 printf("Polynomial B : ");
                 Print_Poly(B);
                 printf("Polynomial A : ");
                 Print_Poly(A);
                 printf("Polynomial B-A : ");
                 C = Sub_Poly_del(B, A);
                 Print_Poly(C);
               };break;
        case 4:{
                 printf("You choose to calculate A*B:\n");
                 printf("Polynomial A : ");
                 Print_Poly(A);
                 printf("Polynomial B : ");
                 Print_Poly(B);
                 printf("Polynomial A*B : ");
                 C = Mul_Poly_del(B, A);
                 Print_Poly(C);
               };break;
        case 5:{
                return;
                };break;
        default:printf("error\n");break;
    }
}

}
