#include <iostream>
#include <random>

#include "dijkstra.hpp"

using namespace std;

int main() {
  // Load the Florida graph.
  Graph graph;
  graph.ReadDIMACS("florida.gr");

  // Initialize the random number generator.
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(0, graph.NumNodes() - 1);

  // Run Dijkstra's algorithm for 200 randomly selected source-destination pairs.
  int total_runtime = 0;
  for (int i = 0; i < 200; i++) {
    int source = dis(gen);
    int destination = dis(gen);

    // Start the timer.
    auto start = chrono::high_resolution_clock::now();

    // Run Dijkstra's algorithm.
    vector<int> path;
    int distance = graph.Dijkstra(source, destination, path);

    // Stop the timer.
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> runtime = end - start;
    total_runtime += runtime.count();

    // Print the results.
    cout << "Shortest path from " << source << " to " << destination << ": ";
    for (int node : path) {
      cout << node + 1 << " ";
    }
    cout << endl;
    cout << "Shortest path length: " << distance << endl;
  }

  // Print the total runtime.
  cout << "Total runtime in seconds for 200 random Dijkstra: " << total_runtime << endl;

  return 0;
}
