#pragma once
#include<vector>
#include<iostream>
#include <iomanip>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <fstream>

using namespace std;

//Структура графа
struct OrGraph
{
	int count_tops;
	int count_arcs;

	vector<vector<int>> M;
	vector<vector<int>> W;
	vector<vector<int>> T;
	vector<vector<int>> P;
	vector<vector<double>> K;
	bool is_neg;

	OrGraph(int count_tops)
	{
		this->count_arcs = 0;
		this->count_tops = count_tops;
		this->is_neg = false;
	}
	OrGraph(const OrGraph & graph)
	{
		this->count_tops = graph.count_tops;
		this->M = graph.M;
		this->W = graph.W;
		this->T = graph.T;
		this->P = graph.P;
		this->K = graph.K;
	}
};
//Генерации 
void Graph_Generation(OrGraph& graph);
void Graph_Weight_Matrix(OrGraph& graph, bool fl = true);
void Graph_Throughput_Matrix(OrGraph& graph);

//Основные алгоритмы
vector<vector<int>> Alg_Shimbell(OrGraph& graph, int top, bool fl);
vector<int> Alg_Dijkstra(vector<vector<int>> m, int fr_top, int sec_top);
int Count_Routes(OrGraph& graph, int top_1, int top_2);
void Max_Route(OrGraph& graph, int fr_top, int sec_top, bool fl = true);
void Deep_Search(OrGraph& graph, int top_1, int top_2);
int Alg_Ford_Fulkerson(OrGraph& graph, int s, int t, bool flag = true);
int Minimum_Flow(OrGraph& graph, int s, int t);
void Kirchhoff_Theorem(OrGraph& graph);
OrGraph Kruskal_Algorithm(OrGraph& graph);
OrGraph Prim_Algorithm(OrGraph& graph);
vector<pair<int, int>> Pruefer_Code(OrGraph& graph);
vector<vector<int>> Pruefer_deCode(vector<pair<int, int>> vect);
vector<int> Euler_Cycle(OrGraph& graph);
vector<vector<int>> Hamilton_Cycle(OrGraph& graph);
void TSP(OrGraph& graph, vector<vector<int>> cycles);



//Вспомогательные алгоритмы
int Sort(const vector<int>& tops_weight, vector<int>& q);
vector<vector<int>> Mul_Matrix(const vector<vector<int>>& matrix, int level);
void Print_M(const vector<vector<int>>& matrix);
void Print_M(const vector<vector<double>>& matrix);
int Maxi(vector<int> tmp);
int Mini(vector<int> tmp);
double Gamma(const double alpha, const double gamma);
bool bfs(OrGraph& graph, int s, int t, vector<int> &parent);
vector<int> Dijkstra(vector<vector<int >> w, int st, int t);
double Matrix_Determinant(vector<vector<double>> matrix);
double Supplement_Matrix(vector<vector<double>> matrix);
int Route_Weight(vector<vector<int>> matrix);
OrGraph Check_Euler(OrGraph& graph);
OrGraph Check_Hamilton(OrGraph& graph);
bool isSafe(int v, OrGraph& graph, vector<int> path, int pos);
void FindHamCycle(OrGraph& graph, int pos, vector<int> path,
	vector<bool> visited, vector<vector<int>>& cycles);
void Cycles_To_File(OrGraph& graph, vector<vector<int>> cycles);




//Функции меню
OrGraph For_Gen(bool flag);
void For_Shimbell(OrGraph graph);
void For_Alg(OrGraph graph, int x);
void For_Flow(OrGraph graph);
void For_Tree(OrGraph graph, int x);
void For_Cycles(OrGraph graph, int x);