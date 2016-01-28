//LinkedList Node (But I think this is more like a queue?)
#include <cstdio>

#include <cstdio>
//This implementation assumes your first node is a dummy node w/ no data
class Node {
	int data;
	Node * next;
	public:
		Node() {next = NULL;}
		void append(int data) {
			if (next)
				next->append(data);
			else {
				next = new Node();
				next->data = data;
			}
		}
		int pop() {
			if (next == NULL) {
				return -1;
			}
			Node * next_next = this->next->next;
			int out = this->next->data;
			this->next = next_next;
			return out;
		}
};

//test case
int main(){
	Node head = Node();
	head.append(4);
	head.append(7);
	printf("%d\n", head.pop());//4
	head.append(8);
	head.append(3);
	head.append(5);
	printf("%d\n", head.pop());//7
	int x = head.pop(); //8
	head.append(9);
	head.pop();
	printf("%d\n", x + head.pop());//13
	return 0;
}

