#include <iostream>
#include <unordered_set>
#include <queue>
#include "search.h"


bool GraphWidthFirst::neighbors(int v1, int v2)
{
   return graph[v1][v2];
}

// существует ли маршрут между двумя заданными вершинами в неориентированном графе: поиск в ширину
bool GraphWidthFirst::pathExistsWF()
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

void GraphWidthFirst::input()
{
   std::cin >> v1 >> v2;
   std::cin.ignore();
   for (int i = 0; std::cin.peek() != EOF; i++, graphSize++)
   {
      for (int j = 0; j <= i && std::cin.peek() != EOF; j++)
      {
         std::cin >> graph[i][j];
         if (i == j && std::cin.peek() != EOF)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         else
            graph[j][i] = graph[i][j];
      }
   }
}