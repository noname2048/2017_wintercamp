// https://algospot.com/judge/problem/read/QUADTREE
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

namespace ³ë¿äÇÑ {

	struct tree
	{
		char node;
		tree *one, *two, *three, *four;
	};
	typedef tree* treePtr;

	int index;

	treePtr makeTree(string str, treePtr sol)
	{
		int child = 0;

		if (str[index] == 'x') {
			sol->one = new tree();
			sol->two = new tree();
			sol->three = new tree();
			sol->four = new tree();
			index++;
			sol->one = makeTree(str, sol->one);
			index++;
			sol->two = makeTree(str, sol->two);
			index++;
			sol->three = makeTree(str, sol->three);
			index++;
			sol->four = makeTree(str, sol->four);
		}
		else {
			sol->node = str[index];
			sol->one = NULL;
			sol->two = NULL;
			sol->three = NULL;
			sol->four = NULL;
		}
		return sol;
	}

	void readTree(treePtr sol)
	{
		if (sol->one != NULL) {
			cout << "x";
			readTree(sol->three);
			readTree(sol->four);
			readTree(sol->one);
			readTree(sol->two);
		}
		else {
			cout << sol->node;
		}
	}

	int main()
	{
		ios::sync_with_stdio(false);
		int testCase;
		cin >> testCase;
		string input;

		while (testCase--)
		{
			treePtr solution;
			solution = new tree();
			cin >> input;
			index = 0;

			solution = makeTree(input, solution);
			readTree(solution);
			cout << endl;
		}
		//system("pause");
		return 0;
	}

}