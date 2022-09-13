using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size()-1;
	// int start=0, end=s.length()-1;
        cout<<isalnum('0')<<endl;
	while(start<end) {
		if (!isalnum(s[start])){ 
            cout<<"Value: "<<s[start]<<" "<<s[end]<<endl;
            start++;
                                }
		else if (!isalnum(s[end])) end--;
		else {
			if (tolower(s[start++])!=tolower(s[end--])) return false;
		}
	}
        // while(start<end){
        //     //  if(tolower(s[start])>= 'a' && tolower(s[start]) <= 'z' && tolower(s[end])>='a' && tolower(s[end]) <= 'z' ){
        //     //     if(tolower(s[start++]) != tolower(s[end--])){
        //     //         return false;
        //     //     }
        //     // }
        //      if(!(tolower(s[end])>='a' && tolower(s[end]) <= 'z')){
        //         end--;
        //     }
        //     else if(!(tolower(s[start])>= 'a' && tolower(s[start]) <= 'z')){
        //         cout<<"Value: "<<s[start]<<" "<<s[end];
        //         start++;
        //         cout<<"Value: "<<s[start]<<" "<<s[end];
        //     }else{
        //         if(tolower(s[start++]) != tolower(s[end--])){
        //             return false;
        //         }
        //     }
        // }
        return true;
    }
};