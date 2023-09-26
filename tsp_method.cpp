#include "tsp_method.h"

tsp_method::tsp_method()
{
    return_to_base_param();

}

tsp_method::tsp_method(int city_n,vector <vector <int>> distan){
    this->city_n=city_n;
    this->completed_visit = (1<<this->city_n)-1;
    this->DP =  vector <vector<int>> (static_cast<int>(1<<this->city_n),vector<int>(this->city_n,-1));
    this->distan=distan;
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

QString tsp_method::show_path(){
    QString path= "Path: 1->";

    for (auto i=this->best_path.begin();i!=this->best_path.end();i++){
        if (i+1 != best_path.end()){
            path+=QString::number(*i);
            path+="->";
        }
        else
            path+=QString::number(*i);
    }

    return path;
}

int tsp_method::get_city(){
    return this->city_n;
}

vector <vector <int>> tsp_method::get_distan(){
    return this->distan;
}

QString tsp_method::show_path_cost(){
    QString cost="Path cost:"+QString::number(this->answer);
    return cost;
}

void tsp_method::return_to_base_param(){
    this->city_n = 6;
    this->distan = {{0, 5, 9, 6, 3, 5},
              {3, 0, 8, 8, 5, 9},
              {6, 9, 0, 1, 6, 7},
              {7, 3, 4, 0, 4, 2},
              {4, 6, 3, 2, 0, 2},
              {5, 2, 2, 7, 1, 0}};
    this->do_TSP();

}

void tsp_method::do_TSP(){
    this->completed_visit = (1<<this->city_n)-1;
    this->DP =  vector <vector<int>> (static_cast<int>(1<<city_n),vector<int>(city_n,-1));
    this->best_path.clear();
    this->answer=this->get_path_cost(1,0);
    this->get_path(1,0);

}

void tsp_method::change_city_n(int city_n){
    this->city_n=city_n;
}

