
class Solution {
public:
    int lastRemaining(int n) {
        bool left = true;
        int remaining = n;
        int step = 1;
        int head = 1;
        while (remaining > 1) {
            if (left || remaining % 2 ==1) {
                head = head + step;
            }
            remaining = remaining / 2;
            step = step * 2;
            left = !left;
        }
        return head;
    }
};











// TLE
// class Solution {
// public:
//     int lastRemaining(int n) {
//         if(n == 1) return n;
//         vector<int> arr;
//         for(int i=1; i<=n; i++) arr.push_back(i);
//         return recursive(arr, true);
        
//     }
//     int recursive(vector<int> arr, bool begin){
//         int n = arr.size();
//         if(n == 1) return arr[0];
//         vector<int> inter(n/2);
//         if(begin){
//              for(int i = 0; i<n-1; i+=2){
//                 inter[i/2] = arr[i+1];
//              }
//         }else{
//             for(int i = n-1; i>0; i-=2){
//                  inter[(i-1)/2] = arr[i-1];
//              }
//         }
//         return recursive(inter, !begin);
//     }
// };