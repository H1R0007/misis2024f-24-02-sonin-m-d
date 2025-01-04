#pragma once

#include <cstddef>
#include <cstdint>

class StackL final {
public:
    using T = std::uint8_t;

    StackL() = default;

    StackL(const StackL& src);

    StackL(StackL&& src) noexcept;

    ~StackL() = default;

    StackL& operator=(const StackL& src);

    StackL& operator=(StackL&& src) noexcept;

    [[nodiscard]] bool IsEmpty() const noexcept;

    void Pop() noexcept;

    void Push(const T val);

    [[nodiscard]] T& Top()&;

    [[nodiscard]] const T& Top() const&;

    void Clear() noexcept;

private:
    struct Node {
        T val = T();
        Node* next = nullptr;
    };

    Node* head_ = nullptr;   //!< 
};