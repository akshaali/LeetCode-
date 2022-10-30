using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        int size = num.size();
        if(size == 1) return -1;
        int i = size - 1;
        for(; i>0 && num[i]<=num[i-1]; i--){}
        // cout<<i<<endl;
        if(i == 0) return -1;
        sort(num.begin()+i, num.end());
        // cout<<"num: "<<num<<endl;
        for(int j = i; j<size; j++){
            if(num[i-1]<num[j]){
                swap(num[i-1], num[j]);
                break;
            }
        }
        // cout<<"num after: "<<num<<endl;
        auto res = stol(num);
        if(res == n || res > INT_MAX) return -1;
        return res;
    }
};