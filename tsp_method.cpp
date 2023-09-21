#include "tsp_method.h"

tsp_method::tsp_method()
{
    city_n = 6;
    completed_visit = (1<<city_n)-1;
    DP =  vector <vector<int>> (static_cast<int>(1<<city_n),vector<int>(city_n,-1));
    distan = {{0, 5, 9, 6, 3, 5},
              {3, 0, 8, 8, 5, 9},
              {6, 9, 0, 1, 6, 7},
              {7, 3, 4, 0, 4, 2},
              {4, 6, 3, 2, 0, 2},
              {5, 2, 2, 7, 1, 0}};
}

tsp_method::tsp_method(int city_n){
    this->city_n=city_n;

}
void tsp_method::new_distan(vector <vector <int>> distan){
    this->distan.clear();
    this->distan.assign(distan.begin(),distan.end());
}


int tsp_method::get_path_cost(int mask, int position){
    if (mask == completed_visit) {
        return distan[position][0];
    }

    if (DP[mask][position] != -1) {
        return DP[mask][position];
    }

    int answer = MAX ;
    for (int city = 0; city < city_n; city++) {
        if (!(mask & (1 << city)) ) {
            answer=min(answer, distan[position][city] + get_path_cost(mask | (1 << city), city));
        }
    }
    return DP[mask][position] = answer;

}
void tsp_method::get_path(int mask, int position){

    if (mask == (1 << city_n) - 1) {
        best_path.push_back(1); // Добавить начальный город в путь
        return;
    }

    int bestNext = -1;
    int bestCost = MAX;

    for (auto next_city = 0; next_city < city_n; ++next_city) {
        if (!(mask & (1 << next_city))) {
            auto cost = distan[position][next_city] + DP[mask | (1 << next_city)][next_city];
            if (cost <= bestCost) {
                bestCost = cost;
                bestNext = next_city;
            }
        }
    }
    best_path.push_back(bestNext + 1);
    get_path(mask | (1 << bestNext), bestNext);


}
vector <int> tsp_method::show_path(){
    return best_path;
}

