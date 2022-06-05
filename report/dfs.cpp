/* DFS */
#include <iostream>
#include <stack>
#include <unordered_set>
#include <chrono>

const int graphMaxSize = 44800;
struct Graph
{
   bool graph[graphMaxSize][graphMaxSize] = {};
   int graphSize = 0;

   bool neighbors(int v1, int v2)
   {
      return graph[v1][v2];
   }

   bool Graph::pathExistsDFS(int v1, int v2)
   {
      std::unordered_set<int> visited;
      if (v1 >= graphSize || v2 >= graphSize)
         return false;
      if (v1 == v2)
         return true;

      visited.insert(v1);

      std::stack<int> s;
      s.push(v1);
      int current = v1;
      bool pathFound = false;
      while (!s.empty() && !pathFound)
      {
         int unvisited = 0;
         for (int i = 0;
              i < graphSize && !(neighbors(current, i) && !visited.count(i));
              i++, unvisited++);
         if (neighbors(current, unvisited) && !visited.count(unvisited))
         {
            if (unvisited == v2)
               pathFound = true;
            else
            {
               s.push(current);
               current = unvisited;
               visited.insert(unvisited);
            }
         } else
         {
            if (!s.empty())
            {
               current = s.top();
               s.pop();
            }
         }
      }

      return pathFound;
   }

   void Graph::input()
   {
      int n = 0;
      std::cin >> graphSize;
      if (graphSize > graphMaxSize)
         throw;
      std::cin >> n;
      for (int i = 0; i < graphSize; i++)
         for (int j = 0; j <= i; j++)
         {
            graph[i][j] = false;
            graph[j][i] = false;
         }

      for (int i = 0; i < n; i++)
      {
         int v1 = 0, v2 = 0;
         std::cin >> v1;
         std::cin >> v2;
         if (v1 >= graphSize || v2 >= graphSize || v1 < 0 || v2 < 0)
            throw;
         graph[v1][v2] = true;
         graph[v2][v1] = true;
      }
      if (std::getchar() != '\n')
         throw;
   }
};

int main()
{
   Graph *g = new Graph();

   while (std::cin.peek() != EOF)
   {
      int v1, v2;
      std::cin >> v1 >> v2;
      std::cin.ignore();
      g->input();
      std::cout << g->graphSize << ": ";

      std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
      bool result = g->pathExistsDFS(v1, v2);
      std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
      std::cout << "depth-first: " << (result ? "true, " : "false, ")
         << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms; ";
   }
}