#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, i, j;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        long long sum = 0;
        int c = 0, d = 0;
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                c = 1;
                if (d)
                    d--;
            }
            if (s[i] == '1' && c)
            {
                sum += (10 * (i + 1) - d * 10);
                d++;
            }
            else if (s[i] == '1' && c == 0)
            {
                sum += 10;
                d++;
            }
        }
        cout << sum << endl;
    }
}