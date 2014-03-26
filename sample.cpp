#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;
#include"hashset.h"
#define N 30

int main()
{
	HashSet myset1(10);
	HashSet myset2(15);
	srand((unsigned int)time(0));
	for (int i = 0; i < N; i++)
	{
		int tmp = rand() % 100;
		myset1.add(tmp);
		myset2.add(tmp);
	}
	cout <<"\nCase 1: Sample(same with the case2's sample) when the length is 10.\nmyset1:\n";
	myset1.output();
	cout <<"\nCase 2: Sample(same with the case1's sample) when the length is 15.\nmyset2:\n";
	myset2.output();

	HashSet myset3(10);
	cout <<"\nCase 3: Insert 1-20 to myset3.\nmyset3:\n";
	for (int i = 1; i <= 20; i++)
		myset3.add(i);
	myset3.output();

	cout <<"\n********Robustness test**********"<<endl;
	cout <<"\nCase 4: Insert 5-15 to myset3.\nmyset3:\n";
	for (int i = 5; i <= 15; i++)
		myset3.add(i);
	myset3.output();
	
	cout <<"\nCase 5: Delete 4-16 from myset3.\nmyset3:\n";
	for (int i = 4; i <= 16; i++)
		myset3.del(i);
	myset3.output();
	
	cout <<"\nCase 6: Delete 5 3times from myset3.\nmyset3:\n";
	for (int i = 0; i < 3; i++)
		myset3.del(5);
	myset3.output();
	cout <<"\nEnd"<<endl;
	return 0;
}
