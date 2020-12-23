#include <stdio.h>
#include <stdlib.h>

typedef struct node* Node;
typedef struct node* Tree; //root

typedef struct node{
	int val;
	Node parent;
	Node leftChild;
	Node rightChild;
} node;

Tree createTree();
int isEmpty(Tree T);
Node search(Tree T, int key);
void deleteNode(Tree T, int key);
void insertNode(Tree T, int key);
void showAll(Tree T);
int getHeight(Tree T, int key); //find Node(val==key) --> maxHeight(Node) call
int maxHeight(Tree T); //find leftHeight and rightHeight --> compare and return

//main////////////////////////////////////////////

int main(){
	char act;
	Tree T = createTree();
	int key;

	while(1){
		scanf("%c", &act);

		switch(act){
			case 'i':
				scanf("%d", &key);
				insertNode(T, key);
				break;
			case 'd':
				scanf("%d", &key);
				deleteNode(T, key);
				break;
			case 'h':
				scanf("%d", &key);
				printf("The height of the node (%d) is %d\n", key, getHeight(T, key));
				break;
			case 's':
				showAll(T->rightChild);
				printf("\n");
				break;
			case 'e':
				exit(0);
			default:
				break;
		}
	}

	return 0;
}


//function////////////////////////////////////////

Tree createTree(){
	Tree tmp = (Tree)malloc(sizeof(struct node));
	tmp->val = 0;
	tmp->leftChild = NULL;
	tmp->rightChild = NULL;
	tmp->parent = NULL;
	return tmp;
}

int isEmpty(Tree T){ //root == 0
	if(!T || !(T->rightChild))
		return 1;
	return 0;
}

Node search(Tree T, int key){ //where key is
	if(!T) return NULL;
	else if(key < T->val) return search(T->leftChild, key);
	else if(key > T->val) return search(T->rightChild, key);
	else return T;
}

void deleteNode(Tree T, int key){
	Node del = search(T, key);
	int dif = 0;
	if(!del){
		printf("Not found\n");
		return;
	}

	if(del->parent->leftChild == del)
		dif = 0;
	else
		dif = 1;
	
	Node tmp = del;
	int value = 0;

	if(del->leftChild == NULL && del->rightChild == NULL){
		if(dif)
			del->parent->rightChild = NULL;
		else
			del->parent->leftChild = NULL;
		free(del);
	}
	else if(del->leftChild != NULL && del->rightChild == NULL){
		if(dif)
			del->parent->rightChild = del->leftChild;
		else
			del->parent->leftChild = del->leftChild;
		free(del);
	}
	else if(del->leftChild == NULL && del->rightChild != NULL){
		if(dif)
			del->parent->rightChild = del->rightChild;
		else
			del->parent->leftChild = del->rightChild;
		free(del);
		
	}else{ //right -> all left
		tmp = del->rightChild; //go to the right
		while(tmp->leftChild) //if leftChild isn't NULL, keep going to the left
			tmp = tmp->leftChild;
//		printf("tmp->val: %d\n", tmp->val);
		del->val = tmp->val;
		if(del->rightChild == tmp) //if tmp can't go to the left
			del->rightChild = NULL;
		else
			tmp->parent->leftChild = tmp->rightChild;
		
		free(tmp);
	}
}

void insertNode(Tree T, int key){
	Node parent = NULL;
	Node tmp = NULL;
	int dif = 0;
	if(isEmpty(T)){
		tmp = createTree();
		tmp->val = key;
		tmp->parent = T;
		T->rightChild = tmp;
		return;
	}else{
		while(T){
			parent = T;
			if(key < parent->val){ //left child
				T = T->leftChild;
				dif = 0;
			}
			else if(parent->val < key){ //right child
				T = T->rightChild;
				dif = 1;
			}
		}
		T = createTree();
		T->val = key;
		T->parent = parent;
		if(dif == 1){ //right child
			parent->rightChild = T;
		}else{ //left child
			parent->leftChild = T;
		}
		return;
	}

	return;
}

void showAll(Tree T){ //inorder traversal --> sort form
	if(T){
		showAll(T->leftChild);
		printf("%d ", T->val);
		showAll(T->rightChild);
	}
}

int getHeight(Tree T, int key){
	Node tmp = search(T, key);

	if(!tmp || (tmp->leftChild == NULL & tmp->rightChild == NULL))
		return 0; //No height
	else
		return maxHeight(tmp)-1;
}

int maxHeight(Tree T){
	if(!T)
                return 0;
        else{
                int lHeight = maxHeight(T->leftChild);
                int rHeight = maxHeight(T->rightChild);

                if(lHeight > rHeight)
                        return lHeight+1;
                else
                        return rHeight+1;
        }
}

