#include <sim.h>
#include <simplecpp.h>


namespace simplecpp{

double sim::time = 0;
std::priority_queue< sim::ETpair, std::vector<sim::ETpair>, sim::compareETpair> sim::pq;
}
