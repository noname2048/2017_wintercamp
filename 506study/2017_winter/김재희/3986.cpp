#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

stack<char> st;
char temp[100002];

int _3986(){
	int n;
	scanf("%d", &n);
	int count = 0;
	while (n--){
		scanf("%s", temp);
		int len = strlen(temp);
		for (int i = 0; i < len; i++){
			if (st.empty())
				st.push(temp[i]);
			else{
				if (temp[i] == st.top())
					st.pop();
				else
					st.push(temp[i]);
			}
		}
		if (st.empty()) count++;
		else
			while (!st.empty())
				st.pop();
	}
	printf("%d", count);
}