class Bfs:
    def __init__(self, graph, nodes):
        self.graph = graph
        self.nodes = nodes
        self.visited = [False for i in range(nodes)]
        self.queue = [0]

    def bfs(self):
        while self.queue:
            node = self.queue.pop(0)
            self.visit(node)
            
        for node in range(self.nodes):
            if not self.visited[node]:
                self.queue.append(node)
                self.bfs()

    def visit(self, node):
        self.visited[node] = True
        print (node)
        for neighbour in graph[node]:
            if not self.visited[neighbour]:
                self.visited[neighbour] = True
                self.queue.append(neighbour)
        
                                                
                

# graph = [[1,3], [2], [], [2], [7], [6,7], [7], [], []]
# nodes = 9
# makeBFS = Bfs(graph, nodes)
# makeBFS.bfs()
