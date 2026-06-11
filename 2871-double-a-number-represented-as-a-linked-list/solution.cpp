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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        head=reverse(head);
        int crry=0;
        ListNode* p=head;
        while(p!=nullptr){
            int vall=p->val*2+crry;
            p->val=vall%10;
            crry=vall/10;
            p=p->next;
        }
        return crry ? new ListNode(crry, reverse(head)) : reverse(head);

    }
};
