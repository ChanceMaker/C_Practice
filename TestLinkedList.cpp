#include <iostream>

void display();
void front_insert(int);
struct Node{
	int data;
	struct Node* next;
};
struct Node* head = NULL;
void front_insert(int new_data){
	struct Node * new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = head;
	head = new_node;
}

int main(){
	front_insert(1);
	front_insert(3);
	front_insert(3);
	display();


	return 0;
}
void display(){
	struct Node* ptr;
	ptr = head;
	while(ptr != NULL){
		std::cout << ptr-> data << " ";
		ptr = ptr->next;
	}
}