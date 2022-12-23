// Also called "Tagged Unions"

#include <iostream>

using std::cout;
using std::endl;

union RustLikeEnum
{
  using KeyInput = uint64_t;
  using UserInput = std::string_view;
};

int main()
{
  auto rle = RustLikeEnum::KeyInput( 65 );
  //auto rle = RustLikeEnum::UserInput( "Hello" );

  cout << "Rust like enum example " << rle << endl;
}

// Or

template<MessageType T>
struct Message;

template<>
struct Message<MessageType::Quit>
{
  // No data needed for a quit message
};

template<>
struct Message<MessageType::Move>
{
  int x;
  int y;
};

template<>
struct Message<MessageType::Write>
{
  std::string_view write;
};

template<>
struct Message<MessageType::ChangeColor>
{
  int r;
  int g;
  int b;
};

// Or

#include <variant>
#include <string>
#include <concepts>

enum class Message { Quit, Move, Write, ChangeColor };

using MovePayload = std::pair<int, int>;
using WritePayload = std::string;
using ChangeColorPayload = std::tuple<int, int, int>;

using MessagePayload = std::variant<
    std::monostate, // for Quit
    MovePayload,    // for Move
    WritePayload,   // for Write
    ChangeColorPayload // for ChangeColor
>;

template <typename T>
concept Payload =
    std::same_as<T, std::monostate> ||
    std::same_as<T, MovePayload> ||
    std::same_as<T, WritePayload> ||
    std::same_as<T, ChangeColorPayload>;

template <Payload T>
void handle_payload(const T& payload)
{
    // handle payload...
}

std::pair<Message, MessagePayload> parse_message(const std::string& str)
{
    // parse the string and return a pair of (Message, MessagePayload)
    // ...
}

int main()
{
    auto [msg, payload] = parse_message("...");
    handle_payload(payload);

    return 0;
}
