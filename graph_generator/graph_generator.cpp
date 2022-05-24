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
      {
         for (int j = 0; j < graphSize; j++)
         {
            if (i == j)
            {
               graph[i][j] = 0;
            } else
            {
               graph[i][j] = std::rand() % 2;
            }
         }
      }
   }

   void output()
   {
      std::cout << v1 << " " << v2 << std::endl;
      for (int i = 0; i < graphSize; i++)
      {
         for (int j = 0; j < graphSize; j++)
         {
            std::cout << graph[i][j];
            if (j != graphSize - 1)
               std::cout << " ";
         }
         std::cout << std::endl;
      }
   }
};

int main()
{
   GraphGenerator *ggen = new GraphGenerator();
   std::srand((unsigned int)std::time(nullptr));
   ggen->graphSize = 2;
   ggen->v1 = std::rand() % ggen->graphSize;
   ggen->v2 = std::rand() % ggen->graphSize;
   for (int i = 2; i <= 16; i = i * 2)
   {
         ggen->generate(i);
         ggen->output();
   }
}