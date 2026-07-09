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
    int pairSum(ListNode* head) {
        stack<int> s;
        int c=0,sum=0;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            s.push(temp->val);
            c++;
            temp=temp->next;
        }
        temp=head;
        for(int i=0;i<c/2;i++)
        {
            sum=max(sum,s.top()+temp->val);
            temp=temp->next;
            s.pop();
        }
        return sum;
    }
};