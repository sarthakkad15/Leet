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
        ListNode *p1 = head;
        ListNode *p2 = head;
        ListNode *prev;
        while(p2!=nullptr)
        {
            prev=p1;
            p1=p1->next;
            p2=p2->next->next;
        }
        prev->next=nullptr;
        ListNode *head2 = p1;
        ListNode *prev2 = nullptr;
        ListNode *front;
        while(p1!=nullptr)
        {
            front=p1->next;
            p1->next=prev2;
            prev2=p1;
            p1=front;
        }
        head2=prev2;
        int sum = INT_MIN;
        while(head!=nullptr)
        {
            if(head->val + head2->val > sum)
                sum = head->val + head2->val;
            head = head->next;
            head2 = head2->next;
        }
        return sum;
    }
};