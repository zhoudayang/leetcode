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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) :
        head_(head)
    {
        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode * node = head_->next;
        ListNode * temp = head_;
        int count = 1;
        while(node){
            if(rand()%(++count)==0){
                temp =node;
            }
            node = node->next;
        }
        return temp->val;
    }
private:
    ListNode * head_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */