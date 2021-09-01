
#include "settingHeader.hpp"
#include "listHeader.hpp"

using namespace std;

int main(){

    ownList<int> List;

    List.push_back(2);
    List.push_back(5);
    List.push_back(9);

    for (auto i = List.begin(); i != List.end(); i++){
        cout << *i << " ";
    }
    cout << endl;

    return 0;
}