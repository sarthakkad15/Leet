/**
 * Definition for singly-linked list.
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
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=nullptr;
        ListNode* head2;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast==nullptr)
        {
            head2=slow;
            prev->next=nullptr;
        }
        else
        {
            head2=slow->next;
            slow->next=nullptr;
        }
        prev=nullptr;
        ListNode* curr=head2;
        while(head2!=nullptr)
        {
            head2=head2->next;
            curr->next=prev;
            prev=curr;
            curr=head2;
        }
        while(prev!=nullptr)
        {
            if(head->val!=prev->val)
                return false;
            head=head->next;
            prev=prev->next;
        }
        return true;
    }
};