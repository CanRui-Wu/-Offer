#include <iostream>
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	if(k == 0)
    		return NULL;
    	ListNode *slow = pListHead;
    	ListNode *fast = pListHead;
    	while(fast) {
    		if((--k) == 0)
    			break;
    		fast = fast->next;
    	}
    	if(k != 0)
    		return NULL;
    	while(fast->next) {
    		slow = slow->next;
    		fast = fast->next;
    	}
    	return slow;
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
	current = solution.FindKthToTail(t1,2); 
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