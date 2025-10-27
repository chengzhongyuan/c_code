# -*- coding: utf-8 -*-
import cv2
import numpy as np
import heapq

cell_size = 15
rows, cols = 50, 50
grid = np.zeros((rows, cols), dtype=np.uint8)
start, goal = (5, 5), (45, 45)

# £¨2x2 ·½¿é£©
np.random.seed(42)
for _ in range(100):
    x = np.random.randint(0, rows - 1)
    y = np.random.randint(0, cols - 1)
    for dx in [0, 1]:
        for dy in [0, 1]:
            if (x+dx, y+dy) != start and (x+dx, y+dy) != goal:
                grid[x+dx, y+dy] = 1

class Node:
    def __init__(self, x, y, g=0, h=0, parent=None):
        self.x, self.y = x, y
        self.g, self.h = g, h
        self.parent = parent
    def f(self): return self.g + self.h
    def __lt__(self, other): return self.f() < other.f()

def get_neighbors(node):
    neighbors = []
    for dx, dy in [(0,1),(1,0),(0,-1),(-1,0)]:
        nx, ny = node.x + dx, node.y + dy
        if 0 <= nx < rows and 0 <= ny < cols and grid[nx, ny] == 0:
            neighbors.append((nx, ny))
    return neighbors

def reconstruct_path(node):
    path = []
    while node:
        path.append((node.x, node.y))
        node = node.parent
    return path[::-1]

def draw_path(img, path, color):
    for x, y in path:
        px, py = y * cell_size, x * cell_size
        cv2.rectangle(img, (py, px), (py+cell_size, px+cell_size), color, -1)
        cv2.rectangle(img, (py, px), (py+cell_size, px+cell_size), (0,0,0), 1)

def draw_map(path1=None, path2=None):
    img = np.full((rows * cell_size, cols * cell_size, 3), 255, np.uint8)
    for i in range(rows):
        for j in range(cols):
            if grid[i, j] == 1:
                cv2.rectangle(img, (j*cell_size, i*cell_size), ((j+1)*cell_size, (i+1)*cell_size), (0,0,0), -1)
    cv2.rectangle(img, (start[1]*cell_size, start[0]*cell_size), ((start[1]+1)*cell_size, (start[0]+1)*cell_size), (255,0,0), -1)
    cv2.rectangle(img, (goal[1]*cell_size, goal[0]*cell_size), ((goal[1]+1)*cell_size, (goal[0]+1)*cell_size), (0,0,255), -1)
    if path1: draw_path(img, path1, (0,255,0))  # Green for A*
    if path2: draw_path(img, path2, (0,165,255))  # Orange for Dijkstra
    return img
def astar(start, goal):
    open_list = []
    heapq.heappush(open_list, Node(*start, h=heuristic(*start, *goal)))
    visited = set()
    while open_list:
        current = heapq.heappop(open_list)
        if (current.x, current.y) == goal:
            return reconstruct_path(current)
        visited.add((current.x, current.y))
        for nx, ny in get_neighbors(current):
            if (nx, ny) in visited:
                continue
            h = heuristic(nx, ny, *goal)
            neighbor = Node(nx, ny, g=current.g + 1, h=h, parent=current)
            heapq.heappush(open_list, neighbor)
    return []

def heuristic(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)
def dijkstra(start, goal):
    open_list = []
    heapq.heappush(open_list, Node(*start, g=0, h=0))
    dist = {start: 0}
    visited = set()

    while open_list:
        current = heapq.heappop(open_list)
        if (current.x, current.y) == goal:
            return reconstruct_path(current)
        visited.add((current.x, current.y))

        for nx, ny in get_neighbors(current):
            if (nx, ny) in visited:
                continue
            new_g = current.g + 1
            if (nx, ny) not in dist or new_g < dist[(nx, ny)]:
                dist[(nx, ny)] = new_g
                neighbor = Node(nx, ny, g=new_g, h=0, parent=current)
                heapq.heappush(open_list, neighbor)
    return []

path_astar = astar(start, goal)
path_dijkstra = dijkstra(start, goal)

img = draw_map(path1=path_astar, path2=path_dijkstra)
cv2.imshow("A* (Green) vs Dijkstra (Orange)", img)
cv2.imwrite("astar_vs_dijkstra.png", img)
cv2.waitKey(0)
cv2.destroyAllWindows()
