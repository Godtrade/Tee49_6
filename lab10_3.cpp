#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    int count = 0;
    float sum = 0;
    float sum_sq = 0;
    string textline;
    float num;

    ifstream source("score.txt");
    

    while (source >> num) {
        sum += num;
        sum_sq += num * num;
        count++;
    }
    
    source.close();

    cout << "Number of data = " << count << endl;
    
    if (count > 0) {
        float mean = sum / count;
        
        float variance = (sum_sq / count) - (mean * mean);
        float std_dev = sqrt(variance);
        
        cout << setprecision(3);
        cout << "Mean = " << mean << endl;
        cout << "Standard deviation = " << std_dev << endl;
    } else {
        cout << "No data found." << endl;
    }

    return 0;
}