/* BFS */
#include <iostream>
#include <queue>
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

   bool pathExistsBFS(int v1, int v2)
   {
      if (v1 >= graphSize || v2 >= graphSize)
         return false;
      if (v1 == v2)
         return true;

      std::unordered_set<int> visited;
      std::queue<int> s;
      visited.insert(v1);
      int current = v1;
      bool pathFound = false;
      s.push(v1);
      while (!s.empty() && !pathFound)
      {
         current = s.front();
         s.pop();
         for (int i = 0; i < graphSize; i++)
         {
            if (neighbors(current, i) && !visited.count(i))
            {
               if (i == v2)
                  pathFound = true;
               else
               {
                  s.push(i);
                  visited.insert(i);
               }
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
      result = g->pathExistsBFS(v1, v2);
      std::cout << "bfs: " << (result ? "true" : "false");
   }
}