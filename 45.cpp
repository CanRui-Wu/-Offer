#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool small(int a,int b) {
		string temp1 = to_string(a)+to_string(b);
		string temp2 = to_string(b)+to_string(a);
		return temp1 < temp2;
	}
    string PrintMinNumber(vector<int> numbers) {
    	string ans;
    	if(numbers.size() == 0)
    		return ans;
    	vector<int> result;
    	result.push_back(numbers[0]);
    	for(int i = 1;i < numbers.size();i++) {
    		result.push_back(numbers[i]);
    		for(int j = 0;j < result.size()-1;j++) {
    			if(small(numbers[i],result[j])) {
    				int temp = numbers[i];
    				int index = result.size()-2;
    				while(index >= j) {
    					result[index+1] = result[index];
    					index--;
    				}
    				result[j] = temp;
    				break;
    			}
    		}
    	}
    	for(const auto&val:result)
    		ans += to_string(val); 
    	return ans;
    }
};

int main() {
	Solution solution;
	vector<int> a = {3,32,321};
	cout << solution.PrintMinNumber(a) << endl;
	
}