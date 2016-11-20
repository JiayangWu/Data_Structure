typedef struct Node *PtrToNode;

struct Node
        {
            int Coef;
            int Exp;
            PtrToNode Next;
        };

typedef PtrToNode Poly;

Poly Add_Poly_del(Poly A, Poly B);
void Print_Poly(Poly A);
Poly Create_Term(int Coef, int Exp);
Poly Create_Poly(Poly A);
void Destroy_Poly(Poly A);
Poly *New_next(Poly *pp, int Coef, int Exp);
Poly Add_Poly(Poly A, Poly B);
Poly Mul_Poly(Poly A, Poly B);
Poly Mul_Poly_del(Poly A, Poly B);
Poly Sub_Poly(Poly A, Poly B);
Poly Sub_Poly_del(Poly A, Poly B);
void Rank(Poly C);
void Combine(Poly C);
void Calculation(Poly A, Poly B);




