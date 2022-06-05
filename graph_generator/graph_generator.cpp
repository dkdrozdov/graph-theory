#include <iostream>

const int maxSize = 44800;
class GraphGenerator
{
   bool graph[maxSize][maxSize] = {};

public:
   int graphSize = 0;
   int v1 = 0, v2 = 0;

   void generate(int size)
   {
      graphSize = size;
      for (int i = 0; i < graphSize; i++)
         for (int j = 0; j <= i; j++)
         {
            graph[i][j] = false;
            graph[j][i] = false;
         }

      for (int i = 0; i < graphSize; i++)
         for (int j = 0; j <= i; j++)
            if (!(i == j || j == v2 && i != v2 - 1 || i == v2 && j != v2 - 1))
            {
               graph[i][j] = true;
               graph[j][i] = true;
            }
   }

   void output()
   {
      std::cout << v1 << " " << v2 << std::endl;
      int n = 0;
      for (int i = 0; i < graphSize; i++)
         for (int j = 0; j <= i; j++)
            if (graph[i][j])
               n++;
      std::cout << graphSize << " " << n << std::endl;

      for (int i = 0; i < graphSize; i++)
         for (int j = 0; j <= i; j++)
            if (graph[i][j])
               std::cout << i << " " << j << std::endl;

      std::cout << std::endl;
   }
};

int main()
{
   GraphGenerator *ggen = new GraphGenerator();
   //std::srand((unsigned int)std::time(nullptr));
   ggen->v1 = 0;
   for (int i = 2; i <= maxSize; i = i * 2)
   {
      ggen->v2 = i - 1;
      ggen->generate(i);
      ggen->output();
   }
}