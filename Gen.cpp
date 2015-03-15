// Gen.cpp: implementation of the Gen class.
//
//////////////////////////////////////////////////////////////////////

#include "Gen.h"
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Gen::Gen()
{
	for(int i = 0; i < 8; i++)
		num[i] = 0;

}

Gen::~Gen()
{

}

Gen Gen::operator + (Gen a)
{
	Gen ret;
	int i;
	for(i = 0; i < 3; i++)
		ret.num[i] = num[i];
	for(i = 3; i < 8; i++)
		ret.num[i] = a.num[i];
	return ret;
}

Gen Gen::operator * (Gen a)
{
	Gen ret;
	int i;
	for(i = 0; i < 8; i++)
		ret.num[i] = num[i] * a.num[i];
	return ret;
}

Gen Gen::operator += (Gen a)
{
	Gen ret;
	int i;
	for(i = 0; i < 3; i++)
		ret.num[i] = num[i];
	for(i = 3; i < 8; i++)
		ret.num[i] = a.num[i];
	for(i = 0; i < 8; i++)
		num[i] = ret.num[i];
	return ret;
}

Gen Gen::operator *= (Gen a)
{
	Gen ret;
	int i;
	for(i = 0; i < 8; i++)
		num[i] = num[i] * a.num[i];
	return ret;
}

ostream& operator<<( ostream& output, const Gen & a)
{
	output << "Gen : " ;
	for(int i = 0; i < 8; i++)
		output << a.num[i] << " ";
	return output;
}

istream& operator >>( istream& input, Gen & a)
{
	for(int i = 0; i < 8; i++)
		input >> a.num[i];

	return input;
}

Gen& operator!(Gen & a)
{
	a.num[rand()%8] = (rand()%8) + 1; 
	return a;
}

int Gen::operator[](int s)
{
	return num[s];
}

bool operator <(Gen& a,Gen& b)
{
	int i,j,k,l,m=0,n=0;
	//peida kardane jaye vaziraa
	int map[8][8] = {0};
	for(i = 0; i < 8; i++)
		map[i][a.num[i]-1] = 1;
	m = 0;
	for(i = 0; i < 8; i++)
	{
		for(j= 0; j < 8; j++)
		{
			if(map[i][j] == 1)
			{
				for(k = j-1; k >=0; k--)	//sotun check be baalaa
				{
					if(map[i][k] == 1)
					{
						m++;
						break;
					}
				}
				for(k = j+1; k < 8; k++)	//sotun check be paeen
				{
					if(map[i][k] == 1)
					{
						m++;
						break;
					}
				}
				for(k = i-1; k >=0; k--)	//radif check be chap
				{
					if(map[k][j] == 1)
					{
						m++;
						break;
					}
				}
				for(k = i+1; k < 8; k++)	//radif check be rast
				{
					if(map[k][j] == 1)
					{
						m++;
						break;
					}
				}
				///////zarbdari check
				for(k=i+1,l=j+1; k<8,l<8;k++,l++)
				{
					if(map[k][l] == 1)
					{
						m++;
						break;
					}
				}
				for(k=i-1,l=j-1; k>=0,l>=0;k--,l--)
				{
					if(map[k][l] == 1)
					{
						m++;
						break;
					}
				}
				for(k=i+1,l=j-1; k<8,l>=0;k++,l--)
				{
					if(map[k][l] == 1)
					{
						m++;
						break;
					}
				}
				for(k=i-1,l=j+1; k>=0,l<0;k--,l++)
				{
					if(map[k][l] == 1)
					{
						m++;
						break;
					}
				}
			}
		}
	}
///////////////////////////////////////////////////////////////////////////////////////////////////
	for(i = 0; i < 8; i++)
		for(j= 0; j < 8; j++)
			map[i][j] = 0;

	for(i = 0; i < 8; i++)
		map[i][b.num[i]-1] = 1;
	n = 0;
	for(i = 0; i < 8; i++)
	{
		for(j= 0; j < 8; j++)
		{
			if(map[i][j] == 1)
			{
				for(k = j-1; k >=0; k--)	//sotun check be baalaa
				{
					if(map[i][k] == 1)
					{
						n++;
						break;
					}
				}
				for(k = j+1; k < 8; k++)	//sotun check be paeen
				{
					if(map[i][k] == 1)
					{
						n++;
						break;
					}
				}
				for(k = i-1; k >=0; k--)	//radif check be chap
				{
					if(map[k][j] == 1)
					{
						n++;
						break;
					}
				}
				for(k = i+1; k < 8; k++)	//radif check be rast
				{
					if(map[k][j] == 1)
					{
						n++;
						break;
					}
				}
				///////zarbdari check
				for(k=i+1,l=j+1; k<8,l<8;k++,l++)
				{
					if(map[k][l] == 1)
					{
						n++;
						break;
					}
				}
				for(k=i-1,l=j-1; k>=0,l>=0;k--,l--)
				{
					if(map[k][l] == 1)
					{
						n++;
						break;
					}
				}
				for(k=i+1,l=j-1; k<8,l>=0;k++,l--)
				{
					if(map[k][l] == 1)
					{
						n++;
						break;
					}
				}
				for(k=i-1,l=j+1; k>=0,l<0;k--,l++)
				{
					if(map[k][l] == 1)
					{
						n++;
						break;
					}
				}
			}
		}
	}
	if (m < n)
		return true;
	else
		return false;
}

bool operator >(Gen& a,Gen& b)
{
	int i,j,k,l,m=0,n=0;
	//peida kardane jaye vaziraa
	int map[8][8] = {0};
	for(i = 0; i < 8; i++)
		map[i][a.num[i]-1] = 1;
	m = 0;
	for(i = 0; i < 8; i++)
	{
		for(j= 0; j < 8; j++)
		{
			if(map[i][j] == 1)
			{
				for(k = j-1; k >=0; k--)	//sotun check be baalaa
				{
					if(map[i][k] == 1)
					{
						m++;
						break;
					}
				}
				for(k = j+1; k < 8; k++)	//sotun check be paeen
				{
					if(map[i][k] == 1)
					{
						m++;
						break;
					}
				}
				for(k = i-1; k >=0; k--)	//radif check be chap
				{
					if(map[k][j] == 1)
					{
						m++;
						break;
					}
				}
				for(k = i+1; k < 8; k++)	//radif check be rast
				{
					if(map[k][j] == 1)
					{
						m++;
						break;
					}
				}
				///////zarbdari check
				for(k=i+1,l=j+1; k<8,l<8;k++,l++)
				{
					if(map[k][l] == 1)
					{
						m++;
						break;
					}
				}
				for(k=i-1,l=j-1; k>=0,l>=0;k--,l--)
				{
					if(map[k][l] == 1)
					{
						m++;
						break;
					}
				}
				for(k=i+1,l=j-1; k<8,l>=0;k++,l--)
				{
					if(map[k][l] == 1)
					{
						m++;
						break;
					}
				}
				for(k=i-1,l=j+1; k>=0,l<0;k--,l++)
				{
					if(map[k][l] == 1)
					{
						m++;
						break;
					}
				}
			}
		}
	}
///////////////////////////////////////////////////////////////////////////////////////////////////
	for(i = 0; i < 8; i++)
		for(j= 0; j < 8; j++)
			map[i][j] = 0;

	for(i = 0; i < 8; i++)
		map[i][b.num[i]-1] = 1;
	n = 0;
	for(i = 0; i < 8; i++)
	{
		for(j= 0; j < 8; j++)
		{
			if(map[i][j] == 1)
			{
				for(k = j-1; k >=0; k--)	//sotun check be baalaa
				{
					if(map[i][k] == 1)
					{
						n++;
						break;
					}
				}
				for(k = j+1; k < 8; k++)	//sotun check be paeen
				{
					if(map[i][k] == 1)
					{
						n++;
						break;
					}
				}
				for(k = i-1; k >=0; k--)	//radif check be chap
				{
					if(map[k][j] == 1)
					{
						n++;
						break;
					}
				}
				for(k = i+1; k < 8; k++)	//radif check be rast
				{
					if(map[k][j] == 1)
					{
						n++;
						break;
					}
				}
				///////zarbdari check
				for(k=i+1,l=j+1; k<8,l<8;k++,l++)
				{
					if(map[k][l] == 1)
					{
						n++;
						break;
					}
				}
				for(k=i-1,l=j-1; k>=0,l>=0;k--,l--)
				{
					if(map[k][l] == 1)
					{
						n++;
						break;
					}
				}
				for(k=i+1,l=j-1; k<8,l>=0;k++,l--)
				{
					if(map[k][l] == 1)
					{
						n++;
						break;
					}
				}
				for(k=i-1,l=j+1; k>=0,l<0;k--,l++)
				{
					if(map[k][l] == 1)
					{
						n++;
						break;
					}
				}
			}
		}
	}
	if (m > n)
		return true;
	else
		return false;
}

bool operator ==(Gen& a,Gen& b)
{
	int i,j,k,l,m=0,n=0;
	//peida kardane jaye vaziraa
	int map[8][8] = {0};
	for(i = 0; i < 8; i++)
		map[i][a.num[i]-1] = 1;
	m = 0;
	for(i = 0; i < 8; i++)
	{
		for(j= 0; j < 8; j++)
		{
			if(map[i][j] == 1)
			{
				for(k = j-1; k >=0; k--)	//sotun check be baalaa
				{
					if(map[i][k] == 1)
					{
						m++;
						break;
					}
				}
				for(k = j+1; k < 8; k++)	//sotun check be paeen
				{
					if(map[i][k] == 1)
					{
						m++;
						break;
					}
				}
				for(k = i-1; k >=0; k--)	//radif check be chap
				{
					if(map[k][j] == 1)
					{
						m++;
						break;
					}
				}
				for(k = i+1; k < 8; k++)	//radif check be rast
				{
					if(map[k][j] == 1)
					{
						m++;
						break;
					}
				}
				///////zarbdari check
				for(k=i+1,l=j+1; k<8,l<8;k++,l++)
				{
					if(map[k][l] == 1)
					{
						m++;
						break;
					}
				}
				for(k=i-1,l=j-1; k>=0,l>=0;k--,l--)
				{
					if(map[k][l] == 1)
					{
						m++;
						break;
					}
				}
				for(k=i+1,l=j-1; k<8,l>=0;k++,l--)
				{
					if(map[k][l] == 1)
					{
						m++;
						break;
					}
				}
				for(k=i-1,l=j+1; k>=0,l<0;k--,l++)
				{
					if(map[k][l] == 1)
					{
						m++;
						break;
					}
				}
			}
		}
	}
///////////////////////////////////////////////////////////////////////////////////////////////////
	for(i = 0; i < 8; i++)
		for(j= 0; j < 8; j++)
			map[i][j] = 0;

	for(i = 0; i < 8; i++)
		map[i][b.num[i]-1] = 1;
	n = 0;
	for(i = 0; i < 8; i++)
	{
		for(j= 0; j < 8; j++)
		{
			if(map[i][j] == 1)
			{
				for(k = j-1; k >=0; k--)	//sotun check be baalaa
				{
					if(map[i][k] == 1)
					{
						n++;
						break;
					}
				}
				for(k = j+1; k < 8; k++)	//sotun check be paeen
				{
					if(map[i][k] == 1)
					{
						n++;
						break;
					}
				}
				for(k = i-1; k >=0; k--)	//radif check be chap
				{
					if(map[k][j] == 1)
					{
						n++;
						break;
					}
				}
				for(k = i+1; k < 8; k++)	//radif check be rast
				{
					if(map[k][j] == 1)
					{
						n++;
						break;
					}
				}
				///////zarbdari check
				for(k=i+1,l=j+1; k<8,l<8;k++,l++)
				{
					if(map[k][l] == 1)
					{
						n++;
						break;
					}
				}
				for(k=i-1,l=j-1; k>=0,l>=0;k--,l--)
				{
					if(map[k][l] == 1)
					{
						n++;
						break;
					}
				}
				for(k=i+1,l=j-1; k<8,l>=0;k++,l--)
				{
					if(map[k][l] == 1)
					{
						n++;
						break;
					}
				}
				for(k=i-1,l=j+1; k>=0,l<0;k--,l++)
				{
					if(map[k][l] == 1)
					{
						n++;
						break;
					}
				}
			}
		}
	}
	if (m == n)
		return true;
	else
		return false;
}

Gen& Gen::operator ++()
{
	int temp,i;
	temp = num[7];
	for(i = 6; i <= 0; i--)
		num[i+1] = num[i];
	num[0] = temp;
	return *this;
}

Gen& Gen::operator --()
{
	int temp,i;
	temp = num[0];
	for(i = 0; i <= 8; i++)
		num[i] = num[i+1];
	num[7] = temp;
	return *this;
}

Gen& Gen::operator= (Gen &b)
{
	for(int i = 0; i < 8; i++)
		num[i] = b.num[i];
	return *this;
}

