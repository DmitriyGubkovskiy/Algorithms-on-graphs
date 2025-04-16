#include "functions.h"



int Sort(const vector<int>& tops_weight, vector<int>& q)
{
	int count = 0;
	for (int i = 0; i < q.size(); i++)
	{
		for (int j = 0; j < q.size() - 1; j++)
		{
			if (tops_weight[q[j]] < tops_weight[q[j + 1]])
			{
				swap(q[j], q[j + 1]);
			}
			count++;
		}
	}

	return count;
}





vector<vector<int>> Mul_Matrix(const vector<vector<int>>& matrix, int level)
{
	vector<vector<int>> P(matrix);
	vector<vector<int>> TMP(matrix);
	if (level < 0 || matrix.size() != matrix[0].size())
	{
		cout << "Îøèáêà" << '\n';
		return P;
	}
	for (int k = 1; k < level; k++)
	{
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int c = 0; c < matrix.size(); c++)
			{
				TMP[i][c] = 0;
				for (int j = 0; j < matrix.size(); j++)
				{
					TMP[i][c] += P[i][j] * matrix[j][c];
				}
			}
		}
		P.clear();
		P = TMP;
	}

	return P;
}



void Print_M(const vector<vector<int>>& matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << setw(2);
		for (int j = 0; j < matrix.size(); j++)
		{
			cout << matrix[i][j] << setw(4);
		}
		cout << '\n';
	}
}

void Print_M(const vector<vector<double>>& matrix) 
{

	for (int i = 0; i < matrix.size(); i++)
	{
		cout << setw(2);
		for (int j = 0; j < matrix.size(); j++)
		{
			cout << matrix[i][j] << setw(4);
		}
		cout << '\n';
	}

}






int Maxi(vector<int> tmp)
{
	int maxi = 0;
	for (int i = 0; i < tmp.size(); i++)
	{
		if (maxi < tmp[i])
		{
			maxi = tmp[i];
		}
	}
	return maxi;
}

int Mini(vector<int> tmp)
{
	int mini = 10000000000000;
	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] != 0 and mini > tmp[i])
		{
			mini = tmp[i];
		}
	}
	if (mini == 1316134912)
	{
		return 0;
	}
	return mini;
}

double Gamma(const double alpha, const double lambda)
{
	double s1;
	double s2;
	double r1;
	double r2;
	double r3;
	double x;
	while (true)
	{
		r1 = (double)(rand()) / RAND_MAX * 30;
		r2 = (double)(rand()) / RAND_MAX * 30;
		r3 = (double)(rand()) / RAND_MAX * 30;

		s1 = pow(r1, (1 / alpha));
		s2 = pow(r2, (1 / (1 - alpha)));
		if (s1 + s2 <= 1 )
		{
			x = -((s1 * log(r3)) / (lambda * (s1 + s2)));
			
			if (fabs(x) > 1)
			{
				break;
			}
		}

	}

	return x;
}



bool bfs(OrGraph& graph, int s, int t, vector<int>& parent)
{

	const int tops = graph.count_tops;


	vector<bool> visited(graph.count_tops, 0);



	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;


	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v = 0; v < graph.count_tops; v++) {
			if (visited[v] == false && graph.T[u][v] > 0) {

				if (v == t) {
					parent[v] = u;
					return true;
				}
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}

	return false;
}



vector<int> Dijkstra(vector<vector<int >> w, int st, int t)
{
	vector<int> route(w.size(), -1);

	vector<int> distance(w.size());
	int count, index, i, u, m = st + 1;
	vector<bool> visited(w.size());

	for (i = 0; i < w.size(); i++)
	{
		distance[i] = INT_MAX; visited[i] = false;
	}
	distance[st] = 0;
	for (count = 0; count < w.size() - 1; count++)
	{
		int min = INT_MAX;
		for (i = 0; i < w.size(); i++)
			if (!visited[i] && distance[i] <= min)
			{
				min = distance[i]; index = i;

			}
		u = index;
		visited[u] = true;
		for (i = 0; i < w.size(); i++)
			if (!visited[i] && w[u][i] && distance[u] != INT_MAX &&
				distance[u] + w[u][i] < distance[i] and w[u][i] != INT32_MAX)
			{
				route[i] = u;
				distance[i] = distance[u] + w[u][i];
			}

	}


	vector<int> path;


	while (t != -1)
	{
		path.push_back(t);
		t = route[t];
	}

	reverse(path.begin(), path.end());

	return path;

}

double Matrix_Determinant(vector<vector<double>> m)
{
		int n = m.size();
		double det = 1;
		if (m.size() != m[0].size()) 
		{
			cout << "Îøèáêà" << '\n';
			return -1;
		}
		for (int i = 0; i < n; ++i)
		{
			double mx = fabs(m[i][i]);
			int idx = i;
			for (int j = i + 1; j < n; ++j)
				if (mx < fabs(m[i][j])) mx = fabs(m[i][idx = j]);
			if (idx != i)
			{
				for (int j = i; j < n; ++j)
				{
					double t = m[j][i];
					m[j][i] = m[j][idx];
					m[j][idx] = t;
				}
				det = -det;
			}
			for (int k = i + 1; k < n; ++k)
			{
				double t = m[k][i] / m[i][i];

				for (int j = i; j < n; ++j)
					m[k][j] -= m[i][j] * t;
			}
		}
		for (int i = 0; i < n; ++i) det *= m[i][i];
		return det;

}

double Supplement_Matrix(vector<vector<double>> matrix)
{
	matrix.erase(matrix.begin());
	vector<vector<double>> fic_matrix;
	for (auto x : matrix)
	{
		x.erase(x.begin()+1);
		fic_matrix.push_back(x);
	}
	double res = Matrix_Determinant(fic_matrix) * (-1);
	return res;
}


int Route_Weight(vector<vector<int>> matrix) 
{
	int sumi = 0;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.size(); j++)
		{
			sumi += matrix[i][j];
		}
	}

	return sumi;
}

OrGraph Check_Euler(OrGraph& graph) 
{
	OrGraph Fic_graph(graph);
	vector<int> tops(Fic_graph.count_tops, 0);
	for (int i = 0; i < Fic_graph.count_tops; i++)
	{
		for (int j = 0; j < Fic_graph.count_tops; j++)
		{
			if (Fic_graph.M[i][j] == 1)
			{
				Fic_graph.M[j][i] = 1;
				Fic_graph.W[j][i] = Fic_graph.W[i][j];
			}
		}
	}
	if (Fic_graph.count_tops == 2)
	{
		return Fic_graph;
	}
	

	for (int i = 0; i < Fic_graph.count_tops; i++)
	{
		int sumi = 0;
		for (int j = 0; j < Fic_graph.count_tops; j++)
		{
			sumi += Fic_graph.M[i][j];
		}
		tops[i] = sumi;
	}


	for (int i = 0; i < tops.size(); i++)
	{
		if (tops[i] % 2 == 1)
		{
			for (int j = i; j < tops.size(); j++)
			{
				if ((tops[j] % 2) == 1 and Fic_graph.M[i][j] == 1 and i != j)
				{
					Fic_graph.M[i][j] = 0;
					Fic_graph.W[i][j] = 0;
					Fic_graph.M[j][i] = 0;
					Fic_graph.W[j][i] = 0;
					tops[i]--;
					tops[j]--;
					break;
				}
			}

		}
	}

	



	for (int i = 0; i < tops.size(); i++)
	{
		if (tops[i] % 2 == 1)
		{
			for (int j = i; j < tops.size(); j++)
			{
				bool fl = false;
				if ((tops[j] % 2) == 1 and i != j)
				{
					for (int z = 0; z < tops.size(); z++)
					{
						if (Fic_graph.M[i][z] == 1 and Fic_graph.M[j][z] == 1
							and tops[z] > 3)
						{
							Fic_graph.M[i][z] = 0;
							Fic_graph.W[i][z] = 0;
							Fic_graph.M[z][i] = 0;
							Fic_graph.W[z][i] = 0;

							Fic_graph.M[j][z] = 0;
							Fic_graph.W[j][z] = 0;
							Fic_graph.M[z][j] = 0;
							Fic_graph.W[z][j] = 0;


							tops[i]--;
							tops[j]--;
							tops[z]--;
							tops[z]--;
							fl = true;
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
	}
	return Fic_graph;
}



OrGraph Check_Hamilton(OrGraph& graph) 
{
	OrGraph Fic_graph(graph);
	vector<int> tops(Fic_graph.count_tops, 0);

	int price = ceil((double)Fic_graph.count_tops / 2);
	
	for (int i = 0; i < Fic_graph.count_tops; i++)
	{
		for (int j = 0; j < Fic_graph.count_tops; j++)
		{
			if (Fic_graph.M[i][j] == 1)
			{
				Fic_graph.M[j][i] = 1;
				Fic_graph.W[j][i] = Fic_graph.W[i][j];

				
			}
		}
	}

	int mini = INT32_MAX;

	for (int i = 0; i < Fic_graph.count_tops; i++)
	{
		int sumi = 0;
		for (int j = 0; j < Fic_graph.count_tops; j++)
		{
			sumi += Fic_graph.M[i][j];
		}
		tops[i] = sumi;
		if (mini > sumi)
		{
			mini = sumi;
		}
	}

	for (int i = 0; i < tops.size(); i++)
	{
		while (tops[i] < price)
		{
			for (int j = 0; j < tops.size(); j++)
			{
				if (j != i and Fic_graph.M[i][j] == 0)
				{
					Fic_graph.M[i][j] = 1;
					Fic_graph.W[i][j] = int(fabs(Gamma(0.7, 0.15)));
					Fic_graph.M[j][i] = 1;
					Fic_graph.W[j][i] = Fic_graph.W[i][j];
					tops[i]++;
					tops[j]++;
					break;
				}
			}
		}
	}



	return Fic_graph;
}

bool isSafe(int v, OrGraph& graph, vector<int> path, int pos)
{

	
	if (graph.M[path[pos - 1]][v] == 0)
		return false;

	
	for (int i = 0; i < pos; i++)
		if (path[i] == v)
			return false;

	
	return true;
}


void FindHamCycle(OrGraph& graph, int pos, vector<int> path,
	vector<bool> visited, vector<vector<int>>& cycles)
{
	if (pos == graph.count_tops) 
	{
		if (graph.M[path[path.size() - 1]][path[0]] != 0) 
		{
			path.push_back(0);
			cycles.push_back(path);
			path.pop_back();
		}
		return;
	}

	
	for (int v = 0; v < graph.count_tops; v++) 
	{

		
		if (isSafe(v, graph, path, pos) and !visited[v]) 
		{

			path.push_back(v);
			visited[v] = true;

			FindHamCycle(graph, pos + 1, path, visited, cycles);

			visited[v] = false;
			path.pop_back();
		}
	}
}


void Cycles_To_File(OrGraph& graph, vector<vector<int>> cycles) 
{
	ofstream fout;
	fout.open("Cycles.txt");

	for (auto x : cycles)
	{
		int sumi = 0;
		fout << x[0] + 1;
		for (int i = 0; i < x.size() - 1; i++)
		{
			sumi += graph.W[x[i]][x[i + 1]];
			fout << " -> " << x[i+1] + 1;
		}
		fout << "; cost = " << sumi << '\n';
	}
	fout.close();

}