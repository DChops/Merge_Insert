#include <stdio.h>
#include <stdlib.h>

void Mergesort(int [], int, int);
void Insertsort(int [], int, int);
void Merge(int [], int, int, int);
void ShiftRight(int [], int, int);

int main(int argc, const char * argv[])
{
    //Call fns here
    return 0;
}

void Mergesort(int Arr[MAXSIZE], int m, int n)
{
    int p = (m+n)/2;
    
    if(n-m < S)
    {
        Insertsort(Arr,m,n);
    }
    else
    {
        Mergesort(Arr,m,p);
        Mergesort(Arr,p+1,n);
    
        Merge(Arr,m,n,p+1);
    }
}

void Insertsort(int Arr[MAXSIZE], int m, int n)
{
    int temp, i, j;
    
    for(i=m; i<n; i++)
    {
        j = i;
        temp = Arr[j+1];
        while(j>=m)
        {
            COMP++;     //KEY COMPARISON
            if(Arr[j] < temp)
            {
                if(i!=j)
                {
                    ShiftRight(Arr, j+1, i);
                    Arr[j+1] = temp;
                }
                break;
            }
            j--;
        }
        if(j<m)
        {
            ShiftRight(Arr, j+1, i);
            Arr[j+1] = temp;
        }
    }
}

void Merge(int Arr[MAXSIZE], int m, int n, int p)
{
    int i=m, j=p;
    int temp;
    
    while(i<j && j<=n)
    {
        if(Arr[i] < Arr[j])
        {
            i++;
            
            COMP++;     //KEY COMPARISON
        }
        else if(Arr[i] > Arr[j])
        {
            temp = Arr[j];
            ShiftRight(Arr,i,j-1);
            Arr[i] = temp;
            i++;
            j++;
            
            COMP = COMP + 2 ;     //KEY COMPARISON
        }
        else
        {
            ShiftRight(Arr,i,j-1);
            i+=2;
            j++;
            
            COMP = COMP + 2 ;     //KEY COMPARISON
        }
    }
}

void ShiftRight(int Arr[MAXSIZE], int start, int end)
{
    int i = end;
    while(i>=start)
    {
        Arr[i+1] = Arr[i];
        i--;
    }
}
