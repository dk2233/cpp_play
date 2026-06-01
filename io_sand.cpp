#include "utils.h"
#include <cstddef>
#include <ios>
#include <iostream>
#include <iomanip>
#include <fstream>
constexpr const char  * const file_name {"../test.txt"};
int max_score {5};
constexpr const int total_w  {60};


typedef struct 
{
    std::string name;
    std::string test_answers;
    int points;
} student_data;

void check_students_answers(student_data &data, std::string &correct_answers);
void test_score_analysis() ;

void check_students_answers(student_data &data, std::string &correct_answers)
{
    data.points = max_score;

    int  i = 0;
    for(char c : data.test_answers)
    {
        if (c != correct_answers.at(i++)) data.points--; 
    }

}

void display_results(std::vector<student_data> &vec)
{
    std::cout << std::setfill(' ')
        << std::setw(total_w/2) << std::left << "Student" 
        << std::setw(total_w/2) << std::right << "Score" << std::endl;

    std::cout << std::setw(total_w) << std::setfill('-') << "" << std::endl;

    std::cout << std::setfill(' ');
    double avg {0.0};
    for(student_data sd : vec)
    {
        std::cout << std::setw(total_w/2) << std::left << sd.name
            << std::setw(total_w/2) << std::right << sd.points << std::endl; 
        avg +=  static_cast<double>(sd.points)/ vec.size();
    }
    std::cout << std::setw(total_w) << std::setfill('-') << "" << std::endl;



    std::cout << std::setfill(' ')
        << std::setw(total_w/2) << std::left << "Average Score" 
        << std::setw(total_w/2) << std::right << avg << std::endl;
}

void test_score_analysis() {
    
    std::fstream file1 {file_name};

    if (file1.is_open())
    {
        std::string test_key {};
        student_data data {};
        file1 >> test_key;
        max_score = test_key.size();

        std::vector<student_data> students_vec {};

        while(file1 >> data.name >> data.test_answers)
        {
            check_students_answers(data, test_key);
            students_vec.push_back({data.name, data.test_answers, data.points});

        }

        display_results(students_vec);


        file1.close();
    }
    else 
    {
        std::cerr << "Problem opening file " << std::endl;
    }
    
}

void io_sandbox()
{

    marker_begin("Input Output Begin");
    double d1 (1.23456789);

    std::cout<< std::setw(20) << std::setfill('*') <<  "Test" << std::endl;
    std::cout << std::defaultfloat;
    std::cout << " Double number with default prec "<< d1 << std::endl;
    std::cout << std::setprecision(10) ;
    std::cout << " Double number with 10 prec "<< d1 << std::endl;
    std::cout << std::setprecision(2) ;
    std::cout << " Double number with 10 prec "<< d1 << std::endl;

    test_score_analysis();
    marker_begin("Input Output END");
}
