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
        if(head == NULL || (head->next == NULL && n == 1)){
            return NULL;
        }
        ListNode *move = head;
        ListNode *front = head;
        int count = 1;
        while(move->next != NULL){
            count++;
            move = move->next;
        }
        if(count < n)
            return head;
        int toRemove = count - n;
        if(toRemove == 0)
            return head->next;
        while(--toRemove){
            front = front->next;
        }
        front->next = front->next->next;
        return head;
    }
};