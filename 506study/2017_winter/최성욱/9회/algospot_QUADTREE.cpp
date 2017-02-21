#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<cassert>
#include<cstdio>
namespace �ּ��� {
	/** ���� Ʈ�� Ŭ����, �����Ҷ� '�����͹迭' �� '���絥������ġ'
		�� �޾� 4���� �ڽ����ε� Ʈ���� �����
		�ڽ��� ���� ����Ʈ�� Ŭ�����̴�
		�߿��� �����δ� '���࿩��','�ڽ�'�� �ִ�
	**/
	class QuadTree {
	public:
		QuadTree(const string &data, short &index) {
			blockType = 'n';	//���� �ʱ�ȭ
			for (int i = 0; i < 4; i++) child[i] = nullptr;	//�ڽ��������� �ʱ�ȭ
			assert(index < data.length());

			//�����͸� �Է� �ް�, ����� �������� �ڽ��� �����Ѵ�
			blockType = data[index];
			if (data[index] == 'x') {
				blockType = data[index];
				for (int i = 0; i < 4; i++) child[i] = new QuadTree(data, ++index);
			}
		}

		//Ŭ������ ��� ������, 
		char blockType;
		QuadTree *child[4];

		//���Ϲ����� ��Ű�� �Լ�
		void verticalReflect() {
			if (blockType != 'x') return;	//������� �ʾ����� ���Ϲ����� �� �ʿ䰡 ����
			QuadTree *temp[2] = { child[0], child[1] };
			child[0] = child[2];
			child[1] = child[3];
			child[2] = temp[0];
			child[3] = temp[1];
			for (int i = 0; i < 4; i++) child[i]->verticalReflect();
		}

		//Ʈ���� ���ٷ� ����ϴ� �Լ�. ������ ���ԵǾ����� �ʴ�
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