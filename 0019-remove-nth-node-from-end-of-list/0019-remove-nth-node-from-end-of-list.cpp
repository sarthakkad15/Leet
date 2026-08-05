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
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(head!=nullptr)
        {
            head=head->next;
            curr->next=prev;
            prev=curr;
            curr=head;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head=reverse(head);
        int i=1;
        ListNode* temp=head;
        if(n==1)
            head=head->next;
        else
        {
            while(i<n-1)
            {
                temp=temp->next;
                i++;
            }
            temp->next=temp->next->next;
        }
        head=reverse(head);
        return head;
    }
};