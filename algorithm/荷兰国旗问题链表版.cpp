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
        ListNode* smallTail = nullptr;//С������ 
        ListNode* equalHead = nullptr;
        ListNode* equalTail = nullptr;//�������� 
        ListNode* largeHead = nullptr;
        ListNode* largeTail = nullptr;//�������� 
        ListNode* next = nullptr;//��¼��ǰ�ڵ���һλ�� 
        while(head){
            next = head->next;
            head->next = nullptr;//�Ͽ���ǰ�ڵ�֮�� 
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
        }//���С�������ڣ��������������������sT����eT 
        if(equalTail){
            equalTail->next = largeHead;
        }//������������ڣ������������ 
        return smallHead != nullptr ? smallHead : (equalHead != nullptr ? equalHead : largeHead);
    }
};
