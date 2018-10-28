
PROBLEM STATEMENT:Implement A* approach for any suitable application.

'''

graph={
	1:[2,3],
	2:[3,4,5],
	3:[4],
	4:[5]}

g={
	1:[0,1,4,0,0],
	2:[0,0,2,5,12],
	3:[0,0,0,2,0],
	4:[0,0,0,0,3],
	5:[0,0,0,0,0]}

h=[7,6,2,1,0]

start=int(raw_input("Enter the start node"))
end=int(raw_input("enter the goal node"))

def bfs(graph, start, end):
	count=0
	best=[]
	paths=[]
	queue = []
	d=1
	mini=999
	queue.append([start])
	while queue:
		i=1
		cost=0
        	path = queue.pop(0)
        	node = path[-1]
		if len(path)>1:
			while len(path)>i:
				c=path[i-1]
				d=path[i]
				cost=cost+g[c][d-1]
				i=i+1
		cost=cost+h[d-1]
		print path,"\t",cost
		if node == (end):
			if mini>cost:
				mini=cost
				best=path
		for adjacent in graph.get(node, []):
			if adjacent not in path:
				new_path = list(path)
				new_path.append(adjacent)
       	 			queue.append(new_path)
	return best,mini

c=bfs(graph,start,end)
print "Best Path",c

'''
OUTPUT:-
prjlab26@prjlab26-dx2480-MT:~/cl2prog$ python astar.py
Enter the start node1
enter the goal node5
[1] 	7
[1, 2] 	7
[1, 3] 	6
[1, 2, 3] 	5
[1, 2, 4] 	7
[1, 2, 5] 	13
[1, 3, 4] 	7
[1, 2, 3, 4] 	6
[1, 2, 4, 5] 	9
[1, 3, 4, 5] 	9
[1, 2, 3, 4, 5] 	8
Best Path ([1, 2, 3, 4, 5], 8)
prjlab26@prjlab26-dx2480-MT:~/cl2prog$ 

'''

