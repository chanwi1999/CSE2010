#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack * Stack;

struct stack{
	char *arr;
	int size;
	int top;
};

Stack createStack(int arr_size);
Stack makeEmptyStack(Stack S);
int isEmpty(Stack S);
void push(char X, Stack S);
char pop(Stack S);
void deleteStack(Stack S);


//main///////////////////////////////////////////////

int main(){
	Stack S = createStack(111);
	char input, output[111];
	int cp;// couple check
	int idx = 0;

	for(int i=0; i<111; i++){
		output[i] = 0;
	}// output initial

	while(1){
		scanf(" %c", &input);

		if(input == '!'){
			deleteStack(S);
			break;
		}// quit

		if(input == '#'){
			if(cp != 0){ // not couple
				printf("wrong.");
			}else{ // couple
				printf("right.");
			}
			
			// print output
			for(int i=0; i<strlen(output); i++){
				printf(" %c", output[i]);
			}

			printf("\n");
			
			// output empty
			for(int i=0; i<111; i++){
				output[i] = 0;
			}
		
			// initial	
			idx = 0;
			cp = 0;
			makeEmptyStack(S);
			continue;
		}
		
		if(input == '('){
			cp++;
		}

		push(input, S);
//		printf("%c", input);

		if(input == ')'){
			while(1){// pop until '('
				char out = pop(S);
				
				if(out == '(' || out == 0){
					break;
				}
				if(out == ')' || out == '#'){
					continue;
				}

				output[idx++] = out;
			}

			cp--;
		}

		// simple input
		if(cp==0 && input != '#' && input != ')'){
			while(1){// pop until '('
                                char out = pop(S);

                                if(out == '(' || out == 0){
                                        break;
                                }
                                if(out == ')' || out == '#'){
                                        continue;
                                }

                                output[idx++] = out;
                        }
		}
	}

	return 0;
}


//function////////////////////////////////////////////


Stack createStack(int arr_size){
	Stack S = (Stack)malloc(sizeof(struct stack));

	S->size = arr_size;
	S->top = -1;
	S->arr = (char*)malloc(sizeof(char)*arr_size);

	return S;
}

Stack makeEmptyStack(Stack S){
	S->top = -1;
}

int isEmpty(Stack S){
	if(S->top == -1){// empty check
		return 1;
	}

	return 0;
}

void push(char X, Stack S){// top up -> X push at arr[top]
	(S->arr)[++S->top] = X;
}

char pop(Stack S){// return arr[top] -> top down
	if(S->top == -1){// empty check
		return 0;
	}

	return (S->arr)[(S->top)--];
}

void deleteStack(Stack S){
	free(S->arr);
	free(S);
}

