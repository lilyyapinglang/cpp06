#ifndef DATA_HPP
#define DATA_HPP
class Data
{
  private:
    int age;
  public:
    Data(int age);
    Data(Data &other);
    Data& operator=(Data &other);
    ~Data();

    int getAge() const;
};
#endif