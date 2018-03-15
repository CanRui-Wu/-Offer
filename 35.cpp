#include <iostream>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};


class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
    	if(pHead == NULL) {
    		return NULL;
    	}
    	RandomListNode *current = pHead;
    	
    	RandomListNode *temp = pHead;
    	while(current != NULL) {
    		temp = current->next;
    		current->next = new RandomListNode(current->label);
    		current->next->next = temp;
    		current = temp;
    	}
    	current = pHead;
    	while(current != NULL) {
    		if(current->random == NULL)
    			current->next->random = NULL;
    		else
    			current->next->random = current->random->next;
    		current = current->next->next;
    	}
    	current = pHead;
    	RandomListNode *result = pHead->next;
    	RandomListNode *n_current = NULL;
    	while(current != NULL) {
    		if(n_current == NULL) {
    			n_current = current->next;
    		} else {
    			n_current->next = current->next;
    			n_current = n_current->next;
    			cout << n_current->label << endl;
    		}
    		current->next = current->next->next;
    		current = current->next;
    	}
    	while(pHead != NULL) {
    		cout << "****" << pHead->label << endl;
    		pHead = pHead->next;
    	}
    	n_current->next = NULL;
    	return result;
    }
};

int main() {
	Solution solution;

	RandomListNode *r1 = new RandomListNode(1);
	RandomListNode *r2 = new RandomListNode(2);
	RandomListNode *r3 = new RandomListNode(3);
	RandomListNode *r4 = new RandomListNode(4);
	RandomListNode *r5 = new RandomListNode(5);
	RandomListNode *r6 = new RandomListNode(6);

	r1->next = r2;
	r1->random = NULL;
	r2->next = r3;
	r2->random = r2;
	r3->next = r4;
	r3->random = r4;
	r4->next = r5;
	r4->random = r1;
	r5->next = r6;
	r5->random = r4;
	r6->random = r3;

	RandomListNode *current = solution.Clone(r1);
	while(current != NULL) {

		cout << current->label << " ";
		if(current->random != NULL)
			cout << current->random->label;
		cout << endl;
		current = current->next;
	}

	delete r1;
	delete r2;
	delete r3;
	delete r4;
	delete r5;
	delete r6;
}