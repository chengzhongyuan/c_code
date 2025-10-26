# -*- coding: utf-8 -*-
import cv2
import numpy as np
import heapq

class Node:
    def __init__(self, x, y, g=0, h=0, parent=None):
        self.x, self.y = x, y
        self.g, self.h = g, h
        self.parent = parent
    def f(self):
        return self.g + self.h
    def __lt__(self, other):
        return self.f() < other.f()

def heuristic(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

def get_neighbors(node, grid):
    neighbors = []
    for dx, dy in [(0,1),(1,0),(0,-1),(-1,0)]:
        nx, ny = node.x + dx, node.y + dy
        if 0 <= nx < grid.shape[0] and 0 <= ny < grid.shape[1] and grid[nx, ny] == 0:
            neighbors.append(Node(nx, ny))
    return neighbors

def astar(grid, start, goal, visualize_step=None):
    open_list = []
    heapq.heappush(open_list, Node(*start, h=heuristic(*start, *goal)))
    closed = set()
    while open_list:
        current = heapq.heappop(open_list)
        if (current.x, current.y) == goal:
            path = []
            while current:
                path.append((current.x, current.y))
                current = current.parent
            return path[::-1]
        closed.add((current.x, current.y))
        for neighbor in get_neighbors(current, grid):
            if (neighbor.x, neighbor.y) in closed:
                continue
            neighbor.g = current.g + 1
            neighbor.h = heuristic(neighbor.x, neighbor.y, *goal)
            neighbor.parent = current
            heapq.heappush(open_list, neighbor)
            if visualize_step:
                visualize_step(neighbor.x, neighbor.y)
    return []

def visualize_dynamic(grid, path, start, goal, delay=20, cell_size=15):
    rows, cols = grid.shape
    img = np.full((rows * cell_size, cols * cell_size, 3), 255, np.uint8)

    def draw_cell(x, y, color):
        cv2.rectangle(img, (y*cell_size, x*cell_size), ((y+1)*cell_size, (x+1)*cell_size), color, -1)

    # 绘制障碍物
    for i in range(rows):
        for j in range(cols):
            if grid[i, j] == 1:
                draw_cell(i, j, (0, 0, 0))

    # 绘制起点终点
    draw_cell(*start, (255, 0, 0))
    draw_cell(*goal, (0, 0, 255))

    # 实时绘制搜索过程
    def visualize_step(x, y):
        draw_cell(x, y, (200, 200, 200))
        cv2.imshow("A* Path", img)
        cv2.waitKey(delay)

    # 执行 A* 并获取路径
    final_path = astar(grid, start, goal, visualize_step)

    # 绘制最终路径
    for x, y in final_path:
        draw_cell(x, y, (0, 255, 0))
        cv2.imshow("A* Path", img)
        cv2.waitKey(delay)

    cv2.waitKey(0)
    cv2.destroyAllWindows()

# 示例地图
grid = np.zeros((50, 50), dtype=np.uint8)
grid[10:40, 25] = 1
start, goal = (5, 5), (45, 45)

visualize_dynamic(grid, [], start, goal)


# import cv2
# import numpy as np
# import heapq

# class Node:
#     def __init__(self, x, y, g=0, h=0, parent=None):
#         self.x, self.y = x, y
#         self.g, self.h = g, h
#         self.parent = parent
#     def f(self):
#         return self.g + self.h
#     def __lt__(self, other):
#         return self.f() < other.f()

# def heuristic(x1, y1, x2, y2):
#     return abs(x1 - x2) + abs(y1 - y2)

# def get_neighbors(node, grid):
#     neighbors = []
#     for dx, dy in [(0,1),(1,0),(0,-1),(-1,0)]:
#         nx, ny = node.x + dx, node.y + dy
#         if 0 <= nx < grid.shape[0] and 0 <= ny < grid.shape[1] and grid[nx, ny] == 0:
#             neighbors.append(Node(nx, ny))
#     return neighbors

# def astar(grid, start, goal):
#     open_list = []
#     heapq.heappush(open_list, Node(*start, h=heuristic(*start, *goal)))
#     closed = set()
#     while open_list:
#         current = heapq.heappop(open_list)
#         if (current.x, current.y) == goal:
#             path = []
#             while current:
#                 path.append((current.x, current.y))
#                 current = current.parent
#             return path[::-1]
#         closed.add((current.x, current.y))
#         for neighbor in get_neighbors(current, grid):
#             if (neighbor.x, neighbor.y) in closed:
#                 continue
#             neighbor.g = current.g + 1
#             neighbor.h = heuristic(neighbor.x, neighbor.y, *goal)
#             neighbor.parent = current
#             heapq.heappush(open_list, neighbor)
#     return []

# def visualize(grid, path, start, goal):
#     img = np.full((*grid.shape, 3), 255, np.uint8)
#     img[grid == 1] = [0, 0, 0]
#     for x, y in path:
#         img[x, y] = [0, 255, 0]
#     img[start] = [255, 0, 0]
#     img[goal] = [0, 0, 255]
#     img = cv2.resize(img, None, fx=10, fy=10, interpolation=cv2.INTER_NEAREST)
#     cv2.imshow("A* Path", img)
#     cv2.waitKey(0)

# # 示例地图
# grid = np.zeros((50, 50), dtype=np.uint8)
# grid[10:40, 25] = 1
# start, goal = (5, 5), (45, 45)
# path = astar(grid, start, goal)
# visualize(grid, path, start, goal)
