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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        ListNode* pre = NULL;
        while(n--){
            p1 = p1 ->next;
        }
        while(p1){
            p1 = p1->next;
            pre = p2;
            p2= p2->next;
        }
        if(p2 == head){
            head = p2->next;
        }
        else{
            pre->next = p2->next;
        }
        return head;
    }
};
/**
   ˫ָ�� + ׷�Ϸ�
   
   �ر��ж�  ���ɾ������ͷ���   ��ôhead Ҫ��һ��
*/