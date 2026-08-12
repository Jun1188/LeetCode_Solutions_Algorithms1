#include <iostream>
#include <array>




//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Definition for class:
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

*/


ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
	int sum = 0, carry = 0;
	ListNode* iterator = new ListNode{ };

	ListNode* head = iterator;
	ListNode* tail = iterator;
	std::array<bool, 3> isptr{ static_cast<bool>(l1), static_cast<bool>(l2), static_cast<bool>(l1 or l2) };

	while (isptr[2]) {
		iterator->next = new ListNode{ };
		iterator = iterator->next;
		
		

		if (isptr[0]) {
			sum += l1->val;
			isptr[0] = l1 = l1->next;
		}
		if (isptr[1]) {
			sum += l2->val;
			isptr[1] = l2 = l2->next;
		}

		isptr[2] = isptr[0] or isptr[1];

		iterator->val = sum - (sum / 10)*10;
		sum = carry = sum / 10;
		
	}

	ListNode* del = head;
	head = head->next;
	delete del;

	if (carry)
		iterator->next = new ListNode{ carry };

	return head;
}


