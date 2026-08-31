class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mn = INT_MAX;
        int first = -1, last = -1;
        int pos = 1;

        ListNode* prev = head;
        ListNode* cur = head->next;

        while (cur && cur->next) {
            ListNode* nxt = cur->next;

            if ((cur->val > prev->val && cur->val > nxt->val) ||
                (cur->val < prev->val && cur->val < nxt->val)) {

                if (first == -1) {
                    first = pos;
                } else {
                    mn = min(mn, pos - last);
                }

                last = pos;
            }

            prev = cur;
            cur = nxt;
            pos++;
        }

        if (first == -1 || first == last)
            return {-1, -1};

        return {mn, last - first};
    }
};