Player *create()//建立链表 龙舟
{
	Player* p=new Player;
	p->num=0;
	p->next=NULL;
	return p;
}
Player* addPlayer(Player* head, Player* q)//加链表里加入q指向的结点
{
	Player* temp=head;
	while(1){
	if(temp->next==NULL)
	{
		head->next=q;return temp;
	}
	else if(head->next->num>q->num&&head->num<q->num)
	{
		q->next=head->next;
		head->next=q;
		return temp;
	}
	else head=head->next;}
}
Player* removePlayer(Player *head, int num)//从链表里删除编号为num的结点，如果删除导致缺少鼓手则自动选择一位新鼓手
{
	Player* temp=head;
	while(1)
	{
		if(head->next->num==num){head->next=head->next->next;return temp;}
	}
}