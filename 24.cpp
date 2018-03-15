#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
    	if(pHead == NULL)
    		return NULL;
    	ListNode *current = pHead;
    	ListNode *current_next = current->next;
    	ListNode *temp;
    	current->next = NULL;
    	while(current_next != NULL) {
    		temp = current_next->next;
    		current_next->next = current;
    		current = current_next;
    		current_next = temp;
    	}
    	return current;
    }

};


int main() {
	Solution solution;
	ListNode *t1 = new ListNode(1);
	ListNode *t2 = new ListNode(2);
	ListNode *t3 = new ListNode(3);
	ListNode *t4 = new ListNode(4);
	ListNode *t5 = new ListNode(5);
	t1->next = t2;
	t2->next = t3;
	t3->next = t4;
	t4->next = t5;
	ListNode *current = t1;
	current = solution.ReverseList(t1); 
	while(current != NULL) {
		cout << current->val << endl;
		current = current->next;
	}
	delete t1;
	delete t2;
	delete t3;
	delete t4;
	delete t5;
}
