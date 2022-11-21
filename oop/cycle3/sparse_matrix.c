// Complete add function

#include <stdio.h>
void matrixtotuple(int a[][10], int m, int n, int sp[][3])
{
    int i, j, count = 0, k = 1;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] != 0)
                count++;
    sp[0][0] = m;
    sp[0][1] = n;
    sp[0][2] = count;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                sp[k][0] = i;
                sp[k][1] = j;
                sp[k][2] = a[i][j];
                k++;
            }
        }
    }
}
void displaySparse(int sp[][3])
{
    printf("value of count is %d \n", sp[0][2]);
    for (int i = 0; i <= sp[0][2]; i++)
    {
        printf("%d %d %d \n", sp[i][0], sp[i][1], sp[i][2]);
    }
}
void tupleTransp(int sp[][3], int tra[][3])
{
    int i;
    for (i = 0; i <= sp[0][2]; i++)
    {
        tra[i][0] = sp[i][1];
        tra[i][1] = sp[i][0];
        tra[i][2] = sp[i][2];
    }
}
void addTuple(int tup1[][3], int tup2[][3], int res[][3])
{
    int i = 0, j = 0, k = 0, num_of_elements = 0;
    if ((tup1[0][0] != tup2[0][0]) || (tup1[0][1] != tup2[0][1]))
    {
        printf("Cannot add matrices\n");
    }
    else
    {
        res[0][0] = tup1[0][0];
        res[0][1] = tup1[0][1];
        while ((i <= tup1[0][2]) && (j <= tup2[0][2]))
        {
            if (tup1[i][0] < tup2[j][0])
            {
                res[k][0] = tup1[i][0];
                res[k][1] = tup1[i][1];
                res[k][2] = tup1[i][2];
                k++;
                i++;
                num_of_elements++;
            }
            else if (tup1[i][0] > tup2[j][0])
            {
                res[k][0] = tup2[i][0];
                res[k][1] = tup2[i][1];
                res[k][2] = tup2[i][2];
                k++;
                j++;
                num_of_elements++;
            }
            else
            {
                if (tup1[i][1] < tup2[j][1])
                {
                    res[k][0] = tup1[i][0];
                    res[k][1] = tup1[i][1];
                    res[k][2] = tup1[i][2];
                    k++;
                    i++;
                    num_of_elements++;
                }
                else if (tup1[i][1] > tup2[j][1])
                {
                    res[k][0] = tup2[i][0];
                    res[k][1] = tup2[i][1];
                    res[k][2] = tup2[i][2];
                    k++;
                    j++;
                    num_of_elements++;
                }
                else
                {
                    res[k][0] = tup1[i][0];
                    res[k][1] = tup1[i][1];
                    res[k][2] = tup1[i][2] + tup2[j][2];
                    k++;
                    i++;
                    j++;
                    num_of_elements++;
                }
            }
        } // end while
        while (i <= tup1[0][2])
        {
            res[k][0] = tup1[i][0];
            res[k][1] = tup1[i][1];
            res[k][2] = tup1[i][2];
            k++;
            i++;
            num_of_elements++;
        }
        while (j <= tup2[0][2])
        {
            res[k][0] = tup2[i][0];
            res[k][1] = tup2[i][1];
            res[k][2] = tup2[i][2];
            k++;
            j++;
            num_of_elements++;
        }
        res[0][2] = num_of_elements - 1;
    }
}

void main()
{
    int a[10][10], b[10][10], sp1[10][3], sp2[10][3], sum[10][3];
    int tra1[10][3], tra2[10][3];
    int m, n, p, q, i, j;
    printf("Enter the order of first matrix (mxn) : ");
    scanf("%dx%d", &m, &n);
    printf("Enter elements one by one : \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the order of second matrix (pxq) : ");
    scanf("%dx%d", &p, &q);
    printf("Enter elements one by one : \n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    matrixtotuple(a, m, n, sp1);
    matrixtotuple(b, p, q, sp2);
    displaySparse(sp1);
    displaySparse(sp2);
    tupleTransp(sp1, tra1);
    displaySparse(tra1);
    tupleTransp(sp2, tra2);
    displaySparse(tra2);
    addTuple(sp1, sp2, sum);
    displaySparse(sum);
}