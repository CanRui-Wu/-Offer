#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	bool myFunc(TreeNode *pRoot1,TreeNode *pRoot2) {
		if(pRoot2 == NULL)
			return true;
		if(pRoot1 == NULL)
			return false;
		if(pRoot1->val != pRoot2->val) {
			return false;
		} else {
			return myFunc(pRoot1->left,pRoot2->left) && myFunc(pRoot1->right,pRoot2->right);
		}
	}
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    	if(pRoot1 == NULL || pRoot2 == NULL) {
    		return false;
    	}
    	if(myFunc(pRoot1,pRoot2)) {
    		return true;
    	} else {
    		return HasSubtree(pRoot1->left,pRoot2) || HasSubtree(pRoot1->right,pRoot2);
    	}
    }
};

int main() {
	TreeNode *t1 = new TreeNode(1);
	TreeNode *t2 = new TreeNode(2);
	TreeNode *t3 = new TreeNode(3);
	TreeNode *t4 = new TreeNode(4);
	TreeNode *t5 = new TreeNode(5);
	TreeNode *t6 = new TreeNode(6);
	TreeNode *t7 = new TreeNode(7);
	t1->left = t2;
	t1->right = t3;
	t2->left = t4;
	t2->right = t5;
	t3->left = t6;
	t3->right = t7;
	TreeNode *sub_t1 = new TreeNode(3);
	TreeNode *sub_t2 = new TreeNode(7);
	TreeNode *sub_t3 = new TreeNode(4);
	sub_t1->right = sub_t2;
	sub_t1->left = sub_t3;
	Solution solution;
	cout << solution.HasSubtree(t1,sub_t1) << endl;

}
