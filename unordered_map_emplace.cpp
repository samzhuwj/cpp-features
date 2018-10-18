#include <iostream>
#include <utility>
#include <string>
#include <unordered_map>

int main()
{
  std::unordered_map<std::string, std::string> m;
  m.emplace(std::make_pair(std::string("a"), std::string("a"))); // use pair's move construtor
  m.emplace(std::make_pair("b", "abcd")); // use pair's converting move constructor
  m.emplace("d", "ddd"); // use pair's templace constructor
  m.emplace(std::piecewise_construct, std::forward_as_tuple("c"), std::forward_as_tuple(10, 'c'));

  for (const auto &p : m)
    std::cout << p.first << " => " << p.second << '\n';
}

// Possible output:
// d => ddd
// b => abcd
// c => cccccccccc
// a => a
