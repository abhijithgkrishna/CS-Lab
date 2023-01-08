#include <stdio.h>
void bubblesort(int A[30], int n);
void insertionsort(int A[30], int n);
void selectionsort(int A[30], int n);
int partition(int a[30], int lb, int ub);
void quicksort(int a[30], int lb, int ub);
void display(int A[30], int n);
void mergesort(int a[30], int lb, int ub);
void merge(int a[30], int lb, int mid, int ub);
void maxheapify(int a[30], int n, int i);
void heapsort(int a[30], int n);
void main()
{
    int choice, n, i, A[30], b[30];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &A[i]);
    }
    printf("The elements are\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n1.Bubble sort\n2.Insertion sort\n3.Selection sort\n4.Quick sort\n5.Merge sort\n6.Heap sort\n7.Exit");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        for (i = 0; i < n; i++)
        {
            b[i] = A[i];
        }
        switch (choice)
        {
        case 1:
            bubblesort(b, n);
            printf("After bubble sort: ");
            display(b, n);
            break;
        case 2:
            insertionsort(b, n);
            printf("After insertion sort: ");
            display(b, n);
            break;
        case 3:
            selectionsort(b, n);
            printf("After selection sort: ");
            display(b, n);
            break;
        case 4:
            quicksort(b, 0, n - 1);
            printf("After quick sort: ");
            display(b, n);
            break;
        case 5:
            mergesort(b, 0, n - 1);
            printf("After merge sort: ");
            display(b, n);
            break;
        case 6:
            heapsort(b, n);
            printf("After heap sort: ");
            display(b, n);
            break;
        case 7:
            printf("EXIT\n");
            break;
        case 8:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 7);
}
void bubblesort(int A[30], int n)
{
    int i, j, t;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                t = A[j];
                A[j] = A[j + 1];
                A[j + 1] = t;
            }
        }
    }
}
void insertionsort(int A[30], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > temp)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}
void selectionsort(int A[30], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
}
void quicksort(int a[30], int lb, int ub)
{
    if (lb < ub)
    {
        int loc;
        loc = partition(a, lb, ub);
        quicksort(a, lb, loc - 1);
        quicksort(a, loc + 1, ub);
    }
}
int partition(int a[30], int lb, int ub)
{
    int temp;
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }
        while (a[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    if (start > end)
    {
        temp = a[lb];
        a[lb] = a[end];
        a[end] = temp;
    }
    return end;
}
void mergesort(int a[30], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}
void merge(int a[30], int lb, int mid, int ub)
{
    int b[30];
    int i = lb;
    int j = mid + 1;
    int k = lb;
    while (i <= mid && j <= ub)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = a[i];
            k++;
            i++;
        }
    }
    for (k = lb; k <= ub; k++)
    {
        a[k] = b[k];
    }
}
void maxheapify(int a[30], int n, int i)
{
    int temp;
    int largest = i;
    int l = 2 * i + 1;
    int r = (2 * i) + 2;
    while (l < n && a[l] > a[largest])
    {
        largest = l;
    }
    while (r < n && a[r] > a[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        temp = a[largest];
        a[largest] = a[i];
        a[i] = temp;
        maxheapify(a, n, largest);
    }
}
void heapsort(int a[30], int n)
{
    int temp;
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        maxheapify(a, n, i);
    }
    for (i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        maxheapify(a, i, 0);
    }
}
void display(int A[30], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
}