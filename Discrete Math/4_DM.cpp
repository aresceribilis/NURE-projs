#include <iostream>
#include <iomanip>

int* Dijkstra(int** graph, int dimension, int edge);

int main() {
	int** graph, dimension = 9;
	graph = new int* [dimension];
	for (int i = 0; i < dimension; i++)
		graph[i] = new int[dimension];

	int data[] = {
	 0, 7, 0, 5, 7, 0, 0, 0, 0,
	 0, 0, 1, 0, 5, 8, 0, 0, 0,
	 0, 0, 0, 0, 0, 3, 0, 0, 0,
	 0, 1, 0, 0, 0, 0, 3, 8, 0,
	 0, 0, 1, 1, 0, 2, 0, 5, 9,
	 0, 0, 0, 0, 0, 0, 0, 2, 3,
	 0, 0, 0, 0, 0, 1, 0, 2, 0,
	 0, 0, 0, 0, 0, 0, 0, 0, 3,
	 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	for (int i = 0, k = 0; i < dimension; ++i)
		for (int j = 0; j < dimension; ++j, ++k) graph[i][j] = data[k];

	int** distance = new int*[dimension];
	for (int i = 0; i < dimension; ++i)
		distance[i] = Dijkstra(graph, dimension, i);

	for (int i = 0; i < dimension; i++, std::cout << "\n") {
		std::cout << "Distance beetween the point x" << i + 1 << " and the others:\n\n";
		for (int j = 0; j < dimension; j++)
			if (distance[i][j] != INT_MAX)
				std::cout << "x" << i + 1 << " -> x" << j + 1 << " = " << distance[i][j] << "\n";
			else std::cout << "x" << i + 1 << " -> x" << j + 1 << " = inf\n";
	}
	return 0;
}

int* Dijkstra(int** graph, int dimension, int edge) {
	int* distance = new int[dimension];
	bool* visited = new bool[dimension];

	for (int i = 0; i < dimension; ++i) {
		distance[i] = INT_MAX;
		visited[i] = false;
	}
	distance[edge] = 0;

	for (int count = 0, index, min = INT_MAX; count < dimension - 1; ++count, min = INT_MAX) {
		for (int i = 0; i < dimension; ++i)
			if (!visited[i] && distance[i] <= min) {
				min = distance[i];
				index = i;
			}
		visited[index] = true;
		for (int i = 0; i < dimension; ++i)
			if (!visited[i] && graph[index][i] && distance[index] != INT_MAX && distance[index] + graph[index][i] < distance[i])
				distance[i] = distance[index] + graph[index][i];
	}
	return distance;
}
