#include <cstdint>
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
class Serializer
{
  public:
	Serializer();
	~Serializer();
	/**
		* @brief Serializes a Data pointer into a uintptr_t
		* @param ptr The Data pointer to serialize
		* @return The serialized value
		*/
	static uintptr_t serialize(Data *ptr);
	// It takes an unsigned integer parameter and converts it to a pointer to Data
	static Data *deserialize(uintptr_t raw);
};

#endif