#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > result;
        if(sum <= 2) {
            return result;
        } 
        int start = 1;
        int end = 2;
        int current = 3;
        while(current <= sum) {
            if(current == sum) {
                vector<int> temp;
                for(int i = start;i <= end;i++) {
                    temp.push_back(i);
                }
                result.push_back(temp);
            }
            if(current+end+1 <= sum) {
                end++;
                current += end;
            } else {
                current -= start;
                start++;
                if(start == end) {
                    end++;
                    current += end;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int> > my = solution.FindContinuousSequence(3);
    for(const auto&v:my) {
        for(const auto&val:v) {
            cout << val << " ";
        }
        cout << endl;
    }
}