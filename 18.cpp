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
    ListNode* deleteDuplication(ListNode* pHead) {
    	if(pHead == NULL) {
    		return NULL;
    	}
    	ListNode *result = NULL;
    	ListNode *current = NULL;
    	ListNode *cur_first = pHead;
    	ListNode *cur_last = pHead->next;
    	while(cur_last != NULL) {
    		if(cur_last->val == cur_first->val) {
    			cur_last = cur_last->next;
    		} else {
    			if(cur_first->next == cur_last) {
    				if(result == NULL) {
    					result = cur_first;
    					current = result;
    				} else {
    					current->next = cur_first;
    					current = current->next;
    				}
    				current->next = NULL;
    			}
    			cur_first = cur_last;
    			cur_last = cur_last->next;
    		}
    	}
    	if(cur_first->next == NULL) {
    		if(result == NULL) {
    			result = cur_first;
    		} else {
    			current->next = cur_first;
    		}
    	}
    	return result;
    }
};

int main() {
	Solution solution;
	ListNode *t1 = new ListNode(2);
	ListNode *t2 = new ListNode(3);
	ListNode *t3 = new ListNode(3);
	ListNode *t4 = new ListNode(3);
	ListNode *t5 = new ListNode(4);
	ListNode *t6 = new ListNode(5);
	// t1->next = t2;
	// t2->next = t3;
	// t3->next = t4;
	// t4->next = t5;
	// t5->next = t6;
	ListNode *current = t1;
	current = solution.deleteDuplication(NULL); 
	while(current != NULL) {
		cout << current->val << endl;
		current = current->next;
	}
	delete t1;
	delete t2;
	delete t3;
	delete t4;
	delete t5;
	delete t6;
}