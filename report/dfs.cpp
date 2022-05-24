/* DFS */
#include <iostream>
#include <stack>
#include <unordered_set>

const int graphMaxSize = 10000;
struct Graph
{
   bool graph[graphMaxSize][graphMaxSize] = {};
   int a = 0;
   int graphSize = 0;
   bool neighbors(int v1, int v2)
   {
      return graph[v1][v2];
   }

   bool pathExistsDFS(int v1, int v2)
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

   void input()
   {
      graphSize = 0;
      for (char c = 0;
           std::cin.peek() != '\n'; graphSize++, std::cin >> c);
      std::cin.ignore();

      for (int i = 1; i < graphSize; i++)
      {
         for (int j = 0; j <= i; j++)
         {
            std::cin >> graph[i][j];
            if (i == j)
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            else
               graph[j][i] = graph[i][j];
         }
      }
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

      bool result = false;
      result = g->pathExistsDFS(v1, v2);
      std::cout << "dfs: " << (result ? "true" : "false");
   }
}