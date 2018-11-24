int * maxHeap(int heap[] , int i , int size)
{
	int l,r,largest ,temp ;
	int * p;

	l =2*i;
	r =(2*i)+1;

	if(( l <= size ) && ( heap[l] > heap[i]))
		largest = l;

	else
		largest = i;

	if(( r<= size ) && ( heap[r] > heap[largest]))
		largest = r;

	if(largest != i)
	{
		temp = heap[i];
		heap[i] = heap[largest];
		heap[largest] = temp;
		p = maxHeap(heap , largest , size);
	}
	return heap;
}

int * heapsort(int arr[], int n)
{
    int heapsize = n;
    int temp;
    for(int i=n ; i>=2;i--)
	{
		temp = *(arr +1);
		*(arr + 1) = *(arr+i);
		*(arr+i) = temp;
		heapsize--;
		arr = maxHeap(arr,1,heapsize);
	}
	return arr;

}

void main()
{
	int size,i,temp ;
	int *maxheap;
	printf("Enter size:");
	scanf("%d",&size);
	int arr[size + 1];

	for(i=1 ; i<=size ; i++)
	{
		printf("Enter value: ");
		scanf("%d",&arr[i]);

	}

	for(i = size/2 ; i>=1;i--)
	{
		maxheap = maxHeap(arr,i,size);

	}

	printf("Max heap:\n");

	for(i=1 ; i<= size ; i++)
	{
		printf("%d ",*(maxheap + i));
	}


	maxheap=heapsort(maxheap,size);

	printf("\nAfter heap sort:\n");

	for(i=1 ; i<= size ; i++)
	{
		printf("%d ",*(maxheap + i));

	}

}
