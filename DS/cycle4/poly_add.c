#include <stdio.h>

typedef struct
{
    int coeff;
    int exp;
} poly;

poly p[10], q[10], r[10];
int k = 0;
int polyAdd(poly p[], poly q[], int m, int n)
{
    int i = 0, j = 0;
    while (i <= m && j <= n)
    {
        if (p[i].exp > q[j].exp)
        {
            r[k].exp = p[i].exp;
            r[k].coeff = p[i].coeff;
            k++;
            i++;
        }
        else if (p[i].exp < q[j].exp)
        {
            r[k].exp = q[j].exp;
            r[k].coeff = q[j].coeff;
            j++;
            k++;
        }
        else
        {
            r[k].exp = p[i].exp;
            r[k].coeff = p[i].coeff + q[j].coeff;
            k++;
            i++;
            j++;
        }
    }
    if (i == m)
    {
        while (j <= n)
        {
            r[k].exp = q[j].exp;
            r[k].coeff = q[j].coeff;
            j++;
            k++;
        }
    }
    if (j == n)
    {
        while (i <= m)
        {
            r[k].exp = p[i].exp;
            r[k].coeff = p[i].coeff;
            i++;
            k++;
        }
    }
}

void main()
{
    int deg1, deg2, coeff, i, k = 0;
    printf("Enter degree of polynomial 1 : ");
    scanf("%d", &deg1);
    for (i = deg1; i >= 0; i--)
    {
        printf("Enter coeff of x^%d : ", i);
        scanf("%d", &coeff);
        if (coeff != 0)
        {
            p[k].coeff = coeff;
            p[k].exp = i;
            k++;
        }  
    }
    printf("The polynomial is : \n");
    for (i = 0; i < k; i++)
    {
        if (p[i].exp != 0)
        {
            printf("%d(x^%d) + ", p[i].coeff, p[i].exp);
        }
        else
        {
            printf("%d\n", p[i].coeff);
        } 
    }
    k = 0;
    printf("Enter degree of polynomial 2 : ");
    scanf("%d", &deg2);
    for (i = deg2; i >= 0; i--)
    {
        printf("Enter coeff of x^%d : ", i);
        scanf("%d", &coeff);
        if (coeff != 0)
        {
            q[k].coeff = coeff;
            q[k].exp = i;
            k++;
        }  
    }
    printf("The polynomial is : \n");
    for (i = 0; i < k; i++)
    {
        if (q[i].exp != 0)
        {
            printf("%d(x^%d) + ", q[i].coeff, q[i].exp);
        }
        else
        {
            printf("%d\n", q[i].coeff);
        } 
    }
    polyAdd(p, q, deg1, deg2);
    printf("\nThe result of addition is :\n");
    for (i = k; i >= 0; i--)
    {
        if( i!= 0)
            printf("%d(x^%d) + ", r[k - i].coeff, r[k - i].exp);
        else
            printf("%d\n", r[k - i].coeff);
    }

}