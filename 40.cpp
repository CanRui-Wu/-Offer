#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void sortLeastK(vector<int> &input,int start,int end,int k) {
		int current = start;
        for(int i = start;i <= end;i++) {
        	if(input[i] < input[end]) {
        		if(i != current)
        			swap(input[i],input[current]);
        		current++;
        	}
        }
        swap(input[end],input[current]);
        if(current == k-1)
        	return;
        else if(current < k-1)
        	sortLeastK(input,current+1,end,k);
        else if(current > k-1)
        	sortLeastK(input,start,current-1,k);
	}
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    	if(k > input.size() || k <= 0)
    		return vector<int>();
    	sortLeastK(input,0,input.size()-1,k);
    	vector<int> result;
       	for(int i = 0;i < k;i++)
       		result.push_back(input[i]);
       	return result;
    }
};

int main() {
	Solution solution;
	vector<int> test = {1,3,5,7,9,2,4,6,8,10,5,7,4,2};
	test = solution.GetLeastNumbers_Solution(test,5);
	for(int i = 0;i < test.size();i++)
		cout << test[i] << " ";
	cout << endl;
}