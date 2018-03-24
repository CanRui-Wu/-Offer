#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
    	if(index == 1)
    		return 1;
    	else if(index <= 0)
    		return 0;
        int small_current = 1;
        int middle_current = 1;
        int big_current = 1;
        vector<int> result;
        result.push_back(1);
        while(result.size() < index) {
        	int temp1 = result[small_current-1]*2;
        	int temp2 = result[middle_current-1]*3;
        	int temp3 = result[big_current-1]*5;
        	if(temp1 <= temp2 && temp1 <= temp3) {
        		if(temp1 != result.back()) {
        			result.push_back(temp1);	
        		}
        		small_current++;
        	} else if(temp2 <= temp1 && temp2 <= temp3) {
        		if(temp2 != result.back()) {
        			result.push_back(temp2);	
        		}
        		middle_current++;
        	} else {
        		if(temp3 != result.back()) {
        			result.push_back(temp3);	
        		}
        		big_current++;
        	}	
        }
        return result.back();
    }
};

int main() {
	Solution solution;
	cout << solution.GetUglyNumber_Solution(10) << endl;
}