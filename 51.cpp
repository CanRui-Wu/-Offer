#include <iostream>
#include <vector>
using namespace std;

 class Solution {
public:
	long long mycount(vector<int> &array,vector<int> &temp,int start,int end) {
		if(start == end || start == end+1)
			return 0;
		int middle = (start+end)/2;
		long long count1 = mycount(array,temp,start,middle);
		long long count2 = mycount(array,temp,middle+1,end);
		for(int i = start;i <= end;i++)
			temp[i] = array[i];
		int current1 = start;
		int current2 = middle+1;
		long long count3 = 0;
		int current = start;
		while(current != end+1) {
			if(current1 == middle+1) {
				array[current] = temp[current2];
				current2++;
			} else if(current2 == end+1) {
				array[current] = temp[current1];
				current1++;
			} else if(temp[current1] > temp[current2]) {
				count3 += middle-current1+1;
				array[current] = temp[current2];
				current2++;
			} else {
				array[current] = temp[current1];
				current1++;
			}
			current++;
		}
		return count1+count2+count3;
	}

    int InversePairs(vector<int> data) {
        vector<int> temp(data.begin(),data.end());
		return mycount(data,temp,0,temp.size()-1)%1000000007;
    }
};


int main() {
	Solution solution;
	vector<int> array = {364,637,341,406,747,995,234,971,571,219,993,407,416,366,315,301,601,650,418,355,460,505,360,965,516,648,727,667,465,849,455,181,486,149,588,233,144,174,557,67,746,550,474,162,268,142,463,221,882,576,604,739,288,569,256,936,275,401,497,82,935,983,583,523,697,478,147,795,380,973,958,115,773,870,259,655,446,863,735,784,3,671,433,630,425,930,64,266,235,187,284,665,874,80,45,848,38,811,267,575};
	cout << solution.InversePairs(array) << endl;
}