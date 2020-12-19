// Exercise on TSP
#include <iostream>
#include <vector>
#include <cstdint>
#include <climits>
#include <algorithm>
#include <fstream>
using namespace std;
#define Cities 5
float solution(float graph[][Cities], int start)
{
	ofstream printer;
	printer.open("output.txt");

	vector<int> vertex;
	int path[Cities], temp[Cities];
	for (int i = 0; i < Cities; i++)
		if (i != start)
			vertex.push_back(i);
	float min_path = INT_MAX;
	do {
		float current_pathweight = 0;

		int k = start;
		cout << k + 1 << " to ";
		for (int i = 0; i < vertex.size(); i++) {

			current_pathweight += graph[k][vertex[i]];
			k = vertex[i];
			temp[i] = k;
		}
		current_pathweight += graph[k][start];
		for (int i = 0; i < Cities - 1; i++)
		{
			if (i == Cities - 2)
			{
				cout << temp[i] + 1 << endl;
				printer << temp[i] + 1 << endl;
			}
			else
			{
				cout << temp[i] + 1 << " to ";
				printer << temp[i] + 1 << " to ";
			}
		}
		cout << "This path Costs - " << current_pathweight << endl;
		printer << "This path Costs - " << current_pathweight << endl;
		min_path = min(min_path, current_pathweight);
		if (min_path == current_pathweight)
		{
			for (int i = 0; i < Cities - 1; i++)
			{
				path[i] = temp[i];
			}
		}

	} while (next_permutation(vertex.begin(), vertex.end()));
	cout << start + 1 << " to ";
	for (int i = 0; i < Cities - 1; i++)
	{
		if (i == Cities - 2)
		{
			cout << path[i] + 1 << " to " << start + 1 << endl;
			printer << path[i] + 1 << " to " << start + 1 << endl;
		}
		else
		{
			cout << path[i] + 1 << " to ";
			printer << path[i] + 1 << " to ";
		}
	}
	printer << "Final Solution = " << min_path << " Miles, which costs " << 40 * min_path << " gallons" << endl;
	printer.close();
	return min_path;
}
int main()
{
	// Adjacency Matrix w/ Wt in miles
// 1 = Reno  2 = Salt Lake City  3 = Seattle  4 = Denver  5 = Yellowstone Ntnl. Park
	float graph[][Cities] = { 
		{ 0, 518, 702, 1030, 719 },
		{ 518, 0, 829, 518, 321 },
		{ 702, 829, 0, 1303, 739 },
		{ 1030, 518, 1303, 0, 543  },
		{ 719, 321, 739, 543, 0   } };
	int start = 1; //Starting from Reno
	float sol = solution(graph, start);
	cout << "Final Solution = " << sol << endl;
		return 0;
}
