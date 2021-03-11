#include <stdio.h>

typedef  int keytype;
typedef  float otherType;
typedef  struct recordType {
    keytype key;
    otherType otherfields;
};

void Swap(recordType &x, recordType &y)
{
      recordType temp;
      temp = x;
      x = y;
      y = temp;
}
void ArrInput(recordType a[], int& n){
	printf("enter the number of elements: ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		printf("enter the element %d:",i+1);
		scanf("%d", &a[i].key);
		}
}
void printArr(recordType a[], int n){
	printf("Array elements \n");
	for (int i=0; i<n; i++){
		printf("%d", a[i].key);
	}
	printf("\n");
}

int FindPivot(recordType a[], int i,int j)
{  keytype  firstkey;
   int k ;
   k = i+1;
   firstkey = a[i].key;
   while ( (k <= j) && (a[k].key == firstkey) ) k++;
   if (k > j)  return -1;
   else
      if (a[k].key>firstkey) return k; else return i;
}
int Partition(recordType a[], int i,int j, keytype pivot)
{   int L,R;
	L = i;
	R = j;
 	while (L <= R) {
	   while (a[L].key < pivot)  L++;
	   while (a[R].key >= pivot) R--;
 	   if (L<R) Swap(a[L],a[R]);
	        }
	return L;  //return partition position
}
void QuickSort(recordType a[], int i,int j)
{ keytype pivot;
  int pivotindex, k;
  pivotindex = FindPivot(a,i,j);
  if (pivotindex != -1) {
      pivot = a[pivotindex].key;
      k = Partition(a,i,j,pivot);
      QuickSort(a,i,k-1);
      QuickSort(a,k,j);
  }
}

int main(){
	int n;
	recordType a[100];
	ArrInput(a,n);
	printf("before quicksort: \n");
	printArr(a,n);
	QuickSort(a,0,n-1);
	printf("after quicksort: \n");
	printArr(a,n);
	
}

