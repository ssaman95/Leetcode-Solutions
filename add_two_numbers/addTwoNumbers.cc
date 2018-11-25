/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

pair<int, int> get_sum_car(int x, int y, int car);

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int car = 0;
        ListNode *ans = nullptr, *cur = nullptr;
        
        while (l1 && l2) {
            auto sum_car_pair = get_sum_car(l1->val, l2->val, car);
            int sum = sum_car_pair.first;
            car = sum_car_pair.second;
            
            ListNode *tmp = new ListNode(sum);
            if (!ans) {
                ans = tmp;
                cur = ans;
            } else {
                cur->next = tmp;
                cur = cur->next;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1) {
            auto sum_car_pair = get_sum_car(l1->val, 0, car);
            int sum = sum_car_pair.first;
            car = sum_car_pair.second;
            
            ListNode *tmp = new ListNode(sum);
            cur->next = tmp;
            cur = cur->next;
            
            l1 = l1->next;
        }
        
        while (l2) {
            auto sum_car_pair = get_sum_car(0, l2->val, car);
            int sum = sum_car_pair.first;
            car = sum_car_pair.second;
            
            ListNode *tmp = new ListNode(sum);
            cur->next = tmp;
            cur = cur->next;
            
            l2 = l2->next;
        }
        
        if (car) {
            ListNode *tmp = new ListNode(car);
            cur->next = tmp;
            cur = cur->next;
        }
        
        return ans;
    }
};

pair<int, int> get_sum_car(int x, int y, int car) {
    int sum = x + y + car;
    car = sum / 10;
    sum %= 10;
    pair<int, int> result{sum, car};
    return result;
}
