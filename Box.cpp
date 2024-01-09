#include <utility>

template<typename DataType>
struct Box
{
  // Data
  DataType *data = nullptr;

  // Constructors and destructors
  constexpr Box() = default;
  constexpr Box(DataType *data) : data(data) {}
  constexpr ~Box()
  {
    delete data;
    data = nullptr;
  }

  // Move operations
  constexpr Box(Box &&other) : data(std::exchange(other.data, nullptr)) {}
  constexpr Box &operator = (Box &&other)
  {
    delete data;
    data = nullptr;

    data = std::exchange(other.data, nullptr);
  }

  // Copy operators (they are deleted)
  constexpr Box(const Box&) = delete;
  constexpr Box &operator = (const Box&) = delete;
};

// Testing `Box` in constexpr scope
constexpr void boxTest()
{
  Box<int> data(new int());
}

int main() {}
