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

        int n = iTest / 19 + 3;
        int zeroAns = (iTest % 19) == 0;
    
        system(("./gen " + to_string(n) + " " + to_string(zeroAns) + " " + to_string(iTest) + " > " + fileInp).c_str());
        system(("./sol < " + fileInp + " > " + fileAns).c_str());

        cout << "Testcase " << iTest << " generated" << endl;
    }

    return 0;
}