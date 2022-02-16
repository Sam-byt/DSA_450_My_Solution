/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    bool isLoop(ListNode * &p)
    {
        ListNode *q = p;
        
        do{
            q = q->next;
            p = p->next;
            
            if(p)p = p->next;
            
        }while(p && p!=q);
        
        return p!=nullptr;
    }
    
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(!head)return nullptr;
        ListNode *p = head;
        if(!isLoop(p))return nullptr;
        else{
            
            int len =0;
            ListNode *q = p;
            
            do{
                p = p->next;
                len++;
                
            }while(q != p);
            
            q = head;
            
            while(len--)q = q->next;
            
            while(head!=q)
            {
                q = q->next;
                head = head->next;
            }
            
            return head;
            
            
            
        }
        
        
        
    }
};
