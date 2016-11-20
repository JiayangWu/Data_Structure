#include <Stdio.h>
#include <stdlib.h>
#include "fac.h"
  int main(void)
  {
      int n;
      puts("Which number do you want to calculate its factorial number?");
      scanf("%d",&n);
      printf("The factorial of %d is : %d\n", n, fac(n));
      system("pause");
      return 0;
}
