#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0)
        	return 0;
        int left = 0,right = rotateArray.size()-1;
        int mid;
        while(left < right) {
        	mid = (left+right)/2;
        	if(rotateArray[left] < rotateArray[right])
        		return rotateArray[left];
        	if(rotateArray[mid] > rotateArray[right]) {
        		left = mid+1;
        	} else if(rotateArray[mid] < rotateArray[left]) {
        		right = mid;
        	} else {
        		int min_val = rotateArray[left];
        		for(int i = left+1;i <= right;i++)
        			min_val = min(min_val,rotateArray[i]);
        		return min_val;
        	}
        }
        return rotateArray[left];
    }
};

int main() {
	vector<int> rotateArray = {1};
	Solution solution;
	cout << solution.minNumberInRotateArray(rotateArray) << endl;
}