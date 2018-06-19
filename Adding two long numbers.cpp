void calculateSum(int a, int b, int &carry, Node** head, Node** prev)
{
    int res = a+b+carry;
        
    Node* temp = new Node;
    temp->data = res%10;
    temp->next = NULL;
    
    if((*head)==NULL)
        *head = temp;
    else
        (*prev)->next = temp;
        
    *prev = temp;
        
    carry = res/10;
}

//first represent head of first number
//second represent head of second number

Node* addTwoLists(Node* first, Node* second){
  
    int carry=0;
    Node *head = NULL, *prev=NULL;
    
    while(first && second)
    {
        calculateSum(first->data, second->data, carry, &head, &prev);
        
        first = first->next;
        second = second->next;
    }
    
    while(first)
    {
        calculateSum(first->data, 0, carry, &head, &prev);
        first = first->next;
    }
    
    while(second)
    {
        calculateSum(0, second->data, carry, &head, &prev);
        second = second->next;
    }
    
    if(carry)
    {
        calculateSum(0, 0, carry, &head, &prev);
    }
    
    return head;
}
