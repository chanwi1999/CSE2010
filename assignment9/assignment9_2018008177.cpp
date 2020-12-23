#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ELEMENTS 100000
#define HEAP_FULL(n) (n == MAX_ELEMENTS -1)
#define HEAP_EMPTY(n) (!n)
typedef struct{
	char name[100];
	int korean;
	int english;
	int math;
} student;
student heap[MAX_ELEMENTS+1]={0, 0, 0, 0}; //heap[0] = no student
int heap_size = 0;

int studentComp(student stu1, student stu2);
void adjust(int root, int n);
void mHeapsort(); //Korean max, Enlish min, Math max, Name min
void SWAP(int one, int two);


//main//////////////////////////////////////////////////////

int main(){
	int num = 0;
	int tempKor, tempEng, tempMath;
	char tempName[100];
	scanf("%d", &num);
	for(int i=0; i<num; i++){
		scanf("%s %d %d %d", tempName, &tempKor, &tempEng, &tempMath);
		strcpy(heap[++heap_size].name, tempName);
		heap[heap_size].korean = tempKor;
		heap[heap_size].english = tempEng;
		heap[heap_size].math = tempMath;
	}
	mHeapsort();

	for(int i=heap_size; i>0; i--)
		printf("%s\n", heap[i].name);
	
	return 0;
}


//function///////////////////////////////////////////

void adjust(int root, int n){
	int child;
	student rootStu;
	rootStu = heap[root];
	child = 2*root; //left child
	while(child <= n){
		if((child < n) && studentComp(heap[child], heap[child+1]) > 0){
			//child+1 priority is high
			child++;
		}
		if(studentComp(rootStu, heap[child]) < 0){
			//rootStu priority is high
			break;
		}
		else{
			heap[child/2] = heap[child];
			child *= 2;
		}
	}
	heap[child/2] = rootStu;
}

int studentComp(student stu1, student stu2){
	if(stu1.korean != stu2.korean){
		return stu2.korean - stu1.korean;
	}else{ //same Korea
		if(stu1.english != stu2.english){
			return stu1.english - stu2.english;
		}else{ //same English
			if(stu1.math != stu2.math){
				return stu2.math - stu1.math;
			}else{ //same Math
				return strcmp(stu1.name, stu2.name);
			}
		}
	}
}

void mHeapsort(){
	for(int i=heap_size/2; i>0; i--) //heapliy
		adjust(i,heap_size);
	for(int i=heap_size-1; i>0; i--){
		SWAP(1, i+1);
		adjust(1, i);
	}
}

void SWAP(int one, int two){
	student temp;
	
	strcpy(temp.name, heap[one].name);
	temp.korean = heap[one].korean;
	temp.english = heap[one].english;
	temp.math = heap[one].math;

	strcpy(heap[one].name, heap[two].name);
        heap[one].korean = heap[two].korean;
        heap[one].english = heap[two].english;
        heap[one].math = heap[two].math;

	strcpy(heap[two].name, temp.name);
        heap[two].korean = temp.korean;
        heap[two].english = temp.english;
        heap[two].math = temp.math;
}
