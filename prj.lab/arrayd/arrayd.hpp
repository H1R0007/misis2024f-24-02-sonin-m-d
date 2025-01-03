#pragma once

#include <cstddef>
class ArrayD {

public:
	[[nodiscard]] ArrayD() = default;

	[[nodiscard]] ArrayD(const ArrayD&);

	//! \param size - начальный размер, 0 < size
	[[nodiscard]] ArrayD(const std::ptrdiff_t size);

	~ArrayD();

	ArrayD& operator=(const ArrayD&);

	[[nodiscard]] std::ptrdiff_t Size() const noexcept { return size_; }
	[[nodiscard]] std::ptrdiff_t Capacity() const noexcept { return capacity_; }

	//! \param size - новый размер, 0 <= size
	void Resize(const std::ptrdiff_t size);

	//! \param idx - индекс  элемента, 0 <= idx < Size()
	[[nodiscard]] double& operator[](const std::ptrdiff_t idx);
	[[nodiscard]] double operator[](const std::ptrdiff_t idx) const;

	//! \param idx - индекс вставляемого элемента, 0 <= idx <= size 
	void Insert(const std::ptrdiff_t idx, const double val);

	//! \param idx - индекс удаляемого элемента, 0 <= idx < size 
	void Remove(const std::ptrdiff_t idx);

private:
	std::ptrdiff_t capacity_ = 0;  //!< размер буффера
	std::ptrdiff_t size_ = 0;      //!< число элементов в массиве
	double* data_ = nullptr;             //!< буффер
	double def_value = 0;
};
