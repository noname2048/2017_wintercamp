#include<iostream>
using namespace std;

namespace ±è°æ³â {
	int feb_6_CLOCKSYNC() {
		int testNum, count, min;
		cin >> testNum;
		for (int i = 0; i < testNum; i++) {
			count = -1;
			min = 100;
			int arr[16], temp[16];
			for (int j = 0; j < 16; j++)
				cin >> arr[j];

			for (int a = 0; a < 4; a++) {
				for (int b = 0; b < 4; b++) {
					for (int c = 0; c < 4; c++) {
						for (int d = 0; d < 4; d++) {
							for (int e = 0; e < 4; e++) {
								for (int f = 0; f < 4; f++) {
									for (int g = 0; g < 4; g++) {
										for (int h = 0; h < 4; h++) {
											for (int o = 0; o < 4; o++) {
												for (int p = 0; p < 4; p++) {
													temp[0] = (arr[0] + 3 * (a + d + f)) % 12;			if (temp[0] == 0) temp[0] = 12;
													temp[1] = (arr[1] + 3 * (a + o)) % 12;				if (temp[1] == 0) temp[1] = 12;
													temp[2] = (arr[2] + 3 * (a + f + o)) % 12;			if (temp[2] == 0) temp[2] = 12;
													temp[3] = (arr[3] + 3 * (b + g + o + p)) % 12;		if (temp[3] == 0) temp[3] = 12;
													temp[4] = (arr[4] + 3 * (c + d + h + o + p)) % 12;	if (temp[4] == 0) temp[4] = 12;
													temp[5] = (arr[5] + 3 * (d + h + o + p)) % 12;		if (temp[5] == 0) temp[5] = 12;
													temp[6] = (arr[6] + 3 * (d + e)) % 12;				if (temp[6] == 0) temp[6] = 12;
													temp[7] = (arr[7] + 3 * (b + d + e + h)) % 12;		if (temp[7] == 0) temp[7] = 12;
													temp[8] = (arr[8] + 3 * e) % 12;					if (temp[8] == 0) temp[8] = 12;
													temp[9] = (arr[9] + 3 * (b + p)) % 12;				if (temp[9] == 0) temp[9] = 12;
													temp[10] = (arr[10] + 3 * (c + e)) % 12;			if (temp[10] == 0) temp[10] = 12;
													temp[11] = (arr[11] + 3 * b) % 12;					if (temp[11] == 0) temp[11] = 12;
													temp[12] = (arr[12] + 3 * e) % 12;					if (temp[12] == 0) temp[12] = 12;
													temp[13] = (arr[13] + 3 * p) % 12;					if (temp[13] == 0) temp[13] = 12;
													temp[14] = (arr[14] + 3 * (c + f + g + h)) % 12;	if (temp[14] == 0) temp[14] = 12;
													temp[15] = (arr[15] + 3 * (c + f + g + h)) % 12;	if (temp[15] == 0) temp[15] = 12;

													if (temp[0] == 12 && temp[1] == 12 && temp[2] == 12 && temp[3] == 12 && temp[4] == 12 && temp[5] == 12 && temp[6] == 12 && temp[7] == 12
														&& temp[8] == 12 && temp[9] == 12 && temp[10] == 12 && temp[11] == 12 && temp[12] == 12 && temp[13] == 12 && temp[14] == 12 && temp[15] == 12)
														count = a + b + c + d + e + f + g + h + o + p;
													if (count > 0 && count < min)
														min = count;
												}}}}}}}}}
			}
			if (count != -1)
				cout << min << endl;
			else
				cout << count << endl;
		}
		return 0;
	}
}
