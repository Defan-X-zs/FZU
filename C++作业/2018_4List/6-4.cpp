void CreateListR(LinkNode *&L, ElemType a[], int n)
{
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;
    LinkNode *p,*r=L;
    for(int i=0;i<n;i++)
    {
        p=(LinkNode *)malloc(sizeof(LinkNode));
        p->data=a[i];
        r->next=p;
        r=p;
    }
    r->next=NULL;
}

void DispList(LinkNode *L)
{
    if(L->next==NULL) printf("NULL");
    else{
        LinkNode *p=L->next;
        while(p)
        {
            printf("%d ",p->data);
            p=p->next;
        }
    }
    printf("\n");
}

void Union(LinkNode *A, LinkNode *B, LinkNode *&C)
{
    C=(LinkNode *)malloc(sizeof(LinkNode));
    LinkNode *i=A->next,*j=B->next,*r=C,*p;
    while(i&&j)
    {
        if(i->data<j->data)
        {
            p=(LinkNode *)malloc(sizeof(LinkNode));
            p->data=i->data;
            r->next=p;
            r=p;
            i=i->next;
        }
        else if(i->data>j->data)
        {
            p=(LinkNode *)malloc(sizeof(LinkNode));
            p->data=j->data;
            r->next=p;
            r=p;
            j=j->next;
        }
        else{
            p=(LinkNode *)malloc(sizeof(LinkNode));
            p->data=j->data;
            r->next=p;
            r=p;
            i=i->next;
            j=j->next;
        }
    }
    if(j) r->next=j;
    if(i) r->next=i;
}

void InterSect(LinkNode *A, LinkNode *B, LinkNode *&C)
{
    C=(LinkNode *)malloc(sizeof(LinkNode));
    LinkNode *i=A->next,*j=B->next,*r=C,*p;
    while(i&&j)
    {
        if(i->data<j->data) i=i->next;
        else if(i->data>j->data) j=j->next;
        else{
            p=(LinkNode *)malloc(sizeof(LinkNode));
            p->data=i->data;
            r->next=p;
            r=p;
            i=i->next;
            j=j->next;
        }
    }
    r->next=NULL;
}

void Subs(LinkNode *A, LinkNode *B, LinkNode *&C)
{
    C=(LinkNode *)malloc(sizeof(LinkNode));
    LinkNode *i=A->next,*j=B->next,*r=C,*p;
    while(i&&j)
    {
        if(i->data<j->data)
        {
            p=(LinkNode *)malloc(sizeof(LinkNode));
            p->data=i->data;
            r->next=p;
            r=p;
            i=i->next;
        }
        else if(i->data>j->data)
        {
            j=j->next;
        }
        else{
            i=i->next;
            j=j->next;
        }
    }
    if(i) r->next=i;  //如果A有剩余
    else r->next=NULL;
}

