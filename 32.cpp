#include <iostream>
#include <memory>
#include <queue>
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
    	vector<int> result;
    	if(root == NULL)
    		return result;
    	queue<TreeNode *> myqueue;
    	myqueue.push(root);
    	while(!myqueue.empty()) {
    		result.push_back(myqueue.front()->val);
    		if(myqueue.front()->left != NULL)
    			myqueue.push(myqueue.front()->left);
    		if(myqueue.front()->right != NULL)
    			myqueue.push(myqueue.front()->right);
    		myqueue.pop();
    	}
    	return result;
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
	t1->right = t3.get();
	t2->left = t4.get();
	t2->right = t5.get();
	t3->left = t6.get();
	t3->right = t7.get();
	vector<int> result = solution.PrintFromTopToBottom(t1.get());
	for(const auto &value:result) {
		cout << value << endl;
	}
	//print(t1.get());
}