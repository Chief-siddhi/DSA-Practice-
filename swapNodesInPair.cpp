// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         // Create a dummy node before head
//         ListNode dummy(0);
//         dummy.next = head;
//         ListNode* prev = &dummy;

//         // Loop while there are at least two nodes ahead
//         while (head && head->next) {
//             ListNode* first = head;
//             ListNode* second = head->next;

//             // Swapping
//             prev->next = second;
//             first->next = second->next;
//             second->next = first;

//             // Move pointers ahead
//             prev = first;
//             head = first->next;
//         }

//         return dummy.next;
//     }
// };
