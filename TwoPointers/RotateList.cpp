#include<iostream>
using namespace std;

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
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) return NULL;

        int len = 0;
        ListNode *ptr1 = head, *ptr2 = head, *tail = head;
        while (ptr1 != NULL)
        {
            ++len;
            tail = ptr1;
            ptr1 = ptr1->next;
        }

        k = k%len;
        if (k == 0) return head; //Note: no need to rotate

        ptr1 = nthNodeFromEnd(head, k+1);
        ptr2 = nthNodeFromEnd(head, k);

        ptr1->next = NULL;
        tail->next = head;
        head = ptr2;

        return head;
    }

    ListNode *rotateRight2(ListNode *head, int k) {
        if (head == NULL) return NULL;

        int len = 0;
        ListNode *ptr1 = head, *ptr2 = head;
        while (ptr1 != NULL)
        {
            ++len;
            ptr1 = ptr1->next;
        }

        k = k%len;

        ptr1 = nthNodeFromEnd(head, k+1);
        ptr2 = nthNodeFromEnd(head, k);

        //partition list and rotate: ABCDEF rotate right 2 => reverse(reverse(ABCD),reverse(EF))
        ListNode *tp = ptr1->next;
        ptr1->next = NULL;
        ptr1 = head;
        head = reverseList(head); // now ptr1 points to the end
        ptr2 = reverseList(ptr2);
        ptr1->next = ptr2;
        head = reverseList(head);

        return head;
    }

    ListNode *nthNodeFromEnd(ListNode *head, int k) {
        ListNode *ptr2 = head;
        for (int i = 0; i < k; i++)
        {
            ptr2 = ptr2->next;
        }
        ListNode *ptr1 = head;
        while (ptr2 != NULL)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return ptr1;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode tmp(-1);
        tmp.next = head;
        ListNode *curPtr=head, *prevPtr=&tmp;
        while (curPtr != NULL)
        {
            if (curPtr != tmp.next)
            {
                prevPtr->next = curPtr->next;
                curPtr->next = tmp.next;
                tmp.next = curPtr;
                curPtr = prevPtr->next;
            }
            else
            {
                prevPtr = curPtr;
                curPtr = curPtr->next;
            }
        }
        head = tmp.next;
        
        return head;
    }

    static void visit(ListNode *head)
    {
        while (head != NULL)
        {
            cout<<head->val<<",";
            head = head->next;
        }
        cout<<endl;
    }

    static void test()
    {
        int n, k, x;
        ListNode *head = NULL, *tail = NULL;
        cin>>n>>k;
        for (int i = 0; i < n; i++)
        {
            cin>>x;
            ListNode *np = new ListNode(x);
            if (i == 0)
            {
                head = np;
                tail = np;
            }
            else
            {
                tail->next = np;
                tail = np;
            }
        }

        Solution sol;
        cout<<"result=";
        head = sol.rotateRight(head, k);
        visit(head);
    }
};