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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=l1->val+l2->val;
        int c=sum/10;
        sum=sum%10;
        ListNode* l3 = new ListNode(sum);
        ListNode* temp = l3;
        l1=l1->next;l2=l2->next;
        while(l1!=nullptr && l2!=nullptr)
        {
            temp->next = new ListNode();
            temp=temp->next;
            sum = l1->val + l2->val + c;
            c=sum/10;
            sum=sum%10;
            temp->val = sum;
            l1=l1->next;
            l2=l2->next;
        }
        ListNode* temp2;
        if(l1!=nullptr)
            temp2=l1;
        else
            temp2=l2;
        while(temp2!=nullptr)
        {
            temp->next = new ListNode();
            temp=temp->next;
            sum = temp2->val + c;
            c=sum/10;
            sum=sum%10;
            temp->val = sum;
            temp2=temp2->next;
        } 
        if(c>0)
        {
            temp->next = new ListNode(c);
        }  
        return l3;
    }
};