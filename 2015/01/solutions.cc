#include <iostream>
#include <vector>
#include <fstream>

void part_one(std::ifstream &input){
  input.open("input.txt");
  int floor = 0; 
  char next = 0;

  while(input.get(next)){
    if(next == '(') floor += 1;
    else floor -= 1;
  }

  std::cout << "Part one solution: " << floor << std::endl;
  input.close();
}

void part_two(std::ifstream &input){
  input.open("input.txt");
  int floor = 0;
  char next = 0;
  int basement = 0;

  while(input.get(next) && floor != -1){
    if(next == ')') floor -= 1;
    else floor += 1;

    basement++;
  }

  std::cout << "Part two solution: " << basement << std::endl;
  input.close();
}

int main(int argc, char **argv){
  std::ifstream input;
  part_one(input);
  part_two(input);

  return 0;
}