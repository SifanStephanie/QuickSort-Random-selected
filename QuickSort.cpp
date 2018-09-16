#include <iostream>
#include<cstdlib>
#include<ctime>
#include <algorithm>

#define N 10

using namespace std;

void exchange(int A[], int i, int j){
    int temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}

/*
 * pivot is the first element using the method in algorithm
 */
/*
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

*/

/*
 * pivot is the middle of three random element
 */
/*
int RandPivot(int A[],int p, int q){
    srand((unsigned)time(NULL));
    int r3[3];
    int a3[3];
    int i=0;
    int k;
    for(k=0;k<3;k++){
        r3[i]=rand()%(p-q)+p;
        a3[i]=A[r3[i]];
    }
    sort(a3,a3+3);
    for(k=0;k<3;k++){
        if(A[r3[i]]==a3[1]){
            return r3[i];
        }
    }
}
 */

/*
 * quick sort method 1 定轴法
 */
/*
int Partition(int A[], int p, int q){
    int pivot=A[p];
    int left=p+1;
    int right=q;
    while(left<=right){
        while(A[left]<pivot&&left<=right)
            left++;
        while(A[right]>pivot&&right>=left)
            right--;
        if(left<right){
            exchange(A,left,right);
            left++;
            right--;

        }

    }
    exchange(A,p,right);
    return right;

}
*/

/*
 * quick sort method 2 挖坑法
 */
int Partition(int A[], int p, int q){
    int pivot=A[p];
    int low=p;
    int high=q;
    while(low<high){
        while(low<high && A[high]>=pivot){ //第一次循环一定要从右向左，因为A[low]是一个坑
            high--;
        }
        if(low<high){
            A[low]=A[high]; //A[low]的值已经保存起来了，所以可以填坑；然后A[high]又变成一个坑
            low++;
        }
        while(low<high && A[low]<pivot)
            low++;
        if(low<high){
            A[high]=A[low]; //A[high]的值已经保存起来了，所以可以填坑；然后A[low]又变成一个坑
            high--;
        }

    }
    A[low]=pivot; //最后填A[low]的坑
    return low;
}

void QuickSort(int A[], int p, int q){
    int r;
    if(p<q){
        r=Partition(A,p,q);
        QuickSort(A,p,r-1);
        QuickSort(A,r+1,q);
    }
}






int main() {

    int A[N];
    srand((unsigned)time(NULL));
    for(int i=0;i<N;i++){
        A[i]=rand()%(100-1);

    }

    for(int k:A){
        cout<<k<<endl;
    }

    cout<<endl;



    QuickSort(A,0,N-1);

    for(int a:A){
        cout<<a<<endl;
    }



    return 0;
}