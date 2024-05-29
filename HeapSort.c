#include<stdio.h>

int size = 0;

void max_heapify(int ar[],int parent){
    int left = 2*parent;
    int right = left +1;
    int temp;
    int largest = parent;
    if(ar[left] > ar[right] && left <= size) largest = left;
    else if(ar[left] <= ar[right] && right <= size) largest = right;
    if(largest != parent){
        if(ar[largest] > ar[parent]){
            temp = ar[parent];
            ar[parent] = ar[largest];
            ar[largest] = temp;
            max_heapify(ar,largest);
        }
    }
}



void build_maxhp(int ar[]){
    int i;
    for(i=size/2;i>=1;i--){
        max_heapify(ar,i);
    }
}



void heap_sort(int ar[]){
    int temp,i;
    build_maxhp(ar);
    for(i=size;i>=2;i--){
        temp = ar[i];
        ar[i] = ar[1];
        ar[1] = temp;
        size -= 1;
        max_heapify(ar,1);
    }
}






int main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);
    n++;
    int ar[n];
    size = n-1;
    ar[0] = 0;
    printf("Enter elements : ");
    for(int i=1;i<n;i++){
        scanf("%d", &ar[i]);
    }
    heap_sort(ar);
    printf("after sorting \n");
    for(int i=1;i<n;i++){
        printf("%d\t",ar[i]);
    }
    return 0;
}
