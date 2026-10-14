#ifndef DATA_HPP
#define DATA_HPP
#include<string>

class Data
{
private:
  std::string name;
  int age;

public:
  Data(std::string name, int age);
  Data(Data &other);
  Data &operator=(Data &other);
  ~Data();

  int getAge() const;
  std::string getName() const;
};
#endif