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
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
    	if(pHead == NULL)
    		return NULL;
    	ListNode *fast = pHead;
    	ListNode *slow = pHead;
    	while(true) {
    		fast = fast->next;
    		if(fast == NULL)
    			return NULL;
    		else if(fast == slow)
    			break;
    		fast = fast->next;
    		if(fast == NULL)
    			return NULL;
    		else if(fast == slow)
    			break;
    		slow = slow->next;
    	}
    	int count = 1;
    	ListNode *current = fast->next;
    	while(current != fast) {
    		current = current->next;
    		count++;
    	}
    	slow = pHead;
    	fast = pHead;
    	while(count--) {
    		fast = fast->next;
    	}
    	while(slow != fast) {
    		slow = slow->next;
    		fast = fast->next;
    	}
    	return fast;
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
	current = solution.EntryNodeOfLoop(t1); 
	// while(current != NULL) {
	// 	cout << current->val << endl;
	// 	current = current->next;
	// }
	if(current != NULL) {
		cout << current->val << endl;
	}
	delete t1;
	delete t2;
	delete t3;
	delete t4;
	delete t5;
}