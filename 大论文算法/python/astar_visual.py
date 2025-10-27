# # -*- coding: utf-8 -*-
# # -*- coding: utf-8 -*-
# import cv2
# import numpy as np
# import heapq

# # 参数设置
# cell_size = 15
# rows, cols = 50, 50
# grid = np.zeros((rows, cols), dtype=np.uint8)
# start = None
# goal = None

# # 自动生成障碍（每个障碍是 2x2 方块）
# np.random.seed(42)
# num_blocks = 100
# for _ in range(num_blocks):
#     x = np.random.randint(0, rows - 1)
#     y = np.random.randint(0, cols - 1)
#     block = [(x, y), (x+1, y), (x, y+1), (x+1, y+1)]
#     if all((bx, by) != (5, 5) and (bx, by) != (45, 45) for bx, by in block):
#         for bx, by in block:
#             grid[bx, by] = 1

# # A* 节点类
# class Node:
#     def __init__(self, x, y, g=0, h=0, parent=None):
#         self.x, self.y = x, y
#         self.g, self.h = g, h
#         self.parent = parent
#     def f(self): return self.g + self.h
#     def __lt__(self, other): return self.f() < other.f()

# # 启发函数
# def heuristic(x1, y1, x2, y2):
#     return abs(x1 - x2) + abs(y1 - y2)

# # 获取邻居节点
# def get_neighbors(node, grid):
#     neighbors = []
#     for dx, dy in [(0,1),(1,0),(0,-1),(-1,0)]:
#         nx, ny = node.x + dx, node.y + dy
#         if 0 <= nx < rows and 0 <= ny < cols and grid[nx, ny] == 0:
#             neighbors.append(Node(nx, ny))
#     return neighbors

# # A* 算法
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

# # 绘制地图网格
# def draw_grid(img):
#     for i in range(rows):
#         for j in range(cols):
#             x, y = j * cell_size, i * cell_size
#             color = (255,255,255)
#             if grid[i,j] == 1:
#                 color = (0,0,0)
#             cv2.rectangle(img, (x,y), (x+cell_size, y+cell_size), color, -1)
#             cv2.rectangle(img, (x,y), (x+cell_size, y+cell_size), (200,200,200), 1)

#     if start:
#         x, y = start[1]*cell_size, start[0]*cell_size
#         cv2.rectangle(img, (x,y), (x+cell_size, y+cell_size), (255,0,0), -1)
#     if goal:
#         x, y = goal[1]*cell_size, goal[0]*cell_size
#         cv2.rectangle(img, (x,y), (x+cell_size, y+cell_size), (0,0,255), -1)

# # 绘制路径
# def draw_path(img, path):
#     for x, y in path:
#         px, py = y * cell_size, x * cell_size
#         cv2.rectangle(img, (px, py), (px+cell_size, py+cell_size), (0,255,0), -1)
#         cv2.rectangle(img, (px, py), (px+cell_size, py+cell_size), (0,0,0), 1)

# # 鼠标事件：点击设置起点和终点
# def mouse_event(event, x, y, flags, param):
#     global start, goal
#     i, j = y // cell_size, x // cell_size
#     if event == cv2.EVENT_LBUTTONDOWN:
#         if start is None:
#             start = (i, j)
#         elif goal is None:
#             goal = (i, j)

# # 主程序
# def main():
#     global start, goal
#     cv2.namedWindow("A* Visualizer")
#     cv2.setMouseCallback("A* Visualizer", mouse_event)

#     while True:
#         img = np.full((rows * cell_size, cols * cell_size, 3), 255, np.uint8)
#         draw_grid(img)

#         if start and goal:
#             path = astar(grid, start, goal)
#             draw_path(img, path)

#         cv2.imshow("A* Visualizer", img)
#         key = cv2.waitKey(10)

#         if key == ord('r'):
#             start, goal = None, None
#         elif key == ord('s'):
#             cv2.imwrite("astar_path.png", img)
#             print("Path image saved as astar_path.png")
#         elif key == 27:  # ESC
#             break

#     cv2.destroyAllWindows()

# main()



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

def visualize_dynamic(grid, path, start, goal, delay=5, cell_size=15):
    rows, cols = grid.shape
    img = np.full((rows * cell_size, cols * cell_size, 3), 255, np.uint8)

    def draw_cell(x, y, fill_color, border_color=(50, 50, 50)):
        top_left = (y * cell_size, x * cell_size)
        bottom_right = ((y + 1) * cell_size, (x + 1) * cell_size)
        cv2.rectangle(img, top_left, bottom_right, fill_color, -1)
        cv2.rectangle(img, top_left, bottom_right, border_color, 1)

    # 绘制障碍物
    for i in range(rows):
        for j in range(cols):
            if grid[i, j] == 1:
                draw_cell(i, j, (0, 0, 0), (100, 100, 100))  # 黑色障碍 + 灰色边框

    # 绘制起点终点
    draw_cell(*start, (255, 0, 0))  # 蓝色起点
    draw_cell(*goal, (0, 0, 255))   # 红色终点

    # 实时绘制搜索过程
    def visualize_step(x, y):
        draw_cell(x, y, (200, 200, 200))  # 灰色探索路径
        cv2.imshow("A* Path", img)
        cv2.waitKey(delay)

    # 执行 A* 并获取路径
    final_path = astar(grid, start, goal, visualize_step)

    # 绘制最终路径
    for x, y in final_path:
        draw_cell(x, y, (0, 255, 0))  # 绿色路径
        cv2.imshow("A* Path", img)
        cv2.waitKey(delay)
    # 保存图像
    cv2.imwrite("astar_result.png", img)
    print("Path image saved as astar_result.png")

    cv2.waitKey(0)
    cv2.destroyAllWindows()

# 示例地图
grid = np.zeros((50, 50), dtype=np.uint8)
start, goal = (5, 5), (45, 45)
np.random.seed(42)  # 可选：设置随机种子保证每次一致
num_obstacles = 100  # 障碍点数量
for _ in range(num_obstacles):
    x = np.random.randint(0, grid.shape[0] - 1)
    y = np.random.randint(0, grid.shape[1] - 1)
    block = [(x, y), (x+1, y), (x, y+1), (x+1, y+1)]
    if all((bx, by) != start and (bx, by) != goal for bx, by in block):
        for bx, by in block:
            grid[bx, by] = 1

# grid[10:40, 25] = 1 固定地图


visualize_dynamic(grid, [], start, goal)


# # -*- coding: utf-8 -*-
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

# def astar(grid, start, goal, visualize_step=None):
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
#             if visualize_step:
#                 visualize_step(neighbor.x, neighbor.y)
#     return []

# def visualize_dynamic(grid, path, start, goal, delay=20, cell_size=15):
#     rows, cols = grid.shape
#     img = np.full((rows * cell_size, cols * cell_size, 3), 255, np.uint8)

#     def draw_cell(x, y, color):
#         cv2.rectangle(img, (y*cell_size, x*cell_size), ((y+1)*cell_size, (x+1)*cell_size), color, -1)

#     # 绘制障碍物
#     for i in range(rows):
#         for j in range(cols):
#             if grid[i, j] == 1:
#                 draw_cell(i, j, (0, 0, 0))

#     # 绘制起点终点
#     draw_cell(*start, (255, 0, 0))
#     draw_cell(*goal, (0, 0, 255))

#     # 实时绘制搜索过程
#     def visualize_step(x, y):
#         draw_cell(x, y, (200, 200, 200))
#         cv2.imshow("A* Path", img)
#         cv2.waitKey(delay)

#     # 执行 A* 并获取路径
#     final_path = astar(grid, start, goal, visualize_step)

#     # 绘制最终路径
#     for x, y in final_path:
#         draw_cell(x, y, (0, 255, 0))
#         cv2.imshow("A* Path", img)
#         cv2.waitKey(delay)

#     cv2.waitKey(0)
#     cv2.destroyAllWindows()

# # 示例地图
# grid = np.zeros((50, 50), dtype=np.uint8)
# grid[10:40, 25] = 1
# start, goal = (5, 5), (45, 45)

# visualize_dynamic(grid, [], start, goal)


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
