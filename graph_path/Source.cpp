#include "search.h"
#include <iostream>
#include <chrono>

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
      std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
      result = g->pathExistsDF(v1, v2);
      std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
      std::cout << "depth-first: " << (result ? "true, " : "false, ")
         << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms; ";

      begin = std::chrono::steady_clock::now();
      result = g->pathExistsWF(v1, v2);
      end = std::chrono::steady_clock::now();
      std::cout << "width-first: " << (result ? "true, " : "false, ")
         << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms" << std::endl;
   }
}