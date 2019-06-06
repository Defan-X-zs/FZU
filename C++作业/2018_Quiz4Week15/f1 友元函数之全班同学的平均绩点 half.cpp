//友元函数之全班同学的平均绩点
double averagegrade(student *stu, int count){
	double persongrade[count], sumgrade=0, personscore[count], sumscore=0;
	int i, j;
	for (i = 0; i < count; ++i)
	{
		persongrade[i] = 0;
		for (j = 0;stu[i].grade[j]!=NULL&&stu[i].score[j]!=NULL; ++j)
		{
			persongrade[i] += (stu[i].grade[j]/10.0 - 5)*stu[i].score[j];
			personscore[i] += stu[i].score[j];
		}
		sumgrade+=persongrade[i];
		sumscore+=personscore[i];
	}
	return sumgrade/sumscore;
}