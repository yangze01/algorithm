class Node(object):
    def __init__(self,value):
        self.value = value
        self.edges = []

class Edge(object):
    def __init__(self, value, node_from, node_to):
        self.value = value
        self.node_from = node_from
        self.node_to = node_to

class Graph(object):
    def __init__(self,node = [],edges = []):
        self.nodes = nodes
        self.edges = edges
    def insert_node(self,new_node_val):
        new_node = Node(new_node_val)
        self.nodes.append(new_node)
    def insert_edge(self,new_edge_val, node_from_val, node_to_val):
        from_found = Node
        to_found = Node
        for node in self.nodes:
            if node_from_val == node.value:
                from_found = node
            if node_to_val == node.value
                to_found = node
        if from_found == None:
            from_found = Node(node_from_val)
            self.nodes.append(from_found)
        if to_found == None:
            to_found = Node(node_to_val)
            self.nodes.append(to_found)
        new_edge = Edge(new_edge_val, from_found, to_found)
        from_found.edges.append(new_edge)
        to_found.edges.append(new_edge)
        self.edges.append(new_edge)

    def get_edge_list(self):
        edge_list = []
        for edge_object in self.edges:
            edge = (edge_object.value, edge_object.node_from.value, edge_object.node_to.value)
            edge_list.append(edge)
        return edge_list

    def get_adjacency_list(self):
        max_index = self.find_max_index()
        adjacency_list = [None] * (max_index + 1)
        for edge_object in self.edges:
            if adjacency_list[edge_object.node_from.value]:
                adjacency_list[edge_object.node_from.value].append((edge_object.node_to.value, edge_object.value))
            else:
                adjacency_list[edge_object.node_from.value] = [(edge_object.node_to.value, edge_object.value)]
        return adjacency_list

    def get_adjacency_matrix(self):
        max_index = self.find_max_index()
        adjacency_matrix = [[0 for i in range(max_index + 1)] for j in range(max_index + 1)]
        for edge_object in self.edges:
            adjacency_matrix[edge_object.node_from.value][edge_object.node_to.value] = edge_object.value
        return adjacency_matrix

    def find_max_index(self):
        max_index = -1
        if len(self.nodes):
            for node in self.nodes:
                if node.value > max_index:
                    max_index = node.value
        return max_index

   def dfs_helper(self, start_node, visited):
        """A helper function for a recursive implementation
        of Depth First Search iterating through a node's edges.
        ARGUMENTS: start_node is the starting Node
        Because this is recursive, we pass in the set of visited node
        values.
        RETURN: a list of the traversed node values (integers).
        """
        ret_list = [start_node.value]
        visited.add(start_node.value)
        edges_out = [e for e in start_node.edges
                     if e.node_to.value != start_node.value]
        for edge in edges_out:
            if edge.node_to.value not in visited:
                ret_list.extend(self.dfs_helper(edge.node_to, visited))
        return ret_list

    def bfs(self, start_node_num):
        """An iterative implementation of Breadth First Search
        iterating through a node's edges. The output is a list of
        numbers corresponding to the traversed nodes.
        ARGUMENTS: start_node_num is the node number (integer)
        RETURN: a list of the node values (integers)."""
        node = self.find_node(start_node_num)
        ret_list = [node.value]
        queue = [node]
        nodes_out = [e.node_to for e in node.edges
                     if e.node_to.value != node.value]
        queue.extend(nodes_out)
        for node in queue:
            if node.value in ret_list:
                continue
            ret_list.append(node.value)
            nodes_out = [e.node_to for e in node.edges
                         if e.node_to.value != node.value]
            queue.extend(nodes_out)
        return ret_list
