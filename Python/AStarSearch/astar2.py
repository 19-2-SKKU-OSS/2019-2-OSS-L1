class Queue:
    def __init__(self):
        self.items = []
    def enqueue(self, node):
        self.items.append(node)
    def sortedEnqueue(self, node):
        i = 0
        while i < len(self.items) and self.items[i].f <= node.f:
            i = i + 1
        self.items.insert(i, node)           
            
    def dequeue(self):
        return self.items.pop(0)  # updated 
    def isEmpty(self):
        if len(self.items) == 0 : return True
        else: return False

class Problem:
    def __init__(self, i, g, m):
        self.initState = i
        self.goalState = g
        self.model = m

    def isGoal(self, s):
        if self.goalState == s:
            return True
        else:
            return False

    def sucFN(self, city):
        return self.model.get(city, [])



class Node:
    def __init__(self,s, p, c, d, h):
        self.state = s
        self.parent = p
        self.cost = c
        self.depth = d
        self.f = h + self.cost

    def solutionPath(self):
        path = self.state
        if self.depth == 0: 
            return path
        else:
            return path + ' <-- ' + self.parent.solutionPath()

    def __str__(self):
        return 'S: ' + self.state + ', depth = ' + str(self.depth) + ', cost = ' + str(self.cost)


class Astar:
    def __init__(self, p, hmap):
        self.numberGeneratedNodes = 0
        self.prob = p
        self.frontier = Queue()      
        self.visited = set()
        self.hmap = hmap
    def expand(self, parent):
        children = []
        for i in self.prob.sucFN(parent.state):
            s = Node(i[0], parent, i[1] + parent.cost, parent.depth + 1, self.hmap[i[0]] )
            print('CHILD generated', i[0])
            children.append(s)
        self.numberGeneratedNodes += len(children)
        return children
    def solution(self):e
        root = Node(self.prob.initState, None, 0, 0, self.hmap[self.prob.initState])
        self.frontier.enqueue(root)
        while not self.frontier.isEmpty():
            parent = self.frontier.dequeue()
            self.visited.add(parent.state) 
            if self.prob.isGoal(parent.state):
                return parent
            expandedNodes = self.expand(parent)
            for i in expandedNodes:
                    print('CHECKING CHILD', i.state)
                if i.state not in self.visited:  
                    self.frontier.sortedEnqueue(i)
                     print('CHILD ADDED')
        return False


