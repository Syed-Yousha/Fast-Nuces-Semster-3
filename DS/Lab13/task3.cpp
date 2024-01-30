#include <iostream>
#include <list>
#include <stack>

using namespace std;

struct Vertex {
    char label;
    list<char> neighbors;
};

Vertex graph[26];
stack<char> topological_order;

bool is_valid_vertex(char vertex) {
    return vertex >= 'A' && vertex <= 'Z';
}

void add_edge(char source, char destination) {
    if (!is_valid_vertex(source) || !is_valid_vertex(destination)) {
        throw invalid_argument("Invalid vertex");
    }
    graph[source - 'A'].neighbors.push_back(destination);
}

void mark_visited(char vertex, bool visited[]) {
    visited[vertex - 'A'] = true;
}

void topological_sort_util(char vertex, bool visited[]) {
    mark_visited(vertex, visited);

    for (char neighbor : graph[vertex - 'A'].neighbors) {
        if (!visited[neighbor - 'A']) {
            topological_sort_util(neighbor, visited);
        }
    }

    topological_order.push(vertex);
}

void print_topological_order() {
    bool visited[26] = {false};

    for (int i = 0; i < 26; ++i) {
        if (!visited[i]) {
            topological_sort_util('A' + i, visited);
        }
    }

    while (!topological_order.empty()) {
        cout << topological_order.top() << " ";
        topological_order.pop();
    }
}

int main() {
    char vertices[] = "MNOQRSTUVWXZY";

    add_edge('M', 'O');
    add_edge('M', 'N');
    add_edge('N', 'O');
    add_edge('N', 'P');
    add_edge('O', 'Q');
    add_edge('O', 'R');
    add_edge('P', 'Q');
    add_edge('P', 'S');
    add_edge('Q', 'T');
    add_edge('Q', 'U');
    add_edge('R', 'S');
    add_edge('R', 'V');
    add_edge('S', 'T');
    add_edge('S', 'U');
    add_edge('S', 'V');
    add_edge('T', 'W');
    add_edge('U', 'X');
    add_edge('V', 'X');
    add_edge('W', 'Y');
    add_edge('X', 'Z');

    print_topological_order();

    return 0;
}
