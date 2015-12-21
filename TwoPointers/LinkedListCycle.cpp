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
        ListNode(int x): val(x), next(NULL) {}
    };

public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;

        ListNode *p1 = head;
        ListNode *p2 = head;
        do
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }while(p1 != p2 && p1!=NULL && p2!=NULL && p2->next!=NULL);

        if (p1 == p2 && p1!=NULL && p2!=NULL)
            return true;
        else
            return false;
    }

    static void test()
    {
        int n, x;
        ListNode *head = NULL, *p = NULL;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            cin>>x;
            ListNode *np = new ListNode(x);
            if (i == 0)
            {
                p = np;
                head = p;
            }
            else
            {
                ListNode *tp = head;
                p = tp;
                while (tp != NULL)
                {
                    if (tp->val == x)
                        break;
                    p = tp;
                    tp = tp->next;
                }
                if (tp != NULL)
                {
                    p->next = tp;
                    p = tp;
                }
                else
                {
                    p->next = np;
                    p = np;
                }
            }
        }

        Solution sol;
        cout<<"result="<<sol.hasCycle(head)<<endl;
    }
};