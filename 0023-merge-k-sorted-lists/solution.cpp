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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newHead=new ListNode(0);
        ListNode* head1=list1;
        ListNode* head2=list2;
        ListNode* temp=newHead;
        while(head1!=nullptr && head2!=nullptr){
            if(head1->val<=head2->val){
                temp->next=head1;
                temp=head1;
                head1=head1->next;
            }else{
                temp->next=head2;
                temp=head2;
                head2=head2->next;
            }
        }
        if(head1) temp->next=head1;
        else temp->next=head2;
        return newHead->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        ListNode* head=lists[0];
        for(int i=1;i<lists.size();i++){
            head=mergeTwoLists(head,lists[i]);
        }
        return head;
    }
};
