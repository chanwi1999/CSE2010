#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	node* next;
} node;

typedef node* nptr;

typedef struct queue{
	int count;
	nptr front; //node* front: output place
	nptr rear; //node* rear: input place
} queue;

queue* create_queue();
void delete_queue(queue* qptr);
int add_from_rear(queue* qptr, int val);
int remove_from_front(queue* qptr);


//main////////////////////////////////////////////////////

int main(){
	int word, input_val, output_val, prev_val;
	queue* list_queue = create_queue();

	while(1){
		scanf("%d", &word);

		if(word == 1){ //insert
			scanf("%d", &input_val);
			prev_val = add_from_rear(list_queue, input_val);

			if(prev_val == -1){ //if empty->new
				printf("only %d!\n", input_val);
			}else{
				printf("%d after %d\n", input_val, prev_val);
			}

		}else if(word == 2){ //one delete
			output_val = remove_from_front(list_queue);
			
			if(output_val == -1){ //if empty
				printf("There is no element!\n");		
			}else{
				printf("remove value %d\n", output_val);
			}

		}else if(word == -1){ //all delete and quit
			delete_queue(list_queue);
			break;

		}else{ //another input; quit
			break;
		}
	}

	return 0;
}


//function///////////////////////////////////////////////

queue* create_queue(){ //create and initial and return
	queue* new_queue = (queue*)malloc(sizeof(queue));
	
	new_queue->count = 0;
	new_queue->front = NULL;
	new_queue->rear = NULL;

	return new_queue;
}

void delete_queue(queue* qptr){
	while(qptr->count != 0){ //all dequeue and delete
		printf("%d ", qptr->front->val);

		nptr tmp = qptr->front;
		qptr->front = qptr->front->next;
		free(tmp);

		qptr->count--;
	}

	free(qptr);
	printf("\nDelete complete!\n");
}

int add_from_rear(queue* qptr, int val){
	//create and initial
	nptr new_element = (nptr)malloc(sizeof(node)); //node* new_element
	new_element->val = val;
	new_element->next = NULL;

	int tmp_val; //prev_val of input_val

	if(qptr->count == 0){ //if front == rear == NULL
		tmp_val = -1;
		qptr->rear = new_element;
		qptr->front = new_element;
	}else{
		tmp_val = qptr->rear->val;
		qptr->rear->next = new_element;
		qptr->rear = qptr->rear->next;
	}

	qptr->count++;

	return tmp_val;
}

int remove_from_front(queue* qptr){
	if(qptr->count == 0){
		return -1;
	}else{
		nptr tmp = qptr->front; //node* tmp == front
		int tmp_val = tmp->val;
		
		qptr->front = qptr->front->next;
		free(tmp);

		qptr->count--;
		return tmp_val; //output
	}
}

