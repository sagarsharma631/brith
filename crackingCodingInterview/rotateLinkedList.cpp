/*

 AUTHOR - SAGAR SHARMA
 
 Question - Right rotate linked list

*/

#include<iostream>
#include<string>
#include<stack>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}	
};

ListNode* newNode(int key)
{
	ListNode* temp = new ListNode;
	temp->val = key;
	temp->next = NULL;
	return temp;
}

void rotateList(ListNode* head, ListNode* oldHead, int k, int nodeNumber, int& firstNodeNumber, ListNode** newHead) {

	// Lambda to check whether this node is my first node of the rotated list.
	auto isThisFirst = [&]() -> bool {
		return (nodeNumber == firstNodeNumber) ? true : false;
	};

	if (head->next == NULL) {
		if ((k % nodeNumber) == 0) {
			// This means there is no need to rotate the list.
			firstNodeNumber = nodeNumber + 1;
			return;
		}
		firstNodeNumber = (nodeNumber - (k % nodeNumber)) + 1;
		head->next = oldHead;
		if (isThisFirst()) {
			*newHead = head;
		}
		return;
	}
	rotateList(head->next, oldHead, k, nodeNumber + 1, firstNodeNumber, newHead);
	if (isThisFirst()) {
		*newHead = head;
		return;
	}
	if (nodeNumber == firstNodeNumber - 1) {
		head->next = NULL;
	}
	return;
}

ListNode* rotateList(ListNode* head, int k) {
	if (head == NULL) {
		return NULL;
	}
	ListNode* newHead = NULL;
	int firstNodeNumber = 0;
	rotateList(head, head, k, 1, firstNodeNumber, &newHead);
	return newHead;
}

int main(int argc, char* Argv[]) {
	ListNode* head = newNode(1);

	// Lambda to print the linked list
	auto printList = [&]() -> void {
		ListNode* temp = head;
		while (temp) {
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	};
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head = rotateList(head,3);
	printList();
	return 0;
}
