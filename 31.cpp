#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    	if(pushV.size() == 0 || popV.size() == 0)
    		return true;
        stack<int> mystack;
        int push_index = 0;
        int pop_index = 0;
        while(true) {
        	if(pop_index == popV.size())
        		return true;
        	if(push_index != pushV.size() && pushV[push_index] == popV[pop_index]) {
        		push_index++;
        		pop_index++;
        	} else if(!mystack.empty() && mystack.top() == popV[pop_index]) {
        		mystack.pop();
        		pop_index++;
        	} else {
        		if(push_index == pushV.size())
        			break;
        		mystack.push(pushV[push_index++]);
        	}
        }
        return false;
    }
};


int main() {
	Solution solution;
	vector<int> temp1 = {4,5};
	vector<int> temp2 = {5,4};
	cout << solution.IsPopOrder(temp1,temp2) << endl;
}

