class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;

        ListNode* temp = head;

        while (temp != nullptr) {
            if (visited.find(temp) != visited.end()) {
                return true;
            }

            visited.insert(temp);
            temp = temp->next;
        }

        return false;
    }
};