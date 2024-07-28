#include <bits/stdc++.h>
using namespace std;

const int nTest = 100;

int main() {
    system("g++ gen.cpp -o gen");
    system("g++ sol.cpp -o sol");

    for (int iTest = 0; iTest < nTest; iTest++) {
        string fileInp = "tests/" + to_string(iTest);
        string fileAns = "tests/" + to_string(iTest) + ".a";

        ofstream inp(fileInp); inp.close();
        ofstream ans(fileAns); ans.close();

        int n = iTest / 5 + 1;
        int m = max(1, (iTest % 5) * 5);
        int large = (iTest % 5) > 2;
        
        system(("./gen " + to_string(n) + " " + to_string(m) + " " + to_string(large) + " > " + fileInp).c_str());
        system(("./sol < " + fileInp + " > " + fileAns).c_str());

        cout << "Testcase " << iTest << ": done" << endl;
    }

    return 0;
}