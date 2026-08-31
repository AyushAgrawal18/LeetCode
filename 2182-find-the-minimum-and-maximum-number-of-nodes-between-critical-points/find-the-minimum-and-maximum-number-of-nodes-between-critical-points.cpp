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
        ListNode* check=head;
        int count=0;
        while(check !=NULL){
            count++;
            check=check->next;
        }
        if(count<=2) return {-1,-1};
        vector<int> ans;
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* front= head->next->next;
        count=1;
        while(front!=NULL){
            count++;
            if((curr->val>prev->val && curr->val>front->val) || (curr->val<prev->val && curr->val<front->val)){
                ans.push_back(count);
            }
            prev=curr;
            curr=front;
            front=front->next;
        }
        if(ans.size()<2){
            return {-1, -1};
        }
        // int mini=INT_MAX,maxi=INT_MIN;
        // for(int i=0;i<ans.size();i++){
        //     mini=min({mini,ans[i],count-ans[i]});
        // }
        // maxi=count;
        // return {mini, maxi};
        int maxi=ans[ans.size()-1]-ans[0];
        int mini=INT_MAX;
        for(int i=0;i<ans.size()-1;i++){
            mini=min(mini,ans[i+1]-ans[i]);
        }
        return {mini,maxi};
    }
};