//Huff Encoding
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define node structure
struct node {
	char value;
	struct node *left, *right; // pointer
};

//search tree
int search(char c[], struct node *n, int i){
	//printf("%c\n", n->value);
	if (n->value != '<' && n->value != '>' && n->value != '\0'){
		printf("%c", n->value);
		return i;
	}
	else if (c[i] == '0'){
		return search(c, n->left, i + 1);
	}
	else {
		return search(c, n->right, i + 1);
	}
}

//add node function
struct node* newNode_Helper(char a){
	struct node *x = malloc(sizeof(*x));
	x->value = a;
	x->left = NULL; 
	x->right = NULL;

	return(x); 
}

void newNode(struct node *n, char x[], int i){
	
	if (i == strlen(x) - 1 && x[i] == '0') {
		n->left = newNode_Helper(x[0]);
	}
	else if (i == strlen(x) - 1 && x[i] == '1') {
		n->right = newNode_Helper(x[0]);
	}
	else if (x[i] == '0' && n->left == NULL) {
		n->left = newNode_Helper('<');
		newNode(n->left, x, i+1);
	}
	else if (x[i] == '1' && n->right == NULL) {
		n->right = newNode_Helper('>');
		newNode(n->right, x, i+1);
	}
	else if (x[i] == '0' && n->left != NULL){
		newNode(n->left, x, i+1);
	}
	else if (x[i] == '1' && n->right != NULL){
		newNode(n->right, x, i+1);
	}
	//return 0;
}

int main() {
	//Initialize first parent node with dummy value
	struct node* parent = newNode_Helper('\0');

	//Read decoding imput
	int N;
	scanf("%d", &N);
	int i;
	for (i = 0; i <= N; i = i + 1){
		char code[100];
		gets(code);

		newNode(parent, code, 1); //Building tree
	}

	//search through tree
	char message[100000];
	gets(message);
	int index = 0;
	
	while (index < strlen(message)) {
		index = search(message, parent, index);
	}
	free(parent);
	
	return 0;
}