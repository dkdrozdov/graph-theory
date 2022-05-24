#pragma once

const int graphMaxSize = 10000;
class Graph
{
   bool graph[graphMaxSize][graphMaxSize] = {};
   int a = 0;
   bool neighbors(int v1, int v2);
public:
   int graphSize = 0;
   bool pathExistsDFS(int v1, int v2);
   bool pathExistsBFS(int v1, int v2);
   void input();
};