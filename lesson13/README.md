1. Реализовать обход графа в глубину с использованием стека void depthTraversStack(int** matrix, int size)
2. Дан готовый неориентированный, невзвешенный, несмежный простой граф с петельными связями(т.е. могут быть ребра из вершины A в вершину A).
Нужно обойти этот граф двумя способами и подсчитать количество ссылок на каждый из узлов графа (полустепень захода).
a) Обход графа по матрице смежности (с подсчётом всех вершин графа) - void adjacencyCount(int** matrix, const int size)
b) Обход графа функцией (с подсчётом только смежных со стартовой вершин) - void traversalCount(int** matrix, int start, const int size)
