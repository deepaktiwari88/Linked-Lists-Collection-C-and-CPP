//head contain the head of the linked list

bool isPalindrome(Node *head)
{
    stack<int> s;
    
    Node* temp = head;
    
    while(temp)
    {
        s.push(temp->data);
        temp = temp->next;
    }
    
    temp=head;
    
    while(!s.empty())
    {
        if(s.top()!=temp->data)
            return false;
            
        s.pop();
        temp=temp->next;
    }
    
    return s.empty();
}
