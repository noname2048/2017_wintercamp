#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cstring>
#include<cmath>
#include<vector>
namespace 최성욱 {
	int 세개의소수(int input = 0) {
		if (input) freopen("txt/세개의소수.txt", "r", stdin);

		bool sosu[1001]; memset(sosu, true, sizeof(sosu));
		sosu[0] = sosu[1] = false;
		//벡터 형태의 변수에 소수만 압축해서 저장하기
		vector<int> sosuOpt; sosuOpt.clear();

		int sqrtN = (int)ceil(sqrt(1000));
		//for if for 형식의 소수 찾기
		for (int i = 2; i <= 1000; i++) {
			//만일 소수이면 벡터에 집어 넣습니다
			if (sosu[i]) sosuOpt.push_back(i);
			else continue;
			//소수의 배수는 소수가 아닙니다
			for (int j = 2; i*j <= 1000; j++) {
				sosu[i*j] = false;
			}
		}

		int testCase; cin >> testCase;
		while (testCase--) {
			bool find = false;
			int k; cin >> k;
			//낮은 순서로 정렬 되기 때문에 첫번째 숫자가 결정되면,
			//나머지 숫자는 무조건 현재 숫자보다 커야하므로
			//현재숫자 - 1번숫자 >= 1번숫자 
			//현재숫자 - (1번숫자 +2번숫자) >= 2번숫자 를 만족할 때까지만
			//계산하면 계산식을 크게 줄일 수 있습니다.

			//for문의 조건식에 find가 참 거짓을 판별 하고 있음을 확인하고,
			//find가 참이 되면 모든 for문을 빠져나가 제일 빠른 한개의 조합만을 
			//출력하는걸 참고하시기 바랍니다.

			//1번 고르기
			for (int i = 0; i < sosuOpt.size() && (k - sosuOpt[i] >= sosuOpt[i]) && !find; i++) {
				//2번고르기
				for (int j = i; j < sosuOpt.size() && (k - sosuOpt[i] - sosuOpt[j] >= sosuOpt[j] && !find); j++) {
					//3번은 소수인지만 확인하면 됨
					if (sosu[k - sosuOpt[i] - sosuOpt[j]]) {
						find = true;
						cout << sosuOpt[i] << " " << sosuOpt[j] << " " << k - sosuOpt[i] - sosuOpt[j] << endl;
					}
				}
			}
			if (!find) cout << 0 << endl;
		}
		return 0;
	}
}