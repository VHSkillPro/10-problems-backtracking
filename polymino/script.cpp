#include <bits/stdc++.h>
using namespace std;

int main() {
    system("g++ sol.cpp -o sol");
    system("g++ gen.cpp -o gen");

    int iTest = 0;
    for (int n = 1; n <= 8; ++n)
        for (int k = 1; k <= 8; ++k) {
            string fileInp = "tests/" + to_string(iTest);
            string fileAns = "tests/" + to_string(iTest) + ".a";

            ofstream inp(fileInp); inp.close();
            ofstream ans(fileAns); ans.close();

            system(("./gen " + to_string(n) + " " + to_string(k) + " > " + fileInp).c_str());
            system(("./sol < " + fileInp + " > " + fileAns).c_str());

            cout << "Generated test " << ++iTest << endl;
        }

    return 0;
}