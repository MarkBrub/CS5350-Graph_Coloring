#include <functional>
#include "Graph.hpp"

void RunWithTimings(const int x) {
	Graph graph;

	std::cout << "Establish:         " << TimeClass(&graph, &Graph::Establish, x) << "ms" << std::endl;
	std::cout << "Distribution:      " << TimeClass(&graph, &Graph::CreateModifiedNormalDistribution, x * 200) << "ms" << std::endl;
	std::cout << "Order:             " << TimeClass(&graph, &Graph::SmallestLastVertexOrder, nullptr) << "ms" << std::endl;
	std::cout << "Color Graph:       " << TimeClass(&graph, &Graph::ColorGraph, nullptr) << "ms" << std::endl;
	std::cout << "Colors used:       " << graph.maxColor << std::endl;
}

int main(int argc, char* argv[]) {
	const int size = 1000;

	Graph graph;
	graph.Establish(size);
	graph.CreateModifiedNormalDistribution(size * 200);
	graph.SmallestLastVertexOrder();
	graph.ColorGraph();
	graph.Print();

	std::cout << "Colors used: " << graph.maxColor << std::endl;

	return 0;
}