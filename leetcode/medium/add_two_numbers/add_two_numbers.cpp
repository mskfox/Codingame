/**
 * @brief Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *head = new ListNode();
		ListNode *cur = head;

		int carry = 0;
		while (l1 || l2 || carry) {
			int x = l1 ? l1->val : 0;
			int y = l2 ? l2->val : 0;

			int sum = carry + x + y;
			carry = sum / 10;

			cur->next = new ListNode(sum % 10);
			cur = cur->next;

			l1 = l1 ? l1->next : nullptr;
			l2 = l2 ? l2->next : nullptr;
		}

		return head->next;
	}
};
