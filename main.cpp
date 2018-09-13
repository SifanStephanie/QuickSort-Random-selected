#include <iostream>
#include <random>
using namespace std;

#define N 10

int Random(int p,int q){
    return p+rand()%(q-p+1);
}

void exchange(int A[], int i, int j){
    int temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}

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