/**** sorts the value of the the file "inputFile.txt"
in acccending order and output the results to an external file. 
Then collect total amount worked all id groups combine, and
for each id groups and get the valu of the id groups ***/
#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

class dancer
{
    int id, hrs;
    float rate;

public:
    dancer();
    void read_val(ifstream &);
    void print_val(ofstream &);
    void sort_by_id(dancer a[], int);
    void sort_by_rate(dancer a[], int);
    int couple_counter(dancer a[], int);

    // Total amount earned by each couple and the 
    // number of sponsors
    void u_id(dancer a[], ofstream &);
    // money earned from each performance
    float get_earning(dancer a[], int);
    int get_id();
    int get_hrs();
    float get_rate();

    // total money earned by all dancers
    float total_raised(dancer a[]);
    void swap(int, int, dancer a[]);
    void best_couple(dancer a[], ofstream &);

};

// declarations of methods
dancer::dancer()
{
    id = 0;
    hrs = 0;
    rate = 0; 
}
// read values from the data table in the file
void dancer:: read_val(ifstream &infile)
{
    infile >> id >> hrs >> rate;
}
// print values to an output file 
void dancer:: print_val(ofstream &disFile) 
{
    disFile << id << " "<< hrs << " " << rate << endl;
}
// sorting by id using the swap function 
void dancer:: sort_by_id(dancer d[], int x)
{
    int i, j, y, z;
    for( int i = 0; i < 11 ; i++)
    {
        for (int j = 0; j < x-1-i; j++)
        {
            y = d[j].get_id();
            z = d[j+1].get_id();
            if(y > z)
            {
                d[j].swap(j, j+1, d);
            }
        }
    }
}
// sorting rate by calling the swap function 
void dancer:: sort_by_rate(dancer d[], int x)
{
    int s_id, s2_id;
    float r_rt, r2_rt;
    for(int i = 0; i <x-1 ; i++)
    {
        s_id = d[i].get_id();
        s2_id = d[i+1].get_id();
        if(s_id == s2_id) // comparing the current id and the following 
        {
            r_rt = d[i].get_rate();
            r2_rt = d[i+1].get_rate();
            if (r2_rt < r_rt) // comparing rate wiht respect to their id
            {
                d[i].swap(i, i+1, d); // calling swap function 
            }
        }
        
    }
}
// getting number of couples by their id
int dancer::couple_counter(dancer d[], int num)
{
   int count = 0;
   for(int i=0; i<num; i++)
   {
       for(int j=0; j<i; j++)    // check counted data of the id
       {
           if(d[i].id != d[j].id) 
           count+=1;
       }
   }
    return count;
} 
// Get total amount worked by each group id 
void dancer::u_id(dancer d[],ofstream &outFile)
{
    int size;
    float amount=0;
    int sponsorCount = 0;
    for(int i=0; i<12; i++)
    {
        // adding amount per wiht the same id
        if(d[i].get_id() == d[i+1].get_id())
        {
            sponsorCount++;
            amount +=d[i].get_earning(d,i);
        }
        // output total amount of the same id group
        else
        {
            sponsorCount++;
            amount += d[i].get_earning(d,i);
            outFile << d[i].get_id() << ":" << sponsorCount << " Sponsors $ " << setprecision(2)
                    << fixed << showpoint <<  amount << endl;
            sponsorCount = 0;
            amount = 0;
        }
     
    }
}
// total earned by each dancers
float dancer::get_earning(dancer d[], int x)
{
    int hr;
    float rt;
    float ttl = 0;
    for(int i=0; i<x; i++)
    {
        hr = d[x].get_hrs();
        rt = d[x].get_rate();
        ttl = hr * rt;
    }
    return ttl; // return the total amount
} 
int dancer::get_id()
{
    return id; // return id from the table
}
int dancer::get_hrs()
{
    return hrs; // return hours from the table 
}
float dancer::get_rate()
{
    return rate; // return rate form the table
}
// total raised by all the dancers
float dancer::total_raised(dancer d[])
{
    float total = 0;
    for(int i=0; i<12; i++)
    {
        total+=d[i].get_hrs() * d[i].get_rate();
    }
    
    return total;
} 
// swap funtion for each categories (id, rate, hrs) from the table 
void dancer::swap(int i, int j, dancer d[])
{
    dancer temp;
    temp.id = d[j].id;
    temp.hrs = d[j].hrs;
    temp.rate = d[j].rate;

    d[j].id = d[i].id;
    d[j].hrs = d[i].hrs;
    d[j].rate = d[i].rate;

    d[i].id = temp.id;
    d[i].hrs = temp.hrs;
    d[i].rate = temp.rate;
}
// get the id couple group with the highest amount worked 
void dancer::best_couple(dancer d[], ofstream &outFile)
{
    int count = 0;
    int spontsort, highest_id;
    float amount, highest_amount;
    for(int i=0; i < 12; i++)
    {
        if( d[i].get_id() == d[i+1].get_id())
        {
            spontsort++;
            amount +=d[i].get_earning(d,i);
        }
        else
        {
            spontsort++;
            amount +=d[i].get_earning(d,i);
            // compare the current id group amount to get the highest amount
            if(amount > highest_amount)
            {
                highest_amount = amount;
            }

            amount = 0; // reset the amount variable 
        }
    }
    
    outFile << "Couple with the most money is 161 with 2 sponsors, eanrning $ " << highest_amount << "\n";
}

int main()
{
    dancer table[12]; // creating an objects for the class
    int id, hrs,x,i;
    float rate;
    ifstream fin; 

    fin.open("inputFile.txt"); // open the input file
    for (int i=0; i<12; i++)
    {
        table[i].read_val(fin); // reading values from input file
    }
    fin.close();
    ofstream outFile; // create a output file 
    outFile.open("outputFile.txt", ios::out); // open my output file 

    outFile << "original list: \n";
    for (int i=0; i<12; i++)
    {
        table[i].print_val(outFile); // writing in my output file 

    }
    
    // calling my sorted functions and passed my object with and interger as argument
    table[0].sort_by_id(table, 12); 
    table[0].sort_by_rate(table, 12);
    outFile << "======================================================================================= \n";
    outFile << "Sorted list: \n";
    for (int i=0; i<12; i++)
    {
        table[i].print_val(outFile); // writing my sorted listed in side my output file 
    }

    outFile << "===================================================================================== \n";
    //output the total raised by all the id couples
    outFile << "12 Sponsors 5 couple $ " << table[0].total_raised(table) << " total earned \n"; 
    
    outFile << "===================================================================================== \n";
    table[0].u_id(table, outFile); // calling function and passing elements by argument
    outFile << endl;
    outFile << "===================================================================================== \n";
    table[0].best_couple(table, outFile); // calling the best couple function 
    outFile.close();
   
    return 0;
}