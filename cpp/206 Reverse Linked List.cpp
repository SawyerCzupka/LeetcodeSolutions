#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
        {
            return head;
        }

        ListNode *last = nullptr;
        ListNode *next = head->next;

        // Base Case
        while (true)
        {
            head->next = last;

            // Update
            if (next)
            {
                last = head;
                head = next;
                next = head->next;
            }

            else
            {
                return head;
            }
        }
    }
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};