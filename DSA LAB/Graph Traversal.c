#include <stdio.h>
#include <stdlib.h>
int N; //Number of Nodes
//Function for BFS Traversal
void bfs(int a[][N], int visited[], int start)
{
int Q[N],rear=-1,front=-1; //Initializing Empty Queue
int i;
//Initializing the Visited Array with 0
for(i=0;i<N;i++)
visited[i]=0;
//Inserting the First node into Queue
Q[++rear]=start;
++front;
visited[start]=1;
while(rear>=front)
{
start = Q[front++];
printf("%c ",start+65);
for(i=0;i<N;i++)
{
if(a[start][i]&&visited[i]==0)
{
Q[++rear] = i; //Inserting the Adjacent nodes into Queue
visited[i] = 1;
}
}
}
}
void dfs(int a[][N], int visited[], int start)
{
int S[N],top=-1; //Initializing Empty Stack
int i;
//Initializing the Visited Array with 0
for(i=0;i<N;i++)
visited[i]=0;
S[++top] = start;
visited[start]=1;
while(top!=-1)
{
start = S[top--];
printf("%c ",start+65);
for(i=0;i<N;i++)
{
if(a[start][i]&&visited[i]==0)
{
S[++top] = i; //Inserting the Adjacent node into Stack
visited[i] = 1;
break;
}
}
}
}
void main()
{
int matrix[10][10]; //Declaring adjacency matrix of Graph
int visited[10]; //Declaring the Visited Array
int choice,i,j;
char node; //The node from where traversal is started
printf("Menu\n1.Enter the Graph\n2.BFS Traversal\n3.DFS Traversal\n4.Exit\n");
for(;;)
{
printf("\nEnter Your Choice : ");
scanf("%d",&choice);
switch (choice)
{
case 1 : printf("Enter the Number of Nodes : ");
scanf("%d",&N);
printf("Enter the Adjacency Matrix :\n");
for(i=0;i<N;i++)
for(j=0;j<N;j++)
scanf("%d",&matrix[i][j]);
break;
case 2 : printf("The Nodes are named as A,B,C,D...\n");
printf("Enter the node to start with : ");
scanf(" %c",&node);
printf("BFS Traversal : ");
bfs(matrix,visited,node-65);
break;
case 3 : printf("The Nodes are named as A,B,C,D...\n");
printf("Enter the node to start with : ");
scanf(" %c",&node);
dfs(matrix,visited,node-65);
break;
case 4 : printf("!!THANK YOU!!\n");
exit(0);
default: printf("Invalid Choice\n");
}
}
}