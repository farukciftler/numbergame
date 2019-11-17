#pragma region libraries
#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#pragma endregion

vector<int> randomnumber() //creating random number for cpu/ai side
{

    vector<int> randnum;
    int a, b, c, d;
    bool err = 1;

    while (err == 1)
    {

        srand(time(NULL));

        a = rand() % 10;
        b = rand() % 10;
        c = rand() % 10;
        d = rand() % 10;

        randnum.push_back(a);
        randnum.push_back(b);
        randnum.push_back(c);
        randnum.push_back(d);

        if (randnum.at(0) == 0)
        {
            err = 1;
            randnum.clear();
        }
        else if (randnum.at(0) == randnum.at(1))
        {
            err = 1;
            randnum.clear();
        }
        else if (randnum.at(0) == randnum.at(2))
        {
            err = 1;
            randnum.clear();
        }
        else if (randnum.at(0) == randnum.at(3))
        {
            err = 1;
            randnum.clear();
        }
        else if (randnum.at(1) == randnum.at(2))
        {
            err = 1;
            randnum.clear();
        }
        else if (randnum.at(1) == randnum.at(3))
        {
            err = 1;
            randnum.clear();
        }
        else if (randnum.at(2) == randnum.at(3))
        {
            err = 1;
            randnum.clear();
        }
        else
        {
            err = 0;
        }
    }
    return randnum;
}

vector<int> input() //user number 
{
    vector<int> x_input;
    int x;
    bool err = 1;
    while (err == 1)
    {
    

        cout  << "please enter a four digit number: ";
        cin >> x;
       
        x_input.push_back(x / 1000);
        x_input.push_back((x % 1000) / 100);
        x_input.push_back(((x % 1000) % 100) / 10);
        x_input.push_back((((x % 1000) % 100) % 10));

        #pragma region conditions
        if (x_input.at(0) == 0)
        {
            cout << "you must enter a number to first digit which higher than 0 and lower than 10! \n";
            x_input.clear();
        }
        else if (x < 1000 || x > 9999)
        {
            cout << "you must enter a number between from 1000 to 9999! \n";
            x_input.clear();
        }
        else if (x_input.at(0) == x_input.at(1))
        {
            cout << "your each number must be different each others \n";
            x_input.clear();
        }
        else if (x_input.at(0) == x_input.at(2))
        {
            cout << "your each number must be different each others \n";
            x_input.clear();
        }
        else if (x_input.at(0) == x_input.at(3))
        {
            cout << "your each number must be different each others \n";
            x_input.clear();
        }
        else if (x_input.at(1) == x_input.at(2))
        {
            cout << "your each number must be different each others \n";
            x_input.clear();
        }
        else if (x_input.at(1) == x_input.at(3))
        {
            cout << "your each number must be different each others \n";
            x_input.clear();
        }
        else if (x_input.at(2) == x_input.at(3))
        {
            cout << "your each number must be different each others \n";
            x_input.clear();
        }
        #pragma endregion
        else
        {
            err = 0;
        }
        

    }

    return x_input;
}

vector<int> score(vector<int> x_input, vector<int> randnumber) //comparising the numbers
{
    vector<int> score;
    int plus, minus;
    plus = 0;
    minus = 0;
    
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if (i == j && x_input.at(i) == randnumber.at(j))
            {
                plus = plus + 1;
            }
            else if (i != j && x_input.at(i) == randnumber.at(j))
            {
                minus = minus +1;
            }
        }
        
    }
    
    score.push_back(plus);
    score.push_back(minus);

    return score;
}

vector<int> memory(vector<int> *input_memoryvector, vector<int> *minus_memoryvector, vector<int> *plus_memoryvector, vector<int> score, vector<int> input) //memorising old inputs
{
    input_memoryvector->push_back(input.at(0));
    input_memoryvector->push_back(input.at(1));
    input_memoryvector->push_back(input.at(2));
    input_memoryvector->push_back(input.at(3));

    plus_memoryvector->push_back(score.at(0));
    minus_memoryvector->push_back(score.at(1));
}

int main()  //main functions
{
    int period = 0;
    int gameend = 0;
    vector<int> y, y_output, score_vect, input_memoryvect, plus_memoryvect, minus_memoryvect;

    y_output = randomnumber();

    while (gameend == 0)
    {
    y =  input();
    score_vect = score(y, y_output);
    memory(&input_memoryvect, &minus_memoryvect, &plus_memoryvect, score_vect, y);

    y.clear();
    score_vect.clear();
    period++;
   
        cout << "number\tplus\tminus" <<endl; 
        for (int i = 0; i < input_memoryvect.size(); i++)
        {
           cout << input_memoryvect.at(i);
           
           if ((i % 4) == 3)
           {
               cout << "\t";
               cout << plus_memoryvect.at(i/4);
               cout << "\t";
               cout << minus_memoryvect.at(i/4);
               cout << endl;
               if (plus_memoryvect.at(i / 4) == 4)
               {
                   gameend = 1;
               }
           }
           
        }

       
        
    
    
    }

    return 0;
}


    