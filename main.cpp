#include <iostream>
#include <vector>
#include <algorithm>
#include <forward_list>
#include "IntArr.h"

using std::cout;
using std::endl;
using std::vector;

int main(){
    //vector<int> vec = {10, 20, 0 , -5, 10};
    

    // for(auto it = vec.begin(); it != vec.end(); it++){
    //     cout << *it << endl;    //хождение по всем элементам итератора
    // }

    // for(auto it : vec){   //обращение к элементам коллекции для просмотра 
    //     //cout << it << endl;
    // }

    // std::sort(vec.begin(), vec.end());



    //std::forward_list<int> list = {1, 4, 6, -1};
    //std::sort(list.begin(), list.end());   не можем. лист форвард а в сортировке нужен рандом итератор


    





    IntArr vec;
    for(auto it = vec.begin(); it != vec.end(); it++){
        *it = 1;   
    }
    for(auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << endl;   
    }


    for(auto cit = vec.cbegin(); cit != vec.cend(); cit++){
        cout << *cit << endl;
    }
 
   

    return 0;
}