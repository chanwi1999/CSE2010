#include <stdio.h>
#include <stdlib.h>

typedef struct node * pNode;
typedef pNode List;
typedef pNode Node;

struct node{
	int value;
	Node next; //node* next
};

List makeEmptyList(List L); //header
void insert(int v, List L, Node N);//N->next = new Node(value = v)
void delete_one(int v, List L); //delete -> free
Node findPrev(int v, List L);
Node find(int v, List L);
void deleteList(List L); //all free


//main///////////////////////////////////////////////////////////////


int main(){
	List head = NULL;
	head = makeEmptyList(head);
	Node find_node, temp = NULL;
	char input;
	int find_val, new_val;

	while(1){
		scanf("%c", &input);

		if(input == 'e'){ //quit
			deleteList(head);
			break;
		}

		if(input == 'i'){ //insert
			scanf("%d %d",&new_val, &find_val);
			find_node = find(find_val, head);
			if(find_node){
				insert(new_val, head, find_node);
			}else{
				printf("Insert error. The %d isn't in the list.\n"
						, find_val);
			}
		}
		else if(input == 'd'){ //delete
			scanf("%d", &find_val);
			delete_one(find_val, head);
		}
		else if(input == 'f'){ //find
			scanf("%d", &find_val);
			find_node = findPrev(find_val, head);
			if(find_node){
				if(find_node->value == 0){
					printf("The %d is next of the header.\n"
							, find_val);
				}else{
					printf("The %d is next of The %d.\n"
						, find_val, find_node->value);
				}
			}else{
				printf("Find error. The %d isn't in the list.\n"
						, find_val);
			}
		}
		else if(input == 's'){ //show
			temp = head;
			while(temp->next != NULL){
				temp = temp->next;
				printf("%d ", temp->value);
			}
			printf("\n");
		}
	}

	return 0;
}


//funtion////////////////////////////////////////////////////////////


List makeEmptyList(List L){
	L = (List)malloc(sizeof(List));
	L->value = 0;
	L->next = NULL;
	
	return L;
}


void insert(int v, List L, Node N){ //N->next = new_node(value = v)
	Node new_node = (Node)malloc(sizeof(Node));
	new_node->value = v;

	new_node->next = N->next;
	N->next = new_node;
}

void delete_one(int v, List L){
	Node find_node = find(v, L);
	if(find_node){
		Node pre_node = findPrev(v, L);
		pre_node->next = find_node->next;
		free(find_node);
	}else{
		printf("Delete error. The %d isn't in the list.\n", v);
	}
}

Node findPrev(int v, List L){
	Node tmp = (Node)L;
	while(tmp->next != NULL){
		if(tmp->value == v){
			return tmp;
		}
		tmp = tmp->next;
	}
	
	return 0;
}

Node find(int v, List L){
	Node tmp = (Node)L;
	while(tmp != NULL){
		if(tmp->value == v){
			return tmp;
		}
		tmp = tmp->next;
	}

	return 0;
}

void deleteList(List L){ //all free
	while(L->next != NULL){
		free(L);
		L = L->next;
	}
}
