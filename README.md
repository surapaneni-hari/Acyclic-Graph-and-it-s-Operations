# Acyclic-Graph-and-it-s-Operations
This repository contains an implementation of various graph algorithms for Directed Acyclic Graphs (DAGs), written in C. The algorithms include Topological Sort, Shortest Path, and Longest Path specifically designed to work with DAGs. The project demonstrates essential graph theory concepts and provides modular code that can be easily extended for other graph-related problems.

# Key Features:
- **Topological Sort**: Perform a DFS-based topological sort of nodes in the graph.
- **Shortest Path**: Calculate the shortest path from a specified source node to all other nodes using topological sorting.
- **Longest Path**: Find the longest path in a DAG using dynamic programming and topological sorting.

# File:
- `acyclic_graph.c`: Contains the full implementation of the graph data structure and the associated algorithms.

### Technologies Used:
- **C Programming Language**

### **How to Run:**
1. Clone this repository:
   ```bash
   git clone https://github.com/surapaneni-hari/Acyclic-Graph-and-it-s-Operations.git
   ```
2. Navigate into the project directory:
   ```bash
   cd Acyclic-Graph-and-it-s-Operations
   ```
3. Compile the code:
   ```bash
   gcc acyclic_graph.c -o graph_operations
   ```
4. Run the program:
   ```bash
   ./graph_operations
   ```
