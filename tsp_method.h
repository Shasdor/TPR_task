#ifndef TSP_METHOD_H
#define TSP_METHOD_H
# include <vector>
#include <math.h>

using std::vector, std::min;


class tsp_method
{
private:
    int city_n;
    static const int MAX=999;
    vector <int> best_path;
    int completed_visit;
    vector <vector <int>> distan, DP;
public:
    tsp_method();
    tsp_method(int city_n);
    void new_distan(vector <vector <int>> distan);
    int get_path_cost(int mask, int position);
    void get_path(int mask, int position);
    int get_completed_visit();
    vector <int> show_path();
};

#endif // TSP_METHOD_H
