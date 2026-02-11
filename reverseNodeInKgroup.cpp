// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode* temp = head;
//         int cnt = 0;
        
//         // Check if k nodes exist
//         while (cnt < k) {
//             if (temp == nullptr) {
//                 return head;
//             }
//             temp = temp->next;
//             cnt++;
//         }

//         // Recursively reverse the rest of the list
//         ListNode* prevNode = reverseKGroup(temp, k);

//         // Reverse current group
//         temp = head;
//         cnt = 0;
//         while (cnt < k) {
//             ListNode* next = temp->next;
//             temp->next = prevNode;
//             prevNode = temp;  // Fix: assign temp to prevNode
//             temp = next;
//             cnt++;
//         }

//         return prevNode;
//     }
// };
