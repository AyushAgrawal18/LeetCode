class Solution {
public:
    string numberToWords(int n) {
        if (n == 0) return "Zero";
        map<int, string> m;
        m[1] = "One";
        m[2] = "Two";
        m[3] = "Three";
        m[4] = "Four";
        m[5] = "Five";
        m[6] = "Six";
        m[7] = "Seven";
        m[8] = "Eight";
        m[9] = "Nine";
        m[10] = "Ten";
        m[11] = "Eleven";
        m[12] = "Twelve";
        m[13] = "Thirteen";
        m[14] = "Fourteen";
        m[15] = "Fifteen";
        m[16] = "Sixteen";
        m[17] = "Seventeen";
        m[18] = "Eighteen";
        m[19] = "Nineteen";
        m[20] = "Twenty";
        m[30] = "Thirty";
        m[40] = "Forty";
        m[50] = "Fifty";
        m[60] = "Sixty";
        m[70] = "Seventy";
        m[80] = "Eighty";
        m[90] = "Ninety";

        vector<int> a;
        int cnt = 0;
        int sum = 0;
        int place = 1;

        while (n > 0) {
            int last = n % 10;
            n /= 10;
            sum += last * place;
            cnt++;
            place *= 10;
            if (cnt == 3) {
                a.push_back(sum);
                sum = 0;
                cnt = 0;
                place = 1;
            }
        }
        if (cnt > 0) a.push_back(sum);
        reverse(a.begin(),a.end());
        string ans;
        
        for (int i=0;i<a.size();i++) {
            int x = a[i];

            int hundred=x/100;
            int rem=x%100;

            if (hundred > 0) {
                // cout << m[hundred] << " Hundred ";
                ans+=(m[hundred]);
                ans+=(" Hundred ");
            }

            if (rem > 0) {
                if (rem < 20) {
                    // cout << m[rem] << " ";
                    ans+=(m[rem]);
                    ans+=(" ");
                }
                else {
                    int tens = (rem / 10) * 10;
                    int ones = rem % 10;

                    // cout << m[tens] << " ";
                    ans+=(m[tens]);
                    ans+=(" ");

                    if (ones > 0){
                        // cout << m[ones] << " ";
                        ans+=(m[ones]);
                        ans+=(" ");
                    }
                }
            }

            if (a.size()-i==2 && a[i]!=0)
                // cout << "Thousand ";
                    ans+=("Thousand ");

            if (a.size()-i==3&&a[i]!=0)
                ans+=("Million ");
            
            if (a.size()-i==4&&a[i]!=0)
                ans+=("Billion ");
        }
        if (!ans.empty() && ans.back() == ' ')
        ans.pop_back();
        return ans;
    }
};