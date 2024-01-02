#include<iostream>
using namespace std;
struct node
{
    int item;
    int pno;
    node *next;
    node(int data,int p)
    {
        item=data;
        pno=p;
        next=NULL;
    }
};
class PriorityQueue
{
    private:
        node *start;
    public:
        PriorityQueue();
        void insert(int,int);
        void deleteNode();
        int getHighestPriorityElement();
        int getHighestPriorityNumber();
        ~PriorityQueue();
        bool isEmpty();
};
PriorityQueue::PriorityQueue()
{
    start=NULL;
}
void PriorityQueue::insert(int data,int pno)
{
    node *n=new node(data,pno);
    node *t1,*t2;
    if(start==NULL)
    {
        start=n;
    }
    else
    {
        t1=start;
        t2=NULL;
        while(t1)
        {
            if(pno>t1->pno)
                break;
            t2=t1;
            t1=t1->next;
        }
        if(t2)
        {
            n->next=t1;
            t2->next=n;
        }
        else
        {
            n->next=t1;
            start=n;
        }
    }
}
void PriorityQueue::deleteNode()
{
   if(start)
   {
        node *temp=start;
        start=start->next;
        delete temp;
   } 
}
int PriorityQueue::getHighestPriorityElement()
{
    if(start==NULL)
        throw 1;
    return start->item;
}
int PriorityQueue::getHighestPriorityNumber()
{
    if(start==NULL)
        throw 1;
    return start->pno;
}
PriorityQueue::~PriorityQueue()
{
    while(start)
        deleteNode();
}
bool PriorityQueue::isEmpty()
{
    return start==NULL;
}
int main() {

return 0;
}