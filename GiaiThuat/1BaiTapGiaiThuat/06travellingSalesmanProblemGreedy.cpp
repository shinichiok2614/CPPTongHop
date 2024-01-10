#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
#define col 4
struct Result {
	vector<int> min_path;
	vector<vector<int>> tour;
	vector<int> cost;
};
Result travellingSalesmanProblem(int graph[][col], int s)
{
	Result result;
	vector<int> vertex;
	for (int i = 0; i < col; i++)
		if (i != s) vertex.push_back(i);
	int min_path = INT_MAX;
	do {
		int current_pathweight = 0;
		int k = s; //k la row
		for (int i = 0; i < vertex.size(); i++) {
			current_pathweight += graph[k][vertex[i]];
			k = vertex[i];	//di chuyen row hien tai sang col vua moi xet
		}
		current_pathweight += graph[k][s];
		min_path = min(min_path, current_pathweight);
		result.min_path.push_back(min_path);
		result.tour.push_back(vertex);
		result.cost.push_back(current_pathweight);
	} while (next_permutation(vertex.begin(), vertex.end()));//duyet tat ca cac duong di theo thu tu tu dien
	return result;
}
int main()
{
	int graph[][col] = {
		{ 0, 10, 15, 20 },
		{ 10, 0, 35, 25 },
		{ 15, 35, 0, 30 },
		{ 20, 25, 30, 0 }
	};
	int s = 0;
	//cout << travellingSalesmanProblem(graph, s) << endl;
	Result result= travellingSalesmanProblem(graph, s);
	return 0;
}
