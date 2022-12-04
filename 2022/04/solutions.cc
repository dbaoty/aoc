#include <iostream>
#include <fstream>

int part_one(std::fstream &input){
  input.open("input.txt");
  int pairs = 0;
  std::string line;

  while(std::getline(input, line)){
    int ll = std::stoi(line.substr(0, line.find('-')));
    int lr = std::stoi(line.substr(line.find('-') + 1, line.find_first_of(',')));      
    int rl = std::stoi(line.substr(line.find(',') + 1, line.find_last_of('-')));
    int rr = std::stoi(line.substr(line.find_last_of('-') + 1, line.size() - 1));

    if ((rl >= ll && rr <= lr) || (ll >= rl && lr <= rr)) pairs++;
  }

  input.close();
  return pairs;
}

int part_two(std::fstream &input){
  input.open("input.txt");
  int pairs = 0;
  std::string line;

  while(std::getline(input, line)){
    int ll = std::stoi(line.substr(0, line.find('-')));
    int lr = std::stoi(line.substr(line.find('-') + 1, line.find_first_of(',')));      
    int rl = std::stoi(line.substr(line.find(',') + 1, line.find_last_of('-')));
    int rr = std::stoi(line.substr(line.find_last_of('-') + 1, line.size() - 1));

    if (ll == rl || lr == rr || (ll < rl && lr >= rl) || (ll > rl && ll <= rr)) pairs++;
  }

  input.close();
  return pairs;
}

int main(int argc, char **argv){
  std::fstream input;
  std::cout << "Part one solution: " << part_one(input) << std::endl;
  std::cout << "Part two solution: " << part_two(input) << std::endl;
  return 0;
}