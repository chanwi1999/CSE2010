#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//struct////////////////////////////////////////

typedef struct{
	char name[10];
	int age;
	int salary;
	char department[20];
} Employee;

int max_size = 0;


//function////////////////////////////////////////////

void check(Employee list){
	printf("%s %d %d %s\n",
		list.name, list.age,
		list.salary, list.department);
}// struct variable all print

void insert(Employee *list, char *word){
	int i=0;

	for(i=0; i<max_size; i++){
		if(strcmp(list[i].name, " ") == 0) break;
	}// find blank

	if(i == max_size){
		printf("Not enough space\n");
		return;
	}

	// inform insert
	strcpy(list[i].name, strtok(NULL, "\n "));
	list[i].age = atoi(strtok(NULL, "\n "));
	list[i].salary = atoi(strtok(NULL, "\n "));
	strcpy(list[i].department, strtok(NULL, "\n "));

//	check(list[i]);
}

void delete_one(Employee *list, char *word){
	int i;
	char *name = strtok(NULL, "\n ");
//	printf("%s@", name);

	for(i=0; i<max_size; i++){
		if(strcmp(list[i].name, name) == 0) break;
	}

	if(i == max_size){
		printf("Not found\n");
		return;
	}
	
	// empty
	strcpy(list[i].name, " ");
	list[i].age = 0;
	list[i].salary = 0;
	strcpy(list[i].department, " ");

//	check(list[i]);
}

int find(Employee *list, char *word){
	char *name = strtok(NULL, "\n ");

	for(int idx=0; idx<max_size; idx++){
//		printf("%s@%s@\n", list[idx].name, name);
		if(strcmp(list[idx].name, name) == 0){
			return idx;
		}
	}
	
	return -1;
}

void inform(Employee *list, char *word){
	int count = 0;
	char *name = strtok(NULL, "\n ");

	for(int i=0; i<max_size; i++){
//		printf("%s@%s@", list[i].name, name);
		if(strcmp(list[i].name, name) == 0){
			check(list[i]);
			count++;
		}
	}

	if(count == 0){
		printf("Not found\n");
	}

	return;
}

int avgBenefit(Employee *list, char *word){
	int avg = 0, count = 0;
	char *dep = strtok(NULL, "\n ");

	for(int i=0; i<max_size; i++){
//		printf("%s@%s@", list[i].department, dep);
		if(strcmp(list[i].department, dep) == 0){
			avg += list[i].salary;
//			check(list[i]);
			count++;
//			printf("%d %d", avg, count);
		}
	}

	if(count != 0){
		avg /= count;
		return avg;
	}

	return 0;
}


//main///////////////////////////////////////////////

int main(){
	char input[100];
	char *word;
	Employee *list;
	int flag = 0;

	fgets(input, sizeof(input), stdin);
	word = strtok(input, "\n ");

	if(word == NULL) return 0;

	if(strcmp(word, "set") == 0){
		word = strtok(NULL, "\n ");
		max_size = atoi(word);
		list = (Employee*)malloc(sizeof(Employee)*max_size);
		flag = 1;
	} // create space

	if(!flag) return 0; // not create space -> quit

	for(int i=0; i<max_size; i++){
		strcpy(list[i].name, " ");
        	list[i].age = 0;
        	list[i].salary = 0;
     		strcpy(list[i].department, " ");
	} // initial

	while(1){
		fgets(input, sizeof(input), stdin);
		word = strtok(input ,"\n ");

		if(word == NULL) break; // input enter -> quit

		if(strcmp(word, "insert") == 0){
			insert(list, word);
		}
		else if(strcmp(word, "delete") == 0){
			delete_one(list, word);
		}
		else if(strcmp(word, "find") == 0){
			printf("%d\n", find(list, word));
		}
		else if(strcmp(word, "inform") == 0){
			inform(list, word);
		}
		else if(strcmp(word, "avg") == 0){
			printf("%d\n", avgBenefit(list, word));
		}
	}

	free(list);
	return 0;
}
