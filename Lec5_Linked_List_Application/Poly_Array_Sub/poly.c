/* This code doesn't really do much */
/* Thus I haven't bothered testing it */

#include <stdio.h>
#include <stdlib.h>

#define MaxDegree 100
struct Node
        {
            int CoeffArray[ MaxDegree + 1 ];
            int HighPower;
        };

static int
Max( int A, int B )
{
    return A > B ? A : B;
}

/* START: fig3_18.txt */
        typedef struct Node *Polynomial;
/* END */

/* START: fig3_19.txt */
        void ZeroPolynomial( Polynomial Poly )
        {
            int i;

            for( i = 0; i <= MaxDegree; i++ )
                Poly->CoeffArray[ i ] = 0;
            Poly->HighPower = 0;
        }
/* END */

/* START: fig3_20.txt */
        void AddPolynomial( const Polynomial Poly1, const Polynomial Poly2,
                       Polynomial PolySum )
        {
            int i;

            ZeroPolynomial( PolySum );
            PolySum->HighPower = Max( Poly1->HighPower,
                                      Poly2->HighPower );

            for( i = PolySum->HighPower; i >= 0; i-- )
                PolySum->CoeffArray[ i ] = Poly1->CoeffArray[ i ]
                                               + Poly2->CoeffArray[ i ];
        }
/* END */

/* START: fig3_21.txt */
        void MultPolynomial( const Polynomial Poly1,
                        const Polynomial Poly2, Polynomial PolyProd )
        {
            int i, j;

            ZeroPolynomial( PolyProd );
            PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;

            if( PolyProd->HighPower > MaxDegree )
                printf( "Exceeded array size" );
            else
                for( i = 0; i <= Poly1->HighPower; i++ )
                    for( j = 0; j <= Poly2->HighPower; j++ )
                        PolyProd->CoeffArray[ i + j ] +=
                                Poly1->CoeffArray[ i ] *
                                Poly2->CoeffArray[ j ];
        }
/* END */


void SubPolynomial( const Polynomial Poly1, const Polynomial Poly2,
                    Polynomial PolySub )
{
   int i;
//Initialization
   ZeroPolynomial( PolySub );

//Decide the highest power of the result polynomial
   PolySub->HighPower = Max( Poly1->HighPower, Poly2->HighPower );

//add the corresponding terms of Poly1 and Poly2
   for( i = PolySub->HighPower; i >= 0; i-- )
      PolySub->CoeffArray[ i ] = Poly1->CoeffArray[ i ]
                                 - Poly2->CoeffArray[ i ];
}


void
PrintPoly( const Polynomial Q )
{
    int i;

    for( i = Q->HighPower; i > 0; i-- )
       { if (Q->CoeffArray[i]==0)
             continue;
        printf( "%dx^%d + ", Q->CoeffArray[ i ], i );
       }
    printf( "%d\n", Q->CoeffArray[ 0 ] );
}

      

main( )
{
    Polynomial P, Q, S;
    int i;

    P = (Polynomial) malloc( sizeof( *P ) );
    Q = (Polynomial) malloc( sizeof( *Q ) );
    S = (Polynomial) malloc( sizeof( *S ) );

    printf("What's your Polynomial's highest power?\n");
    scanf("%d",&P->HighPower);
    for(i=0;i<=P->HighPower;i++)
      {
        printf("What's your coeffient for the term whose exponent is %d,which is x^%d\n", i,i);
        scanf("%d",&P->CoeffArray[ i ]);
        puts("");
      }
      printf("Now your Polynomial is :\n");
        PrintPoly( P );
    printf("Now your Polynomial is :\n");
    PrintPoly( P );
    puts("");
    printf("Its square Polynomial Q is :\n");
    MultPolynomial( P, P, Q );
    PrintPoly( Q );
    puts("");
    printf("The sum of two P which is defined as the Polynomial S is  :\n");
    AddPolynomial( P, P, S );
    PrintPoly( S );
    puts("");
    printf("The subtraction of Q-S is  :\n");
    SubPolynomial( Q, S, P );
    PrintPoly( P );
    puts("");
    getchar();
    getchar();

    return 0;
}
