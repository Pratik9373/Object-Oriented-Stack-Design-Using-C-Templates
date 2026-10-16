#include<iostream>
using namespace std;

#define MAX_SIZE 5

template <class type>
class Stack
{
    type st[MAX_SIZE];
    int TOP;
    public:
    Stack()
    {
        TOP=-1;
    }
    ~Stack()
    {
        cout<<"Distructor"<<endl;
    }
    void reset_stack(void)
    {
        TOP=-1;
    }
    int get_top()
    {
        return TOP;
    }
    void push()
    {
        if(TOP==4)
        {
            cout<<"***Stack OverFlow***"<<endl;
        }
        else
        {
            TOP++;
            cout<<"Enter data to push: ";
            cin>>st[TOP];
        }
    }
    void pop()
    {
        if(TOP==-1)
        {
            cout<<"***Stack underflow***"<<endl;
        }
        else
        {
            TOP--;
        }
    }
    void display_stack()
    {
        if(TOP==-1)
        {
            cout<<"***Stack is Empty***"<<endl;
        }
        else
        {
            int x=TOP;
            for(x;x>=0;x--)
                cout<<st[x]<<" ";
            cout<<endl;
        }
    }
};

int stack_selection()
{
    int op;
    cout<<"1. Continue with old Stack"<<endl;
    cout<<"2. Create new satck"<<endl;
    cout<<"Enter your choice:"<<endl;
    cin>>op;
    return op;
} 

template<class typ1>
void stack_operation(Stack<typ1> *(&sp))
{
    int op,task_op;
    if(sp!=nullptr && (*sp).get_top()!=-1)
    {
        while(1)
        {
            op=stack_selection();
            if(op==2)
            {
                (*sp).reset_stack();
                break;
            }
            else if(op==1)
            {
                cout<<"***Using the old stack***"<<endl;
                break;
            }
            else
                cout<<"***Enter correct choice***"<<endl;
        }
    }
    else
    {
        sp=new Stack<typ1>;
    }
    while(1)
    {
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Display Stack"<<endl;
        cout<<"4. Main Menu"<<endl;
        cout<<"Enter your choice: ";
        cin>>task_op;
    
        switch(task_op)
        {
            case 1:(*sp).push();break;
            case 2:(*sp).pop();break;
            case 3:(*sp).display_stack();break;
            case 4: return;break;
        }
        cin.ignore();
    }
}

int main()
{
    Stack<int> *ip=nullptr;
    Stack<char> *cp=nullptr;
    Stack<float> *fp=nullptr;
    Stack<double> *dp=nullptr;
    Stack<string> *sp=nullptr;
    int op,c=0;
    while(1)
    {
        if(c==3)
            break;
        cout<<"MAIN MENU OPTIONS    Stack type"<<endl;
        cout<<"1                    int "<<endl;
        cout<<"2                    char "<<endl;
        cout<<"3                    float "<<endl;
        cout<<"4                    double "<<endl;
        cout<<"5                    string "<<endl;
        cout<<"6                    Exit "<<endl;
        cout<<"Enter you choice: ";
        cin>>op;

        switch(op)
        {
            case 1:stack_operation(ip);break;
            case 2:stack_operation(cp);break;
            case 3:stack_operation(fp);break;
            case 4:stack_operation(dp);break;
            case 5:stack_operation(sp);break;
            case 6:exit(0);break;
            default:cout<<"***unknown option***"<<endl;
                    c++;
                    break;
        }

    }
}