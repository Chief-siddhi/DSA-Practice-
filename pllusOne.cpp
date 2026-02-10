// #include <vector>
// using namespace std;

// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
//         int n = digits.size();
//         for (int i = n - 1; i >= 0; i--) {
//             if (digits[i] < 9) {
//                 digits[i]++;
//                 return digits; // no carry, done
//             }
//             digits[i] = 0; // set to 0 and carry over
//         }
//         // if we reach here, all were 9
//         digits.insert(digits.begin(), 1);
//         return digits;
//     }
// };
