#include <stdio.h>
#include <math.h>

#define MAX_ELEMENTS 100000
#define HEAP_FULL(n) (n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)

typedef struct{
	int key;
} element;

element heap[MAX_ELEMENTS]; //==int heap[MAX_ELEMENTS]
int n = 0;

void insert_min_heap(element item);
element delete_min_heap();


//main////////////////////////////////////////////////////

int main(){
	int q, qn;
	element item;
	scanf("%d", &q);

	for(int i=0; i<q; i++){
		scanf("%d", &qn);
		item.key = qn;
		
		if(qn){
			insert_min_heap(item);
		}else{
			item = delete_min_heap();
			printf("%d\n", item.key);
		}
	}

	return 0;
}


//function///////////////////////////////////////////////

void insert_min_heap(element item){
	if(HEAP_FULL(n))
		return;

	int i = ++n;
	heap[i] = item;
	while(i != 1){
		if(abs(heap[i].key) < abs(heap[i/2].key)){ //me < parent
			heap[i].key = heap[i/2].key;
			heap[i/2] = item;
		}
		else if(abs(heap[i].key) == abs(heap[i/2].key)){ //me == parent
			if(heap[i].key < heap[i/2].key){ //me < parent
				heap[i].key = heap[i/2].key; 
				heap[i/2] = item;
			}
		}
		i /= 2;
	}
}

element delete_min_heap(){
	element item, temp;
	
	if(HEAP_EMPTY(n)){
		return heap[0];
	}

	item = heap[1]; //item == root
	temp = heap[n--]; //temp == last node(=heap[n]), n--
	int parent = 1;
	int child = 2;
	while(child <= n){
		if((child < n) && (abs(heap[child].key) > abs(heap[child+1].key)))
			child++;
		else if(abs(temp.key) <= abs(heap[child].key)) break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;

	return item;
}


