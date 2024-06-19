#include "auto_router.h"

double INF = 1000000.0;

// 최소 비용을 계산, 그에 따라 라우팅 테이블을 구성
void AutoRouter::calculate(const std::vector<Node *> &nodes, const std::vector<Link *> &links) {      
    int n = nodes.size();
    // 인접 행렬
    std::vector<std::vector<double>> matrix(n, std::vector<double>(n, INF));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix[i][j] = 0;
            }else {
                Node* a = nodes[i];
                Node* b = nodes[j];

                for (int k = 0; k < (int)links.size(); k++) {
                    Link* l = links[k];
                    if(l->returnNodeA() == a && l->returnNodeB() == b) {
                        matrix[i][j] = l->delay();
                        break;
                    }
                }
            }
        }
    }

    // 다익스트라를 돌리면서 호스트에 대한 최소경로로 갈 수 있는 다음 홉(링크에 있는 노드)을 기록
    routingTable_.resize(n);
    
    for (int i = 0; i < n; i++) {
        std::vector<int> nextHop(n, -1);
        dijkstra(i, matrix, nextHop, nodes, links);

        // 라우팅 테이블 작성
        for (int j = 0; j < n; j++) {
            if (i != j && nextHop[j] != -1) {
                Node* node = nodes[i];
                Host* host = dynamic_cast<Host*>(node);
                Node* nextHopNode = nodes[nextHop[j]];
                Link* nextLink = nullptr;

                // 다음 홉 링크 찾기
                for (int k = 0; k < (int)links.size(); k++) {
                    if ((links[k]->returnNodeA() == nodes[i] && links[k]->returnNodeB() == nextHopNode) ||
                        (links[k]->returnNodeA() == nextHopNode && links[k]->returnNodeB() == nodes[i])) {
                        nextLink = links[k];
                        break;
                    }
                }

                if (nextLink != nullptr && host == nullptr) {
                    routingTable_.push_back(RoutingEntry(host->address(), nextLink));
                }
            }
        }
    }
}

void AutoRouter::dijkstra(int src, const std::vector<std::vector<double>> &matrix, std::vector<int> &nextHop, const std::vector<Node*> &nodes, const std::vector<Link*> &links) {
    int n = (int)matrix.size();
    std::vector<double> dist(n, INF);
    std::vector<bool> visited(n, false);
    dist[src] = 0;

    std::priority_queue<std::pair<double, int>> pq;
    pq.push({0.0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && matrix[u][v] < INF) {
                double newDist = dist[u] + matrix[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.push({newDist, v});
                    nextHop[v] = (u == src) ? v : nextHop[u];
                }
            }
        }
    }
}