/*
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
    struct cmp{
        bool operator() (ListNode *l1, ListNode *l2){
            return l1->val > l2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> listsPQ;
        for(auto node : lists){
            if(node != NULL)
                listsPQ.push(node);
        }
        ListNode dummyHead = ListNode(0);
        ListNode *end = &dummyHead;
        while(!listsPQ.empty()){
            auto presentNode = listsPQ.top();
            listsPQ.pop();
            end->next = presentNode;
            end = end->next;
            if(presentNode ->next != NULL)
                listsPQ.push(presentNode->next);
        }
        return dummyHead.next;
    }
};


//without priority queue: Using merge2

class Solution {
public:
    ListNode* mergeTwo(ListNode *l1, ListNode *l2){
        ListNode *newHead = NULL;
       if(!l2)
           return l1;
        if(!l1)
            return l2;
        if(l1->val < l2->val){
            newHead = l1;
            l1 = l1->next;
        }else{
            newHead = l2;
            l2 = l2->next;
        }
        ListNode *tempHead = newHead;
        while(l1 && l2){
            if(l1->val < l2->val){
                tempHead ->next = l1;
                tempHead = tempHead->next;
                l1 = l1->next;
            }else{
                tempHead->next = l2;
                tempHead = tempHead->next;
                l2 = l2->next;
            }
        }
        if(!l1)
            tempHead->next = l2;
        if(!l2)
            tempHead->next = l1;
        return newHead;
    }
    ListNode* mergeKLists(vector<ListNode *> lists, int size) {
        while(size != 0){
            int i = 0;
            int j = size;
            while(i < j){
                lists[i] = mergeTwo(lists[i], lists[j]);
                i++;
                j--;
                if(i >= j){
                    size = j;
                }
            }
        }
        return lists[0];
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        return mergeKLists(lists,lists.size()-1);
    }
};    