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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* end;
        if(l1 && !l2)
            return l1;
        if(!l1 && l2)
            return l2;
        if(!l1 && !l2)
            return NULL;
        if(l1->val < l2->val){
            head = l1;
            end = l1;
            l1 = l1->next;
        }
        else{
            end = l2;
            head = l2;
            l2 = l2->next;
        }
        while(l1 && l2){
            //cout<<"AAA"<<endl;
            if(l1->val < l2->val){
                end->next = l1;
                end = end->next;
                l1 = l1->next;
            }
            else{
                end->next = l2;
                end = end->next;
                l2 = l2->next;
            }
        }
        if(l1)
            end->next = l1;
        if(l2)
            end->next = l2;
        return head;
    }
};