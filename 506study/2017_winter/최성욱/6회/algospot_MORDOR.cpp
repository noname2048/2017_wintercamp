#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

namespace 최성욱 {
	int totalPlateNum; //1..100,000
	int totalLoadNum; //1..10,000
	int plateHeightInfo[100000];
	int loadInfo[10000][2];

	class RMQ {
		/* range ( minimum | maximum ) query 구현 */
		/* 구간트리 : 구간에서 최소값, 최대값을 logN 복잡도로 검색할 수 있게 해주는 이진트리 (자료구조) */
	public:
		int *plateReference;
		int plateAmount;

		vector<int> rangeMin;
		vector<int> rangeMax;

		const int MY_INT_MIN = -1;
		const int MY_INT_MAX = numeric_limits<int>::max();

		RMQ(int *arr, int arrLength) {
			plateReference = arr;
			plateAmount = arrLength;

			rangeMin.resize(plateAmount * 4);
			rangeMax.resize(plateAmount * 4);

			initMin(0, 0, arrLength - 1);
			initMax(0, 0, arrLength - 1);
		}

		int initMin(int left, int node, int right) {
			if (left == right) return rangeMin[node] = *(plateReference + left);

			int mid = (left + right) / 2;
			int leftMin = initMin(left, node * 2 + 1, mid);
			int rightMin = initMin(mid + 1, node * 2 + 2, right);

			return rangeMin[node] = min(leftMin, rightMin);
		}

		int initMax(int left, int node, int right) {
			if (left == right) return rangeMax[node] = *(plateReference + left);

			int mid = (left + right) / 2;
			int leftMax = initMax(left, node * 2 + 1, mid);
			int rightMax = initMax(mid + 1, node * 2 + 2, right);

			return rangeMax[node] = max(leftMax, rightMax);
		}

		int minQuery(int left, int nodeLeft, int node, int nodeRight, int right) {
			if (nodeRight < left || right < nodeLeft) return MY_INT_MAX;

			if (left <= nodeLeft && nodeRight <= right) return rangeMin[node];

			int nodeMid = (nodeLeft + nodeRight) / 2;
			int nodeMin = min(
				minQuery(left, nodeLeft, node * 2 + 1, nodeMid, right),
				minQuery(left, nodeMid + 1, node * 2 + 2, nodeRight, right)
			);
			return nodeMin;
		}

		int maxQuery(int left, int nodeLeft, int node, int nodeRight, int right) {
			if (nodeRight < left || right < nodeLeft) return MY_INT_MIN;

			if (left <= nodeLeft && nodeRight <= right) return rangeMax[node];

			int nodeMid = (nodeLeft + nodeRight) / 2;
			int nodeMax = max(
				maxQuery(left, nodeLeft, node * 2 + 1, nodeMid, right),
				maxQuery(left, nodeMid + 1, node * 2 + 2, nodeRight, right)
			);
			return nodeMax;
		}

		int minQuery(int left, int right) {
			return minQuery(left, 0, 0, plateAmount - 1, right);
		}

		int maxQuery(int left, int right) {
			return maxQuery(left, 0, 0, plateAmount - 1, right);
		}

		int update(int index, int newValue) {
			updateMinQuery(index, newValue, 0, 0, plateAmount - 1);
			updateMaxQuery(index, newValue, 0, 0, plateAmount - 1);
		}
		int updateMinQuery(int index, int newValue, int nodeLeft, int node, int nodeRight) {
			if (index < nodeLeft || nodeRight < index) return rangeMin[node];

			if (nodeLeft == nodeRight) return rangeMin[node] = newValue;

			int nodeMid = (nodeLeft + nodeRight) / 2;
			int nodeMin = min(
				updateMinQuery(index, newValue, nodeLeft, node * 2 + 1, nodeRight),
				updateMinQuery(index, newValue, nodeLeft, node * 2 + 2, nodeRight)
			);

			return nodeMin;
		}
		int updateMaxQuery(int index, int newValue, int nodeLeft, int node, int nodeRight) {
			if (index < nodeLeft || nodeRight < index) return rangeMax[node];

			if (nodeLeft == nodeRight) return rangeMax[node] = newValue;

			int nodeMid = (nodeLeft + nodeRight) / 2;
			int nodeMax = max(
				updateMaxQuery(index, newValue, nodeLeft, node * 2 + 1, nodeRight),
				updateMaxQuery(index, newValue, nodeLeft, node * 2 + 2, nodeRight)
			);

			return nodeMax;
		}

		int diff(int start, int end) {
			return maxQuery(start, end) - minQuery(start, end);
		}
	};

	int MORDOR(int input = 0) {
		if (input) freopen("txt/MORDOR.txt", "r", stdin);
		int testCase; cin >> testCase;
		while (testCase--) {
			cin >> totalPlateNum >> totalLoadNum;

			for (int i = 0; i < totalPlateNum; i++) {
				cin >> plateHeightInfo[i];
			}
			RMQ mordor(plateHeightInfo, totalPlateNum);

			for (int i = 0; i < totalLoadNum; i++) {
				cin >> loadInfo[i][0] >> loadInfo[i][1];
				cout << mordor.diff(loadInfo[i][0], loadInfo[i][1]) << endl;
			}

		}
		return 0;
	}
}