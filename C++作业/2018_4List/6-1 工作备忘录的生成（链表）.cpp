Node* add(Node *header, Node *newnode)//6-1 工作备忘录的生成（链表）
{
	if(header==NULL)
	{
		header=newnode;
		header->next=NULL;
		return header;
	}
	Node *pcurrent=header;
	Node *pnext=newnode;
	Node *prev=NULL;
	while(pcurrent!=NULL&&pcurrent->start<pnext->start)
	{
		prev=pcurrent;
		pcurrent=pcurrent->next;
	}
	if(pcurrent==header)
	{
		Node *newheader=newnode;
		newheader->next=header;
		header=newheader;
	}
	else
	{
		prev->next=pnext;
		pnext->next=pcurrent;
	}
	return header;
}
void display(Node *header)
{
		Node* pcurrent=header;
		Node *pnext=pcurrent->next;
		while(pcurrent->next!=NULL)
		{
			while(pnext!=NULL)
			{
				
				if(pcurrent->end>pnext->start)
				{
					if(pcurrent->name[0]!='*')
					{
						pcurrent->name.insert(0,1,'*');
					}
					if(pnext->name[0]!='*')
					{
						pnext->name.insert(0,1,'*');
					}
				}
				pnext=pnext->next;
			}
			pcurrent=pcurrent->next;
			pnext=pcurrent->next;
		}
		
		
		pcurrent=header;
 		while(pcurrent!=NULL)
 		{
 			cout<<pcurrent->name<<" "<<pcurrent->start<<" "<<pcurrent->end<<endl;
 			pcurrent=pcurrent->	next;
		}
}


