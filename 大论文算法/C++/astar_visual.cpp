#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

struct AStarNode {
    int x, y;
    float g, h;
    AStarNode* parent;
    float f() const { return g + h; }
};

struct Compare {
    bool operator()(const AStarNode* a, const AStarNode* b) {
        return a->f() > b->f();
    }
};

float heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2); // 曼哈顿距离
}

vector<AStarNode*> getNeighbors(AStarNode* current, const vector<vector<int>>& map) {
    vector<AStarNode*> neighbors;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    for (int i = 0; i < 4; ++i) {
        int nx = current->x + dx[i];
        int ny = current->y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < map.size() && ny < map[0].size() && map[nx][ny] == 0) {
            neighbors.push_back(new AStarNode{nx, ny, 0, 0, nullptr});
        }
    }
    return neighbors;
}

vector<AStarNode*> aStar(const vector<vector<int>>& map, Point start, Point goal) {
    priority_queue<AStarNode*, vector<AStarNode*>, Compare> open;
    vector<vector<bool>> closed(map.size(), vector<bool>(map[0].size(), false));
    AStarNode* startNode = new AStarNode{start.x, start.y, 0, heuristic(start.x, start.y, goal.x, goal.y), nullptr};
    open.push(startNode);

    while (!open.empty()) {
        AStarNode* current = open.top(); open.pop();
        if (current->x == goal.x && current->y == goal.y) {
            vector<AStarNode*> path;
            while (current) {
                path.push_back(current);
                current = current->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        closed[current->x][current->y] = true;
        for (AStarNode* neighbor : getNeighbors(current, map)) {
            if (closed[neighbor->x][neighbor->y]) continue;
            neighbor->g = current->g + 1;
            neighbor->h = heuristic(neighbor->x, neighbor->y, goal.x, goal.y);
            neighbor->parent = current;
            open.push(neighbor);
        }
    }
    return {};
}

void visualize(const vector<vector<int>>& map, const vector<AStarNode*>& path, Point start, Point goal) {
    Mat img(map.size(), map[0].size(), CV_8UC3, Scalar(255,255,255));
    for (int i = 0; i < map.size(); ++i)
        for (int j = 0; j < map[0].size(); ++j)
            if (map[i][j] == 1)
                img.at<Vec3b>(i,j) = Vec3b(0,0,0); // 黑色障碍物

    for (AStarNode* node : path)
        img.at<Vec3b>(node->x, node->y) = Vec3b(0,255,0); // 绿色路径

    img.at<Vec3b>(start.x, start.y) = Vec3b(255,0,0); // 蓝色起点
    img.at<Vec3b>(goal.x, goal.y) = Vec3b(0,0,255);   // 红色终点

    resize(img, img, Size(), 10, 10, INTER_NEAREST);
    imshow("A* Path", img);
    waitKey(0);
}

int main() {
    vector<vector<int>> map(50, vector<int>(50, 0));
    for (int i = 10; i < 40; ++i)
        map[i][25] = 1; // 添加障碍物

    Point start(5, 5), goal(45, 45);
    vector<AStarNode*> path = aStar(map, start, goal);
    visualize(map, path, start, goal);
    return 0;
}

