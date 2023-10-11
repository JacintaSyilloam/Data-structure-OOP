// Jacinta Syilloam
// 5027221036

#include <iostream>

using namespace std;

// struct for linked list node
struct ListNode
{
    int val;
    ListNode *next;
    // constructor to initialize node with x value and no next node
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *addNum(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(0); // create dummy list
    ListNode *curr = dummy;            // initialize pointer
    int carry = 0;                     // initialize carry w 0 initially

    // loop until both input list empty and no carry left
    while (l1 != nullptr || l2 != nullptr || carry == 1)
    {
        int sum = 0; // initialize sum
        if (l1 != nullptr)
        {
            sum += l1->val; // add l1 to sum
            l1 = l1->next;  // move l1
        }
        if (l2 != nullptr)
        {
            sum += l2->val; // add l2 to sum
            l2 = l2->next;  // move l2
        }
        sum += carry;     // if previously have carry, add to sum
        carry = sum / 10; // divide by 10 to get carry
        ListNode *node = new ListNode(sum % 10); // new node of sum's last digit and attach to result
        curr->next = node; // update curr to new node
        curr = curr->next; 
    }
    return dummy->next;
}

// print result
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val; // print current node
        head = head->next; // move next node
    }
    cout << endl;
}

// delete linked list to prevent memory leaks
void cleanMem(ListNode *head)
{
    while (head)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    // testcase: 2+5= 7, 4+6=1(0) 3+4=7(+1=8)
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // call the addNum function to add the two linked lists
    ListNode *result = addNum(l1, l2);

    // print the result
    printList(result);

    // clean up memory to prevent memory leak
    cleanMem(l1);
    cleanMem(l2);
    cleanMem(result);

    return 0;
}
