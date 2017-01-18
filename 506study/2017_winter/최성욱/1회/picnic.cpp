#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string.h>//memset
#define max_friends_pair 10
namespace ÃÖ¼º¿í {

	//global variable from input info,
	//N for student number, M for pair number
	int N, M;

	//info from input, max friends pair is 10
	//{0,} means initialize after ',' with 0 (works in visual studio and etc)
	int areFriends[10][10] = { 0, };

	int countPairings(bool taken[max_friends_pair]) {
		int firstFree = -1;
		//find who is not yet matched
		for (int i = 0; i < N; i++) {
			if (taken[i] == false) {
				firstFree = i; break;
			}
		}
		//first return point, if all friends matched
		if (firstFree == -1) return 1;

		//second point, count
		int ret = 0;
		for (int pairWith = firstFree + 1; pairWith < N; pairWith++) {
			if (taken[pairWith] == false && areFriends[firstFree][pairWith]) {
				taken[firstFree] = taken[pairWith] = true;
				ret += countPairings(taken);
				taken[firstFree] = taken[pairWith] = false;
			}
		}
		return ret;
	}

	int picnic(int input=0) {
		if (input) freopen("txt/picnic.txt", "r", stdin);
		int testCase;
		scanf("%d", &testCase);
		while (testCase--) {
			scanf("%d %d", &N, &M);
			memset(areFriends, 0, sizeof(areFriends));
			int a, b;
			for (int i = 0; i < M; i++) {
				scanf("%d %d", &a, &b);
				areFriends[a][b] = areFriends[b][a] = true;
			}
			bool taken[max_friends_pair] = { 0, };
			int result = countPairings(taken);
			cout << result << endl;
		}
		return 0;
	}
}