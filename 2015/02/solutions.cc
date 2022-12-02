#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

void part_one(std::ifstream &input){
  input.open("input.txt");
  std::string line = "";
  long total = 0;

  while(std::getline(input, line)){
    std::stringstream ss(line);
    std::vector<int> sides {};
    std::string tok = "";
    while(std::getline(ss, tok, 'x')){
      sides.push_back(std::stoi(tok));
    }
    
    int s1 = (2 * sides[0] * sides[1]);
    int s2 = (2 * sides[1] * sides[2]);
    int s3 = (2 * sides[2] * sides[0]);
    int smallest = std::min(s1, std::min(s2, s3));

    std::cout << "Sides: " << s1 << " " << s2 << " " << s3 << std::endl;
    std::cout << "Smallest: " << smallest << std::endl;

    total += (s1 * s2 * s3 * smallest);

  }

  std::cout << "Part one solution: " << total << std::endl;
  input.close();
}

void part_two();

int main(int argc, char **argv){
  std::ifstream input;
  part_one(input);

  return 0;
}