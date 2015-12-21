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

    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL) return NULL;
        ListNode *ptr = head, *ptr2 = head, *ptrToRemove = head;
        int i = 0;
        while (ptr!=NULL)
        {
            ptr = ptr->next;
            ++i;
            if (i > n)
            {
                ptr2 = ptrToRemove;
                ptrToRemove = ptrToRemove->next;
            }
        }
        if (ptrToRemove == head)
        {
            head = head->next;
        }
        else
        {
            ptr2->next = ptrToRemove->next;
        }

        return head;
    }

    static void test() {
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
        cout<<"result="<<(sol.removeNthFromEnd(head, k)->val)<<endl;
    }
};