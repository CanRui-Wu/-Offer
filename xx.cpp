#include <iostream>
#include <memory>
#include <cmath>
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
	int getDepth(TreeNode *root) {
		if(root == NULL)
			return 0;
		int left_dept = getDepth(root->left);
		int right_dept = getDepth(root->right);
		if(left_dept == -1 || right_dept == -1 || abs(left_dept-right_dept) > 1)
			return -1;
		return max(left_dept,right_dept)+1;
	}

    bool IsBalanced_Solution(TreeNode* pRoot) {
    	if(pRoot == NULL)
    		return true;
    	int left_dept = getDepth(pRoot->left);
    	int right_dept = getDepth(pRoot->right);
    	if(left_dept != -1 && right_dept != -1 && abs(left_dept-right_dept) <= 1)
    		return true;
    	return false;
    }
};

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
	// t1->right = t3.get();
	t2->left = t4.get();
	t2->right = t5.get();
	// t3->left = t6.get();
	// t3->right = t7.get();
	cout << solution.IsBalanced_Solution(t1.get()) << endl;
	
	//print(t1.get());
}