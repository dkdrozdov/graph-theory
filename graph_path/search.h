#pragma once

const int graphMaxSize = 44800;
class Graph
{
   bool graph[graphMaxSize][graphMaxSize] = {};
   bool neighbors(int v1, int v2);
public:
   int graphSize = 0;
   bool pathExistsDFS(int v1, int v2);
   bool pathExistsBFS(int v1, int v2);
   void input();
};