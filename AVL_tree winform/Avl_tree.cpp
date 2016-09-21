#include<iostream>
#include<fstream>
#include<ctime>
#include<string.h>
#include<stdlib.h>
#include"file.h"
#include"Avl.h"
using namespace std;
void main()
{
	bool h=true;
	Avl *T=NULL;
	Avl node;
	node.L=new Avl;
	node.R=new Avl;
	char arr[100][11];
	char *num=new char[12];
	build_file();
	save_file(arr);
	for(int i=0 ; i<100 ; i++)
	{
		for(int j=0 ; j<11 ; j++)
		{
			num[j]=arr[i][j];
		}
		num[11]='\0';
		strcpy(node.num,num);
		Insert(T,node,h);
	}
	print_inorder(T);
}