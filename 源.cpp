#include<vector>
#include<iostream>
#include<fstream>
#include <string>
using namespace std;
typedef pair<vector<vector<int>>, int> DTmaze;
vector<DTmaze> mazesolve;
bool mazeJudge(vector<vector<int>> &maze, int x, int y)
{
	if (x > maze.size() - 1 || y > maze[0].size() - 1 || x < 0 || y < 0)
		return false;
	int temp = maze[x][y];
	if (temp == 1)
		return false;
	if (temp == 2)
		return false;
	if (temp == 0)
		return true;
}
void mazeDetect(vector<vector<int>> maze, int x, int y,int n)
{
	if (x == maze.size() - 1 && y == maze[0].size() - 1)
	{
		maze[x][y] = 2;
		DTmaze temp(maze, n);
		mazesolve.push_back(temp);
	}
	if (mazeJudge(maze, x - 1, y))
	{
		maze[x - 1][y] = 2;
		mazeDetect(maze, x - 1, y,n+1); 
		maze[x - 1][y] = 0;
	}
	 if (mazeJudge(maze, x, y + 1))
	{
		 maze[x ][y+1] = 2;
		 mazeDetect(maze, x , y+1, n + 1);
		 maze[x][y + 1] = 0;
	}
	 if (mazeJudge(maze, x, y - 1))
	 {
		 maze[x][y - 1] = 2;
		 mazeDetect(maze, x, y - 1, n + 1);
		 maze[x][y - 1] = 0;
	 }
	if (mazeJudge(maze, x + 1, y))
	{
		maze[x + 1][y] = 2;
		mazeDetect(maze, x + 1, y, n + 1);
		maze[x + 1][y] = 0;
	}
}
int main() 
{
	string path = "C:\\Users\\61640\\Desktop\\mg2.txt";
	ifstream ift(path.c_str());
	int length, width;
	ift >> length>>width;
	vector<vector<int>> maze;
	for (int i = 0; i < length; i++)
	{
		vector<int> temp_vec(width);
		maze.push_back(temp_vec);
		for (int j = 0; j < width; j++)
		{
			int temp_int;
			ift >> maze[i][j];
		}
	}
	maze[0][0]=2;
	mazeDetect(maze, 0, 0,0);
	int minnum = mazesolve[0].second;
	int number = 0;
	for (int i = 0; i < mazesolve.size(); ++i)
	{
		if (mazesolve[i].second < minnum)
			number = i;
	}
	maze = mazesolve[number].first;
	for (auto &i : maze)
	{
		for (int &j : i)
		{
			if (j == 3)
				j = 0;
			cout << j << " ";
		}
		cout << endl;
	}
	system("pause");
}