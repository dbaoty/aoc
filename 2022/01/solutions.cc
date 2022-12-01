#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void part_one(std::ifstream &input){
  input.open("input.txt");
  std::string line = "";
  int gmax = 0;
  int cmax = 0;

  while(std::getline(input, line)){
    if(line.empty()){
      gmax = std::max(gmax, cmax);
      cmax = 0;
    } else {
      cmax += std::stoi(line);
    }
  }

  std::cout << "Part one solution: " << gmax << std::endl;
  input.close();
}

void part_two(std::ifstream &input){
  input.open("input.txt");
  std::vector<int> v {};
  std::string line = "";
  int cmax = 0;

  while(std::getline(input, line)){
    if(line.empty()){
      v.push_back(cmax);
      cmax = 0;
    } else {
      cmax += std::stoi(line);
    }
  }

  int total = 0;
  std::sort(v.begin(), v.end());
  total += v[v.size() - 1] + v[v.size() - 2] + v[v.size() - 3];

  std::cout << "Part two solution: " << total << std::endl;
  input.close();
}

int main(int argc, char **argv){
  std::ifstream input;
  part_one(input);
  part_two(input);

  return 0;
}