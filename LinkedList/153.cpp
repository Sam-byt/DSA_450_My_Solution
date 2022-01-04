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
    
// private:
//     int len(ListNode * p)
//     {
//         int c =0;
//         while(p)
//         {
//             c++;
//             p = p->next;
//         }
        
//         return c;
//     }
    
public:
    ListNode* middleNode(ListNode* head) {
//         int n = len(head)/2;
//         for(int i=0;i<n; i++)
//         {
//             head = head->next;
//         }
        
//         return head;
        
        ListNode * p = head;
        
        while(p && p->next)
        {
            head = head->next;
            p = p -> next -> next;
            
        }
        
        return head;
        
    }
};
