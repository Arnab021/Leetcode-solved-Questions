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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> arr;
        ListNode *temp = head;
        int prev = temp->val;
        temp = temp->next;
        int idx = 2;

        while (temp->next != nullptr) {
            int curr = temp->val;
            int nxt = temp->next->val;
            if ((prev < curr && curr > nxt) || (prev > curr && curr < nxt)) {
                arr.push_back(idx);
            }
            prev = curr; 
            temp = temp->next;
            idx++;
        }

        int n = arr.size();
        int mind = INT_MAX;

        if(n < 2)  return {-1, -1};

        for(int i=0; i<n-1; i++){
            int diff = arr[i+1] - arr[i];
            if(diff < mind) mind = diff;
        }

        return {mind, arr[n-1]-arr[0]};
    }
};