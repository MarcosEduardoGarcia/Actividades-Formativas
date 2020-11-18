//Actividad 4.1
//GRAFOS

//Marcos Eduardo García Ortiz A01276213

//Librerias
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iterator>

using namespace std;
//Clase grafo
class Graph{
private:
  list<int> Adyacen_list[100];
  int Matrix_list[30][30] {};
  vector <int> *adjList;
  int Arco;
  void addEdge(int u, int v);
  void addEdgeMat(int u, int v);
  void addEdge2(int,int);
  void sortAdjList();
public:
  Graph();
  void loadGraphList(string,int,int);
  void loadGraphMat(string,int,int);
  string printAdjList();
  string printAdjMat();

  string DFS(int, int);
  string BFS(int, int);
  void DFSHelper(int actual, int goal, stack<int> &st, bool visited[], int paths[], vector<int> &visitedOrder);
  void BFSHelper(int actual, int goal, queue<int> &qu, bool visited[], int paths[], vector<int> &visitedOrder);
  string printVisited(vector<int> &visitedOrder);
  string printPath(int path[], int inicio, int meta);
};
//Constructor
Graph::Graph(){
  Arco = 0;
}

//Funciones de funcionamiento

void Graph::addEdge(int u, int v){
  Adyacen_list[u].push_back(v);
  Adyacen_list[u].sort();
  Adyacen_list[v].push_back(u);
  Adyacen_list[v].sort();
}

void Graph::addEdgeMat(int u, int v){
  Matrix_list[u][v] = 1;
  Matrix_list[v][u] = 1;
}

void Graph :: addEdge2(int u, int v){
  adjList[u].push_back(v);
  adjList[v].push_back(u);
}

void Graph::loadGraphList(string Archivo,int vertice,int arco){
  Arco  = arco;
  adjList = new vector<int>[Arco];

  ifstream ArchivoLista(Archivo);
  if(!ArchivoLista.is_open()){
    cout << "File failed to open"<<endl;
  }

  string line;
  while(getline(ArchivoLista,line)){

    string nodo_salida_temp;
    string nodo_salida;
    int nodo_salida_num;

    string nodo_llegada_temp;
    string nodo_llegada;
    int nodo_llegada_num;

    stringstream ss(line);

    getline(ss,nodo_salida_temp,',');
    for (int i=0; i<nodo_salida_temp.length();i++){
      if(int(nodo_salida_temp[i])>47 && int(nodo_salida_temp[i])<58){
        nodo_salida = nodo_salida + nodo_salida_temp[i];
      }
    }
    nodo_salida_num = stoi(nodo_salida);

    getline(ss,nodo_llegada_temp,',');
    for (int i=0; i<nodo_llegada_temp.length();i++){
      if(int(nodo_llegada_temp[i])>47 && int(nodo_llegada_temp[i])<58){
        nodo_llegada = nodo_llegada + nodo_llegada_temp[i];
      }
    }
    nodo_llegada_num = stoi(nodo_llegada);

    addEdge(nodo_salida_num,nodo_llegada_num);
    addEdge2(nodo_salida_num,nodo_llegada_num);
  }
  sortAdjList();

  ArchivoLista.close();
}

void Graph::loadGraphMat(string Archivo,int vertice,int arco){
  Arco  = arco;
  ifstream ArchivoLista(Archivo);
  if(!ArchivoLista.is_open()){
    cout << "File failed to open"<<endl;
  }

  string line;
  while(getline(ArchivoLista,line)){

    string nodo_salida_temp;
    string nodo_salida;
    int nodo_salida_num;

    string nodo_llegada_temp;
    string nodo_llegada;
    int nodo_llegada_num;

    stringstream ss(line);

    getline(ss,nodo_salida_temp,',');
    for (int i=0; i<nodo_salida_temp.length();i++){
      if(int(nodo_salida_temp[i])>47&&int(nodo_salida_temp[i])<58){
        nodo_salida = nodo_salida + nodo_salida_temp[i];
      }
    }
    nodo_salida_num = stoi(nodo_salida);

    getline(ss,nodo_llegada_temp,',');
    for (int i=0; i<nodo_llegada_temp.length();i++){
      if(int(nodo_llegada_temp[i])>47&&int(nodo_llegada_temp[i])<58){
        nodo_llegada = nodo_llegada + nodo_llegada_temp[i];
      }
    }
    nodo_llegada_num = stoi(nodo_llegada);

    addEdgeMat(nodo_salida_num,nodo_llegada_num);
  }

  ArchivoLista.close();
}

string Graph :: printAdjList() {
  stringstream aux;
  for(int i = 0; i < Arco; i++) {
    aux <<"vertex "<< i <<" : ";
    list<int> :: iterator it;
    for(it = Adyacen_list[i].begin(); it != Adyacen_list[i].end(); ++it) {
       aux << *it << " ";
    }
  }
  return aux.str();
}

string Graph :: printAdjMat(){
  stringstream aux;
  int i, j;
  for(i = 0; i < Arco; i++) {
    for(j = 0; j < Arco; j++) {
      aux << Matrix_list[i][j] << " ";
    }
    //cout << endl;
  }
  return aux.str();
}

void Graph::sortAdjList(){
	for (int i = 0; i < Arco; i++){
		sort(adjList[i].begin(), adjList[i].end());
	}
}

string Graph::DFS(int inicio, int meta){
	stringstream aux;
	stack<int> st;
	bool visited[Arco];
	vector<int> visitedOrder;
	int path[Arco];
	for (int i = 0; i < Arco; i++){
		visited[i] = false;
		path[i] = -1;
	}
	st.push(inicio);
	DFSHelper(inicio, meta, st, visited, path, visitedOrder);
	aux << printVisited(visitedOrder) << printPath(path, inicio, meta);

	return aux.str();
}

void Graph::DFSHelper(int actual, int goal, stack<int> &st, bool visited[], int paths[], vector<int> &visitedOrder){
	if (actual == goal){
		return;

	} else if (st.empty()){
		cout << "Node not found";
	} else {
		actual = st.top();
		st.pop();
		visited[actual] = true;
		visitedOrder.push_back(actual);

		for (int i = 0; i < adjList[actual].size(); i++){
			if (visited[adjList[actual][i]] == false){
				st.push(adjList[actual][i]);
				paths[adjList[actual][i]] = actual;
			}
		}
		DFSHelper(actual, goal, st, visited, paths, visitedOrder);
	}
}

string Graph::BFS(int inicio, int meta){
	stringstream aux;
	queue <int> qu;
	bool visited[Arco];
	vector<int> visitedOrder;
	int path[Arco];
	for (int i = 0; i < Arco; i++){
		visited[i] = false;
		path[i] = -1;
	}
	qu.push(inicio);
	BFSHelper(inicio, meta, qu, visited, path, visitedOrder);
	aux << printVisited(visitedOrder) << printPath(path, inicio, meta);

	return aux.str();
}

void Graph::BFSHelper(int actual, int goal, queue<int> &qu, bool visited[], int paths[], vector<int> &visitedOrder){
	if (actual == goal){
		return;
	}
  else if (qu.empty()){
		cout << "Node not found";
	}
  else {
		actual = qu.front();
		qu.pop();
		visited[actual] = true;
		visitedOrder.push_back(actual);

		for (int i = 0; i < adjList[actual].size(); i++){
			if (visited[adjList[actual][i]] == false){
				qu.push(adjList[actual][i]);
				if (paths[adjList[actual][i]] == -1){
					paths[adjList[actual][i]] = actual;
				}
			}
		}
		BFSHelper(actual, goal, qu, visited, paths, visitedOrder);
	}
}

string Graph::printVisited(vector<int> &visitedOrder){
	stringstream aux;
	aux << "visited:";
	for (int i = 0; i < visitedOrder.size(); i++){
		aux << " " << visitedOrder[i];
	}
	return aux.str();
}

string Graph::printPath(int path[], int inicio, int meta){
	stringstream aux;

	stack<int> reverse;
	int node = meta;

	while (node != inicio){
		reverse.push(node);
		node = path[node];
	}
	reverse.push(inicio);
	aux << " path:";
	while (!reverse.empty()) {
		aux << " " << reverse.top();
		reverse.pop();
	}
	return aux.str();
}
