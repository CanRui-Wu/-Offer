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
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if(pRootOfTree == NULL)
        	return NULL;
        TreeNode *left =  Convert(pRootOfTree->left);
        TreeNode *right = Convert(pRootOfTree->right);
        TreeNode *result = left;
        if(left != NULL) {
        	while(left->right != NULL)
        		left = left->right;
        	pRootOfTree->left = left;
        	left->right = pRootOfTree;
        }
        if(right != NULL) {
        	pRootOfTree->right = right;
        	right->left = pRootOfTree;
        }
        if(result == NULL)
        	result = pRootOfTree;
        return result;
    }
};

int main() {
	Solution solution;
	TreeNode *t1 = new TreeNode(1);
	TreeNode *t2 = new TreeNode(2);
	TreeNode *t3 = new TreeNode(3);
	TreeNode *t4 = new TreeNode(4);
	TreeNode *t5 = new TreeNode(5);
	TreeNode *t6 = new TreeNode(6);
	TreeNode *t7 = new TreeNode(7);
	TreeNode *t8 = new TreeNode(8);
	TreeNode *t9 = new TreeNode(9);
	t5->left = t3;
	t5->right = t7;
	t3->left = t2;
	t3->right = t4;
	t2->left = t1;
	t7->left = t6;
	t7->right = t8;
	t8->right = t9;
	TreeNode *current = solution.Convert(t5); 
	while(current != NULL) {
		cout << current->val << endl;
		current = current->right;
	}
	delete t1;
	delete t2;
	delete t3;
	delete t4;
	delete t5;
	delete t6;
	delete t7;
	delete t8;
	delete t9;
}