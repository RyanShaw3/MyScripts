#include <stdio.h>
#include <stdlib.h>
#define MaxDegree 100

static int Max(int A, int B)
{
    return A > B ? A : B;
}

//多项式ADT的数组实现的类型声明
typedef struct
{
    int CoeffArray[MaxDegree + 1];
    int HighPower;
} * Polynomial;

//将多项式初始化为零
void ZeroPolynomial(Polynomial Poly)
{
    int i;
    for (i = 0; i <= MaxDegree; i++)
        Poly->CoeffArray[i] = 0;
    Poly->HighPower = 0;
}

//两个多项式相加
void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum)
{
    int i;
    ZeroPolynomial(PolySum);
    PolySum->HighPower = Max(Poly1->HighPower, Poly2->HighPower);
    for (i = PolySum->HighPower; i >= 0; i--)
        PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
}

//两个多项式相乘
void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd)
{
    int i, j;
    ZeroPolynomial(PolyProd);
    PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;
    if (PolyProd->HighPower > MaxDegree)
        printf("Exceeded array size");
    else
        for (i = 0; i <= Poly1->HighPower; i++)
            for (j = 0; j <= Poly2->HighPower; j++)
                PolyProd->CoeffArray[i + j] = Poly1->CoeffArray[i] * Poly2->CoeffArray[j];
}

//输出多项式
void PrintPoly(const Polynomial Poly)
{
    int i;
    for (i = Poly->HighPower; i > 0; i--)
        printf("%dx^%d + ", Poly->CoeffArray[i]);
    printf("%d\n", Poly->CoeffArray[0]);
}