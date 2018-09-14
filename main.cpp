#include <iostream>
#include <random>
using namespace std;

/**
 * Learning Algorithms - From MIT courses
 *
 * Random-selected algorithm gives a array A and finds the i'th
 * element we wants to find in order.
 *
 * This algorithm uses the Partition metho from the Quick-Sort. As in quicksort,
 * we partition the input array recursively. But unlike quicksort, which recursively
 * processes both sides of the partition, RANDOMIZED-SELECT works on only one side of the partition.
 * It is randommized because there is a random-number generator when we do the partition.
 *
 * When we assume that the elements are distinct, the expected running time of Randomized-selected
 * is O(n).
 */

#define N 10

/*
 * generate the random number
 */
int Random(int p,int q){
    return p+rand()%(q-p+1);
}

/*
 * exchange two numbers
 */
void exchange(int A[], int i, int j){
    int temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}

/*
 * using the random pivot to partition the
 * array A into to parts. The elements on the left side <= pivot
 * and the elements on the right side > pivot.
 * Then return the position of the partition pivot
 */
int Partition(int A[], int p, int q){
    int pivot=A[p];
    int j;
    int i=p;
    for(j=p+1;j<=q;j++){
        if(A[j]<=pivot){

            i++;
            exchange(A,i,j);
        }
    }
    exchange(A,p,i);
    return i;
}

/*
 * do the partition using a random number
 */
int randomPartition(int A[],int p, int q){
    int i=Random(p,q);
    exchange(A,p,i);

    return Partition(A,p,q);
}


int randomSelected(int A[],int p,int q,int i){
    if(p==q)
        return A[p];
    int r=randomPartition(A,p,q);
    //the number in the low region + 1 == the k'th large number 's position
    int k=r-p+1;
    if(k==i)
        return A[r];
    else if(k>i)
        return randomSelected(A,p,r-1,i);
    else
        return randomSelected(A,r+1,q,i-k);

}


int main() {
    int A[N];
    srand((unsigned)time(NULL));
    for(int i=0;i<N;i++){
        A[i]=rand()%(100-1);
        cout<<A[i]<<" ";
    }
    cout<<endl;
    int res=randomSelected(A,0,9,1);
    cout<<res<<endl;

    return 0;
}