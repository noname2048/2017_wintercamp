#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

namespace 최성욱 {
	int btn[10][6] = {
		{ 3, 0, 1, 2,-1,-1},//0
		{ 4, 3, 7, 9,11,-1},//1
		{ 4, 4,10,14,15,-1},//2
		{ 5, 0, 4, 5, 6, 7},//3
		{ 5, 6, 7, 8,10,12},//4
		{ 4, 0, 2,14,15,-1},//5
		{ 3, 3,14,15,-1,-1},//6
		{ 5, 4, 5, 7,14,15},//7
		{ 5, 1, 2, 3, 4, 5},//8
		{ 5, 3, 4, 5, 9,13} //9
	};
	int myClock[16];
	int minTabNum = 100;

	int search(int btnIndex, int globalTab) {
		if (btnIndex >= 10) return 0;

		for (int tab = 0; tab < 4; tab++) {

			//한번 누른다.
			if (tab)
				for (int j = 0; j < btn[btnIndex][0]; j++) {
					int clockNum = btn[btnIndex][1 + j];
					myClock[clockNum] = (myClock[clockNum] + 3 * tab) % 12;
				}

			//확인하는 부분
			bool allAlignWith16 = true;
			for (int j = 0; j < 16; j++) {
				if (myClock[j] != 0) {
					allAlignWith16 = false;
					break;
				}
			}
			if (allAlignWith16 && minTabNum > (globalTab + tab)) minTabNum = (globalTab + tab);

			//재귀검색
			search(btnIndex + 1, globalTab + tab);

			//되돌린다.
			if (tab)
				for (int j = 0; j < btn[btnIndex][0]; j++) {
					int clockNum = btn[btnIndex][1 + j];
					myClock[clockNum] = (myClock[clockNum] + 9 * tab) % 12;
				}
		}
		return 0;
	}

	int search2(int btnIndex, int globalTab) {
		if (btnIndex >= 10) return 0;

		for (int tab = 0; tab < 4; tab++) {

			//확인하는 부분
			bool allAlignWith16 = true;
			for (int j = 0; j < 16; j++) {
				if (myClock[j] != 0) {
					allAlignWith16 = false;
					break;
				}
			}
			if (allAlignWith16 && minTabNum > (globalTab + tab)) minTabNum = (globalTab + tab);

			//재귀검색
			search2(btnIndex + 1, globalTab + tab);

			//한번 누른다.
			for (int j = 0; j < btn[btnIndex][0]; j++) {
				int clockNum = btn[btnIndex][1 + j];
				myClock[clockNum] = (myClock[clockNum] + 3) % 12;
			}
		}
		return 0;
	}

	int CLOCKSYNC(int input = 0) {
		if (input) freopen("txt/CLOCKSYNC.txt", "r", stdin);
		int testCase; cin >> testCase;
		while (testCase--) {
			minTabNum = 100;
			for (int i = 0; i < 16; i++) {
				cin >> myClock[i];
				if (myClock[i] == 12) myClock[i] = 0;
			}
			//search(0, 0); cout << "1:" << minTabNum << endl;
			//minTabNum = 100;
			search2(0, 0); //cout << "2:" << minTabNum << endl;
			//minTabNum = 100;
			if (minTabNum == 100) cout << -1 << endl;
			else cout << minTabNum << endl;
		}
		return 0;
	}
}