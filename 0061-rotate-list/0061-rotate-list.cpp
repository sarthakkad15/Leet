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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode* temp=head;
        ListNode* prev;
        int n=1;
        while(temp->next!=nullptr)
        {
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k==0)
            return head;
        temp->next=head;
        prev=temp;
        temp=temp->next;
        for(int i=0;i<n-k;i++)
        {
            prev=temp;
            temp=temp->next;
        }
        head=temp;
        prev->next=nullptr;
        return head;
        
    }
};