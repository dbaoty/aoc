#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>

int part_one(std::fstream &input){
  input.open("input.txt");
  int prio = 0;
  std::string line = "";
  while(std::getline(input, line)){
    std::string left = line.substr(0, line.size() / 2);
    std::string right = line.substr(line.size() / 2, line.size() - 1);
    std::set<char> common {};
    
    for(int i = 0; i < left.size(); ++i){
      for(int j = 0; j < left.size(); ++j){
        if(left[i] == right[j]) common.emplace(left[i]);
      }
    }

    for(const auto &e : common){
      if(e >= 'a' && e <= 'z') prio += (e - 96);
      if(e >= 'A' && e <= 'Z') prio += (e - 38);
    }
  }

  input.close();
  return prio;
}

int part_two(std::fstream &input){
  input.open("input.txt");
  int prio = 0;
  std::string line = "";
  std::vector<std::string> v {};
  int group = 0;
  while(std::getline(input, line)){
    std::set<char> common {};
    v.push_back(line);
    group += 1;

    if(group == 3){
      std::sort(v.begin(), v.end(), std::greater<std::string>());

      for(const auto &c : v[0]){
        for(const auto &d : v[1]){
          if(c == d){
            for(const auto &e : v[2]){
              if(d == e) common.emplace(d);
            }
          }
        }
      }

      for(const auto &e : common){
        if(e >= 'a' && e <= 'z') prio += (e - 96);
        if(e >= 'A' && e <= 'Z') prio += (e - 38);
      }

      v.clear();
      group = 0;
    }
  }

  input.close();
  return prio;
}

int main(int argc, char **argv){
  std::fstream input;
  
  std::cout << "Part one solution: " << part_one(input) << std::endl;
  std::cout << "Part two solution: " << part_two(input) << std::endl;
  
  return 0;
}