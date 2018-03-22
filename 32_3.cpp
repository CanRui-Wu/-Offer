#include <iostream>
#include <vector>
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
    vector<vector<int> > Print(TreeNode* pRoot) {
    	vector<vector<int> > result;
    	if(pRoot == NULL)
    		return result;
    	queue<pair<TreeNode*,int> > myqueue;
    	myqueue.push(make_pair(pRoot,0));
    	vector<int> temp;
    	int current = 0;
    	while(!myqueue.empty()) {
    		pair<TreeNode*,int> mypair = myqueue.front();
    		myqueue.pop();
    		if(mypair.second != current) {
                if(current & 1 == 1) {
                    for(int i = 0;i < temp.size()/2;i++) {
                        swap(temp[i],temp[temp.size()-1-i]);
                    }
                } 
                result.push_back(temp);
    			temp.clear();
    			current++;
    		}
    		temp.push_back(mypair.first->val);
    		if(mypair.first->left != NULL)
    			myqueue.push(make_pair(mypair.first->left,mypair.second+1));
    		if(mypair.first->right != NULL)
    			myqueue.push(make_pair(mypair.first->right,mypair.second+1));
    	}
    	if(current & 1 == 1) {
            for(int i = 0;i < temp.size()/2;i++) {
                swap(temp[i],temp[temp.size()-1-i]);
            }
        } 
        result.push_back(temp);
    	return result;
    }
};

int main() {
	Solution solution;
	// vector<int> sequence = {4,8,6,12,16,14,10};
	// cout << solution.VerifySquenceOfBST(sequence) << endl;
}