
#include "SortTest.h"
#include <iostream>
using namespace std;


void TestMain() 
{
	if (!InsertionSortTest_100_1_Less())
	{
		cout<<"Failed:InsertionSortTest_100_1_Less "<<endl;
	}
	else 
	{
		cout<<"Succed:InsertionSortTest_100_1_Less"<<endl;
	}
	if (!InsertionSortTest_1_100_Greater())
	{
		cout<<"Failed:InsertionSortTest_1_100_Greater"<<endl;
	}
	else 
	{
		cout<<"Succed:InsertionSortTest_1_100_Greater"<<endl;
	}
	if (!SelectSortTest_100_1_Less())
	{
		cout<<"Failed:SelectSortTest_100_1_Less"<<endl;
	}
	else 
	{
		cout<<"Succed:SelectSortTest_100_1_Less"<<endl;
	}

	
}


int main()
{
	TestMain();

}