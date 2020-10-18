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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(0,head);//添加哑节点（dummy node）
        int len=getlength(head);
        ListNode* cur=dummy;
        for(int i=1;i<len-n+1;i++){
            cur=cur->next;
        }
        cur->next=cur->next->next;
        ListNode* t=dummy->next;
        delete dummy;
        return t;
    }   

    int getlength(ListNode* head){
        int count=0;//记录链表长度
        while(head){
            count++;
            head=head->next;
        }   
        return count;
    }     
};
