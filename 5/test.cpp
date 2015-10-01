#include "header.h"

void search(unordered_map<string,vector<int> >& country_astr, int curr, int k, vector<string>& countries, vector<string>& selected, int& res){
    if(selected.size() == k){
        int temp = 1;
        for(auto c:selected) temp*=country_astr[c].size();
        res += temp;
        print_vector<string>(selected);
        return;
    }
    if(curr == country_astr.size()) return;
    for(int i=curr; i<countries.size(); i++){
        selected.push_back(countries[i]);
        search(country_astr, i+1, k, countries, selected, res);
        selected.pop_back();
    }
}

int count(unordered_map<string,vector<int> >& country_astr){
    if(country_astr.size() == 0) return 0;
    int res = 0;
    vector<string> selected;
    vector<string> countries;
    for(auto i:country_astr) countries.push_back(i.first);
    print_vector<string>(countries);
    search(country_astr, 0, 2, countries, selected, res);
    return res;
}

int main(){
    unordered_map<string, vector<int> > country_astr;
    vector<int> China = {0, 1, 2};
    vector<int> US = {0, 1};
    vector<int> India = {0, 1};
    country_astr["China"] = China;
    country_astr["US"] = US;
    country_astr["India"] = India;
    cout<<count(country_astr)<<endl;
    return 0;
}