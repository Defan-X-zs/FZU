#include<iostream>//7-3 程序猿和产品狗
#include<string>
using namespace std;
class CodeMonkey;
class ProductDog
{
    public:
        void add_todolist(CodeMonkey&,int);
        void reduce_todolist(CodeMonkey& , int);
};

class CodeMonkey
{
    private:
        string name;
        int todolist;
    public:
        void set(string na,int todo)
        {
            name=na;
            todolist=todo;
        }
        int sizeof_todolist()
        {
            cout<<todolist<<endl;
            return 0;
        }
        friend  void ProductDog::add_todolist(CodeMonkey&,int);
        friend  void ProductDog::reduce_todolist(CodeMonkey&,int);
};


void ProductDog::add_todolist(CodeMonkey &d,int x)
{
    d.todolist+=x;
}
void ProductDog::reduce_todolist(CodeMonkey &d,int x)
{
    d.todolist-=x;
}

int main()
{
    CodeMonkey monkey[100];
    ProductDog dog;
    string nam[100],na;
    int todos[100],y;
    int n,m;
    int opt;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>nam[i]>>todos[i];
        monkey[i].set(nam[i],todos[i]);
    }
    cin>>m;
    for(int j=0; j<m; j++)
    {
        cin>>na>>opt>>y;
        for(int i=0; i<n; i++)
        {
            if(na==nam[i])
            {
                if(opt==0)
                {
                    dog.add_todolist(monkey[i],y);
                }
                else if(opt==1)
                {
                    dog.reduce_todolist(monkey[i],y);
                }
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        cout<<nam[i]<<" ";
        monkey[i].sizeof_todolist();
    }
    return 0;
}
