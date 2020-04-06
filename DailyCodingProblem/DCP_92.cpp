/*

AUTHOR - SAGAR SHARMA

TOPIC - Topological Sort

Graph taken from - https://www.youtube.com/watch?v=eL-KzMXSXXI

*/

#include<iostream>
#include<unordered_map>
#include<vector>

void topologicalSort() {
	std::unordered_map<char, std::vector<char>> graph;
	createGraph(graph);
	if (graph.empty()) {
		return;
	}
	std::unordered_map<char,bool> visited;
	std::vector<char> vec;
	vec.reserve(graph.size());
	auto iter = graph.begin();
	while (graph.size() != visited.size()) {
		topologicalSortUtil(graph, visited, vec, iter->first);
		++iter;
	}
	auto iterVec = vec.begin();
	while (iterVec != vec.end()) {
		std::cout << *iterVec<<" ";
		++iterVec;
	}
	return;
}

void topologicalSortUtil(std::unordered_map<char, std::vector<char>>& graph, std::unordered_map<char, bool>& visited, std::vector<char>& vec, const char& character) {
	// This means that the node is already visited please do not proceed.
	if (visited[character]) {
		return;
	}
	auto iter = graph[character].begin();
	while (iter != graph[character].end()) {
		topologicalSortUtil(graph, visited, vec, *iter);
		++iter;
	}
	// insert into the vector
	vec.push_back(character);
	// set the visited to be true
	visited[character] = true;
	return;
}


void createGraph(std::unordered_map<char, std::vector<char>>& graph) {
	graph['A'] = std::vector<char>({'C','E'});
	graph['B'] = std::vector<char>({'C'});
	graph['C'] = std::vector<char>();
	graph['D'] = std::vector<char>({'A','B','E'});
	graph['E'] = std::vector<char>();
	graph['F'] = std::vector<char>({'E'});
	graph['G'] = std::vector<char>({'D'});
	graph['H'] = std::vector<char>({'D'});
	graph['I'] = std::vector<char>({'H'});
	graph['J'] = std::vector<char>({'K','F','H'});
	graph['K'] = std::vector<char>({'F'});
	graph['L'] = std::vector<char>({'J'});
	graph['M'] = std::vector<char>({'J'});
	return;
}

int main(int argc, char *argv[]){
  topologicalSort();
  return 0;
}
