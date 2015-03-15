// Gen.h: interface for the Gen class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GEN_H__C55F6C08_74F9_493A_B118_11583DA43130__INCLUDED_)
#define AFX_GEN_H__C55F6C08_74F9_493A_B118_11583DA43130__INCLUDED_
#include <iostream>
using namespace std;

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Gen  
{
	friend ostream& operator <<( ostream&, const Gen & );
	friend istream& operator >>( istream&, Gen & );
	friend Gen& operator !(Gen & );
	friend bool operator <(Gen &,Gen &);
	friend bool operator >(Gen &,Gen &);
	friend bool operator ==(Gen &,Gen &);
	public:
	int num[8];
	Gen();
	virtual ~Gen();
	Gen operator+( Gen );
	Gen operator*( Gen );
	Gen operator+=( Gen );
	Gen operator*=( Gen );
	Gen& operator=( Gen& );
	Gen& operator ++ ();
	Gen& operator -- ();
	int operator[](int s);
};

#endif // !defined(AFX_GEN_H__C55F6C08_74F9_493A_B118_11583DA43130__INCLUDED_)
