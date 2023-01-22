#include "Graf.h"

Graph::Graph(int V) : m_V(V)
{
    m_Adj = new Vertex * [V];
    for (int i = 0; i < V; i++)
    {
        m_Adj[i] = nullptr;
    }
}

Graph::~Graph()
{
    for (int i = 0; i < m_V; i++)
    {
        Vertex* tmp = m_Adj[i];
        while (tmp)
        {
            Vertex* r = tmp;
            tmp = tmp->next;
            delete r;
        }
    }
    delete  m_Adj;
}

int Graph::Get_m_V() const
{
    return m_V;
}

Vertex** Graph::Get_m_Adj() const
{
    return m_Adj;
}

void Graph::add_edge(int src, int dest, int weight, QString srcCity, QString destCity)
{
    Vertex* p = new Vertex;
    p->id = dest;
    p->weight = weight;
    p->city = destCity;
    p->next = m_Adj[src];
    m_Adj[src] = p;

    Vertex* pr = new Vertex;
    pr->id = src;
    pr->weight = weight;
    pr->city = srcCity;
    pr->next = m_Adj[dest];
    m_Adj[dest] = pr;
}

int Graph::Dijkstra(int start, int koniec)
{
    std::priority_queue<node, vector<node>, greater<node>> kolejka;        //waga, id
    int* distance = new int[m_V];
    bool* visited = new bool[m_V];
    int* previous = new int[m_V];
    for (int i = 0; i < m_V; i++)
    {
        distance[i] = std::numeric_limits<int>::max();
        visited[i] = 0;
        previous[i] = std::numeric_limits<int>::max();
    }

    distance[start] = 0;
    kolejka.push(make_pair(0, start));
    for (Vertex* i = m_Adj[start]; i != nullptr; i = i->next)
    {
        if (distance[i->id] > i->weight)
        {
            distance[i->id] = i->weight;
            kolejka.push(make_pair(i->weight, i->id));
            previous[i->id] = start;
        }

    }
    kolejka.pop();
    visited[start] = 1;

    while (!kolejka.empty() && kolejka.top().second != koniec)
    {
        Vertex* tmp = m_Adj[kolejka.top().second];
        for (Vertex* i = tmp; i != nullptr; i = i->next)
        {
            if (distance[i->id] > distance[kolejka.top().second] + i->weight && visited[i->id] == 0)
            {
                distance[i->id] = distance[kolejka.top().second] + i->weight;
                kolejka.push(make_pair(distance[i->id], i->id));
                previous[i->id] = kolejka.top().second;
            }
        }
        visited[kolejka.top().second] = 1;
        kolejka.pop();
    }
    path.push_back(koniec);
    int tmp = previous[koniec];
    while (tmp != start)
    {
        path.push_back(tmp);
        tmp = previous[tmp];
    }
    path.push_back(start);
    /*for(int i = 0; i < m_V; i++)
    {
        int wei = kolejka.top().first;
        int idl = kolejka.top().second;
        cout << distance[i] << '\t' << idl << " " << wei << endl;
        kolejka.pop();
    } */
    int wynik = distance[koniec];
    delete[] previous;
    delete[] distance;
    delete[]  visited;
    return wynik;
}