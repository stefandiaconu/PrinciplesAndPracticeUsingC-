//
//  main.cpp
//  Ch20-01
//
//  Created by Stefan Diaconu on 27/11/2020.
//

#include <iostream>
#include <vector>

double* getFromJack(int* count)
{
    

    std::vector<double> v;
    
    for (int i=0; i<5; ++i) {
        v.push_back(i);
    }
    
    *count = (int)v.size();
    double* result = new double[*count];
    for (int i=0; i<v.size(); ++i) {
        result[i] = v[i];
    }
    
    return result;
}

std::vector<double>* getFromJill()
{
    std::vector<double>* result = new std::vector<double>;
    for (int i=0; i<5; ++i) {
        result->push_back(i);
    }
    return result;
}

double* high(double* first, double* last)
// Return a pointer to the element in [first,lasr) that has the highest value
{
    double h = -1;
    double* high = nullptr;
    
    for (double* p=first; p!=last; ++p) {
        if (h < *p) { high = p; h = *p; }
    }
    
    return high;
}

void fct()
{
    int jackCount = 0;
    
    double* jackData = getFromJack(&jackCount);
    std::vector<double>* jillData = getFromJill();
    
    double* jackHigh = high(jackData,jackData+jackCount);
    std::vector<double>& v = *jillData;
    double* jillHigh = high(&v[0],&v[0]+v.size());
    
    std::cout << "Jill's max: " << *jillHigh << "; Jack's max: " << *jackHigh << std::endl;
    
    delete[] jackData;
    delete jillData;
}

int main(int argc, const char * argv[]) {
    
    fct();
    
    return 0;
}
