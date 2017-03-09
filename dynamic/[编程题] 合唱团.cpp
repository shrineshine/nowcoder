#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <random> 
#include <cmath>  

using namespace std;

int main() {
	int n;
	cin >>n;
	int i;
	vector<int> a(n, 0);
	for (i = 0; i < n; i++){
		cin >> a[i];
	}
	int k, d;
	cin >> k;
	cin >> d;

	vector<long long> max(n);
	vector<long long> newmax(n);
	vector<long long> min(n);
	vector<long long> newmin(n);
	for (i = 0; i < n; i++){
		max[i] = a[i];
		min[i] = a[i];
	}
	int ki = 0;
	for (ki = 1; ki < k; ki++){
		for (i = 0; i < n; i++){
			if (i < ki){
				newmax[i] = 0;
				newmin[i] = 0;
				continue;
			}
			if (i == ki){
				newmax[i] = max[i-1]*a[i];
				newmin[i] = min[i-1]*a[i];
				continue;
			}
			int start = (i - d) >= 0 ? i - d : 0;
            start = (start >= ki-1) ? start : ki-1;
			int j;
			for (j = start; j < i; j++){
				if (j == start){
                    if(max[j] * a[i]>min[j] * a[i]){
                        newmax[i] = max[j] * a[i];
						newmin[i] = min[j] * a[i];
                    }
                    else{
                        newmax[i] = min[j] * a[i];
						newmin[i] = max[j] * a[i];
                    }
					
				}
				else{
					if (max[j] * a[i]>newmax[i])
						newmax[i] = max[j] * a[i];
					if (min[j] * a[i]>newmax[i])
						newmax[i] = min[j] * a[i];
					if (max[j] * a[i]<newmin[i])
						newmin[i] = max[j] * a[i];
					if (min[j] * a[i]<newmin[i])
						newmin[i] = min[j] * a[i];
				}

					
			}
				
		}
		for (i = 0; i < n; i++){
			max[i] = newmax[i];
			min[i] = newmin[i];
		}
	}
	long long returnvalue = 0;
	for (i = 0; i < n; i++){
		if (max[i]>returnvalue)
			returnvalue = max[i];
	}
	cout << returnvalue << endl;
	/*
	cout << a[0]<<a[1]<<a[2] << endl;
	cout << k << endl;
	cout << d << endl;
	*/
	

	return 0;

	
}
