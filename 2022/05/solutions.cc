#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstring>

/* FILTERED by input edition */
/* both parts complete 12/6 @ 8:49 EST */

void part_one(std::fstream &input){
  input.open("input.txt");

  std::vector<std::vector<char>> v = {
   {'B', 'L', 'D', 'T', 'W', 'C', 'F', 'M'},
   {'N', 'B', 'L'}, {'J', 'C', 'H', 'T', 'L', 'V'},
   {'S', 'P', 'J', 'W'}, {'Z', 'S', 'C', 'F', 'T', 'L', 'R'},
   {'W', 'D', 'G', 'B', 'H', 'N', 'Z'},
   {'F', 'M', 'S', 'P', 'V', 'G', 'C', 'N'},
   {'W', 'Q', 'R', 'J', 'F', 'V', 'C', 'Z'},
   {'R', 'P', 'M', 'L', 'H'}
  };
  
  std::string line;
  while(std::getline(input, line) && !line.empty()){

  }

  while(std::getline(input, line)){
    int n, s, d;
    std::sscanf(line.c_str(), "move %d from %d to %d", &n, &s, &d);

    for(int i = 0; i < n; ++i){
      v[d - 1].push_back(v[s - 1].back());
      v[s- 1].pop_back();
    }  
  }

  for(const auto &each : v){
    std::cout << each.back();
  }

  std::cout << std::endl;

  input.close();
}

void part_two(std::fstream &input){
  input.open("input.txt");

  std::vector<std::vector<char>> v = {
   {'B', 'L', 'D', 'T', 'W', 'C', 'F', 'M'},
   {'N', 'B', 'L'}, {'J', 'C', 'H', 'T', 'L', 'V'},
   {'S', 'P', 'J', 'W'}, {'Z', 'S', 'C', 'F', 'T', 'L', 'R'},
   {'W', 'D', 'G', 'B', 'H', 'N', 'Z'},
   {'F', 'M', 'S', 'P', 'V', 'G', 'C', 'N'},
   {'W', 'Q', 'R', 'J', 'F', 'V', 'C', 'Z'},
   {'R', 'P', 'M', 'L', 'H'}
  };
  
  std::string line;
  while(std::getline(input, line) && !line.empty()){

  }

  while(std::getline(input, line)){
    int n, s, d;
    std::sscanf(line.c_str(), "move %d from %d to %d", &n, &s, &d);
    std::vector<char> temp {};

    for(int i = 0; i < n; ++i){
      temp.push_back(v[s - 1].back());
      v[s- 1].pop_back();
    }

    for(int i = 0; i < temp.size(); ++i){
      v[d - 1].push_back(temp[temp.size() - 1 - i]);
    }
  }

  for(const auto &each : v){
    std::cout << each.back();
  }

  std::cout << std::endl;

  input.close();
}

int main(int argc, char **argv){
  std::fstream input;
  std::cout << "Part one solution: ";
  part_one(input);
  std::cout << "Part two solution: ";
  part_two(input);

  return 0;
}