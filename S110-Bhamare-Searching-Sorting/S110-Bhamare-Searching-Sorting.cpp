// S110-Bhamare-Searching-Sorting.cpp 
//Author: P.Bhamare
//Goal:  Compare performance of sequential versus binary search

#include <iostream>
#include <vector>
using namespace std;

//Prototype
int sequentialSearch(vector <int>v, int key);
void showVector(vector<int> v);
int binarySearch(vector <int> v, int key);
void bubbleSort(vector<int> &v);
void experiment01();
void experiment02();
int main()
{
	
	//experiment01();
	experiment02();


}
void experiment01() {
	vector<int> v{ 2, 3, 6, 8, 9, 11, 14, 16, 20, 40, 51, 52, 60 };
	showVector(v);
	int pos;
	int key = 51;

	pos = sequentialSearch(v, key);
	cout << "SEQ-Key: " << key << " found at position: " << pos << endl;

	pos = binarySearch(v, key);
	cout << "BIN-Key: " << key << " found at position: " << pos << endl;
}
void experiment02() {
	vector <int>v{ 11,22,33,44,55,66,77,88};
	bubbleSort(v);
	cout << "Sorted Vector\n";
	showVector(v);
}
int sequentialSearch(vector <int>v, int key) {

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == key)
			return i;
	}
	return -1;
}

void showVector(vector<int> v) {
	cout << "\nVector v\n";
	for (int i = 0; i < v.size(); i++) {
		cout <<i << ":" << v[i] << ", ";
	}
	cout << endl;
}
int binarySearch(vector <int> v, int key) {
	int first = 0;
	int last = v.size() - 1;
	bool found =false;
	int position = -1;
	int middle;
	while (first <= last ) {
		 middle = (first + last) / 2;

		if (v[middle] == key) {
			
			return middle;
		}
		else if (v[middle] > key)
			last = middle - 1;
		else
			first = middle + 1;

	}
	return -1;
}
void bubbleSort(vector<int>& v) {
	int timesAround = 0;
	bool pairWasExchanged = true;

	for (int right = v.size() - 1; pairWasExchanged && right > 0; right--) {
		pairWasExchanged = false;
		for (int left = 0; left < right; left++) {
			timesAround++;
			if (v[left] > v[left + 1]) {
				int temp = v[left];
				v[left] = v[left+1];
				v[left + 1] = temp;
				pairWasExchanged = true;
			}
		}
	}
	cout << "\nDEBUG - Times Around: " << timesAround << endl;
}