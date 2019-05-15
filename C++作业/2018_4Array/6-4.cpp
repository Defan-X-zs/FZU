double getScore(int *score, int total)//6-4 歌唱比赛打分
{
	int i,max=0,min=100,k,j,sum=0;
	double ave;
	for(i=0;i<total;i++)
	{
		if(score[i]>max)
		{
			max=score[i];
		}
	}
	for(j=0;j<total;j++)
	{
		if(score[j]<min)
		{
			min=score[j];
		}
	}
	for(k=0;k<total;k++)
	{
		sum+=score[k];
	}
	ave=(sum-max-min)*1.0/(total-2)*1.0;
	return ave;
} 

