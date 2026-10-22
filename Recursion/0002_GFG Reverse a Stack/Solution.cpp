#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void insertStack(stack<int> &st, int value)
{

    if (st.empty())
    {
        st.push(value);
        return;
    }

    if (!st.empty())
    {
        int t = st.top(); 
        st.pop();
        insertStack(st, value);
        st.push(t);
    }
}

void reverseStack(stack<int> &st)
{

    int n = st.size();

    if (n <= 1)
        return;

    int stkTop = st.top();
    st.pop();

    reverseStack(st);

    insertStack(st, stkTop);
}

int main()
{
    stack<int> st;
    st.push(11);
    st.push(2);
    st.push(32);
    st.push(3);
    st.push(41);
    reverseStack(st);

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}