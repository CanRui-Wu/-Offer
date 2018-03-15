#include <iostream>
#include <memory>
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
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL)
        	return;
        swap(pRoot->left,pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};

void print(TreeNode* root) {
	if(root == NULL)
		return;
	cout << root->val << endl;
	print(root->left);
	print(root->right);
}

int main() {
	shared_ptr<TreeNode> t1 = make_shared<TreeNode>(1);
	shared_ptr<TreeNode> t2 = make_shared<TreeNode>(2);
	shared_ptr<TreeNode> t3 = make_shared<TreeNode>(3);
	shared_ptr<TreeNode> t4 = make_shared<TreeNode>(4);
	shared_ptr<TreeNode> t5 = make_shared<TreeNode>(5);
	shared_ptr<TreeNode> t6 = make_shared<TreeNode>(6);
	shared_ptr<TreeNode> t7 = make_shared<TreeNode>(7);
	Solution solution;
	t1->left = t2.get();
	t1->right = t3.get();
	t2->left = t4.get();
	t2->right = t5.get();
	t3->left = t6.get();
	t3->right = t7.get();
	solution.Mirror(t1.get());
	print(t1.get());
}