#include <bits/stdc++.h>
using namespace std;

const int nTest = 100;

int main() {
    system("g++ sol.cpp -o sol");
    system("g++ gen.cpp -o gen");

    for (int iTest = 0; iTest < nTest; ++iTest) {
        string fileInp = "tests/" + to_string(iTest);
        string fileAns = "tests/" + to_string(iTest) + ".a";
    
        ofstream inp(fileInp); inp.close();
        ofstream ans(fileAns); ans.close();
    
        int n = min(7, iTest / 15 + 1);
        int h = min(10, (iTest % 15 + 1));
        int w = min(10, h * n * iTest % 23 + 1);

        if (system(("./gen " + to_string(n) + " " + to_string(h) + " " + to_string(w) + " > " + fileInp).c_str())) {
            cerr << "Generated test " << iTest << " failed!" << "\n";
            return 1;
        }
        
        if (system(("./sol < " + fileInp + " > " + fileAns).c_str())) {
            cerr << "Generated test " << iTest << " failed!" << "\n";
            return 1;
        }

        cout << "Generated test " << iTest << " done!" << "\n";
    }

    return 0;
}