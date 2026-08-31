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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp=head->next;
        int prev=head->val,nex,i=1,minD=INT_MAX;
        vector<int> critical;
        if(temp->next==nullptr || temp->next->next==nullptr)
            return {-1,-1};
        while(temp->next!=nullptr)
        {
            nex=temp->next->val;
            if((temp->val>prev && temp->val>nex) || (temp->val<prev && temp->val<nex))
            {
                if(!critical.empty() && (i-critical.back())<minD)
                    minD=i-critical.back();
                critical.push_back(i);
            }
            prev=temp->val;
            temp=temp->next;
            i++;
        }
        int n=critical.size();
        if(n<2)
            return {-1,-1};
        else
            return {minD,critical[n-1]-critical[0]};
    }
};