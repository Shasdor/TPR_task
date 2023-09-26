#ifndef TSP_METHOD_H
#define TSP_METHOD_H
# include <vector>
#include <math.h>
#include <QString>

using std::vector, std::min;


class tsp_method
{
private:
    int city_n;
    static const int MAX=999;
    vector <int> best_path;
    int completed_visit;
    vector <vector <int>> distan, DP;

    int answer;
public:
    tsp_method();
    tsp_method(int, vector <vector <int>>);
    void new_distan(vector <vector <int>> distan);
    int get_path_cost(int mask, int position);
    void get_path(int mask, int position);
    int get_completed_visit();
    QString show_path();
    int get_city();
    vector <vector <int>> get_distan();
    QString show_path_cost();
    void return_to_base_param();
    void do_TSP();
    void change_city_n(int);


};

#endif // TSP_METHOD_H
