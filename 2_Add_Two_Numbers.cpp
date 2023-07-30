/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //careful with carry and unequal length of tow num
        //dont have leading zero
        //TC O(max(l1.len(), l2.len())), SC O(1)
        int carry = 0;
        ListNode* result = new ListNode(0);
        ListNode *temp = result;
        while(l1 && l2){
            temp->next = new ListNode((l1->val + l2->val + carry)%10);
            carry = (l1->val + l2->val + carry)/10;
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        //the last 2 while loop are to handle unequal length of 2 nums, only one would work for each iteration of the program
        while(l1){
            temp->next = new ListNode((l1->val+carry)%10);
            carry = (l1->val + carry)/10;
            temp = temp->next;
            l1 = l1->next;
        }

        while(l2){
            temp->next = new ListNode((l2->val+carry)%10);
            carry = (l2->val + carry)/10;
            temp = temp->next;
            l2 = l2->next;
        }

        //carry could be non-zero
        if(carry!= 0){
            temp->next = new ListNode(carry);
        }
        return result->next;
    }
};