#pragma once
#include <vector>
#include <queue>
#include <limits>
#include <qstring.h>

using namespace std;

typedef pair<int, int> node;

struct Miasto_pozycja
{
    QString city;
    int x;
    int y;
};

struct Vertex
{
    int id;
    int weight;
    QString city;
    Vertex* next;
};

class Graph
{
private:
    Vertex** m_Adj;
    int m_V;

public:
    std::vector<int> path;
    Graph(int V);
    ~Graph();
    
    int Get_m_V() const;
    Vertex** Get_m_Adj() const;

    void add_edge(int src, int dest, int weight, QString srcCity, QString destCity);
    int Dijkstra(int start, int koniec);
};