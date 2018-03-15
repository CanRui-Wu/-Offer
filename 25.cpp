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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
     	if(pHead1 == NULL)
     		return pHead2;
     	else if(pHead2 == NULL)
     		return pHead1;
     	ListNode *result = pHead1;
     	ListNode *current = result;
     	if(pHead1->val > pHead2->val) {
     		result = pHead2;
     		pHead2 = pHead2->next;
     	} else {
     		pHead1 = pHead1->next;
     	}
     	while(pHead1 != NULL || pHead2 != NULL) {
     		if(pHead1 == NULL||(pHead2 != NULL && pHead2->val < pHead1->val)) {
     			current->next = pHead2;
     			pHead2 = pHead2->next;
     		} else {
     			current->next = pHead1;
     			pHead1 = pHead1->next;
     		}
     		current = current->next;
     	}
     	return result;
    }
};

int main() {
	Solution solution;
	ListNode *t1 = new ListNode(2);
	ListNode *t2 = new ListNode(5);
	ListNode *t3 = new ListNode(8);
	ListNode *t4 = new ListNode(3);
	ListNode *t5 = new ListNode(5);
	ListNode *t6 = new ListNode(7);
	t1->next = t2;
	t2->next = t3;
	t4->next = t5;
	t5->next = t6;
	ListNode *current = t1;
	current = solution.Merge(t1,t4); 
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
