#include <iostream>
#include <fstream>
#include <map>

int part_one(std::fstream &input){
  input.open("input.txt");
  std::string line;
  
  while(std::getline(input, line)){
    int idx = 4;
    for(int i = 0; i < line.size() - 4; ++i){
      std::map<char, int> m {};
      for(int j = i; j < i + 4; ++j){
        m[line[j]]++;
      }

      if(m.size() != 4) idx += 1;
      else return idx;
    }
  }

  return -1;
}

int part_two(std::fstream &input){
  input.open("input.txt");
  std::string line;
  while(std::getline(input, line)){
    int idx = 14;
    for(int i = 0; i < line.size() - 13; ++i){
      std::map<char, int> m {};
      for(int j = i; j < i + 14; ++j){
        m[line[j]]++;
      }

      if(m.size() != 14) idx += 1;
      else return idx;
    }
  }
  
  return -1;
}

int main(int argc, char **argv){
  std::fstream input;
  std::cout << "Part one solution: " << part_one(input) << std::endl;
  input.close();
  std::cout << "Part two solution: " << part_two(input) << std::endl;
  input.close();
  
  return 0;
}
