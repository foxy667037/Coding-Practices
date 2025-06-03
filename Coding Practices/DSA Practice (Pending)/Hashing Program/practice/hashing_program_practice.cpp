#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

int maximumFrequency(vector<int> &arr)
{
    // Question Problem:
    // So we have many numbers and the problem tell me how many a number can be present.
    unordered_map<int, int> count;
    int maxFreq = 0;
    int maxAns = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    };

    for (int i = 0; i < arr.size(); i++)
    {
        if (maxFreq == count[arr[i]])
        {
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
};

int main()
{

    // creation:
    // unordered_map<string, int> MAP; // print data randomly. time complexity: O(1)
    // map<string, int> MAP2; // print data sorted and the order is preserved. time complexity: O(logn)

    // // insertion:
    // // 1
    // pair<string, int> p = make_pair("foxy", 3);
    // MAP.insert(p);

    // // 2
    // pair<string, int> pair2("fahad", 2);
    // MAP.insert(pair2);

    // // 3
    // MAP["mera"] = 1;
    // MAP["mera"] = 2;

    // // searching:
    // cout << MAP["mera"] << endl;
    // cout << MAP.at("foxy") << endl;

    // // size
    // cout << MAP.size() << endl;

    // // check the presence of key in map:
    // cout << MAP.count("bro") << endl;  // show 0 if the key not found;
    // cout << MAP.count("foxy") << endl; // show 1 if the key found;

    // // erase
    // MAP.erase("mera");    // use to remove the key and its value also
    // cout << MAP.size() << endl;

    // //transversal: // first method
    // for(auto iterator:MAP){
    //     cout<< iterator.first << " " << iterator.second <<endl;
    // };

    // //transversal: // second method using iterator
    // unordered_map<string, int> :: iterator it = MAP.begin();
    // while(it != MAP.end()){
    //     cout<<"First Element: "<<it->first <<" " << "Second ELement: "<< it->second<<endl;
    // }

    vector<int> arr = {1,2,4,1,12,4,1,3,1,2,2,2,2,2,2,2};
    cout << maximumFrequency(arr);
}