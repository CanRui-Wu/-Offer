#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.size() == 0 || array[0].size() == 0)
        	return false;
        int col_current = array[0].size()-1;
       	int row_current = 0;
       	while(true) {
       		if(array[row_current][col_current] == target) {
       			return true;
       		}
       		else if(array[row_current][col_current] < target) {
       			if(++row_current == array.size())
       				return false;
       		} else {
       			if(--col_current == -1)
       				return false;
       		}
       	}
        return false;
    }
};

int main() {
	vector<vector<int> > array;
	vector<int> temp = {2,5,6,8};
	array.push_back(temp);
	temp = {3,5,6,9};
	array.push_back(temp);
	temp = {4,7,8,10};
	array.push_back(temp);
	Solution solution;
	cout << solution.Find(6,array) << endl;
}