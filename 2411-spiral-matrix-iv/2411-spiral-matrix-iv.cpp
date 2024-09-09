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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m,vector<int>(n,-1)); // Fill matrix with -1's
        ListNode* temp=head;
        int r=0,c=0,rlim=m-1,clim=n-1;
        while(temp) {
            // Move right
            for(int i=r;i<=clim;i++) {
                if(!temp) goto End;
                mat[r][i]=temp->val;
                temp=temp->next;
            }
            r++; // The uppermost row has been visited
            // Move Down
            for(int i=r;i<=rlim;i++) {
                if(!temp) goto End;
                mat[i][clim]=temp->val;
                temp=temp->next;
            }
            clim--; // The rightmost column has been visited
            // Move Left
            for(int i=clim;i>=c;i--) {
                if(!temp) goto End;
                mat[rlim][i]=temp->val;
                temp=temp->next;
            }
            rlim--; // The lowermost row has been visited
            // Move Up
            for(int i=rlim;i>=r;i--) {
                if(!temp) goto End;
                mat[i][c]=temp->val;
                temp=temp->next;
            }
            c++; // The leftmost column has been visited
        }
        // Implementing labelled breaking using goto to move out of both loops at once
        End: return mat;
    }
};