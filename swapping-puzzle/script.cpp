#include <bits/stdc++.h>
using namespace std;

int main() {
    system("g++ gen.cpp -o gen");
    system("g++ sol.cpp -o sol");

    for (int h = 1, iTest = 0; h <= 5; ++h)
        for (int w = 1; w <= 5; ++w) 
            for (int haveAns = 0; haveAns <= 1; ++haveAns, ++iTest) {
                string fileInp = "tests/" + to_string(iTest);
                string fileAns = "tests/" + to_string(iTest) + ".a";

                ofstream inp(fileInp); inp.close();
                ofstream ans(fileAns); ans.close();

                system(("./gen " + to_string(h) + " " + to_string(w) + " " + to_string(haveAns) + " > " + fileInp).c_str());
                system(("./sol < " + fileInp + " > " + fileAns).c_str());

                cout << "Generated test " << iTest << endl;
            }

    return 0;
}