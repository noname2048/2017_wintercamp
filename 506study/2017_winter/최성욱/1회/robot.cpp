#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
namespace ÃÖ¼º¿í {
	//rows for robot_dirs, cols for y,x input
	int robot_dirs[4][2] = {
		{0,1}, {1,0}, {0,-1}, {-1,0}
	};
	//no return value function
	//dirChange(dir,0) means dir to turn left
	void dirChange(int &dir, int turn) {
		//turn 0 = turn left(90 degree)
		if (!turn)
			dir = (dir + 1) % 4;
		else
			dir = (dir - 1 + 4) % 4;
	}

	int robot(int test=0) {
		if (test) {
			freopen("txt/robot.txt", "r", stdin);
		}
		//problem condition, M N
		int rectSize, nOrders;
		scanf("%d %d", &rectSize, &nOrders);

		//defines direction to enum class variable
		enum DIR { right, up, left, down };

		//initialize first dir & position
		int dir = right;
		int position[2] = { 0,0 };

		//input values
		string text; int turn, d;

		//execute for n times to evaluate robotValidation
		bool validation = true;
		for (int i = 0; i < nOrders && validation; i++) {
			cin >> text;
			if (text == "MOVE") {
				scanf("%d", &d);
				position[0] += robot_dirs[dir][0] * d;
				position[1] += robot_dirs[dir][1] * d;

				//robot is still inside region S?
				if (position[0]<0 ||
					position[0]>rectSize ||
					position[1]<0 ||
					position[1]>rectSize)
					validation = false;
			}
			else if (text == "TURN") {
				scanf("%d", &turn);
				dirChange(dir, turn);
			}
			else {
				printf("WRONG TEXT INTPUT\n");
				exit(0);
			}
		}

		if (validation)
			cout << position[1] << " " << position[0] << endl;
		else
			cout << "-1" << endl;
		return 0;
	}
}