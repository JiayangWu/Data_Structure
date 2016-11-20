//This is a poly calculator to calculate the sum, subtraction and multplecation of two polynomials.


#include <stdio.h>
#include "poly_list.h"
int main(void){
   Poly A,B;
   int n;
   A=Create_Poly(A); 
   B=Create_Poly(B);
   Calculation(A,B);
   system("pause");
   return 0;
}
