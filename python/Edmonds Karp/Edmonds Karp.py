'''
Edmonds-Karp algorithm
Edmonds-Karp algorithm is an implementation of the Ford-Fulkerson algorithm
with maximum flow O(|V||E|^2) time.
Ford-Fulkerson algorithm is greedy algorithm and its basic idea is as follows:
as long as there is a path from the start node to the end node,
we send flow along one of the paths.
Edmonds-Karp algorithm used formally than Ford-Fulkerson algorithm.

Algorithm
1. initialize all edges 0.
2. while there is a augmenting path from start to end. Add this path-flow.
3. return path-flow

Time complexity
O(max_flow * Edges)
'''


# This class represents a directed graph using adjacency matrix representation
class Graph:

    def __init__(self, graph):
        self.graph = graph
        self.row = len(graph)

    def BFS(self, s, t, parent):

        # Initialize all the vertices as not visited
        visited = [False] * (self.row)

        # Create a queue for BFS
        vertex_queue = []

        # Enqueue the source node and start BFS.
        vertex_queue.append(s)
        visited[s] = True

        # BFS Loop
        while vertex_queue:

            # Dequeue current vertex from queue
            current = vertex_queue.pop(0)

            # Get all adjacent vertices of the current node.
            # if this node was not visited add it to path.
            for i, val in enumerate(self.graph[current]):
                if visited[i] == False and val > 0:
                    vertex_queue.append(i)
                    visited[i] = True
                    # connect popped node and next node
                    parent[i] = current

        # if end node is visited after BFS process, return True else False.
        return True if visited[t] else False

    # Returns tne maximum flow from s to t in the given graph
    def FordFulkerson(self, start, goal):

        # Initialize parent list for BFS
        parent = [-1] * (self.row)

        max_flow = 0

        while self.BFS(start, goal, parent):
            path_flow = float("Inf")
            s = goal
            while (s != start):
                path_flow = min(path_flow, self.graph[parent[s]][s])
                s = parent[s]

            # Add path flow to overall flow
            max_flow += path_flow

            v = goal
            while (v != start):
                u = parent[v]
                self.graph[u][v] -= path_flow
                self.graph[v][u] += path_flow
                v = parent[v]

        return max_flow


graph = [[0, 16, 13, 0, 0, 0],
         [0, 0, 10, 12, 0, 0],
         [0, 4, 0, 0, 14, 0],
         [0, 0, 9, 0, 0, 20],
         [0, 0, 0, 7, 0, 4],
         [0, 0, 0, 0, 0, 0]]

g = Graph(graph)

source = 0
sink = 5

print("The maximum flow is %d " % g.FordFulkerson(source, sink))
