#include<iostream>
#include<cstdio>
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
	
	cout <<"\n********Constructor Test**********"<<endl;
	cout <<"\nCase 1: Sample(same with the case2's sample) when the length is 10.\nmyset1:\n";
	myset1.output();
	cout <<"\nCase 2: Sample(same with the case1's sample) when the length is 15.\nmyset2:\n";
	myset2.output();

	HashSet myset3(10);
	cout <<"\nCase 3: Insert 1-20 then 40-21 to myset3.\nmyset3:\n";
	for (int i = 1; i <= 20; i++)
		myset3.add(i);
	for (int i = 40; i >= 21; i--)
		myset3.add(i);
	myset3.output();

	cout <<"\n********Robustness Tests**********"<<endl;
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
	
	cout <<"\n********Other Functions tests**********"<<endl;
	cout <<"\nCase 7: Whether myset3 has [1,11..51].\nmyset3:\n";
	for (int i = 1; i <= 51; i+=10)
		printf("%d %c\n", i, myset3.hasdata(i) == true ? 'Y' : 'N');
	
	cout <<"\nCase 8: A new myset4 copy from myset3.\nmyset4:\n";
	HashSet myset4;
	myset4.copy(myset3);
	myset4.output();

	cout <<"\nCase 9: Judge whether myset4 equal to myset3.\n";
	printf("%c\n", myset4.equal(myset3) == true ? 'Y' : 'N');
	cout <<"Delete 28 from myset3, then judge again.\n";
	myset3.del(28);
	printf("%c\n", myset4.equal(myset3) == true ? 'Y' : 'N');

	cout <<"\nCase 10: clear myset4 and output it.\nmyset4:";
	myset4.clear();
	myset4.output();
	cout <<"Judge whether myset3 and myset4 are empty.\n";
	printf("myset3 is empty? %c\n", myset3.empty() == true ? 'Y' : 'N');
	printf("myset4 is empty? %c\n", myset4.empty() == true ? 'Y' : 'N');

	cout <<"\n********Set Function Test**********"<<endl;
	HashSet setA, setB, uset, iset, dset;
	for (int i = 0; i < 7; i++)
	{
		setA.add(i);
		setB.add(10 - i);
	}
	cout <<"setA:";
	setA.output2();
	cout <<"setB:";
	setB.output2();
	uset.copy(setA);
	uset.Union(setB);
	cout <<"uset is the Union Set of setA and setB:\n";
	uset.output2();
	iset.copy(setA);
	iset.Insect(setB);
	cout <<"iset is the Insect Set of setA and setB:\n";
	iset.output2();
	dset.copy(setA);
	dset.Diff(setB);
	cout <<"dset is the Diff Set of setA and setB:\n";
	dset.output2();
	cout <<"whether dset is the child set of setA and setB:\n";
	printf("dset is the child set of setA?\n%c\n", dset.IsChildOf(setA) == true ? 'Y' : 'N');
	printf("dset is the child set of setB?\n%c\n", dset.IsChildOf(setB) == true ? 'Y' : 'N');
	cout <<"whether setA is the super set of dset and setB:\n";
	printf("setA is the super set of dset?\n%c\n", setA.IsSuperOf(dset) == true ? 'Y' : 'N');
	printf("setA is the super set of setB?\n%c\n", setA.IsSuperOf(setB) == true ? 'Y' : 'N');


	cout <<"\nEnd"<<endl;
	return 0;
}
