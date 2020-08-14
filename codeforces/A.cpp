#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

void customSort(int arr1[], int arr2[], int m, int n)
{
	// map to store frequency of each element of first array
	unordered_map<int, int> freq;

	// freq frequency of each element of first array and
	// store it in a map.
	for (int i = 0; i < m; i++)
		freq[arr1[i]]++;

	// Note that once we have the frequencies of all elements of
	// first array, we can overwrite elements of first array

	int index = 0;

	// do for every element of second array
	for (int i = 0; i < n; i++)
	{
		// If current element is present in the map, print it n times
		// where n is the frequency of that element in first array
		while (freq[arr2[i]])
		{
			arr1[index++] = arr2[i];
			freq[arr2[i]]--;
		}
		// erase the element from map
		freq.erase(arr2[i]);
	}

	// Now we are only left with elements that are only present
	// in the first array but not present in the second array
	// We need to sort the remaining elements present in the map
	// Note - If use std::map, keys already sorted
	int i = index;
	for (auto it = freq.begin(); it != freq.end(); ++it)
		while (it->second--)
			arr1[index++] = (it->first);

	// sort the remaining elements
	sort(arr1 + i, arr1 + index);
}

int main()
{
	string s;
	cin>>s;
	int arr1[s.size()];
	for(int i=0;i<s.size();i++)
		arr1[i] = int(s[i])-97;
	int arr2[] = {38 ,13 ,24 ,14 ,11 ,5 ,3 ,24 ,17 ,0};

	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	customSort(arr1, arr2, m, n);

	cout << "After sorting the array is : ";
	for (int i = 0; i < m; i++)
		cout << (char)(arr1[i]+97) << " ";
	cout << endl;

	return 0;
}
