#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point {
    double x, y;

    // Конструктор для удобства
    Point(double x, double y) : x(x), y(y) {}
};

// Функция для вычисления расстояния между двумя точками
double distance(const Point& p1, const Point& p2) {
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}

// Функция для решения задачи коммивояжера методом ближайшего соседа
std::vector<int> tspNearestNeighbor(const std::vector<Point>& points) {
    int n = points.size();
    std::vector<int> tour;
    std::vector<bool> visited(n, false);

    // Начинаем с первой точки
    int current = 0;
    tour.push_back(current);
    visited[current] = true;

    // Итеративно выбираем ближайший непосещенный город
    for (int i = 1; i < n; ++i) {
        int nearestCity = -1;
        double minDistance = std::numeric_limits<double>::max();

        for (int j = 0; j < n; ++j) {
            if (!visited[j] && j != current) {
                double dist = distance(points[current], points[j]);
                if (dist < minDistance) {
                    minDistance = dist;
                    nearestCity = j;
                }
            }
        }

        // Переходим к ближайшему городу
        current = nearestCity;
        tour.push_back(current);
        visited[current] = true;
    }

    return tour;
}

int main() {
    setlocale(LC_ALL, "rus");
     
    // Пример использования
    std::vector<Point> points = { {0, 0}, {1, 2}, {2, 4}, {3, 1}, {4, 3} };
    std::vector<int> tour = tspNearestNeighbor(points);

    // Выводим порядок посещения городов
    std::cout << "Order of cities visited: ";
    for (int city : tour) {
        std::cout << city << " ";
    }
    std::cout << std::endl;

    return 0;
}
