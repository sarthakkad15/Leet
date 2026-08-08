/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        Node* temp=head;
        Node* nextNode;
        while(temp!=nullptr)
        {
            nextNode=temp->next;
            Node* newNode = new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=nextNode;
        }
        temp=head;
        while(temp!=nullptr)
        {
            if(temp->random)
                temp->next->random=temp->random->next;
            else
                temp->next->random=nullptr;
            temp=temp->next->next;
        }
        temp=head;
        Node* head2=temp->next;
        Node* temp2=head2;
        while(temp!=nullptr)
        {
            temp->next=temp->next->next;
            temp=temp->next;
            if(!temp)
                return head2;
            temp2->next=temp2->next->next;
            temp2=temp2->next;
        }
        return head2;
    }
};