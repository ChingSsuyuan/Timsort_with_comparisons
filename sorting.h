#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <algorithm>

using namespace std;

static int swapCount = 0;

void swap(int* a, int* b)
{
    //swapCount++;
    int temp;
    temp = *a; 
    *a = *b; 
    *b = temp; 
}


/* See Knuth's shuffles https://en.wikipedia.org/wiki/Random_permutation */



void insertionsort(int a[],  int n)
{ 
  for(int j=1;j<n;j++){
  int key=a[j];
  int i=j-1;
  while (i>-1 && a[i]>key)
  {
    a[i+1]=a[i];
    i--;
  }
  a[i+1]=key;
  }
}



// Order Theta(NlogN) sorting


void mergeSort(int a[], int a_tmp[], int l, int r)
{
  if (l<r)
  {
    int mid=(l+r)/2;
    mergeSort(a,a_tmp,l,mid);
    mergeSort(a,a_tmp,mid+1,r);
    int i=l;int k=l;int j=mid+1;
    while (i <= mid && j <= r) {
      if (a[i] <= a[j]) {
        a_tmp[k++] = a[i++];
      } else {
        a_tmp[k++] = a[j++];
      }
    }
    while (i <= mid) {
      a_tmp[k++] = a[i++];
    }
    while (j <= r) {
      a_tmp[k++] = a[j++];
    }
    for (int i = l; i <= r; i++) {
      a[i] = a_tmp[i];
    }
  }
}

// 
void mergeSortblend(int a[], int a_tmp[], int l, int r)
{if (r-l+1<=32)
{
  insertionsort(a,r-l);
}
else
{
  mergeSort(a,a_tmp,l,r);
}

}

void checkInorder(int a[],int left, int right){
  //checks  that a is in order from left to right
  for (int i = left;i <right; i++){
    if (a[i] > a[i+1]){
      int tmp = i;
    }
  }
}
void simpleTimsort(int a[], int a_tmp[], int n)
{ 
  int l=0;
  int r=n-1;
  const int minsizerun=32;
  // sort small chunks using insertion sort
  for (int i = 0; i < n; i+=minsizerun)
  {
    int right=std::min(i + minsizerun, n)-i;
    insertionsort(a+i,right);
  // merge sorted chunks using merge sort
  }for (int size = minsizerun; size< n; size=size*2)
  {
    for (int l = 0; l < n; l=l+2*size)
    {// Calculate the end of the second subarray
      int r=std::min((l+2*size-1),n-1);
      if(l+size<r){
      mergeSort(a,a_tmp,l,r);}
    }
  }
}// end function

#endif 
