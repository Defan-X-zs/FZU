//6-3 ����ָ����������飨�����裩
void Student::addPair()
{
	if(this->pair!=NULL)return; 
    for(int i=0;i<2;i++)
    {
    	if(this->welcome[i]->pair!=NULL)continue;
    	for(int j=0;j<2;j++)
    	{
    			if(this->welcome[i]->welcome[j]==this) 
    		{
    	 		this->pair=this->welcome[i];
    	 		this->welcome[i]->pair=this;
    	 		return;
    		}  
    	}  
    	for(int j=0;j<2;j++)        //����ڴ���������δƥ��ɹ������Ǵպ����
    	{
       		if(this->welcome[j]->welcome[0]->pair!=NULL && this->welcome[j]->welcome[1]->pair!=NULL && this->welcome[j]->pair==NULL)
        	{
         		this->pair=this->welcome[j];
         		this->welcome[j]->pair=this;
          		return;
        	}
    	} 
    }
}
void Student::printPair()
{
    if(this->pair)
  	cout<<this->name<<":"<<this->pair->name<<endl;
}


