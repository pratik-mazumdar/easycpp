#pragma once
#include <vector>
#include "datatype.h"
namespace easycpp {
	class Matrix {
		std::vector<std::vector<long>> row;
		size_t total_row = 0;
		size_t total_coloum = 0;
	public:
		Matrix() {}
		Matrix(std::vector<std::vector<long>> row) { this->row = row; }
		void create_matrix(size_t total_row, size_t total_coloum) {
			this->total_row = total_row;
			this->total_coloum = total_coloum;
			for (size_t j = 0; j < total_row; j++) {
				std::vector <long> row_array;
				for (size_t i = 0; i < total_coloum;) {
					std::cout << "Coloum "<< ++i << " : ";
					row_array.push_back(integer_().to_long());
				}
				row.push_back(row_array);
			}
		}
		Matrix maltiply_matrix(Matrix matrix_two) {
			try {
				std::vector<std::vector<long>> final_matrix;
				for (size_t i = 0; i < total_row; i++) {
					std::vector <long> final_matrix_array;
					for (size_t j = 0; j < total_coloum; j++) {
						final_matrix_array.push_back(0);
						for (size_t k = 0; k < total_coloum; k++)
							final_matrix_array[j] += matrix_two.row[i][k] * row[k][j];
					}
					final_matrix.push_back(final_matrix_array);
				}
				return final_matrix;
			}
			catch (const std::out_of_range& e) { std::cout << "Out of Range error."; }
		}
		void display_matrix() {
			for (std::vector<long> each_vector : row) {
				for (long element : each_vector)
					std::cout << element << "\t";
				std::cout << "\n";
			}
		}
		Matrix operator + (Matrix matrix_two) {
			std::vector<std::vector<long>> final_matrix;
			if (matrix_two.total_coloum == total_coloum && matrix_two.total_row == total_row) {
				for (size_t i = 0; i < total_row; i++) {
					std::vector <long> final_matrix_array;
					for (size_t j = 0; j < total_coloum; j++) {
						final_matrix_array.push_back(matrix_two.row[i][j] + row[i][j]);
					}
					final_matrix.push_back(final_matrix_array);
				}
				return final_matrix;
			}
		}
		Matrix operator - (Matrix matrix_two) {
			std::vector<std::vector<long>> final_matrix;
			if (matrix_two.total_coloum == total_coloum && matrix_two.total_row == total_row) {
				for (size_t i = 0; i < total_row; i++) {
					std::vector <long> final_matrix_array;
					for (size_t j = 0; j < total_coloum; j++) {
						final_matrix_array.push_back(row[i][j] - matrix_two.row[i][j]);
					}
					final_matrix.push_back(final_matrix_array);
				}
				return final_matrix;
			}
		}
	};
}