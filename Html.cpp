using size_t = unsigned long long int;

template<typename T>
struct add_rvalue_reference
{
    using type = T;
};

template<typename T>
using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;

template<typename T>
add_rvalue_reference_t<T> declval() noexcept;

template<typename... Args>
struct CommonType;

template<typename T>
struct CommonType<T>
{
    using Type = T;
};

template<typename T, typename... Args>
struct CommonType<T, Args...>
{
    using Type = decltype(true ? declval<T>() : declval<typename CommonType<Args...>::Type>());
};

template<typename... Args>
using CommonType_t = typename CommonType<Args...>::Type;



struct Element {};

template<size_t SIZE>
struct P : Element
{
  char buffer[SIZE + 1]{};

  constexpr P(char const *stream)
  {
    for (unsigned index = 0; index != SIZE; ++index) { buffer[index] = stream[index]; }
  }

  constexpr P()
  {
    for (unsigned index = 0; index != SIZE; ++index) { buffer[index] = '\0'; }
  }
};

template<unsigned N>
P(char const (&)[N]) -> P<N - 1>;

template<typename, size_t SIZE>
class Html
{
public:
  Element data[SIZE]{};

  constexpr Html(){}

  constexpr Html(Element data[SIZE])
  {
    for (unsigned index = 0; index <= SIZE; index++)
    {
      this->data[index] = data[index];
    }
  }

  template<typename... Args>
  constexpr Html(Args... args) : data{args...} {}

  constexpr Element *begin() const {    return (Element*)this->data;     }
  constexpr Element *end() const   { return (Element*)this->data + SIZE; }

private:
  const size_t size = SIZE;
};

template<size_t SIZE>
Html(Element (&)[SIZE]) -> Html<Element, SIZE>;

template<typename... Args>
Html(Args...) -> Html<CommonType_t<Args...>, sizeof...(Args)>;

int main()
{
  Html h{ Element{}, Element{}, P{"Paragraph"}, Element{} };
}



// OR



// https://stackoverflow.com/questions/4041447/how-is-stdtuple-implemented/52208842#52208842

#include <iostream>
#include <string>
#include <tuple>

template <typename... Tags>
struct Html {
    constexpr Html(Tags... args) : tags(args...) {}

    template <typename Tag>
    constexpr const Tag& get() const {
        return std::get<Tag>(tags);
    }

    std::tuple<Tags...> tags;
};

struct h1 {
    static constexpr std::string_view tag = "h1";
    std::string_view content = "Header 1";
};
struct h2 {
    static constexpr std::string_view tag = "h2";
    std::string_view content = "Header 2";
};
struct b {
    static constexpr std::string_view tag = "b";
    std::string_view content = "Bold";
};
struct p {
    static constexpr std::string_view tag = "p";
    std::string_view content = "Paragraph";
};

template <typename... Tags>
constexpr auto make_html(Tags&&... tags) {
    return Html<std::decay_t<Tags>...>{std::forward<Tags>(tags)...};
}

template <typename... Tags>
auto make_html2(Tags... tags)
{
  return Html{tags...}; 
}

constexpr auto html = make_html(h1{}, h2{}, b{}, p{});

int main() {
    // visitor function that prints the type and content of each tag
    static constexpr auto visitor = [](const auto& tag) {
        std::cout << tag.tag << ": " << tag.content << std::endl;
    };

    // get the h1 tag and print its content
    static constexpr auto& h1_tag = html.get<h1>();
    std::cout << h1_tag.content << std::endl;

    return 0;
}
