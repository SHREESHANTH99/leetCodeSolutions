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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;

        while(head) {
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* t1, ListNode* t2) {
        ListNode* l1=reverseList(t1);
        ListNode* l2=reverseList(t2);
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        int crry=0;
        while(l1!=nullptr || l2!=nullptr || crry!=0){
           int digit1 = (l1 != nullptr) ? l1->val : 0;
           int digit2 = (l2 != nullptr) ? l2->val : 0;
           int sum=digit1+digit2+crry;
           int digit=sum%10;
           crry=sum/10;
           ListNode* newN=new ListNode(digit);
           tail->next=newN;
           tail=tail->next;
           if(l1!=nullptr){
            l1=l1->next;
           }
           if(l2!=nullptr){
            l2=l2->next;
           }
        }
        ListNode* res=dummy->next;
           return reverseList(res);
           
    }
};
