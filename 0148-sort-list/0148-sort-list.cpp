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
    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        ListNode* tempNode=new ListNode(0);
        ListNode* temp=tempNode;
        while(list1!=nullptr && list2!=nullptr)
        {
            if(list1->val<list2->val)
            {
                temp->next=list1;
                list1=list1->next;
            }
            else
            {
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        if(list1!=nullptr)
            temp->next=list1;
        else
            temp->next=list2;
        return tempNode->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode* mid=head;
        ListNode* fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            mid=mid->next;
            fast=fast->next->next;
        }
        ListNode* right=mid->next;
        mid->next=nullptr;
        ListNode* left=head;
        left=sortList(left);
        right=sortList(right);
        return merge(left,right);
    }
};