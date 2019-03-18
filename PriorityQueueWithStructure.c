///Creating the Priority Queue(Min Heap Data Structure) using structure.
///This can be use as Auxiliary Data Structure for other Algorithms

#include<stdio.h>
#include<stdlib.h>
struct PriorityQueue
{
    int data;
};
typedef struct PriorityQueue PriorityQueue;
PriorityQueue* createPriorityQueue(int n)
{
    PriorityQueue *P=(PriorityQueue*)malloc(sizeof(PriorityQueue)*n);
    return P;
}
void heapify(PriorityQueue A[],int i ,int n)
{
    int t;
    int l=2*i+1;
    int r=2*i+2;
    int lar=i;
    if(A[lar].data<A[l].data&&l<n)
    {
        lar=l;
    }
        if(A[lar].data<A[r].data&&r<n)
    {
        lar=r;
    }
    if(lar!=i)
    {
        t=A[lar].data;
        A[lar].data=A[i].data;
        A[i].data=t;
        heapify(A,lar,n);
    }


}
void Build_Max_Heap(PriorityQueue A[],int n)
{
     int i=0;
    for(i=n/2+1;i>=0;i--)
        heapify(A,i,n);

}

void heap_sort(PriorityQueue A[],int n)
{
    int size=n-1;
    int i;
    int temp;

    Build_Max_Heap(A,n);

    for(i=0;i<n;i++)
    {
       temp=A[0].data;
       A[0].data=A[size].data;
       A[size].data=temp;
       Build_Max_Heap(A,size);
       size--;
    }



}
void DeleteHeap(PriorityQueue A[],int n,int item)
{
    int temp=A[0].data;
    A[0].data=A[n-1].data;
    n--;
    heapify(A,0,n);

}
void display(PriorityQueue A[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",A[i].data);

}
void generateArray(PriorityQueue A[],int n)
{
    int i;
   // srand();
    for(i=0;i<n;i++)
    {
        A[i].data=rand()%1000;
    }
}
int main()
{
    PriorityQueue *A=createPriorityQueue(100);
    generateArray(A,10);
    display(A,10);
    printf("\nAfter Sorting :-");
    heap_sort(A,10);
    display(A,10);
    return 0;
}

