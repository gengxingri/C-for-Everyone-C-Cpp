/* 
  Simple STL vector program

  Output of a random graph
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

double prob()
{
   return (static_cast<double>(rand()/RAND_MAX));
}



int main(void)
{
	int size = 15;
	double density;

	cout << "Graph size?" << endl;
	cin >> size;

	cout << "Graph density (0, 1)?" << endl;
	cin >> density;

	bool** graph;
	int** colour;
	int** cost;

	srand(time(0)); //seed random number generate

	graph = new bool*[size];
	colour = new int*[size];
	cost = new int*[size];

	// generate undirected graph
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			if ( i == j)
				graph[i][j] = false;
			else
			 graph[i][j] = graph[j][i] = (prob() < density);
			
		}
	}
  
  // generate cost and colour
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			if (graph[i][j]){
				colour[i][j] = colour[j][i] = rand()%3;
				cost[i][j] = cost[j][i] = prob()*30;
			}
		}
	}

// oupput

  ofstream outp("graph_data.txt");
  outp << size <<"\n";
  for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j)
			if (graph[i][j])
				outp << i << '\t' << j << '\t' << cost[i][j]
			       << '\t' << colour[i][j] << '\t';
	}

}
