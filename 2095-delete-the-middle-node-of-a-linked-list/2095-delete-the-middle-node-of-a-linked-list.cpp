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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp1=head;
        ListNode* temp2=head;
        ListNode* prev;
        if(temp1->next==nullptr)
            return nullptr;
        while(temp2!=nullptr && temp2->next!=nullptr)
        {
            prev=temp1;
            temp1=temp1->next;
            temp2=temp2->next->next;
        }
        prev->next=temp1->next;
        delete temp1;
        return head;
    }
};