#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <algorithm>
using namespace std;

const int SIZE = 50;

class Object 
{
    static int ID;
    int id;
public:
    int weight;
    int price;
    double worth;
    int value;
    Object(int price, int weight) : weight(weight), price(price) 
    {
        id = ++ID;
        this->worth = price / weight;
        this->value = price - weight;
    }
    void info()
    {
        cout << "Number of obj -> " << id << "\tWeight -> " << weight << "\tPrice -> " << price << endl;
    }
    int getID() { return id; }
    double get() { return worth; }
};

int Object::ID = 0;


void solution(vector <Object> A) 
{
    int weight = 0;
    int count = 0;
    vector <Object> res;
    sort(A.begin(), A.end(), [](const Object& a, const Object& b) { return a.worth > b.worth; });
    
    for (size_t i = 0; i < A.size(); i++)
    {
        if (weight + A[i].weight <= SIZE) {
            res.push_back(A[i]);
            weight += A[i].weight;
        }
    }

    for (size_t i = 0; i < res.size(); i++)
    {
        count += res[i].price;
        res[i].info();
    }
    cout << endl << "Total price -> " << count << endl;
    cout << "Total weight -> " << weight << endl;
}

int main()
{
    vector <Object> v;
    random_device random_device;
    mt19937 generator(random_device());
    uniform_int_distribution<> price(1, 250);
    uniform_int_distribution<> weight(1, 70);

    for (size_t i = 0; i < 100; i++)
    {
        Object buff(price(generator), weight(generator));
        v.push_back(buff);

        buff.info();
    }

    cout << "\n\n\n";
    solution(v);
}