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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallHead = nullptr;
        ListNode* smallTail = nullptr;//小于区域 
        ListNode* equalHead = nullptr;
        ListNode* equalTail = nullptr;//等于区域 
        ListNode* largeHead = nullptr;
        ListNode* largeTail = nullptr;//大于区域 
        ListNode* next = nullptr;//记录当前节点下一位置 
        while(head){
            next = head->next;
            head->next = nullptr;//断开当前节点之后 
            if(head->val < x){
                if(smallHead == nullptr){
                    smallHead = head;
                    smallTail = head;
                }
                else{
                    smallTail->next = head;
                    smallTail = smallTail->next;
                }
            }
            else if(head->val == x){
                if(equalHead == nullptr){
                    equalHead = head;
                    equalTail = head;
                }
                else{
                    equalTail->next = head;
                    equalTail = equalTail->next;
                }
            }
            else{
                if(largeHead == nullptr){
                    largeHead = head;
                    largeTail = head;
                }
                else{
                    largeTail->next = head;
                    largeTail = largeTail->next;
                }
            }
            head = next;
        }
        if(smallHead){
            smallTail->next = equalHead;
            equalTail = equalTail == nullptr ? smallTail : equalTail;
        }//如果小于区存在，决定与大于区相连的是sT还是eT 
        if(equalTail){
            equalTail->next = largeHead;
        }//如果等于区存在，与大于区相连 
        return smallHead != nullptr ? smallHead : (equalHead != nullptr ? equalHead : largeHead);
    }
};
