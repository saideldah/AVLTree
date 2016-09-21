#pragma once
#include"stdafx.h"
#include<fstream>
#include<ctime>
#include<string.h>
#include<stdlib.h>
//#include"file.h"

struct Avl{
	char num[12];
	int bal;
	Avl *R;
	Avl *L;
};
// left right rotation
void LR(Avl *&T)
{
	Avl *temp;
	temp=T->R;
	T->R=temp->L;
	temp->L=T;
	T->bal=0;
	T=temp;
}

//----------------------------------
//right rotation

void RR(Avl *&T)
{
	Avl *temp;
	temp=T->L;
	T->L=temp->R;
	temp->R=T;
	T->bal=0;
	T=temp;
}

//---------------------------------------------
//left right rotation

void LRR(Avl *&T)
{
	Avl *temp1;
	Avl *temp2;
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
	}
	if(temp2->bal==-1)
	{
		temp1->bal=1;
	}
	else
	{
		temp1->bal=0;
	}
	T=temp2;
}//end procedur LRR

//---------------------------------------------------
//right left rotation
void RLR(Avl *&T)
{
	Avl *temp1;;
	Avl *temp2;
	temp1=T->R;
	temp2=temp1->L;
	temp1->L=temp2->R;
	temp2->R=temp1;
	T->R=temp2->L;
	temp2->L=T;
	if(temp2->bal == -1)
	{
		T->bal=1;
	}
	else
	{
		T->bal=0;
	}
	if(temp2->bal==1)
	{
		temp1->bal=-1;
	}
	else
	{
		temp1->bal=0;
	}
	T=temp2;
}//end procedure RLR

//-----------------------------------------------------------------------
void Rebalance_left(Avl *&T, bool &h)
{
	Avl *ptr1=NULL;
	Avl	*ptr2=NULL;
	if(h)
	{
		switch(T->bal)
		{
		case 1:
			{
				T->bal=0;
				break;
			}
		case 0:
			{
				T->bal=-1;
				h=false;
				break;
			}
		case -1:
			{
				ptr1=T->R;
				switch(ptr1->bal)
				{
				case -1:
					{
						T->R=ptr1->L;
						ptr1->L=T;
						T->bal=0;
						ptr1->bal=0;
						T=ptr1;
						h=false;
						break;
					}//end case -1:
				case 0:
					{
						T->R=ptr1->L;
						ptr1->L=T;
						T->bal=-1;
						ptr1->bal=1;
						T=ptr1;
						h=false;
						break;
					}//end case 0
				case 1:
					{
						ptr2=ptr1->L;
						ptr1->L=ptr2->R;
						T->R=ptr2->L;
						ptr2->L=T;
						ptr2->R=ptr1;
						if(ptr2->bal < 0)
						{
							T->bal=1;
						}
						else
						{
							T->bal=0;
						}
						if(ptr2->bal > 0)
						{
							ptr1->bal=-1;
						}
						else
						{
							ptr1->bal=0;
						}
						ptr2->bal=0;
						T=ptr2;
						break;
					}//end case 1:
				}//end switch(ptr1->bal)
				break;
			}//end case -1
		}//end switch(T->bal)
	}// end if h
}// end procedure Rebance_left
//----------------------------------------------------------------------
void Rebalance_right(Avl *&T, bool &h)
{
	Avl *ptr1=NULL;
	Avl	*ptr2=NULL;
	if(h)
	{
		switch(T->bal)
		{
		case -1:
			{
				T->bal=0;
				break;
			}
		case 0:
			{
				T->bal=1;
				h=false;
				break;
			}
		case 1:
			{
				ptr1=T->L;
				switch(ptr1->bal)
				{
				case 1:
					{
						T->L=ptr1->R;
						ptr1->R=T;
						T->bal=0;
						ptr1->bal=0;
						T=ptr1;
						h=false;
						break;
					}//end case -1:
				case 0:
					{
						T->L=ptr1->R;
						ptr1->R=T;
						T->bal=1;
						ptr1->bal=-1;
						T=ptr1;
						h=false;
						break;
					}//end case 0
				case -1:
					{
						ptr2=ptr1->R;
						ptr1->R=ptr2->L;
						T->L=ptr2->R;
						ptr2->R=T;
						ptr2->L=ptr1;
						if(ptr2->bal < 0)
						{
							T->bal=-1;
						}
						else
						{
							T->bal=0;
						}
						if(ptr2->bal > 0)
						{
							ptr1->bal=1;
						}
						else
						{
							ptr1->bal=0;
						}
						ptr2->bal=0;
						T=ptr2;
						break;
					}//end case 1:
				}//end switch(ptr1->bal)
				break;
			}//end case -1
		}//end switch(T->bal)
	}// end if h
}// end procedure Rebalnce right
//---------------------------------------------------------------------- 
// get_max is a function retunt the max number in tree 
void get_max(Avl *&T ,char *max)
{
	strcpy(max,T->num);
	if(T->R!=NULL)
	{
		get_max(T->R,max);
	}
}
//---------------------------------------------------------------------
//delete element
void Delete_element(Avl *&T , Avl &element ,bool &h )
{
	if(T==NULL)
	{
		h=false;
	}
	else
	{
		if(strcmp(element.num,T->num) < 0)
		{
			Delete_element(T->L,element,h);
			if(h)
			{
				Rebalance_left(T,h);
			}
		}// end if(strcmp(element.num,T->num)<0)
		else
		{
			if(strcmp(element.num,T->num) > 0)
			{
				Delete_element(T->R,element,h);
				if(h)
				{
					Rebalance_right(T,h);
				}
			}
			else
			{
				if(T->L==NULL)
				{
					T=T->R;
					h=true;
				}
				else 
				{
					if(T->R==NULL)
					{
						T=T->L;
						h=true;
					}
					else
					{
						char *max=new char[12];
						get_max(T->L,max);
						strcpy(T->num,max);
						strcpy(element.num,max);
						Delete_element(T->L,element,h);
						if(h)
						{
							Rebalance_left(T,h);
						}//end if(h)
					}//end else if it has two child
				}
			}// end else if(strcmp(element.num,T->num)==0)
		}//end else if(strcmp(element.num,T->num) > 0)
	}//end else (T!=NULL)
}
//----------------------------------------------------------------------
Avl* Delete_element1(Avl *T , Avl &element ,bool h )
{
	Delete_element(T,element,h);
	return T;
}
//-----------------------------------------------------------------------
// insert node in AVL tree

void Insert(Avl *&T, Avl &node , bool &h)
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
		if( strcmp(node.num , T->num) < 0)
		{//if( strcmp(node.num , T->num) < 0 )
			Insert(T->L,node,h);
			if(h)
			{//if h
				//case bal=(-1,0,1)
				if(T->bal <= 0)
				{
					if(T->bal==0)
					{
						T->bal=1;
					}
					else
					{//balance =-1
						T->bal=0;
						h=false;
					}
				}//end if T->bal<=0
				else
				{// balance=1
					if(T->L->bal==1)
					{
						RR(T);//m right rotation
					}
					else
					{
						LRR(T);//left right rotation
					}
					T->bal=0;
					h=false;
				}//end else balance=1
			}//end if h
		}//end if( strcmp(node.num , T->num) < 0 )

		else//if( strcmp(node.num , T->num) > 0 )
		{//start else 
			if(strcmp(node.num , T->num) > 0)
			{//if( strcmp(node.num , T->num) > 0 )
				Insert(T->R,node,h);
				if(h)
				{//if(h)
					if(T->bal >= 0)
					{
						if(T->bal==0)
						{
							T->bal=-1;
						}
						else
						{//balance = 1
							T->bal=0;
							h=false;
						}
					}//end if T->bal<=0
					else
					{// balance =-1
						if(T->R->bal == -1)
						{
							LR(T);//left rotation
						}
						else
						{
							RLR(T);
						}
						T->bal=0;
						h=false;
					}
				}//end if h
			}//end if( strcmp(node.num , T->num) > 0 )
			else
			{
				h=false;
			}
		}//end else
	}//end else T!=NULL
}//end procedure insert

//-------------------------------------------
Avl *Insert1(Avl *T, Avl &element , bool h)
{
	Insert(T,element,h);
	return T;
}
//-------------------------------------------
//function to build up the AVL tree
Avl *buildup_tree()
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
	return T;
}
/*
void print_inorder(Avl *T)
{
	if(T!=NULL)
	{
		print_inorder(T->L);
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
}*/