#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> object; // store the size of all the objects
	vector<int> box; // store the size of all the boxes
	vector<bool> visited; // see whether object has been visited (added to the box)
	vector<bool> throwout; // see whether object has been thrown away
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		object.push_back(temp);
		visited.push_back(false);
		throwout.push_back(false);
	} 
	for (int i = 0; i < m; i++) {
		box.push_back(k);
	} // load data


	int i = 0; // index for the remaining size of ith box
	int j = 0; // index for the size of jth object
	int k0 = k; // store the initial value for the size of the box
	int cnt = 0; // store the number of objects stored in all of the boxes
	int idx = 0; // store the index of thrown-away objects
	int cntVisited = 0; // count number of visited
	while (cntVisited < n && idx <= object.size() - 1) {
		if (box[i] - object[j] >= 0 && visited[j] == false && throwout[j] == false) {
			box[i] -= object[j];
			cnt++;
			visited[i] = true;
			cntVisited++;
		} // if jth object can fit into ith box
		// then just fit into it and decrase the size by object[j]
		else if (i < m - 1){
			// if jth object cannot fit into ith box
			// then use the next box if possible
			i++;
			if (box[i] - object[j] >= 0 && visited[j] == false && throwout[j] == false) {
				box[i] -= object[j];
				cnt++;
				visited[i] = true;
				cntVisited++;
			}
		}
		else {
			// if jth object cannot fit into ith box
			// and we are running out of boxes,
			// we would clear out the leftmost box 
			// and throw away the leftmost object in the set 
			box.front() = k0;
			throwout[idx] = true;
			cnt--;
			idx++;
			j = 0;
		}
		j++;

		cout << "----------------------" << endl;
		for (int i = 0; i < box.size(); i++) {
			cout << box[i] << ' ';
		}
		cout << j << endl;
		cout << "----------------------" << endl;
	}
	cout << cnt << endl;
	return 0;
}