#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void counting_sort(vector<int>&us_array, vector<int>&s_array)
{
	int max= *max_element(us_array.begin(), us_array.end());
	vector<int>c(max + 1);
	int n = us_array.size();

	for(int i = 0; i < n; ++i)
	{
		++c[us_array[i]];
	}
	for(int j = 1;j <= max; ++j)
	{
		c[j] = c[j] + c[j - 1];
	}
	for(int i = n - 1; i >= 0; --i)// 只有从后面开始循环才能保证相同的值维持原先在数组中的顺序
	{
		s_array[--c[us_array[i]]] = us_array[i];
		
	}
}

int main()
{
	vector<int> us_array{1, 4, 5, 2, 1, 4, 5, 6, 7, 2, 4, 5, 6, 3, 0, 19, 18, 201};
	int n = us_array.size();
	vector<int>s_array(n);
	counting_sort(us_array, s_array);
	for(int i : us_array)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	for(int i : s_array) 
	{
		cout<<i<<" ";
	}
}