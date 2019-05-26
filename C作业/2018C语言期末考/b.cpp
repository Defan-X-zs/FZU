#include<stdio.h>
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char a,b,c;
	scanf("%c %c %c",&a,&b,&c);

	if(a=='Q'&&b=='Q'&&c=='Q')printf("Cold snap");
	
	if(a=='Q'&&b=='Q'&&c=='W')printf("Ghost walk");
	if(a=='Q'&&b=='W'&&c=='Q')printf("Ghost walk");
	if(a=='W'&&b=='Q'&&c=='Q')printf("Ghost walk");
		
	if(a=='Q'&&b=='W'&&c=='W')printf("Tornado");
	if(a=='W'&&b=='Q'&&c=='W')printf("Tornado");
	if(a=='W'&&b=='W'&&c=='Q')printf("Tornado");
		
	if(a=='W'&&b=='W'&&c=='W')printf("EMP");
		
	if(a=='E'&&b=='E'&&c=='E')printf("Sun strike");
		
	if(a=='W'&&b=='W'&&c=='E')printf("Alacrity");;
	if(a=='W'&&b=='E'&&c=='W')printf("Alacrity");
	if(a=='E'&&b=='W'&&c=='W')printf("Alacrity");
		
	if(a=='E'&&b=='W'&&c=='E')printf("Chaos meteor");
	if(a=='E'&&b=='E'&&c=='W')printf("Chaos meteor");
	if(a=='W'&&b=='E'&&c=='E')printf("Chaos meteor");
		
	if(a=='E'&&b=='Q'&&c=='Q')printf("Forge spirit");
	if(a=='Q'&&b=='Q'&&c=='E')printf("Forge spirit");
	if(a=='Q'&&b=='E'&&c=='Q')printf("Forge spirit");
		
	if(a=='Q'&&b=='W'&&c=='E')printf("Deafening blast");
	if(a=='Q'&&b=='E'&&c=='W')printf("Deafening blast");
	if(a=='W'&&b=='Q'&&c=='E')printf("Deafening blast");
	if(a=='W'&&b=='E'&&c=='Q')printf("Deafening blast");
	if(a=='E'&&b=='Q'&&c=='W')printf("Deafening blast");
	if(a=='E'&&b=='W'&&c=='Q')printf("Deafening blast");

return 0;
}
