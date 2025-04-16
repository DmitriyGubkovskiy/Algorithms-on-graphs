#include "functions.h"

void Graph_Generation(OrGraph& graph)
{
	for (int i = 0; i < graph.count_tops; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < graph.count_tops; j++)
		{
			tmp.push_back(0);
		}
		graph.M.push_back(tmp);
	}


	vector<int> tops;
	for (int i = 0; i < graph.count_tops; i++)
	{
		while (true)
		{
			int x = int(fabs(Gamma(0.7, 0.23)));
			if (x <= graph.count_tops - 1)
			{
				tops.push_back(x);
				break;
			}
		}
	}

	int count = 0;
	for (int i = 0; i < graph.count_tops; i++)
	{
		/*cout << tops[i] << '\t';*/
		count += tops[i];
	}

	int m = round(count / 2);
	graph.count_arcs = m;
	m++;
	for (int k = 1; k < m; k++)
	{
		double r;
		while (true)
		{
			r = fabs(Gamma(0.35, 0.9434)) - 1;
			if (r < 1)
			{
				break;
			}
		}


		int n = ((int)(graph.count_tops * graph.count_tops * r)) + 1;
		int i = ((n - 1) / graph.count_tops) + 1;
		int j = (n - 1) % graph.count_tops + 1;

		/*cout << k << '\t' << r << '\t' << n << '\t'
			<< i << '\t' << j << '\t' << m << '\n';*/
		if (graph.M[i - 1][j - 1] != 1 and i > j)
		{
			graph.M[i - 1][j - 1] = 1;
		}
		else
		{
			m++;
		}
	}
}

void Graph_Weight_Matrix(OrGraph& graph, bool fl)
{
	graph.W = graph.M;
	graph.is_neg = !fl;
	for (int i = 0; i < graph.count_tops; i++)
	{
		for (int j = 0; j < graph.count_tops; j++)
		{
			if (graph.W[i][j] != 0)
			{
				if (fl)
				{
					graph.W[i][j] = int(fabs(Gamma(0.7, 0.15)));
				}
				else
				{
					if (int(fabs(Gamma(0.23, 0.15))) < 10)
					{
						int wei = int(fabs(Gamma(0.7, 0.15)));
						if (wei == INT32_MIN)
						{
							graph.W[j][i] = int(fabs(Gamma(0.7, 0.15)));
						}
						else
						{
							graph.W[j][i] = wei;
						}
					}
					else
					{
						int wei = int(fabs(Gamma(0.7, 0.15)));
						if (wei == INT32_MIN)
						{
							graph.W[j][i] = int(fabs(Gamma(0.7, 0.15)));
						}
						else
						{
							graph.W[j][i] = wei;
						}
					}
				}
			}
		}
	}

}

void Graph_Throughput_Matrix(OrGraph& graph)
{
	int source_count = 0;
	int drain_count = 0;
	vector<int> Source;
	vector<int> Drain;
	for (int i = 0; i < graph.count_tops; i++)
	{
		int count = 0;
		int sum_tops = 0;
		for (int j = 0; j < graph.count_tops; j++)
		{
			count += graph.M[j][i];
			sum_tops += graph.M[i][j];
		}
		if (count == 0)
		{
			source_count++;
			Source.push_back(i);
		}
		if (sum_tops == 0)
		{
			drain_count++;
			Drain.push_back(i);
		}
	}


	int real_source = Source[Source.size() - 1];
	int real_drain = Drain[0];
	Source.pop_back();
	Drain.erase(Drain.begin());
	for (auto x : Source)
	{
		graph.M[real_source][x] = 1;
		graph.W[real_source][x] = int(fabs(Gamma(0.7, 0.15)));
	}

	for (auto x : Drain)
	{
		graph.M[x][real_drain] = 1;
		graph.W[x][real_drain] = int(fabs(Gamma(0.7, 0.15)));
	}
	graph.P = graph.M;
	for (int i = 0; i < graph.count_tops; i++)
	{
		for (int j = 0; j < graph.count_tops; j++)
		{
			if (graph.M[i][j] == 1)
			{
				graph.P[i][j] = int(fabs(Gamma(0.7, 0.15)));
			}
		}
	}

	graph.T = graph.W;
}