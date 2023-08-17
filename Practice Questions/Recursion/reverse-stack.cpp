
void insertAtBottom(stack<int>& s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }

    int top = s.top();
    s.pop();

    insertAtBottom(s, x);

    s.push(top);
}

void helper(stack<int>& s)
{
    if(s.empty())
        return;

    int top = s.top();
    s.pop();

    helper(s);
    insertAtBottom(s, top);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    helper(stack);
}
