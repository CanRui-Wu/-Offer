#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};


// class Solution {
// public:
//     ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
//         unordered_set<ListNode *> my_set;
//         while(pHead1) {
//         	my_set.insert(pHead1);
//         	pHead1 = pHead1->next;
//         }
//         while(pHead2) {
// 			if(my_set.find(pHead2) != my_set.end())
//         		return pHead2;
//         	pHead2 = pHead2->next;
//         }
//         return NULL;
//     }
// };



class Solution {
public:
	static bool compare(ListNode *a,ListNode *b) {
		return a == b;
	}
	static size_t hasher(ListNode *a) {
		return hash<decltype(a)>()(a);
	}
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        unordered_set<ListNode *,size_t(*)(ListNode*),bool(*)(ListNode*,ListNode*)> my_set(100,hasher,compare);
        while(pHead1) {
        	my_set.insert(pHead1);
        	pHead1 = pHead1->next;
        }
        while(pHead2) {
			if(my_set.find(pHead2) != my_set.end())
        		return pHead2;
        	pHead2 = pHead2->next;
        }
        return NULL;
    }
};

int main() {
	Solution solution;
	ListNode *t1 = new ListNode(1);
	ListNode *t2 = new ListNode(2);
	ListNode *t3 = new ListNode(3);
	ListNode *t4 = new ListNode(4);
	ListNode *t5 = new ListNode(5);
	ListNode *t6 = new ListNode(6);
	ListNode *t7 = new ListNode(7);
	t1->next = t4;
	t4->next = t3;
	t2->next = t7;
	t7->next = t3;
	t3->next = t6;
	t6->next = t5;
	cout << solution.FindFirstCommonNode(t1,t2)->val << endl;
	delete t1;
	delete t2;
	delete t3;
	delete t4;
	delete t5;
	delete t6;
	delete t7;
}