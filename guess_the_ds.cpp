#include <bits/stdc++.h>
using namespace std;

int main()
{

    int i, j, a, b;

    int t, n;

    while (~scanf("%d", &n))
    {
        a = 1, b = 1;
        int c = 1;
        stack<int> st;
        queue<int> q;
        priority_queue<int> pq;
        int y, z;

        for (int i = 0; i < n; ++i)
        {
            scanf("%d %d", &y, &z);
            if (y == 1)
            {
                q.push(z);
                st.push(z);
                pq.push(z);
            }
            else if (y == 2)
            {
                int x;
                if (!q.empty())
                {
                    x = q.front();
                    q.pop();
                    if (x != z)
                        a = 0;
                }
                else
                    a = 0;
                if (!st.empty())
                {
                    x = st.top();
                    if (x != z)
                        b = 0;
                    st.pop();
                }
                else
                    b = 0;
                if (!pq.empty())
                {
                    x = pq.top();
                    if (x != z)
                        c = 0;
                    pq.pop();
                }
                else
                    c = 0;
            }
        }
        j = c + b + a;
        if (j > 1)
            cout << "not sure\n";
        else if (a)
            cout << "queue\n";
        else if (b)
            cout << "stack\n";
        else if (c)
            cout << "priority queue\n";
        else
            cout << "impossible\n";
    }
    return 0;
}