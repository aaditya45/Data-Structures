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
    ListNode* partition(ListNode* head, int x) {
        queue<ListNode*> less;
        queue<ListNode*> more;
        ListNode*ptr=head;
        while(ptr!=NULL){
            if(ptr->val>=x){
                more.push(ptr);
            }else{
                less.push(ptr);
            }
            ptr=ptr->next;
        }
        ListNode *dm=new ListNode(0);
        ListNode *res=dm;
        while(!less.empty()){
            ptr=less.front();
            less.pop();
            dm->next=ptr;
            dm=ptr;
        }
        while(!more.empty()){
            ptr=more.front();
            more.pop();
            dm->next=ptr;
            dm=ptr;
        }
        dm->next=NULL;
        return res->next;
        
    }
};