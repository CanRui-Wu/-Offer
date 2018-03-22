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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    	if(root == NULL) {
    		return final_result;
    	}
    	current_result.push_back(root->val);
    	if(root->left == NULL && root->right == NULL && root->val == expectNumber) {
    		final_result.push_back(current_result);
    	} 
    	if(root->left != NULL) {
    		FindPath(root->left,expectNumber-root->val);
    	} 
    	if(root->right != NULL) {
    		FindPath(root->right,expectNumber-root->val);
    	}
    	current_result.pop_back();
    	return final_result;
    }
private:
	vector<vector<int> > final_result;
	vector<int> current_result;
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
	vector<vector<int> > result = solution.FindPath(t1.get(),10);
	for(const auto &v:result) {
		for(const auto &value:v) {
			cout << value << " ";
		}
		cout << endl;
	}
	//print(t1.get());
}