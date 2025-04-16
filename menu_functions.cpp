#include "functions.h"

OrGraph For_Gen(bool flag)
{
	int in_tops;
	bool fl;
	while (true)
	{
		cout << "������� ���������� ������." << '\n';
		cin >> in_tops;
		cout.clear();
		if (in_tops > 1)
		{
			break;
		}
		cout << "����� ���� ��������� ��������� �� ������." << '\n';
	}

	fl = true;
	while (true)
	{
		cout << "����� � ������� ������� ������ ���� ������ ��������������? (y/n)" << '\n';
		string x;
		cin >> x;
		if (x == "y")
		{
			break;
		}
		else if (x == "n")
		{
			fl = false;
			break;
		}
		cout << "������ �����." << '\n';
		cout << "����� ���� ��������� ��������� �� ������." << '\n';
	}
	OrGraph graph(in_tops);
	Graph_Generation(graph);
	Graph_Weight_Matrix(graph, fl);
	Graph_Throughput_Matrix(graph);
	cout << "������� ���������:" << '\n';
	Print_M(graph.M);
	cout << "������� �������:" << '\n';
	Print_M(graph.W);
	return graph;
}

void For_Shimbell(OrGraph graph)
{
	int in_arcs;
	bool fl;
	while (true)
	{
		cout << "������� ���������� �����." << '\n';
		cin >> in_arcs;
		if (in_arcs > 0 and in_arcs < graph.count_tops)
		{
			break;
		}
		cout << "��� ����� �������� �� ��������� \
			��������������� ������� ��������." << '\n';
	}
	while (true)
	{
		string x;
		cout << "����� ������� ��������(����������� ��� ������������)?" << '\n'
			<< "������� min ��� max." << '\n';
		cin >> x;
		if (x == "max")
		{
			fl = true;
			break;
		}
		else if (x == "min")
		{
			fl = false;
			break;
		}
		cout << "������ �����." << '\n';
	}
	cout << "�������:" << '\n';
	Print_M(Alg_Shimbell(graph, in_arcs, fl));
}


void For_Alg(OrGraph graph, int x)
{
	int top_1;
	int top_2;
	while (true)
	{
		cout << "������� ������� �����������." << '\n';
		cin >> top_1;
		if (top_1 > 0 and top_1 <= graph.count_tops)
		{
			break;
		}
		cout << "�������� ������� � ����� ���." << '\n';
	}
	while (true)
	{
		cout << "������� ������� ��������." << '\n';
		cin >> top_2;
		if (top_2 > 0 and top_2 <= graph.count_tops)
		{
			break;
		}
		cout << "�������� ������� � ����� ���." << '\n';
	}
	vector<int> path;
	int y;

	switch (x)
	{
	case 0:
		y = Count_Routes(graph, top_1, top_2);
		if (y == 0)
		{
			cout << "��������� ���" << '\n';
		}
		else
		{
			cout << "���������� ���������:" << '\t';
			cout << y << '\n';
		}
		break;
	case 1:
		path = Alg_Dijkstra(graph.W, top_1, top_2);
		if (!path.empty())
		{
			int sumi = 0;
			for (int i = 0; i < path.size() - 1; i++)
			{
				sumi += graph.W[path[i]][path[i + 1]];
			}
			cout << "���������� ����������:" << '\t';
			cout << sumi << '\n';
			cout << path[0] + 1;
			for (int i = 1; i < path.size(); i++)
			{
				cout << " -> " << path[i] + 1;
			}
			cout << '\n';
		}
		break;
	case 2:
		Deep_Search(graph, top_1, top_2);
		break;
	case 3:
		Max_Route(graph, top_1, top_2);
		break;
	default:
		break;
	}

}

void For_Flow(OrGraph graph) 
{
	if (graph.is_neg)
	{
		for (int i = 0; i < graph.count_tops; i++)
		{
			for (int j = 0; j < graph.count_tops; j++)
			{
				graph.W[i][j] = abs(graph.W[i][j]);
				graph.T[i][j] = abs(graph.T[i][j]);
			}
		}
	}


	cout << "������� ���������:" << '\n';
	Print_M(graph.M);
	cout << "������� �����:" << '\n';
	Print_M(graph.W);
	cout << "������� ���������� ������������:" << '\n';
	Print_M(graph.T);
	cout << "������� ���������:" << '\n';
	Print_M(graph.P);

	while (true)
	{
		bool fl = false;
		int x;
		cout << '\n' << "�������� �����-���������� - 1" << '\n';
		cout <<"����� ����������� ��������� - 2" << '\n';
		cout << "����� - 0" << '\n';
		cin >> x;

		int res;
		switch (x)
		{
		case(1):
			res = Alg_Ford_Fulkerson(graph, graph.count_tops - 1, 0);
			cout << "������������ �����: " << '\t'  << res << '\n';
			break;
		case(2):
			res = Minimum_Flow(graph, graph.count_tops - 1, 0);
			cout << "����� ����������� ���������: " << '\t' << res << '\n';
			break;
		case(0):
			fl = true;
			break;
		default:
			cout << "������." << '\n';
			break;
		}
		if (fl)
		{
			break;
		}
	}

}
void For_Tree(OrGraph graph, int x) 
{
	OrGraph fic_graph(graph.count_tops);
	vector<pair<int, int>> V;
	switch (x)
	{
	case 1:
		Kirchhoff_Theorem(graph);
		cout << "������� ��������: " << '\n';
		Print_M(graph.K);
		cout << "���������� ������� ������� �����: " << '\t';
		cout << Supplement_Matrix(graph.K) << '\n';
		break;
	case 2:
		fic_graph = Kruskal_Algorithm(graph);
		cout << "������� ����� ������: " << '\n';
		Print_M(fic_graph.W);
		cout << "��������� �������� �� ������� ������: " << '\t';
		cout << Route_Weight(graph.W) << '\n';
		break;
	case 3:
		fic_graph = Prim_Algorithm(graph);
		cout << "������� ����� ������: " << '\n';
		Print_M(fic_graph.W);
		cout << "��������� �������� �� ������� ������: " << '\t';
		cout << Route_Weight(graph.W) << '\n';
		break;
	case 4:
		fic_graph = Prim_Algorithm(graph);
		V = Pruefer_Code(fic_graph);
		cout << "��� ������� ��� �����: " << '\t';
		for (auto x: V)
		{
			cout << x.first <<"(" << x.second << ")" << " ";
		}
		cout << '\n' << "������� ����� �������������: " << '\n';
		Print_M(Pruefer_deCode(V));
		break;
	default:
		break;
	}


}



void For_Cycles(OrGraph graph, int x) 
{
	OrGraph fic_graph(graph.count_tops);
	vector<int> V;
	vector<vector<int>> Vector;
	switch (x)
	{
	case 1:
		cout << "������� ��������� ��������� �����: " << '\n';
		Print_M(graph.M);
		cout << '\n';
		cout << "������� ������� ��������� �����: " << '\n';
		Print_M(graph.W);
		cout << '\n';

		if (graph.count_tops == 2)
		{
			cout << "���� � ����� ���������� ������ �� �������� ���������." << '\n';
			return;
		}

		fic_graph = Check_Euler(graph);
		cout << "������� ��������� �������� �����: " << '\n';
		Print_M(fic_graph.M);
		cout << '\n';
		cout << "������� ������� �������� �����: " << '\n';
		Print_M(fic_graph.W);
		cout << '\n';
		V = Euler_Cycle(fic_graph);
		cout << "������� ����������� �������� �����: " << '\n';
		cout << V[0] + 1;
		for (int i = 1; i < V.size(); i++)
		{
			cout << " -> " << V[i] + 1;
		}
		cout << '\n';
		break;
	case 2:

		if (graph.count_tops == 2)
		{
			cout << "���� � ����� ���������� ������� ������������ �������� \
				���������� ������������ �����." << '\n';
			return;
		}
		cout << "������� ��������� ��������� �����: " << '\n';
		Print_M(graph.M);
		cout << '\n';
		cout << "������� ������� ��������� �����: " << '\n';
		Print_M(graph.W);
		cout << '\n';

		fic_graph = Check_Hamilton(graph);
		cout << "������� ��������� ������������ �����: " << '\n';
		Print_M(fic_graph.M);
		cout << '\n';
		cout << "������� ������� ������������ �����: " << '\n';
		Print_M(fic_graph.W);
		cout << '\n';
		Vector = Hamilton_Cycle(fic_graph);
		Cycles_To_File(fic_graph, Vector);
		system("\"C:\\Users\\dimag\\source\\repos\\Graphs\\Lab1\\Cycles.txt\"");
		TSP(fic_graph, Vector);
		break;
	default:
		break;
	}
}