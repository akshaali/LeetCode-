class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int j = 0;
        int i = 0;
        int index = -1;
        while(i<n && j<m){
            if(haystack[i] == needle[j]){
                index = i;
                cout<<"index: "<<index<<endl;
                while(j<m && i<n){
                    if(haystack[i] == needle[j]){
                        i++;
                        j++;
                    }else{
                        i = index;
                        index = -1;
                        j = 0;
                        break;
                    }
                }
                
            }else{
                j = 0;
                index = -1;
            }
            i++;
        }
        return j<m ? -1 : index;
    }
};