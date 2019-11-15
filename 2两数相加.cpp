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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        ListNode* head = NULL;
        ListNode* end = NULL;
        if(l1 == NULL && l2 == NULL)
            return NULL;
        while(l1 != NULL || l2 != NULL){
            int cnt = 0;
            if(l1 == NULL){
                cnt = l2->val + flag;
                flag = cnt/10;
                cnt = cnt%10;
                l2 = l2->next;
            }
            else if(l2 == NULL){
                cnt = l1->val + flag;
                flag = cnt/10;
                cnt = cnt%10;
                l1 = l1->next;
                
            }
            else{
                cnt = l1->val + l2->val +flag;
                flag = cnt/10;
                cnt = cnt %10;
                l1 = l1->next;
                l2 = l2->next;
            }
            if(head == NULL){
                head = new ListNode(cnt);
                end = head;
            }
            else{
                ListNode* tmp = new ListNode(cnt);
                end->next = tmp;
                end = tmp;
            }
        }
        if(flag){
            ListNode* tmp = new ListNode(flag);
            end->next = tmp;
            end = tmp;
        }
        end->next = NULL;
        return head;
    }
};
/**
    链表是从低位到高位的
    
*/