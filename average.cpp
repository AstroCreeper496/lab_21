#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(int argc, char *argv[]){
    if(argc == 1) cout << "Please input numbers to find average.";
    else if(argc >= 1) {
        double sum = 0;
        cout << "---------------------------------\n";
        for(int v = 0; v < argc; v++){
            sum += atof(argv[v]);
        }
        double mu = sum / (argc - 1);
        cout << "Average of "<< argc - 1 <<" numbers = " << mu << endl;
        cout << "---------------------------------\n";
    }
    return 0;
}
