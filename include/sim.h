#ifndef _SIM_INCLUDED_
#define _SIM_INCLUDED_

#include <functional>
#include <queue>
#include <bits/stdc++.h>
#include <simplecpp.h>

namespace simplecpp{

class sim {
public:
    using Event = std::function<void()>;
    using ETpair = std::pair<Event, double>;
    struct compareETpair {
        bool operator()(const ETpair& p, const ETpair& q) const {
            return p.second > q.second;
        }
    };
    static double time;
    static std::priority_queue<ETpair, std::vector<ETpair>, compareETpair> pq;

public:
    static void post(double dT, Event e) {
        pq.push(std::make_pair(e, time + dT));
    }
    static double getTime() {
        return time;
    }
    static void processAll(double tmax = std::numeric_limits<double>::infinity()) {
        while (!pq.empty() && time < tmax) {
            ETpair ETp = pq.top();
            time = ETp.second;
            pq.pop();
            ETp.first();
        }
    }
    static std::ostream& log() {
        std::cout << time << ") ";
        return std::cout;
    }
};

class Resource {
public:
    using Event = std::function<void()>;
    std::queue<Event> q;
    bool inUse;

public:
    Resource() : inUse(false) {}
    int size() const {
        return q.size();
    }
    bool reserve() {
        if (inUse) {
            return false;
        } else {
            inUse = true;
            return true;
        }
    }
    void acquire(Event e) {
        if (!inUse) {
            inUse = true;
            sim::post(0, e);
        } else {
            q.push(e);
        }
    }
    void release() {
        if (!q.empty()) {
            inUse = true;
            Event e = q.front();
            q.pop();
            sim::post(0, e);
        } else {
            inUse = false;
        }
    }
};

}
#endif
