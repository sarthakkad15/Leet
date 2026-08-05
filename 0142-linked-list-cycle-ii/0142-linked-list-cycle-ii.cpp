/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int> vis;
        while(head!=nullptr)
        {
            if(!vis[head])
                vis[head]=1;
            else
                return head;
            head=head->next;
        }
        return head;
    }
};