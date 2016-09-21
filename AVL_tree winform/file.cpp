#pragma once
#include"stdafx.h"
#include<fstream>
#include<ctime>
#include<stdlib.h>
#include"file.h"
using namespace std;
ofstream outf("E:\\num.txt" , ios::out);
ifstream inf("E:\\num.txt" , ios::in);
bool Foun(int *arr , int num , int end)
{
	bool found=false;
	for(int i=0 ; i<end ; i++)
	{
		if(arr[i]==num)
		{
			found=true;
		}
	}
	return found;
}
void build_file()
{
	//ofstream outf("D:\\num.txt" , ios::out);
	srand(time(0));
	int Ci,Ar,Ho,Pe;
	int City[10]={0,0,0,0,0,0,0,0,0,0};
	int Area[10]={0,0,0,0,0,0,0,0,0,0};
	int House[10]={0,0,0,0,0,0,0,0,0,0};
	int Person[10]={0,0,0,0,0,0,0,0,0,0};
	for(int c=0 ; c<10 ; c++)//City for
	{
		if(c==0)
		{//city if
			City[c]=((rand()%10)+1);
		}// end city if
		else
		{// city else
			do
			{
				Ci=((rand()%10)+1);
			}while(Foun(City,Ci,c));
			City[c]=Ci;
		}//end city else
		for(int a=0 ; a<10 ; a++)// area for
		{
			if(a==0)
			{// area if
				Area[a]=((rand()%999)+1);
			}//end area if
			else
			{// area else
				do
				{
					Ar=((rand()%999)+1);
				}while(Foun(Area,Ar,a));
				Area[a]=Ar;
			}// area else
			for(int h=0 ; h<10 ; h++)// house for
			{
				if(h==0)
				{// house if
					House[h]=((rand()%9999)+1);
				}//end house if
				else
				{// house else
					do
					{
						Ho=((rand()%9999)+1);
					}while(Foun(House,Ho,h));
					House[h]=Ho;
				}// house else
				for(int p=0 ; p<10 ; p++)// Person for
				{
					if(p==0)
					{// person if
						Person[p]=((rand()%99)+1);
					}//end person if
					else
					{// person else
						do
						{
							Pe=((rand()%99)+1);
						}while(Foun(Person,Pe,p));
						Person[p]=Pe;
					}//end person else
				}//end Person for
				for(int i=0 ; i<10 ; i++)
				{
					if(City[c]<10)
					{
						outf<<0<<City[c];
					}
					else
					{
						outf<<City[c];
					}


					if(Area[a]<100 && Area[a]>9)
					{
						outf<<0<<Area[a];
					}
					else
					{
						if(Area[a]<10)
						{
							outf<<00<<Area[a];
						}
						else
						{
							outf<<Area[a];
						}
					}


					if(House[h]<1000 && House[h]>99)
					{
						outf<<0<<House[h];
					}
					else
					{
						if(House[h]<100 && House[h]>99 )
						{
							outf<<00<<House[h];
						}
						else
						{
							if(House[h]<10)
							{
								outf<<000<<House[h];
							}
							else
							{
								outf<<House[h];
							}
						}
					}


					if(Person[i]<10)
					{
						outf<<0<<Person[i]<<endl;
					}
					else
					{
						outf<<Person[i]<<endl;
					}

				}
			}//end house for
		}//end area for
	}//end city for
}// end function
void save_file(char arr[100][11])
{
	for(int i=0 ; i<100 ; i++)
	{
		for(int j=0 ; j<11 ; j++)
		{
			inf>>arr[i][j];
		}
	}
}
void save_num(char *str)
{
}