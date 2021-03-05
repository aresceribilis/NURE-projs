#pragma once

// структура, которая представляет однозвязный список дуг
struct _Edge {
	int id_from;
	int id_to;
	int weight;
	_Edge* next;
};

// класс-контейнер для оброботки дуг
class _Graph {
	_Edge* head;
public:
	// для очистки графа
	void Clear_graph() {
		while (head)
			this->Pop(head->id_from, head->id_to);
	}
	// конструктор по умолчанию
	_Graph() : head(nullptr) {};
	 // для добавления дуги в граф
	int Add(int id_from, int id_to, int weight) {
		_Edge* tmp = head;
		_Edge* tmp_prev = tmp;
		if (head)
			while (tmp) {
				if (tmp->id_from == id_from && tmp->id_to == id_to) {
					if (tmp->weight > weight) {
						tmp->weight = weight;
						return 0;
					}
					return 1;
				}
				tmp_prev = tmp;
				tmp = tmp->next;
			}

			tmp = new _Edge;
			tmp->id_from = id_from;
			tmp->id_to = id_to;
			tmp->weight = weight;
			tmp->next = nullptr;

			if (!head)
				head = tmp;
			else
				tmp_prev->next = tmp;
	
			return 2;
	}
	// для удаления дуги из графа
	int Pop(int id_from, int id_to) {
		if (!head) return 0;

		int count = 0;
		_Edge* tmp = head;
		while (tmp->next) {
			if (tmp->id_from == id_from && tmp->id_to == id_to)
				break;
			tmp = tmp->next;
			++count;
		}
		if (!count) {
			if (!tmp->next) {
				if (tmp->id_from != id_from || tmp->id_to != id_to)
					return 2;
				delete head;
				head = nullptr;
				return 1;
			}
			else {
				if (tmp->id_from != id_from || tmp->id_to != id_to)
					return 2;
				head = tmp->next;
				tmp->next = nullptr;
				delete tmp;
				return 1;
			}
		}
		else {
			tmp = head;
			_Edge* tmp_prev = tmp;
			while (tmp->next) {
				if (tmp->id_from == id_from && tmp->id_to == id_to)
					break;
				tmp_prev = tmp;
				tmp = tmp->next;
			}
			if (tmp->id_from == id_from && tmp->id_to == id_to) {
				tmp_prev->next = tmp->next;
				tmp->next = nullptr;
				delete tmp;
				return 1;
			}
			return 2;
		}
	}
	// возвращает матрицу весов графа
	int** get_weight_matrix() {
		_Edge* tmp = head;
		int count_of_elems = 0;
		while (tmp) {
			tmp = tmp->next;
			++count_of_elems;
		}

		int* all_vertexes = new int[count_of_elems * 2];
		tmp = head;
		for (int i = 0; i < count_of_elems; ++i) {
			all_vertexes[2 * i] = tmp->id_from;
			all_vertexes[2 * i + 1] = tmp->id_to;
			tmp = tmp->next;
		}

		for (int i = 0, tmp_swap; i < count_of_elems * 2; ++i) {
			for (int j = i; j < count_of_elems * 2; ++j) {
				if (all_vertexes[i] > all_vertexes[j]) {
					tmp_swap = all_vertexes[i];
					all_vertexes[i] = all_vertexes[j];
					all_vertexes[j] = tmp_swap;
				}
			}
		}

		int count_of_unique = 0;
		for (int i = 0; i < count_of_elems * 2 - 1; ++i)
			if (all_vertexes[i] != all_vertexes[i + 1])
				++count_of_unique;
		
		if (count_of_unique)
			++count_of_unique;

		if (count_of_unique) {
			int** weight_matrix = new int* [count_of_unique];
			for (int i = 0; i < count_of_unique; ++i)
				weight_matrix[i] = new int[count_of_unique];

			for (int i = 0; i < count_of_unique; ++i)
				for (int j = 0; j < count_of_unique; ++j)
					weight_matrix[i][j] = 0;

			int* ids = new int[count_of_unique];
			ids[0] = all_vertexes[0];
			for (int i = 0, j = 0; j < count_of_unique - 1; ++i) {
				if (all_vertexes[i] != all_vertexes[i + 1])
					ids[++j] = all_vertexes[i + 1];
			}

			tmp = head;
			for (int i = 0, id_from = 0, id_to = 0; i < count_of_elems; ++i, id_from = 0, id_to = 0) {
				for (int j = 0; j < count_of_unique; ++j) {
					if (ids[j] == tmp->id_from)
						id_from = j;
				}
				for (int j = 0; j < count_of_unique; ++j) {
					if (ids[j] == tmp->id_to)
						id_to = j;
				}
				weight_matrix[id_from][id_to] = tmp->weight;
				//weight_matrix[id_to][id_from] = tmp->weight;
				tmp = tmp->next;
			}

			return weight_matrix;
		}
		else
			return nullptr;
	}
	// возвращает массив вершин графа
	int* get_array_of_unique() {
		int* array_of_unique;
		int count_of_unique = this->get_count_of_unique();
		array_of_unique = new int[count_of_unique];

		_Edge* tmp = head;
		int count_of_elems = 0;
		while (tmp) {
			tmp = tmp->next;
			++count_of_elems;
		}

		int* all_vertexes = new int[count_of_elems * 2];
		tmp = head;
		for (int i = 0; i < count_of_elems; ++i) {
			all_vertexes[2 * i] = tmp->id_from;
			all_vertexes[2 * i + 1] = tmp->id_to;
			tmp = tmp->next;
		}

		for (int i = 0, tmp_swap; i < count_of_elems * 2; ++i) {
			for (int j = i; j < count_of_elems * 2; ++j) {
				if (all_vertexes[i] > all_vertexes[j]) {
					tmp_swap = all_vertexes[i];
					all_vertexes[i] = all_vertexes[j];
					all_vertexes[j] = tmp_swap;
				}
			}
		}

		/*int count_of_unique = 0;
		for (int i = 0; i < count_of_elems * 2 - 1; ++i)
			if (all_vertexes[i] != all_vertexes[i + 1])
				++count_of_unique;

		if (count_of_unique)
			++count_of_unique;*/

		if (count_of_unique) {
			int** weight_matrix = new int* [count_of_unique];
			for (int i = 0; i < count_of_unique; ++i)
				weight_matrix[i] = new int[count_of_unique];

			for (int i = 0; i < count_of_unique; ++i)
				for (int j = 0; j < count_of_unique; ++j)
					weight_matrix[i][j] = 0;

			array_of_unique[0] = all_vertexes[0];
			for (int i = 0, j = 0; j < count_of_unique - 1; ++i) {
				if (all_vertexes[i] != all_vertexes[i + 1])
					array_of_unique[++j] = all_vertexes[i + 1];
			}
		}

		return array_of_unique;
	}
	// возвращает кол-во вершин графа
	int get_count_of_unique() {
		_Edge* tmp = head;
		int count_of_elems = 0;
		while (tmp) {
			tmp = tmp->next;
			++count_of_elems;
		}

		int* all_vertexes = new int[count_of_elems * 2];
		tmp = head;
		for (int i = 0; i < count_of_elems; ++i) {
			all_vertexes[2 * i] = tmp->id_from;
			all_vertexes[2 * i + 1] = tmp->id_to;
			tmp = tmp->next;
		}

		for (int i = 0, tmp_swap; i < count_of_elems * 2; ++i) {
			for (int j = i; j < count_of_elems * 2; ++j) {
				if (all_vertexes[i] > all_vertexes[j]) {
					tmp_swap = all_vertexes[i];
					all_vertexes[i] = all_vertexes[j];
					all_vertexes[j] = tmp_swap;
				}
			}
		}

		int count_of_unique = 0;
		for (int i = 0; i < count_of_elems * 2 - 1; ++i)
			if (all_vertexes[i] != all_vertexes[i + 1])
				++count_of_unique;

		if (count_of_unique)
			++count_of_unique;
		
		return count_of_unique;
	}
	// поиск в глубину в графе
	void dfs(int source, bool* used, int** matrix, int size) {
		used[source] = 1;
		for (int i = 0; i < size; i++) {
			if (used[i] == 0 && (matrix[source][i]/* || matrix[i][source]*/))
				dfs(i, used, matrix, size);
		}
	}
	// возвращает кол-во компонент связности графа
	int get_connectivity_component_count() {
		int count = 0;
		int size = this->get_count_of_unique();
		int** matrix = this->get_weight_matrix();

		bool* used = new bool[size];
		for (int i = 0; i < size; ++i)
			used[i] = 0;

		for (int i = 0; i < size; i++) {
			if (used[i] == 0) {
				this->dfs(i, used, matrix, size);
				++count;
			}
		}

		return count;
	}
	// возвращает матрицу кратчайших расстояний
	int** get_minimal_ways() {
		int** weight_matrix = this->get_weight_matrix();
		int* array_of_unique = this->get_array_of_unique();
		int count_of_unique = this->get_count_of_unique();
		int** distances = new int*[count_of_unique];
		if (count_of_unique)
			for (int k = 0; k < count_of_unique; ++k) {

				int* distance = new int[count_of_unique];
				bool* visited = new bool[count_of_unique];

				for (int i = 0; i < count_of_unique; ++i) {
					distance[i] = 1000000;
					visited[i] = false;
				}
				distance[k] = 0;

				for (int count = 0, index, min = 1000000; count < count_of_unique - 1; ++count, min = 1000000) {
					for (int i = 0; i < count_of_unique; ++i)
						if (!visited[i] && distance[i] <= min) {
							min = distance[i];
							index = i;
						}
					visited[index] = true;
					for (int i = 0; i < count_of_unique; ++i)
						if (!visited[i] && weight_matrix[index][i] && distance[index] != 1000000 && distance[index] + weight_matrix[index][i] < distance[i])
							distance[i] = distance[index] + weight_matrix[index][i];
				}

				distances[k] = distance;
			}
		else 
			distances = nullptr;

		return distances;
	}
	// возвращает множество инциденций минимального остова
	int** get_minimal_ostov() {
		int** weight_matrix = this->get_weight_matrix();
		int* array_of_unique = this->get_array_of_unique();
		int count_of_unique = this->get_count_of_unique();

		if (!count_of_unique) return nullptr;

		bool* visited = new bool[count_of_unique];
		for (int i = 0; i < count_of_unique; ++i)
			visited[i] = false;
		visited[0] = true;

		int** minimal_ostov = new int* [count_of_unique - 1];
		for (int i = 0; i < count_of_unique - 1; ++i)
			minimal_ostov[i] = new int[3];

		for (int l = 0; l < count_of_unique - 1; ++l) {
			int min_target = -1, min_source = -1;
			for (int i = 0; i < count_of_unique; ++i)
				if (visited[i])
					for (int j = 0; j < count_of_unique; ++j)
						if (!visited[j] && weight_matrix[i][j] > 0 && (min_source == -1 || weight_matrix[i][j] < weight_matrix[min_source][min_target]))
							min_source = i, min_target = j;
			visited[min_target] = true;
			minimal_ostov[l][0] = min_source;
			minimal_ostov[l][1] = min_target;
			minimal_ostov[l][2] = weight_matrix[min_source][min_target];
		}

		return minimal_ostov;
	}
	// возвращает кол-во рёбер
	int get_count_of_edges() {
		int count = 0;
		_Edge* tmp = this->head;
		while (tmp) {
			++count;
			tmp = tmp->next;
		}
		return count;
	}

};