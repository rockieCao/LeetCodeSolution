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
/* Test cases:
{0},1 -> {0}
{1,1},2 -> {1,1}
{1,4,3,2,5,2},3 -> {1,2,2,4,3,5}
*/
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) return NULL;
        ListNode tmpNode(x-1);
        tmpNode.next = head;
        ListNode *curPtr = head, *prevPtr = &tmpNode, *tp = &tmpNode;

        while (curPtr != NULL)
        {
            if (curPtr->val < x) {
                if (curPtr == tp->next) { // note: boundary condition
                    prevPtr = curPtr;
                    curPtr = curPtr->next;
                }
                else {
                    ListNode *tmpPtr = curPtr->next;
                    curPtr->next = tp->next;
                    tp->next = curPtr;
                    prevPtr->next = tmpPtr;
                    curPtr = tmpPtr;
                }
                tp=tp->next;
            }
            else {
                prevPtr = curPtr;
                curPtr = curPtr->next;
            }
        }
        head = tmpNode.next;
        
        return head;
    }

    static void visit(ListNode *head) {
        while (head != NULL)
        {
            cout<<head->val<<",";
            head = head->next;
        }
        cout<<endl;
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
        cout<<"result=";
        visit(sol.partition(head, k));
    }
};