#include <iostream>
//#include <ctime>
#include <fstream>
#include <cstdlib>
#include <random>
#include <chrono>
#include "include/ListaPos_LSE.h"
#include "include/Algoritmos.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[])
{

	// Generador de numeros aleatorios //
	
	//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	//std::mt19937 RNG(seed);
	
	std::mt19937 RNG;


	// Archivo al que se van a escribir los resultados de las pruebas
	if (argc < 2)
		return -1;

	char* filename = argv[1];
    std::ofstream outFile;       
	outFile.open(filename);


	///////////////////////////
	// Cifras significativas //
	// outFile.precision(10);

	const int MIN = 100;
	const int MAX = 2000;
	const int STEP = 2;

	int total_pruebas = (MAX-MIN)/STEP;
	///////////////////////////


	////////////////////////////////////////////////////////////
	// Por cada n guardamos mejor caso, peor caso, y promedio //
	const int MEJOR = 0;
	const int PROM = 1;
	const int PEOR = 2;

	double datos[total_pruebas][3];
	////////////////////////////////////////////////////////////



	int n = MIN;
	for (int prueba = 0; prueba < total_pruebas; prueba++)
	{
		/////////////////////////////////////////////
		// La lista se llena de numeros aleatorios //
		
		//cout << "Construyendo Lista " << n << endl;
		ListaIndex<int> L[10];
		for (int j = 0; j < 10; j++) {
			for (int i = 0; i < n; i++) {
				L[j].Insertar(L[j].NumElem()+1,(int)RNG());
			}
		}


		///////////////////////////
		// Aqui van las pruebas: //
		//cout << "Prueba " << n << endl;
		
		steady_clock::time_point begin;
		steady_clock::time_point end;


		// Prueba tiempo quicksort
		int cant_iteraciones = 1;
		double tiempos[cant_iteraciones];

		int iter = 0;
		//ListaPos<int>::pos_t pos;
		//while (iter < cant_iteraciones) {
		cout << "Sorting for " << n << endl;

			// Se cuentan los ciclos de relo
			//begin = clock();
			begin = steady_clock::now();
			Quicksort(L[0]);
			end = steady_clock::now();
			//end = clock();

			// 
			//double elapsed_secs = ((double)(end-begin))/CLOCKS_PER_SEC;
			duration<double> elapsed_secs = duration_cast<duration<double>>(end-begin);
			
			tiempos[iter] = elapsed_secs.count();
		//}

		
		///////////////////////////////////////////////
		// Se calcula el promedio, mejor y peor caso //
		double mejor, peor, sum, prom;
		mejor = tiempos[0];
		peor = tiempos[0];
		sum = 0 ;
		for (int i = 0; i < cant_iteraciones; i++) {
			mejor = tiempos[i] < mejor ? tiempos[i] : mejor;
			peor = tiempos[i] > peor ? tiempos[i] : peor;
			sum += tiempos[i];
		}
		prom = sum/(double)cant_iteraciones;
		
		datos[prueba][MEJOR] = mejor;
		datos[prueba][PEOR] = peor;
		datos[prueba][PROM] = prom;
		///////////////////////////////////////////////
		
		n += STEP;
	}

	////////////////////////////////////////
	// Escribir al archivo los resultados //
	
	n = MIN;
	for (int i = 0; i < total_pruebas; i++)
	{
		outFile << n << ",";
		outFile << datos[i][MEJOR] << ",";
		outFile << datos[i][PROM] << ",";
		outFile << datos[i][PEOR];
		outFile << endl;
		n += STEP;
	}
	outFile.close();
	//                                    //
	////////////////////////////////////////
}

