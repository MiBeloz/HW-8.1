#pragma once

#include <exception>


class bad_length : public std::exception {
public:
	const char* what() const override;
};