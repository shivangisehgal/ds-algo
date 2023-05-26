//BRUTE
//Use a DS, check if palindrome
//TC: O(N)
//SC: O(N)

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        vector<int> nums;
        
        while(head != NULL) 
        {
            nums.push_back(head->val);
            head = head->next;
        }
        
        int n = nums.size();
        
        for(int i = 0; i < n / 2; i++) 
        {
            if(nums[i] != nums[n - i - 1]) 
                return false;
        }
        
        return true;
    }
};

//OPTIMAL
//Find middle of ll, reverse the ll from the next element. compare the two sublists
//TC: O(N)
//SC: O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        ListNode* fast = head;
        ListNode* slow = fast;
        
        //middle element of LL (first middle in case of even list)
        while (fast->next and fast->next->next) 
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //reverse from next of middle element (or reverse from second middle in case of even)
        ListNode* curr = slow->next;
        ListNode* prev = NULL;
        ListNode* n;
        
        while(curr != NULL)
        {
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        
        //compare values
        ListNode* firstStart = head;
        ListNode* secondStart = prev;
        
        while(secondStart != NULL)
        {
            if(firstStart->val != secondStart->val)
                return false;
            
            firstStart = firstStart->next;
            secondStart = secondStart->next;
        }
        
        return true;
             
    }
};
