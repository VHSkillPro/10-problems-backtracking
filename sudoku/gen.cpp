#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fi("HardestDatabase110626.txt");
    system("g++ sol.cpp -o sol");

    for (int iTest = 0;; ++iTest) {
        if (fi.eof()) break;

        string fileInp = "./tests/" + to_string(iTest);
        string fileAns = "./tests/" + to_string(iTest) + ".a";

        string table; fi >> table;

        ofstream fo(fileInp);
        for (int i = 0; i < table.size(); i += 9) {
            fo << table.substr(i, 9) << "\n";
        }   
        fo.close();

        clock_t begin = clock();
        system(("./sol " + fileInp + " " + fileAns).c_str());
        clock_t end = clock();

        cerr << fixed << "Testcase " << iTest << ": " << (end - begin + 0.0) / CLOCKS_PER_SEC << "s\n";
    }

    fi.close();
    return 0;
}