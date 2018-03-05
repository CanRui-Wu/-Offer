#include <iostream>
#include <vector>
#include <stack>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> mystack;
        vector<int> result;
        ListNode *current = head;
        while(current != NULL) {
        	mystack.push(current->val);
        	current = current->next;
        }
        while(!mystack.empty()) {
        	result.push_back(mystack.top());
        	mystack.pop();
        }
        return result;
    }	
};

int main() {
	
}