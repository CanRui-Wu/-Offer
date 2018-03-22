#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
    	if(numbers.size() != 5)
    		return false;
    	sort(numbers.begin(),numbers.end());
    	int dist = 0;
    	for(int i = 0;i < 4;i++) {
    		if(numbers[i] == 0)
    			continue;
    		if(numbers[i+1] == numbers[i])
    			return false;
    		dist += numbers[i+1]-numbers[i]; 
    	}
    	if(dist <= 4)
    		return true;
    	return false;
    }
};


int main() {
	vector<int> numbers = {8,9,0,5,6};
	Solution solution;
	cout << solution.IsContinuous(numbers) << endl;
}