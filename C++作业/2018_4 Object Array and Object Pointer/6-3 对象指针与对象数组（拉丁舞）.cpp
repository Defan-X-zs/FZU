//6-3 对象指针与对象数组（拉丁舞）
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
    	for(int j=0;j<2;j++)        //如果期待的名单上未匹配成功，则考虑凑合情况
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


