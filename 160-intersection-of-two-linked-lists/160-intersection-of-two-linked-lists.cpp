/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/*
we will take two dummy nodes one pointing to headA and other to headB and then move both the dummy node simultaneously and if any node becomes NULL (usually after last node) immidiatly shift it to the head of other list (is initiated at headA then point it to headB and vice versa). So, this method will make both dummy nodes move together at some point and when both the dummy nodes becomes same, return that node. 
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        ListNode *d1,*d2;
        d1 = headA;
        d2 = headB;
        while(d1!=NULL || d2!=NULL){
            if(d1 == NULL) d1 = headB;
            if(d2 == NULL) d2 = headA;
            if(d1 == d2) return d1;
            d1 = d1 -> next;
            d2 = d2 -> next;
        }
        return NULL;
    }
};