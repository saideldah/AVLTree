#pragma once
#include"stdafx.h"
#include<fstream>
#include<ctime>
#include<string.h>
#include<stdlib.h>
#include "Avl.h"
#include"file.h"
using namespace std;
void LR(Avl *&T)
{
	Avl *temp;
	temp=T->R;
	T->R=temp->L;
	temp->L=T;
	T->bal=0;
	T=temp;
}
void RR(Avl *&T)
{
	Avl *temp;
	temp=T->L;
	T->L=temp->R;
	temp->R=T;
	T->bal=0;
	T=temp;
}
void LRR(Avl *&T)
{
	Avl *temp1=NULL;
	Avl *temp2=NULL;
	temp1=T->L;
	temp2=temp1->R;
	temp1->R=temp2->L;
	temp2->L=temp1;
	T->L=temp2->R;
	temp2->R=T;
	if(temp2->bal==1)
	{
		T->bal=-1;
	}
	else
	{
		T->bal=0;
		if(temp2->bal==-1)
		{
			temp1->bal=1;
		}
		else
		{
			temp1->bal=0;
		}
		T=temp2;
	}
}//end procedur LRR
void RLR(Avl *&T)
{
	Avl *temp1=NULL;
	Avl *temp2=NULL;
	temp1=T->R;
	temp2=temp1->L;
	temp1->L=temp2->R;
	temp2->R=temp1;
	T->R=temp2->L;
	temp2->L=T;
	if(temp2->bal==-1)
	{
		T->bal=11;
	}
	else
	{
		T->bal=0;
		if(temp2->bal==1)
		{
			temp1->bal=-1;
		}
		else
		{
			temp1->bal=0;
		}
		T=temp2;
	}
}//end procedure RLR
void Insert(Avl *&T, Avl &node , bool h)
{
	if(T==NULL)
	{
		h=true;
		T=new Avl(node);
		T->L=NULL;
		T->R=NULL;
		T->bal=0;
	}
	else
	{
		if( strcmp(node.num , T->num) < 0 )
		{
			Insert(T->L,node,h);
			if(h)
			{//if h
				if(T->bal<=0)
				{
					if(T->bal==0)
					{
						T->bal++;
					}
					else
					{
						T->bal++;
						h=false;
					}
				}//end if T->bal<=0
				else
				{
					if(T->L->bal==1)
					{
						RR(T);//m right rotation
					}
				}
			}//end if h
			else
			{
				LRR(T);//left right rotation
			}
			T->bal=0;
			h=false;
		}
		else
		{//start else 
			Insert(T->R,node,h);
			if(h)
			{
				if(T->bal>=0)
				{
					if(T->bal==0)
					{
						T->bal--;
					}
					else
					{
						T->bal--;
						h=false;
					}
				}//end if T->bal<=0
				else
				{
					if(T->R->bal==-1)
					{
						LR(T);//m right rotation
					}
					else
					{
						RLR(T);
					}
					T->bal=0;
					h=false;
				}
			}//end if h
		}//end else
	}//end else T!=NULL
}//end procedure insert

void print_inorder(Avl *T)
{
	if(T!=NULL)
	{
		print_inorder(T->L);
		cout<<T->num<<endl;
		print_inorder(T->R);
	}
}
void print_preorder(Avl *T)
{
	if(T!=NULL)
	{
		cout<<T->num<<endl;
		print_preorder(T->L);
		print_preorder(T->R);
	}
}
void print_postorder(Avl *T)
{
	if(T!=NULL)
	{
		print_postorder(T->L);
		print_postorder(T->R);
		cout<<T->num<<endl;
	}
}