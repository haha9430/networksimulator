#include "auto_router.h"

// 라우팅 테이블에 라우팅 엔트리 추가
void AutoRouter::addRoutingEntry(const Address &destination, Link *nextLink) {
    RoutingEntry re(destination, nextLink);
    routingTable_.push_back(re);
}

// 최소 비용을 계산, 그에 따라 라우팅 테이블을 구성
void AutoRouter::calculate(const std::vector<Node *> &nodes,
                            const std::vector<Link *> &links) {      
    double INF = 1000000.0;
    std::vector<std::pair<double, Link *>> linkInfo;
    std::vector<std::vector<double>> valueInfo;

    // 인접 행렬 생성
    double matrix[1000][1000];
    for (int i = 0; i < (int)nodes.size(); i++) {
        for (int j = 0; i < (int)nodes.size(); j++) {
            Node* a = nodes[i];
            Node* b = nodes[j];

            for (int k = 0; k < (int)links.size(); k++) {
                Link* l = links[k];
                if(l->returnNodeA() == a && l->returnNodeB() == b) {
                    matrix[i][j] = l->delay();
                }
            }
        }
    }

    // 다익스트라를 돌리면서 호스트에 대한 최소경로로 갈 수 있는 다음 홉(링크에 있는 노드)을 기록
    for (int i = 0; i < (int)nodes.size(); i++) {
        Node* node = nodes[i];
        Host* host = dynamic_cast<Host*>(node);
        if (host == nullptr) {
            //...
        }
    }

    // 라우팅 테이블에 추가


    // 간선 정보
    for (int i = 0; i < (int)links.size(); i++) {
        double delay = links[i]->delay();
        linkInfo.push_back(std::make_pair(delay, links[i]));
    }

    // 최소 비용 테이블
    for (int i = 0; i < (int)nodes.size(); i++) {
        std::vector<double> d;
        for (int j = 0; j < (int)nodes.size(); j++) {
            d.push_back(INF);
        }
        valueInfo.push_back(d);
    }
    
    for (int i = 0; i < (int)nodes.size(); i++) {
        valueInfo[i][i] = 0.0;
        std::priority_queue<std::pair<double, Link *>> pq;
        pq.push(linkInfo[i]);

        while(!pq.empty()) {
            double cur = pq.top().first;
            double dis = -pq.top().first;
        }
    }

}

