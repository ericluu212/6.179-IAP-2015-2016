#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
	int value;
	struct node_t *next; // pointer
} Node;

int main() {
	Node *node = malloc(sizeof(*node));
	node->value = 1;
	node->next = malloc(sizeof(*node));
	printf("%d\n", node->next);
	free(node);
	return 0;
}