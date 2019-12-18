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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        int tmp = head->val;
        ListNode* pre = head;
        ListNode* p = head->next;
        while(p){
           //cout<<p->val<<"  "<<tmp<<endl;
            if(p->val == tmp){
                //cout<<"AAA"<<endl;
                ;
            }
            else{
                pre->next = p;
                pre = pre->next;
                tmp = p->val;
            }
            p = p->next;
        }
        pre->next = NULL; //这里不能错
        return head;
    }
};