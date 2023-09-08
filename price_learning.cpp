#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::pair<std::string, std::vector<int>>> read_csv(char **av)
{
    std::string line;
    std::string word;
    std::vector<std::pair<std::string, std::vector<int>>> data;
    int value;

    std::ifstream myfile(av[1]);
    if (!myfile.is_open())
        std::cout << "Can't open the file" << std::endl;
    if (myfile.good())
    {
        getline(myfile, line);
        std::stringstream s(line);
        while (getline(s, word, ','))
            data.push_back(make_pair(word, std::vector<int>()));
    }

    while (getline(myfile, line))
    {
        std::stringstream s(line);
        int id = 0;
        while (s >> value)
        {

            data[id].second.push_back(value);
            if (s.peek() == ',')
                s.ignore();
            id++;
        }
    }
    myfile.close();
    return (data);
}

void    linear_regression(std::vector<std::pair<std::string, std::vector<int>>> data, double *t0, double *t1) 
{
    double tmp0, tmp1 = -1;
    long int estimatePrice0 = 0, estimatePrice1 = 0;
    int j = 0;
    int mileage, price;
    std::cout << estimatePrice1 << std::endl;
    for (; j < data[0].second.size(); j++) {
        mileage = data[0].second[j];
        price = data[1].second[j];
        double predictPrice = *t0 + (*t1 * mileage);

        *t0 = *t0 + predictPrice - price;
        *t1 = *t1 + (predictPrice - price) * mileage;
        std::cout << *t0 << " - " << *t1 << std::endl << std::endl;
    }
    *t0 = *t0 / j; 
    *t1 = *t1 / j; 

    *t0 = tmp0;
    *t1 = tmp1;
}

int main(int ac, char **av)
{
    double t0, t1 = 0;
    if (ac != 2)
    {
        std::cout << "Please add a dataset File" << std::endl;
        return (0);
    }
    std::vector<std::pair<std::string, std::vector<int>>> data;
    data = read_csv(av);

    for (std::pair<std::string, std::vector<int>> name : data)
    {
        std::cout << name.first << " ";
    }
    std::cout << std::endl;

    if (data.size() > 0)
    {

        for (int j = 0; data[0].second[j]; j++)
        {
            int i = 0; // Data[0] -> mileage, Data[1] -> price.
            for (; i + 1 < data.size(); i++)
            {
                std::cout << data[i].second[j] << ',';
            }
            std::cout << data[i].second[j];
            std::cout << std::endl;
        }
    }
    std::cout << "t0 = " << t0 << " t1 = " << t1 << std::endl;
    linear_regression(data, &t0, &t1);
    std::cout << "t0 = " << t0 << " t1 = " << t1 << std::endl;


    return (0);
}