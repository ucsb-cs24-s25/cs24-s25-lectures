// reverse.cpp
// Solution to Leet Code Problem to reverse a singly linked list:
// https://leetcode.com/problems/reverse-linked-list/description/
 /* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next){
            return head;
        }
        ListNode* prev = nullptr, *curr = head, * next = head->next;
        while(curr){
            curr->next = prev;
            prev = curr;
            curr = next;
            if(next)
                next = next->next;
        }
        return prev;

        
    }
};