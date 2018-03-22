#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
	void getPermutaition(char *ok,char *temp,char *use,int total,int current,vector<string> &result) {
		if(current == total) {
			result.push_back(string(temp));
			return;
		}
		for(int i = 0;i < total;i++) {
			if(use[i] != 1) {
				use[i] = 1;
				temp[current] = ok[i];
				getPermutaition(ok,temp,use,total,current+1,result);
				use[i] = 0;
			}
		}
	}
    vector<string> Permutation(string str) {
    	vector<string> result;
    	if(str.length() == 0) {
    		return result;
    	}
        char *ok = new char[str.length()+1];
        char *use = new char[str.length()];
        char *temp = new char[str.length()+1];
        memset(use,0,str.length());
        strcpy(ok,str.c_str());
        sort(ok,ok+str.length());
       
        getPermutaition(ok,temp,use,str.length(),0,result);
        delete []ok;
        delete []temp;
        delete []use;
        unordered_set<string> mymap;
        vector<string> final_result;
        for(const auto &s:result) {
			if(mymap.find(s) == mymap.end()) {
				final_result.push_back(s);
				mymap.insert(s);
			}
		}
        return final_result;
    }
};

int main() {
	Solution solution;
	vector<string> result = solution.Permutation("aa");
	for(const auto &s:result) {
		cout << s << endl;
	}
}