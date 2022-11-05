#include <string>
#include <vector>
#include <stdio.h>
#include <stdh.h>
#include <iterator>
#include <utility>


template <typename T> T invert(T number) {
  return number * (-1);
}

void splittovec(std::string str, std::string splitby, std::vector<std::string>& tokens)
{
    tokens.push_back(str);
    size_t splitAt;
    size_t splitLen = splitby.size();
    std::string frag;
    while(true)
    {
        frag = tokens.back();
        splitAt = frag.find(splitby);
        if(splitAt == std::string::npos)
        {
            break;
        }
        tokens.back() = frag.substr(0, splitAt);
        tokens.push_back(frag.substr(splitAt+splitLen, frag.size()-(splitAt+splitLen)));
    }
}

std::vector<std::string> split(std::string stra, std::string splitbya) {
  std::vector<std::string> resultsa;
  splittovec(stra, splitbya, resultsa);
  return resultsa;
}

void outvec_int(std::vector <int> const &a) {
  std::cout << "{ ";
  for(int i=0; i < a.size(); i++) {
    if(i==a.size()-1) {
      std::cout << a.at(i) << " }\n";
    }
    else {
      std::cout << a.at(i) << ", ";
    }
  }
}

void outvec_str(std::vector <std::string> const &a) {
  std::cout << "{ ";
  for(int i=0; i < a.size(); i++) {
    if(i==a.size()-1) {
      std::cout << a.at(i) << " }\n";
    }
    else {
      std::cout << a.at(i) << ", ";
    }
  }
}

void outvec_char(std::vector <char> const &a) {
  std::cout << "{ ";
  for(int i=0; i < a.size(); i++) {
    if(i==a.size()-1) {
      std::cout << a.at(i) << " }\n";
    }
    else {
      std::cout << a.at(i) << ", ";
    }
  }
}

void outvec_bool(std::vector <bool> const &a) {
  std::cout << "{ ";
  for(int i=0; i < a.size(); i++) {
    if(i==a.size()-1) {
      std::cout << a.at(i) << " }\n";
    }
    else {
      std::cout << a.at(i) << ", ";
    }
  }
}

template<typename T>
class Range
{
    public:
    typedef T value_type;

    public:
    class iterator
    {
        public:
        typedef typename std::forward_iterator_tag iterator_category;
        typedef typename std::size_t size_type;
        typedef typename std::ptrdiff_t difference_type;
        typedef T value_type;
        typedef const T& reference;
        typedef const T* pointer;

        public:
        iterator(const T& value) noexcept
        :   m_value(value)
        {}

        reference operator * () const noexcept { return m_value; }
        pointer operator -> () const noexcept { return &m_value; }
        iterator& operator ++ () noexcept { ++m_value; return *this; }

        friend bool operator == (const iterator & a, const iterator b) noexcept {
            return a.m_value == b.m_value;
        }
        friend bool operator != (const iterator & a, const iterator b) noexcept {
            return a.m_value != b.m_value;
        }

        private:
        T m_value;
    };

    public:
    Range(const T& first, const T& last) noexcept
    :   m_first(first), m_last(last)
    {}

    Range(T&& first, T&& last) noexcept
    :   m_first(std::move(first)), m_last(std::move(last))
    {}

    Range(Range&& other) noexcept
    :   m_first(std::move(other.m_first)),
        m_last(std::move(other.m_last))
    {}

    Range& operator = (Range&& other) noexcept {
        m_first = std::move(other.m_first);
        m_last = std::move(other.m_last);
        return *this;
    }

    iterator begin() const noexcept { return  m_first; }
    iterator end() const noexcept { return m_last; }

    private:
    T m_first;
    T m_last;
};

template<typename T>
inline Range<T> range(T&& first, T&& last) noexcept {
    return Range<T>(std::move(first), std::move(last));
}


