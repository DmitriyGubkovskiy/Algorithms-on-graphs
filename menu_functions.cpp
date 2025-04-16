#include "functions.h"

OrGraph For_Gen(bool flag)
{
	int in_tops;
	bool fl;
	while (true)
	{
		cout << "Введите количество вершин." << '\n';
		cin >> in_tops;
		cout.clear();
		if (in_tops > 1)
		{
			break;
		}
		cout << "Такой граф программа построить не сможет." << '\n';
	}

	fl = true;
	while (true)
	{
		cout << "Числа в весовой матрице должны быть только положительными? (y/n)" << '\n';
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
		cout << "Ошибка ввода." << '\n';
		cout << "Такой граф программа построить не сможет." << '\n';
	}
	OrGraph graph(in_tops);
	Graph_Generation(graph);
	Graph_Weight_Matrix(graph, fl);
	Graph_Throughput_Matrix(graph);
	cout << "Матрица смежности:" << '\n';
	Print_M(graph.M);
	cout << "Весовая матрица:" << '\n';
	Print_M(graph.W);
	return graph;
}

void For_Shimbell(OrGraph graph)
{
	int in_arcs;
	bool fl;
	while (true)
	{
		cout << "Введите количество ребер." << '\n';
		cin >> in_arcs;
		if (in_arcs > 0 and in_arcs < graph.count_tops)
		{
			break;
		}
		cout << "При таких условиях не получится \
			воспользоваться методом Шимбелла." << '\n';
	}
	while (true)
	{
		string x;
		cout << "Какой элемент выбирать(минимальный или максимальный)?" << '\n'
			<< "Укажите min или max." << '\n';
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
		cout << "Ошибка ввода." << '\n';
	}
	cout << "Матрица:" << '\n';
	Print_M(Alg_Shimbell(graph, in_arcs, fl));
}


void For_Alg(OrGraph graph, int x)
{
	int top_1;
	int top_2;
	while (true)
	{
		cout << "Введите вершину отправления." << '\n';
		cin >> top_1;
		if (top_1 > 0 and top_1 <= graph.count_tops)
		{
			break;
		}
		cout << "Подобной вершины в графе нет." << '\n';
	}
	while (true)
	{
		cout << "Введите вершину прибытия." << '\n';
		cin >> top_2;
		if (top_2 > 0 and top_2 <= graph.count_tops)
		{
			break;
		}
		cout << "Подобной вершины в графе нет." << '\n';
	}
	vector<int> path;
	int y;

	switch (x)
	{
	case 0:
		y = Count_Routes(graph, top_1, top_2);
		if (y == 0)
		{
			cout << "Маршрутов нет" << '\n';
		}
		else
		{
			cout << "Количество маршрутов:" << '\t';
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
			cout << "Наименьшее расстояние:" << '\t';
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


	cout << "Матрица смежности:" << '\n';
	Print_M(graph.M);
	cout << "Матрица весов:" << '\n';
	Print_M(graph.W);
	cout << "Матрица пропускных способностей:" << '\n';
	Print_M(graph.T);
	cout << "Матрица стоимости:" << '\n';
	Print_M(graph.P);

	while (true)
	{
		bool fl = false;
		int x;
		cout << '\n' << "Алгоритм Форда-Фалкерсона - 1" << '\n';
		cout <<"Поток минимальной стоимости - 2" << '\n';
		cout << "Выход - 0" << '\n';
		cin >> x;

		int res;
		switch (x)
		{
		case(1):
			res = Alg_Ford_Fulkerson(graph, graph.count_tops - 1, 0);
			cout << "Максимальный поток: " << '\t'  << res << '\n';
			break;
		case(2):
			res = Minimum_Flow(graph, graph.count_tops - 1, 0);
			cout << "Поток минимальной стоимости: " << '\t' << res << '\n';
			break;
		case(0):
			fl = true;
			break;
		default:
			cout << "Ошибка." << '\n';
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
		cout << "Матрица Кирхгофа: " << '\n';
		Print_M(graph.K);
		cout << "Количества остовов данного графа: " << '\t';
		cout << Supplement_Matrix(graph.K) << '\n';
		break;
	case 2:
		fic_graph = Kruskal_Algorithm(graph);
		cout << "Матрица весов остова: " << '\n';
		Print_M(fic_graph.W);
		cout << "Стоимость маршрута по данному остову: " << '\t';
		cout << Route_Weight(graph.W) << '\n';
		break;
	case 3:
		fic_graph = Prim_Algorithm(graph);
		cout << "Матрица весов остова: " << '\n';
		Print_M(fic_graph.W);
		cout << "Стоимость маршрута по данному остову: " << '\t';
		cout << Route_Weight(graph.W) << '\n';
		break;
	case 4:
		fic_graph = Prim_Algorithm(graph);
		V = Pruefer_Code(fic_graph);
		cout << "Код Прюфера для графа: " << '\t';
		for (auto x: V)
		{
			cout << x.first <<"(" << x.second << ")" << " ";
		}
		cout << '\n' << "Матрица после декодирования: " << '\n';
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
		cout << "Матрица смежности исходного графа: " << '\n';
		Print_M(graph.M);
		cout << '\n';
		cout << "Весовая матрица исходного графа: " << '\n';
		Print_M(graph.W);
		cout << '\n';

		if (graph.count_tops == 2)
		{
			cout << "Граф с таким количество вершин не является эйлеровым." << '\n';
			return;
		}

		fic_graph = Check_Euler(graph);
		cout << "Матрица смежности эйлерова графа: " << '\n';
		Print_M(fic_graph.M);
		cout << '\n';
		cout << "Весовая матрица эйлерова графа: " << '\n';
		Print_M(fic_graph.W);
		cout << '\n';
		V = Euler_Cycle(fic_graph);
		cout << "Маршрут прохождения эйлерова цикла: " << '\n';
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
			cout << "Граф с таким количетвом решений противоречит услвоиям \
				построения гамильтоного цикла." << '\n';
			return;
		}
		cout << "Матрица смежности исходного графа: " << '\n';
		Print_M(graph.M);
		cout << '\n';
		cout << "Весовая матрица исходного графа: " << '\n';
		Print_M(graph.W);
		cout << '\n';

		fic_graph = Check_Hamilton(graph);
		cout << "Матрица смежности гамильтонова графа: " << '\n';
		Print_M(fic_graph.M);
		cout << '\n';
		cout << "Весовая матрица гамильтонова графа: " << '\n';
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