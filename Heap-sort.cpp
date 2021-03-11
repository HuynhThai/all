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
void PushDown(recordType a[], int first,int last)
{ int  r= first;
  while (r <= (last-1)/2)
   if (last == 2*r+1) {
     if (a[r].key > a[last].key) Swap(a[r],a[last]);
     r = last; //break;
   } else
   if ((a[r].key>a[2*r+1].key) && (a[2*r+1].key<=a[2*r+2].key))
   {
      Swap(a[r],a[2*r+1]);
      r = 2*r+1 ;
   } else
      if ((a[r].key>a[2*r+2].key) && (a[2*r+2].key<a[2*r+1].key))
      {
	 Swap(a[r],a[2*r+2]);
	 r = 2*r+2 ;
      }
      else
	 r = last; //break;
}
void HeapSort(recordType a[], int n){  
	int i;
	for (i = (n-2)/2; i>=0; i--)
		PushDown(a,i,n-1); //building initial heap
	//sort 
	for (i = n-1; i>=2; i--) {
		Swap(a[0],a[i]);
		PushDown(a, 0, i-1); // rearrange A[0…i-1]
      }
	Swap(a[0],a[1]);// for 2 last elements in descending order
}

int main(){
	int n;
	recordType a[100];
	ArrInput(a,n);
	printf("before heapsort: \n");
	printArr(a,n);
	HeapSort(a,n);
	printf("after heapsort: \n");
	printArr(a,n);
	
}
