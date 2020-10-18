#include<stdio.h>

void merge(int a[], int start, int mid, int end)
{
    int size1, size2, i,j,k;
    size1 = (mid-start)+1;
    size2 = (end-mid);

    // temporary arrays to copy elements of subarray
    int temp1[size1], temp2[size2];
    for(i=0;i<size1;i++)
    temp1[i] = a[start+i];

    for(i=0;i<size2;i++)
    temp2[i] = a[mid+1+i];

    i=0;
    j=0;
    k=start;
    while(i<size1 && j<size2)
    {
        if(temp1[i]<temp2[j])
        {
            // filling the main array with smaller element 
            a[k] = temp1[i];
            i++;
        }
        else
        {
            a[k] = temp2[j];
            j++;
        }
        k++;
        
    }
    // copying leftovers
    while(i<size1)
    {
        a[k] = temp1[i];
        k++;
        i++;
    }
    while(j<size2)
    {
        a[k] = temp2[j];
        k++;
        j++;
    }
}

void mergeSort(int a[], int start, int end)
{
    if(start<end)
    {
        int mid = (start+end)/2;
        mergeSort(a, start, mid);
        mergeSort(a, mid+1, end);
        merge(a, start, mid, end);
    }
}

int main()
{
    int a[] = {4,8,1,3,10,9,2,11,5,6};
    mergeSort(a, 0, 9);

    //printing array
    int i;
    for(i=0; i<10; i++)
    printf("%d ",a[i]);
    

    printf("\n");
    return 0;
}