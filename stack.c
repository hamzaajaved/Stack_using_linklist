#include<stdio.h>
#include<stdlib.h>
void PUSH(int val);
void PRINT();
void POP();
struct stackNode{
	int value;
	struct stackNode *next;
};
struct stackNode *Top = NULL;
int main(){
	PUSH(5);
	PUSH(10);
	PUSH(15);
	PUSH(20);
	PUSH(25);
	PRINT();
	POP();
	POP();
	PRINT();	
}
void PUSH(int val){
	struct stackNode *ptr;
	ptr = (struct stackNode*) malloc (sizeof(struct stackNode));
	ptr->next = Top;
	ptr->value = val;
	Top = ptr;
}
void POP(){
	if(Top == NULL){
		printf("***Stack is Empty***\n");
	}else{
		struct stackNode *curr = Top;
		printf("Deleted: %d\n",curr->value);
		Top = Top->next;
		free(curr);
	}
}
void PRINT(){
	printf("The Elements of Stack are: \n");
	if(Top == NULL){
		printf("***Stack is Empty***");
	}else{
		struct stackNode *curr = Top;
		while(curr != NULL){
			printf("%d -> ",curr->value);
			curr = curr->next;
		}
		printf("NULL\n\n");
	}
}
