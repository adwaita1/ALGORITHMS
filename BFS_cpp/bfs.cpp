

/*

Assignment Name: Implementation of any 2 uninformed search methods with some application.

*/

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int cost[10][10],i,j,k,n,qu[10],front,rare,v,visit[10],visited[10];
 
main()
{
int m;
cout <<"\nEnterno of vertices : ";
cin >> n;
cout <<"\nEnter no of edges : ";
cin >> m;
cout <<"\n\nEDGES : \n\n";
for(k=1;k<=m;k++)
{
cin >>i>>j;
cost[i][j]=1;
}
 
cout <<"\nEnter initial vertex : ";
cin >>v;
cout <<"\nVisitied vertices:\n";
cout << v;
visited[v]=1;
k=1;
while(k<n)
{
for(j=1;j<=n;j++)
if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
{
visit[j]=1;
qu[rare++]=j;
}
v=qu[front++];
cout<<v << " ";
k++;
visit[v]=0; visited[v]=1;
}
}

/*
OUTPUT-
Enter no of vertices : 9
Enter no of edges : 9
EDGES :
 
1 2
2 3
1 5
1 4
4 7
7 8
8 9
2 6
5 7

Enter initial vertex : 1
Visited vertices:
12 4 5 3 6 7 8 9
*/
