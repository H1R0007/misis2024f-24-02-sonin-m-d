#pragma once

#include <cstddef>
class ArrayD {

public:
	[[nodiscard]] ArrayD() = default;

	[[nodiscard]] ArrayD(const ArrayD&);

	[[nodiscard]] ArrayD(const std::ptrdiff_t size);

	~ArrayD();

	ArrayD& operator=(const ArrayD&);

	[[nodiscard]] std::ptrdiff_t Size() const noexcept { return size_; }
	[[nodiscard]] std::ptrdiff_t Capacity() const noexcept { return capacity_; }

	void Resize(const std::ptrdiff_t size);

	[[nodiscard]] double& operator[](const std::ptrdiff_t idx);
	[[nodiscard]] double operator[](const std::ptrdiff_t idx) const;

	void Insert(const std::ptrdiff_t idx, const double val);

	void Remove(const std::ptrdiff_t idx);

private:
	std::ptrdiff_t capacity_ = 0;
	std::ptrdiff_t size_ = 0;
	double* data_ = nullptr;
};
