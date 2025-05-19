/*
	Ввод вещественной матрицы построчно, а вывод по столбцам
*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Функция для ввода строки матрицы с проверкой
static vector<double> input_row_of_matrix(const int& n){
	vector<double> row(n);
	while(true){
		cout << "Введите " << n << " чисел: ";
		bool valid = true;
		for(int i = 0; i < n; i++){
			cin >> row[i];
			if(cin.fail()){  // Проверяем корректность ввода
				valid = false;
				cin.clear();
			}
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка лишнего ввода

		if(valid)
			return row; // Если все числа корректны, возвращаем строку

		cout << "Ошибка ввода! Попробуйте снова.\n";
	}
}

static void input_matrix_by_rows(vector<vector<double>>& matrix, const int& m, const int& n){
	for(int i = 0; i < m; i++){
		cout << "Строка " << (i + 1) << ":\n";
		matrix[i] = input_row_of_matrix(n);
	}
}

static void output_matrix_by_columns(vector<vector<double>>& matrix, const int& m, const int& n){
	cout << "\nВывод матрицы по столбцам:\n";
	for(int j = 0; j < n; j++){
		cout << "Столбец " << (j + 1) << ": ";
		for(int i = 0; i < m; i++)
			cout << matrix[i][j] << " ";

		cout << endl;
	}
}

int main(int argc, char* argv[]){
	setlocale(0, "Russian");
	// 1. Запрос размерности матрицы
	int m, n;
	cout << "Введите количество строк (m): ";
	cin >> m;
	cout << "Введите количество столбцов (n): ";
	cin >> n;

	// 2. Создание матрицы
	vector<vector<double>> matrix(m);

	// 3. Ввод матрицы построчно с проверками
	input_matrix_by_rows(matrix, m, n);

	// 4. Вывод матрицы по столбцам
	output_matrix_by_columns(matrix, m, n);
} 
