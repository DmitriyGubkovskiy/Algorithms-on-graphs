#include "functions.h"

vector<vector<int>> Alg_Shimbell(OrGraph& graph, int arcs, bool fl)
{
	vector<vector<int>> P(graph.W);
	vector<vector<int>> TMP(graph.W);
	for (int k = 1; k < arcs; k++)
	{
		for (int i = 0; i < graph.count_tops; i++)
		{
			for (int c = 0; c < graph.count_tops; c++)
			{
				vector<int> tmp;
				for (int j = 0; j < graph.count_tops; j++)
				{
					tmp.push_back(P[i][j] == 0 or graph.W[j][c] == 0 ?
						0 : P[i][j] + graph.W[j][c]);
				}
				if (fl)
				{
					TMP[i][c] = Maxi(tmp);
				}
				else
				{
					TMP[i][c] = Mini(tmp);
				}
				tmp.clear();
			}

		}
		P.clear();
		P = TMP;
	}
	return P;
}

vector<int> Alg_Dijkstra(vector<vector<int>> m, int fr_top, int sec_top)
{
	const int INF = INT32_MAX;
	vector<int> tops_weight;
	vector<int> q;
	vector<int> route(m.size(), -1);
	vector<int> copy_route;

	int count_it = 0;
	int sumi = 0;

	if (fr_top == sec_top)
	{
		cout << "Вершина отправления совпадает с вершиной прибытия. " << '\n';
		cout << "Длина пути: 0 " << '\n';
		return copy_route;
	}

	for (int i = 0; i < m.size(); i++)
	{
		sumi += m[fr_top - 1][i];
		count_it++;
	}

	if (sumi == 0)
	{
		cout << "Данные вершины не имеют между собой маршрутов." << '\n';
		return copy_route;
	}

	for (int i = 0; i < m.size(); i++)
	{
		if (i == fr_top - 1)
		{
			tops_weight.push_back(0);
		}
		else
		{
			tops_weight.push_back(INF);
		}
		count_it++;
	}


	for (int i = 0; i < m.size(); i++)
	{
		if (m[fr_top - 1][i] != 0)
		{
			tops_weight[i] = min(tops_weight[i], m[fr_top - 1][i]);
			q.push_back(i);
			route[i] = fr_top - 1;
		}
		count_it++;
	}



	count_it += Sort(tops_weight, q);
	int x_with_top = q[q.size() - 1];
	q.pop_back();
	/*cout << x_with_top << '\n';

	for (int i = 0; i < q.size(); i++)
	{
		cout << q[i] << '\t' << tops_weight[q[i]] << '\n';
	}*/

	int tmp_for_top = INF;
	int need_top_weight = tops_weight[sec_top - 1];
	while (true)
	{

		for (int i = 0; i < m.size(); i++)
		{
			if (m[x_with_top][i] != 0 and m[x_with_top][i] != INT32_MAX)
			{

				tops_weight[i] = min(tops_weight[i], m[x_with_top][i] +
					tops_weight[x_with_top]);
				bool fl = true;
				for (int j = 0; j < q.size(); j++)
				{
					if (q[j] == i)
					{
						fl = false;
					}
					count_it++;
				}
				if (fl)
				{
					q.push_back(i);
				}

				route[i] = x_with_top;
				if (i == sec_top - 1 and tmp_for_top > tops_weight[i])
				{
					tmp_for_top = tops_weight[i];
					copy_route.clear();
					copy_route = route;
				}
			}
			count_it++;
		}

		if (q.empty())
		{
			break;
		}

		count_it += Sort(tops_weight, q);
		x_with_top = q[q.size() - 1];
		q.pop_back();
		/*cout << x_with_top << '\n';*/

	}

	vector<int> path;

	int t = sec_top - 1;
	if (copy_route.size() < m.size())
	{
		while (t != -1)
		{
			path.push_back(t);
			t = route[t];
			count_it++;
		}
	}
	else
	{
		while (t != -1)
		{
			path.push_back(t);
			t = copy_route[t];
			count_it++;
		}
	}



	reverse(path.begin(), path.end());

	cout << "Затраченное количество итераций:" << '\t';
	cout << count_it << '\n';

	if (tops_weight[sec_top - 1] == INF)
	{
		cout << "Данные вершины не имеют между собой маршрутов." << '\n';
		return copy_route;
	}
	else
	{
		return path;
	}

}

int Count_Routes(OrGraph& graph, int top_1, int top_2)
{
	int count = 0;
	for (int i = 1; i < graph.count_tops; i++)
	{
		count += Mul_Matrix(graph.M, i)[top_1 - 1][top_2 - 1];
	}
	return count;
}

void Max_Route(OrGraph& graph, int fr_top, int sec_top, bool fl)
{
	const int INF = INT32_MIN;
	vector<int> tops_weight;
	vector<int> q;
	vector<int> route(graph.count_tops, -1);
	vector<int> copy_route;

	int count_it = 0;
	int sumi = 0;

	if (fr_top == sec_top)
	{
		cout << "Вершина отправления совпадает с вершиной прибытия. " << '\n';
		cout << "Длина пути: 0 " << '\n';
		return;
	}

	for (int i = 0; i < graph.count_tops; i++)
	{
		sumi += graph.M[fr_top - 1][i];
		count_it++;
	}

	if (sumi == 0)
	{
		cout << "Данные вершины не имеют между собой маршрутов." << '\n';
		return;
	}

	for (int i = 0; i < graph.count_tops; i++)
	{
		if (i == fr_top - 1)
		{
			tops_weight.push_back(0);
		}
		else
		{
			tops_weight.push_back(INF);
		}
		count_it++;
	}


	for (int i = 0; i < graph.count_tops; i++)
	{
		if (graph.W[fr_top - 1][i] != 0)
		{
			tops_weight[i] = max(tops_weight[i], graph.W[fr_top - 1][i]);
			q.push_back(i);
			route[i] = fr_top - 1;
		}
		count_it++;
	}



	count_it += Sort(tops_weight, q);
	reverse(q.begin(), q.end());
	int x_with_top = q[q.size() - 1];
	q.pop_back();
	/*cout << x_with_top << '\n';

	for (int i = 0; i < q.size(); i++)
	{
		cout << q[i] << '\t' << tops_weight[q[i]] << '\n';
	}*/

	int tmp_for_top = INF;
	int need_top_weight = tops_weight[sec_top - 1];
	while (true)
	{

		for (int i = 0; i < graph.count_tops; i++)
		{
			if (graph.W[x_with_top][i] != 0)
			{

				tops_weight[i] = max(tops_weight[i], graph.W[x_with_top][i] +
					tops_weight[x_with_top]);
				bool fl = true;
				for (int j = 0; j < q.size(); j++)
				{
					if (q[j] == i)
					{
						fl = false;
					}
					count_it++;
				}
				if (fl)
				{
					q.push_back(i);
				}

				route[i] = x_with_top;
				if (i == sec_top - 1 and tmp_for_top < tops_weight[i])
				{
					tmp_for_top = tops_weight[i];
					copy_route.clear();
					copy_route = route;
				}
			}
			count_it++;
		}

		/*cout << x_with_top << '\n';

		for (int i = 0; i < q.size(); i++)
		{
			cout << q[i] << '\t' << tops_weight[q[i]] << '\n';
		}
		cout << "____________________________________________________" << '\n';*/

		if (q.empty())
		{
			break;
		}

		count_it += Sort(tops_weight, q);
		reverse(q.begin(), q.end());
		x_with_top = q[q.size() - 1];
		q.pop_back();
		/*cout << x_with_top << '\n';*/

	}

	vector<int> path;

	int t = sec_top - 1;
	if (copy_route.size() < graph.count_tops)
	{
		while (t != -1)
		{
			path.push_back(t);
			t = route[t];
			count_it++;
		}
	}
	else
	{
		while (t != -1)
		{
			path.push_back(t);
			t = copy_route[t];
			count_it++;
		}
	}



	reverse(path.begin(), path.end());


	if (tops_weight[sec_top - 1] == INF)
	{
		cout << "Данные вершины не имеют между собой маршрутов." << '\n';
	}
	else
	{
		if (fl)
		{
			cout << "Наибольшее расстояние:" << '\t';
		}
		else
		{
			cout << "Максимальный поток:" << '\t';
		}
		cout << tops_weight[sec_top - 1] << '\n';
		cout << "Маршрут:" << '\t';
		cout << path[0] + 1;
		for (int i = 1; i < path.size(); i++)
		{
			cout << " -> " << path[i] + 1;
			count_it++;
		}
		cout << '\n';
	}
	cout << "Затраченное количество итераций:" << '\t';
	cout << count_it << '\n';
}

void Deep_Search(OrGraph& graph, int s, int t)
{
	int count_it = 0;
	vector<vector<int>> paths;
	s = s - 1;
	t = t - 1;
	vector<int> path;
	path.push_back(s);

	
	vector<vector<int>> visited(graph.count_tops, vector<int>(graph.count_tops, 0));
	vector<int> visited_end(graph.count_tops, 0);


	int count_routes = Count_Routes(graph, s + 1, t + 1);
	
	int i = s;
	while (true)
	{
		bool flag = true; 
		for (int j = 0; j < graph.count_tops; j++)
		{
			bool flag2 = true;
			if (graph.M[i][j] != 0 and visited[i][j] == 0 and flag2)
			{
				path.push_back(j);
				i = j;
				flag = false;
				break;
			}
			count_it++;
		}
		
		if (count_routes == paths.size())
		{
			break;
		}
		if (flag)
		{
			int tmp = i;
			
			path.pop_back();
			i = path[path.size() - 1];
			visited[i][tmp] = 1;
			for (int iter = 0; iter < i; iter++)
			{
				visited[iter].clear();
				visited[iter] = vector<int>(graph.count_tops, 0);
			}
			
		}
		if (path[path.size() - 1] == t)
		{
			paths.push_back(path);
			visited[path[path.size() - 2]][i] = 1;
			
		}



		/*for (auto x : paths)
		{
			cout << x[0] + 1;
			for (int j = 1; j < x.size(); j++)
			{
				cout << " -> " << x[j] + 1;
				count_it++;
			}
			cout << '\n';
		}*/
		

		count_it++;
	}



	if (paths.size() == 0)
	{
		cout << "Маршрутов между данными вершинами нет." << '\n';
		return;
	}

	int min_weight = INT32_MAX;
	path.clear();
	for (auto x : paths)
	{
		int sumi = 0;
		for (int i = 0; i < x.size() - 1; i++)
		{
			sumi += graph.W[x[i]][x[i + 1]];
			count_it++;
		}
		if (sumi < min_weight)
		{
			min_weight = sumi;
			path = x;
		}
	}
	
	cout << '\n' << "Маршрут:" << '\t';
	cout << path[0] + 1;
	for (int j = 1; j < path.size(); j++)
	{
		cout << " -> " << path[j] + 1;
		count_it++;
	}
	cout << '\n';
	cout << "Наименьшее расстояние:" << '\t';
	cout << min_weight << '\n';
	cout << "Затраченное количество итераций:" << '\t';
	cout << count_it << '\n'; 
}

int Alg_Ford_Fulkerson(OrGraph& graph, int s, int t, bool flag)
{
	int u, v;

	OrGraph rGraph(graph.count_tops);
	rGraph.T = graph.T;


	vector<int> parent(graph.count_tops, 0);


	int max_flow = 0;


	while (bfs(rGraph, s, t, parent)) 
	{
		vector<int> path(graph.count_tops, -1);
		int path_flow = INT_MAX;
		for (v = t; v != s; v = parent[v]) {
			
			u = parent[v];
			path[v] = u;
			path_flow = min(path_flow, rGraph.T[u][v]);
		}


		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			rGraph.T[u][v] -= path_flow;
			rGraph.T[v][u] += path_flow;
		}



		vector<int> route;

		int t_copy = t;
		while (t_copy != -1)
		{
			route.push_back(t_copy);
			t_copy = path[t_copy];
		}

		reverse(route.begin(), route.end());
		if (flag)
		{
			cout << "Пущенный поток: " << path_flow << '\n';
			cout << "Маршрут: ";
			for (int i = 0; i < route.size(); i++)
			{
				if (i == route.size() - 1)
				{
					cout << route[i] + 1 << '\n';
				}
				else
				{
					cout << route[i] + 1 << " -> ";
				}
			}
		}
		max_flow += path_flow;
	}


	return max_flow;
}

int Minimum_Flow(OrGraph& graph, int s, int t)
{
	int omege = ceil((double)Alg_Ford_Fulkerson(graph, s, t, false) * 2 / 3);
	if (omege == 0)
	{
		return 0;
	}
	int fi = 0;
	vector<vector<int>> all_path;
	vector<int> all_fi;

	auto Fic_graph = graph;

	Fic_graph.count_tops = graph.count_tops;
	Fic_graph.M = graph.M;
	Fic_graph.P = graph.P;
	Fic_graph.T = graph.T;
	Fic_graph.W = graph.W;

	auto path = Dijkstra(Fic_graph.P, s, t);

	while (true)
	{
		all_path.push_back(path);
		vector<int> tmp;
		for (int i = 0; i < path.size() - 1; i++)
		{
			tmp.push_back(Fic_graph.T[path[i]][path[i + 1]]);
		}


		if ((fi + *min_element(begin(tmp), end(tmp))) >= omege)
		{
			all_fi.push_back(omege - fi);
			break;
		}

		fi += *min_element(begin(tmp), end(tmp));
		all_fi.push_back(*min_element(begin(tmp), end(tmp)));


		for (int i = 0; i < path.size() - 1; i++)
		{
			//Fic_graph.P[path[i + 1]][path[i]] = -Fic_graph.P[path[i]][path[i + 1]];
			Fic_graph.T[path[i + 1]][path[i]] = *min_element(begin(tmp), end(tmp));
		}

		for (int i = 0; i < path.size() - 1; i++)
		{
			if (Fic_graph.T[path[i]][path[i + 1]] != *min_element(begin(tmp), end(tmp)))
			{
				Fic_graph.P[path[i]][path[i + 1]] = graph.P[path[i]][path[i + 1]];
				Fic_graph.T[path[i]][path[i + 1]] = graph.T[path[i]][path[i + 1]]
					- *min_element(begin(tmp), end(tmp));
			}
			else
			{
				Fic_graph.P[path[i]][path[i + 1]] = INT32_MAX;
				Fic_graph.T[path[i]][path[i + 1]] = 0;
			}
		}


		path.clear();
		path = Dijkstra(Fic_graph.P, s, t);
	}
	cout << "Целевой поток величины\t" << omege << '\n';
	int sumi = 0;
	for (int i = 0; i < all_fi.size(); i++)
	{
		cout << i + 1 << ". Поток равен: " << all_fi[i] << '\n';
		cout  << "Маршрут потока:\t";
		for (int j = 0; j < all_path[i].size(); j++)
		{
			if (j < all_path[i].size() - 1)
			{
				sumi += graph.P[all_path[i][j]][all_path[i][j + 1]] * all_fi[i];
			}
			
			if (j == all_path[i].size() - 1)
			{
				cout << all_path[i][j] + 1<< '\n';
			}
			else
			{
				cout << all_path[i][j] + 1 << " -> ";
			}

		}
	}
	return sumi;
}

void Kirchhoff_Theorem(OrGraph& graph)
{
	if (graph.K.size() != 0)
	{
		return;
	}

	graph.K = vector<vector<double>>(graph.count_tops, vector<double>(graph.count_tops, 0));
	for (int i = 0; i < graph.count_tops; i++)
	{
		for (int j = 0; j < graph.count_tops; j++)
		{
			if (i == j)
			{
				int sumi = 0;
				for (int x : graph.M[i])
				{
					sumi += x;
				}
				graph.K[i][j] = sumi;
			}
			else
			{
				graph.K[i][j] = graph.M[i][j] * (-1);
			}
		}
	}

}

OrGraph Kruskal_Algorithm(OrGraph& graph)
{
	int count = 0;
	OrGraph Fic_graph(graph.count_tops);
	Fic_graph.M = vector<vector<int>>
		(graph.count_tops, vector<int>(graph.count_tops, 0));
	Fic_graph.W = vector<vector<int>>
		(graph.count_tops, vector<int>(graph.count_tops, 0));


	vector<int> visited(graph.count_tops, 0);
	int iter = 0;
	while (true)
	{
		count++;
		pair<int, int> indexs;
		int min_weight = INT32_MAX;
		for (int i = 0; i < graph.count_tops; i++)
		{
			count++;
			for (int j = 0; j < graph.count_tops; j++)
			{
				count++;
				if (min_weight > graph.W[i][j] and graph.M[i][j] == 1
					and Fic_graph.M[i][j] == 0 and visited[j] == 0)
				{
					min_weight = graph.W[i][j];
					indexs.first = i;
					indexs.second = j;
				}
			}
		}
		if (min_weight != INT32_MAX)
		{
			Fic_graph.M[indexs.first][indexs.second] = 1;
			Fic_graph.W[indexs.first][indexs.second] = min_weight;
			visited[indexs.second] = 1;
		}

		iter++;
		if (iter == graph.count_tops )
		{
			break;
		}
	}
	cout << "Количество итераци:" << '\t' << count << '\n';
	return Fic_graph;
}



OrGraph Prim_Algorithm(OrGraph& graph) 
{
	int count = 0;
	OrGraph Fic_graph(graph.count_tops);
	Fic_graph.M = vector<vector<int>>
		(graph.count_tops, vector<int>(graph.count_tops, 0));
	Fic_graph.W = vector<vector<int>>
		(graph.count_tops, vector<int>(graph.count_tops, 0));


	vector<int> visited(graph.count_tops, INT32_MAX);
	

	for (int i = 0; i < graph.count_tops; i++)
	{
		count++;
		for (int j = 0; j < graph.count_tops; j++)
		{
			count++;
			if (graph.M[i][j] == 1 and visited[j] > graph.W[i][j])
			{
				visited[j] = graph.W[i][j];
				Fic_graph.M[i][j] = 1;
				Fic_graph.W[i][j] = visited[j];
				for (int x = 0; x < graph.count_tops; x++)
				{
					count++;
					if (x != i)
					{
						Fic_graph.M[x][j] = 0;
						Fic_graph.W[x][j] = 0;
					}
				}
			}
		}
	}
	cout << "Количество итераци:" << '\t' << count << '\n';
	return Fic_graph;
}

vector<pair<int, int>> Pruefer_Code(OrGraph& graph)
{
	vector<pair<int, int>> res;
	map<int, vector<int>> Tree;
	for (int i = 0 ;  i < graph.count_tops; i++)
	{
		
		vector<int> tmp;
		for (int j = 0;  j < graph.count_tops; j++)
		{
			
			if (graph.M[i][j] == 1)
			{
				tmp.push_back(j);
			}
		}
		Tree.insert(pair<int, vector<int>>(i, tmp));
	}

	set<int> zero_childrens;
	while (true)
	{
		
		int mini = INT32_MAX;
		bool fl = false;
		if (Tree.size() == 1)
		{
			break;
		}
 		for (auto x : Tree)
		{
			
			if (x.second.size() == 0)
			{
				zero_childrens.insert(x.first);
			}
		}
		for (auto i = zero_childrens.rbegin(); i != zero_childrens.rend(); ++i)
		{
			
			if (mini > *i)
			{
				mini = *i;
				
			}
		}
		for (auto x = Tree.begin(); x != Tree.end();  x++)
		{
			
			if ((*x).second.size() != 0)
			{
				for (int i = 0; i < (*x).second.size(); i++)
				{
					
					if (mini == (*x).second[i])
					{
						res.push_back(pair<int, int>((*x).first + 1, 
							graph.W[(*x).first][mini]));
						(*x).second.erase((*x).second.begin() + i);
						zero_childrens.erase(mini);
						fl = true;
						for (auto it = Tree.begin(); it != Tree.end(); it++)
						{
							
							if (it->first ==  mini)
							{
								Tree.erase(it);
								break;
							}
						}
						break;

					}
				}
			}
			if (fl)
			{
				break;
			}
		}
	}


	return res;
}

vector<vector<int>> Pruefer_deCode(vector<pair<int, int>> vect)
{
	map<int, vector<int>> Tree; 
	
	int maxi = INT32_MIN;
	for (int x = 0; x <vect.size(); x++)
	{
		
		vect[x].first -= 1;
		if (maxi < vect[x].first)
		{
			maxi = vect[x].first;
		}
	}
	for (int i = 0; i < maxi + 1; i++)
	{
		Tree.insert(pair<int, vector<int>>(i, vector<int>()));
	}
	vector<int> visited(maxi+1, 0);
	vector<vector<int>> res(maxi + 1, vector<int>(maxi + 1, 0));
	while (true)
	{
		int i = vect[0].first;
		for (int j = 0; j < maxi; j++)
		{
			bool fl = true;
			for (auto x : vect)
			{
				if (x.first == j or visited[j] == 1)
				{
					fl = false;
					break;
				}
			}
			if (fl)
			{
				Tree[i].push_back(j);
				res[i][j] = vect[0].second;
				visited[j] = 1;
				vect.erase(vect.begin());
				break;
			}
		}
		if (vect.size() == 0)
		{
			break;
		}
	}
	/*for (auto x : Tree)
	{
		for (auto i : x.second)
		{
			res[x.first][i] = 1;
		}
	}*/

	return res;
}

vector<int> Euler_Cycle(OrGraph& graph) 
{
	
	vector<int> res;
	stack<int> q;
	int v = 0;
	q.push(v);
	while (!q.empty())
	{
		v = q.top();
		int sumi = 0;
		for (int i = 0; i < graph.count_tops; i++)
		{
			sumi += graph.M[v][i];
			if (sumi != 0)
			{
				break;
			}
		}
		if (sumi == 0)
		{
			res.push_back(v);
			q.pop();
		}
		else
		{
			for (int i = 0; i < graph.count_tops; i++)
			{
				if (graph.M[v][i] == 1)
				{
					q.push(i);
					graph.M[v][i] = 0;
					graph.M[i][v] = 0;
					break;
				}
			}
		}
	}

	return res;
}



//void Hamilton_Cycle(OrGraph& graph) 
//{
//	int a = 0;
//	vector<vector<int>> cycles;
//	vector<pair<int,vector<int>>> Tree;
//	vector<int> path;
//	vector<int> visited(graph.count_tops, 0);
//
//
//
//	path.push_back(a);
//	visited[a] = 1;
//
//	for (int i = 0; i < graph.count_tops; i++)
//	{
//
//		vector<int> tmp;
//		for (int j = 0; j < graph.count_tops; j++)
//		{
//
//			if (graph.M[i][j] == 1)
//			{
//				tmp.push_back(j);
//			}
//		}
//		Tree.push_back(pair<int, vector<int>>(i, tmp));
//	}
//	
//
//
//	for (auto x : Tree)
//	{
//		cout << x.first + 1 << ":\t";
//		for (int y : x.second)
//		{
//			cout << y + 1 << "\t";
//		}
//		cout << '\n';
//	}
//	
//	int i = 0;
//	while (i > -1)
//	{
//		auto x = Tree[i];
//		bool fl = true;
//		for (int y : (x).second)
//		{
//			if (graph.M[x.first][y] == 1 and visited[y] == 0)
//			{
//				visited[y] = 1;
//				path.push_back(y);
//				i = x.first;
//				fl = false;
//				break;
//			}
//		}
//		if (fl)
//		{
//			i = path[path.size() - 1];
//			path.pop_back();
//			
//		}
//		if (path.size() == graph.count_tops 
//			and graph.M[a][path[path.size() - 1]] == 1)
//		{
//			cycles.push_back(path);
//			path.pop_back();
//			i--;
//		}
//
//
//	}
//
//	
//
//
//	for (auto x : cycles)
//	{
//		cout << x[0] + 1;
//		for (int i = 1; i < x.size(); i++)
//		{
//			cout << " -> " << x[i] + 1 << '\t';
//		}
//		cout << '\n';
//	}
//}






vector<vector<int>> Hamilton_Cycle(OrGraph& graph)
{
	vector<int> path;
	path.push_back(0);
	vector<vector<int>> cycles;
	vector<bool> visited(graph.count_tops, false);

	visited[0] = true;

	FindHamCycle(graph, 1, path, visited, cycles);
	return cycles;
}



void TSP(OrGraph& graph, vector<vector<int>> cycles) 
{
	int mini = INT32_MAX;
	vector<int> path;
	
	for (auto x : cycles)
	{
		int sumi = 0;
		for (int i = 0; i < x.size() - 1; i++)
		{
			sumi += graph.W[x[i]][x[i + 1]];
		}
		if (sumi < mini)
		{
			mini = sumi;
			path = x;
		}
	}


	cout << '\n' << "Маршрут коммивояжёр:" << '\t';
	cout << path[0] + 1;
	for (int j = 1; j < path.size(); j++)
	{
		cout << " -> " << path[j] + 1;
	}
	cout << '\n';
	cout << "Наименьшее пройденное расстояние:" << '\t';
	cout << mini << '\n';
}