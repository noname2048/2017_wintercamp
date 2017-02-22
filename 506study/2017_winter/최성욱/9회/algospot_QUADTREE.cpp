#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<cassert>
#include<cstdio>
namespace 최성욱 {
	/** 쿼드 트리 클래스, 생성할때 '데이터배열' 과 '현재데이터위치'
		를 받아 4개의 자식으로된 트리를 만든다
		자식은 역시 쿼드트리 클래스이다
		중요한 정보로는 '압축여부','자식'이 있다
	**/
	class QuadTree {
	public:
		QuadTree(const string &data, short &index) {
			blockType = 'n';	//블럭의 초기화
			for (int i = 0; i < 4; i++) child[i] = nullptr;	//자식포인터의 초기화
			assert(index < data.length());

			//데이터를 입력 받고, 재귀형 문법으로 자식을 생성한다
			blockType = data[index];
			if (data[index] == 'x') {
				blockType = data[index];
				for (int i = 0; i < 4; i++) child[i] = new QuadTree(data, ++index);
			}
		}

		//클래스의 멤버 변수들, 
		char blockType;
		QuadTree *child[4];

		//상하반전을 시키는 함수
		void verticalReflect() {
			if (blockType != 'x') return;	//압축되지 않았으면 상하반전을 할 필요가 없다
			QuadTree *temp[2] = { child[0], child[1] };
			child[0] = child[2];
			child[1] = child[3];
			child[2] = temp[0];
			child[3] = temp[1];
			for (int i = 0; i < 4; i++) child[i]->verticalReflect();
		}

		//트리를 한줄로 출력하는 함수. 개행은 포함되어있지 않다
		void printTree() {
			cout << blockType;
			if (blockType == 'x')
				for (int i = 0; i < 4; i++) child[i]->printTree();
		}
	};
	int QUADTREE(int input = 0) {
		if(input) freopen("txt/QUADTREE.txt", "r", stdin);
		ios::sync_with_stdio(false);
		int testCase; cin >> testCase;
		while (testCase--) {
			short indx = 0;
			string inData; cin >> inData;
			QuadTree solve(inData, indx);
			solve.verticalReflect();
			solve.printTree(); cout << endl;
		}
		return 0;
	}
}