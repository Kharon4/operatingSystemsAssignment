#include<iostream>
#include<bits/stdc++.h>
// #include<sstream>
#include <thread>
using namespace std;

float average_val;
int max_value;
int min_value;
float std_dev;
int num_of_integers;
int median;

void get_input(vector<int>& vec, string str) {
    istringstream ss(str);
    do { 
        // Read a word 
        string word; 
        ss >> word; 
        if(word != "")
            vec.push_back(stoi(word));
        // Print the read word 
        // cout << word << endl; 
  
        // While there is more to read 
    } while (ss); 
}
void average_fn(float& average_val, vector<int> vec){
    float sum = 0;
    for(int i = 0; i< vec.size(); i++) {
        sum += vec[i];
    }
    average_val = sum / vec.size();
}
void max_fn(int& max_value, vector<int> vec){
    max_value = INT_MIN;
    for(int i = 0; i< vec.size(); i++) {
        if(vec[i] > max_value){
            max_value = vec[i];
        }
    }
}
void min_fn(int& min_value, vector<int> vec){
    min_value = INT_MAX;
    for(int i = 0; i< vec.size(); i++) {
        if(vec[i] < min_value){
            min_value = vec[i];
        }
    }
}
void std_dev_fn(float& std_dev, vector<int> vec) {
    float sum = 0;
    for(int i = 0;i< vec.size(); i++) {
        sum += ((vec[i]-average_val)*(vec[i]-average_val));
    }
    sum /= vec.size();
    std_dev = sqrt(sum);
}
void median_fn(int& median, vector<int> vec) {
    sort(vec.begin(), vec.end());
    if(vec.size() % 2) {
        median = vec[vec.size()/2];
    } else {
        median = vec[vec.size()/2] + vec[(vec.size()-1)/2];
        median /= 2;
    }
}
void num_of_int_fn(int& num_of_integers, vector<int> vec) {
    num_of_integers = vec.size();
}
int main(int argc, char** argv) {
    char str[25];
    // char s[25];
    cin.getline(str,25); 
  
    // Traverse through all words 
    vector<int> vec;
    // vec.push_back()
    // get_input(vec, str);
    // cout << argc << endl;
    for(int i = 1; i< argc; i++) {
        string s = argv[i];
        // cout << argv[i] << endl;
        vec.push_back(stoi(s));
    }
    thread t1(average_fn, ref(average_val), vec);
    thread t2(max_fn, ref(max_value), vec);
    thread t3(min_fn, ref(min_value), vec);
    t1.join();
    thread t4(std_dev_fn, ref(std_dev), vec);
    thread t5(median_fn,ref(median), vec);
    thread t6(num_of_int_fn,ref(num_of_integers), vec);
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    cout << "The mean is " << average_val << endl;
    cout << "The max value is " << max_value << endl;
    cout << "The min value is " << min_value << endl;
    cout << "The standard deviation is " << std_dev << endl;
    cout << "The median is " << median << endl;
    cout << "The number of integers passed is " << num_of_integers << endl;

}