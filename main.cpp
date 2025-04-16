#include<vector>
#include<iostream>
#include <iomanip> 
#include "functions.h"

using namespace std;




void main() 
{
	/*setlocale(LC_ALL, "russian");
	setiosflags(ios::left);
	
	auto graph = For_Gen(true);
	while (true)
	{
		bool fl = false;
		int x;
		cout << '\n' << "Сгенерировать граф - 1" << '\n';
		cout << "Метод Шимбелла - 2" << '\n';
		cout << "Количество таковых маршрутов из одной вершины в другую - 3" << '\n';
		cout << "Алгоритм Дейкстры - 4" << '\n';
		cout << "Поиск в глубину - 5" << '\n';
		cout << "Максимальный путь - 6" << '\n';
		cout << "Перейти к потокам - 7(Необходимо перегенерировать матрицы)" << '\n';
		cout << "Количество остовов графа - 8" << '\n';
		cout << "Минимальный по весу остов по алгоритму Краскала - 9" << '\n';
		cout << "Минимальный по весу остов по алгоритму Прима - 10" << '\n';
		cout << "Кодирование остова через код Прюфера - 11" << '\n';
		cout << "Переход к эйлерову графу - 12" << '\n';
		cout << "Переход к гамильтонову графу - 13" << '\n';
		cout << "Выход - 0" << '\n' << '\n';
		cin >> x;
		switch (x)
		{
		case(1):
			graph = For_Gen(true);
			break;
		case(2):
			For_Shimbell(graph);
			break;
		case(3):
			For_Alg(graph, 0);
			break;
		case(4):
			For_Alg(graph, 1);
			break;
		case(5):
			For_Alg(graph, 2);
			break;
		case(6):
			For_Alg(graph, 3);
			break;
		case(7):
			For_Flow(graph);
			break;
		case(8):
			For_Tree(graph, 1);
			break;
		case(9):
			For_Tree(graph, 2);
			break;
		case(10):
			For_Tree(graph, 3);
			break;
		case(11):
			For_Tree(graph, 4);
			break;
		case(12):
			For_Cycles(graph, 1);
			break;
		case(13):
			For_Cycles(graph, 2);
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
	}*/
	/*double sumi0 = 0;
	double sumi1 = 0;
	double sumi2 = 0;
	double sumi3 = 0;
	double sumi4 = 0;
	double sumi5 = 0;

	for (int i = 0; i < 10000; i++)
	{
		double x = fabs(Gamma(0.5, 1));
		if (x < 1)
		{
			sumi0 ++;
		}
		else if (x >= 1 and x < 2)
		{
			sumi1++;
		}
		else if (x >= 2 and x < 3)
		{
			sumi2++;
		}
		else if (x >= 4 and x < 5)
		{
			sumi3++;
		}
		else if (x >= 6 and x < 7)
		{
			sumi4++;
		}
		else if (x >= 7 and x < 8)
		{
			sumi5++;
		}
	}
	cout << sumi0 / 10000 << '\n';
	cout << sumi1 / 10000 << '\n';
	cout << sumi2 / 10000 << '\n';
	cout << sumi3 / 10000 << '\n';
	cout << sumi4 / 10000 << '\n';
	cout << sumi5 / 10000 << '\n';*/
	
	{
		/*OrGraph graph(7);
		graph.W = { 
		{0, 3, 4, 10, 0, 0, 0},
		{0, 0, 0, 6, 2, 0, 0},
		{0, 0, 0, 8, 0, 0, 3},
		{0, 0, 0, 0, -7, 0, -5},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, -5, 0, 0},
		{0, 0, 0, 0, -3, 1, 0}
		};
		graph.M = {
		{0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 1, 1, 0, 0},
		{0, 0, 0, 1, 0, 0, 1},
		{0, 0, 0, 0, 1, 0, 1},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 1, 0}
		};*/
	//	/*OrGraph graph(7);
	//	graph.M = {
	//	{0, 1, 1, 0, 0, 0, 0},
	//	{0, 0, 0, 1, 0, 0, 0},
	//	{0, 0, 0, 1, 1, 1, 0},
	//	{0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 1, 0, 1},
	//	{0, 0, 0, 0, 0, 0, 0}
	//	};*/
	//	Alg_Dijkstra(graph, 1, 5);
	//	OrGraph graph(6);
	//	graph.W = {
	//	{0, 13, 11, 0, 0, 0},
	//	{0, 0, 11, 6, 0, 0},
	//	{0, 0, 0, 11, 13, 17},
	//	{0, 0, 0, 0, 9, 0},
	//	{0, 0, 0, 0, 0, 10},
	//	{0, 0, 0, 0, 0, 0},
	//	};
	//	graph.M = {
	//	{0, 1, 1, 0, 0, 0},
	//	{0, 0, 1, 1, 0, 0},
	//	{0, 0, 0, 1, 1, 1},
	//	{0, 0, 0, 0, 1, 0},
	//	{0, 0, 0, 0, 0, 1},
	//	{0, 0, 0, 0, 0, 0},
	//	};


	//	/*auto graph = For_Gen();*/

	//	graph.T = graph.W;

	//	/*Graph_Throughput_Matrix(graph);*/

	//	graph.P = {
	//	{0, 9, 10, 0, 0, 0},
	//	{0, 0, 12, 9, 0, 0},
	//	{0, 0, 0, 7, 9, 13},
	//	{0, 0, 0, 0, 14, 0},
	//	{0, 0, 0, 0, 0, 9},
	//	{0, 0, 0, 0, 0, 0},
	//	};


	//	

	//	cout << '\n';
	//	Print_M(graph.T);
	//	cout << '\n';
	//	Print_M(graph.P);
	//	cout << '\n';

	//

	//	/*for (auto x : tmp)
	//	{
	//		cout << x << '\t';
	//	}*/
	//	
	//	cout << '\n';
	//	cout << Minimum_Flow(graph, 0, 5) << '\n';
	
	
		/*OrGraph graph(7);
		
		graph.M = {
		{0, 1, 1, 1, 0, 0, 0},
		{0, 0, 1, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 1, 0},
		{0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0},
		};
		graph.W = {
		{0, 2, 3, 3, 0, 0, 0},
		{0, 0, 4, 0, 3, 0, 0},
		{0, 0, 0, 0, 1, 6, 0},
		{0, 0, 0, 0, 0, 7, 0},
		{0, 0, 0, 0, 0, 8, 0},
		{0, 0, 0, 0, 0, 0, 9},
		{0, 0, 0, 0, 0, 0, 0},
		};*/
		/*OrGraph graph(4);

		graph.M = {
		{0, 1, 1, 0},
		{1, 0, 1, 0},
		{1, 1, 0, 1},
		{0, 0, 1, 0}
		};*/


		
		/*auto graph = For_Gen(1);
		
		auto x = Prim_Algorithm(graph);
		auto v = Pruefer_Code(x);



		for (int i : v )
		{
			cout << i << '\t';
		}
		cout << '\n';
		Print_M(x.M);
		cout << '\n';
		cout << '\n';
		cout << '\n';
		Print_M(Pruefer_deCode(v));
		*/

		
		
		/*auto G = Check_Euler(graph);
		cout << '\n';
		Print_M(G.M);
		cout << '\n';
		
		auto V = Euler_Cycle(G);
		cout << '\n';
		for (int x : V)
		{
			cout << x + 1 << '\t';
		}*/

		/*auto graph = For_Gen(1);
		auto G = Check_Hamilton(graph);

		cout << '\n';
		Print_M(G.M);
		cout << '\n';*/

		/*auto graph = For_Gen(1);
		auto G = Check_Hamilton(graph);

		cout << '\n';
		Print_M(G.M);
		cout << '\n';

		auto V = Hamilton_Cycle(G);

		for (auto x: V)
		{
			cout << x[0] + 1;
			for (int i = 1; i < x.size(); i++)
			{
				cout << " -> " << x[i] + 1;
			}
			cout << '\n';
		}

		TSP(G, V);*/


		vector<vector<double>> m = { {5,7,1},{-4,1,0},{2,0,3} };
		cout << Matrix_Determinant(m) << '\n';
	}
	

}