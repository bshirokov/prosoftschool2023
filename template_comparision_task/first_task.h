#include <string>

template<typename T>
class OtherComparisionOperators {
public:
    T& that = *static_cast<T*>(this);

    //Сравнение со схожим типом
    bool operator<=(const T& other) const {
        return !(that > other);
    }

    bool operator>=(const T& other) const {
        return !(that < other);
    }

    bool operator==(const T& other) const {
        return !(that > other) && !(that < other);
    }

    bool operator!=(const T& other) const {
        return !(that == other);
    }

    //Сравнение с другим типом
    template <typename U>
    bool operator<=(const U& other) const {
        return !(that > other);
    }

    template <typename U>
    bool operator>=(const U& other) const {
        return !(that < other);
    }

    template <typename U>
    bool operator==(const U& other) const {
        return !(that > other) && !(that < other);
    }

    template <typename U>
    bool operator!=(const U& other) const {
        return !(that == other);
    }
};

class NewA: public OtherComparisionOperators<NewA>
{
public:
    NewA(int a, int b) : m_a(a), m_b(b){}

    // Операторы сравнения с NewA
    bool operator<(const NewA& other) const
    {
        return (m_a < other.m_a) && (m_b < other.m_b);
    }

    bool operator>(const NewA& other) const
    {
        return (m_a > other.m_a) && (m_b > other.m_b);
    }

    // Операторы сравнения с int
    bool operator<(const int other) const
    {
        return m_a < other;
    }

    bool operator>(const int other) const
    {
        return m_a > other;
    }

    // Операторы сравнения с double
    bool operator<(const double other) const
    {
        return static_cast<int>(m_a) < other;
    }

    bool operator>(const double other) const
    {
        return static_cast<int>(m_a) > other;
    }

    // Операторы сравнения с char
    bool operator<(const char other) const
    {
        return m_a < static_cast<int>(other);
    }

    bool operator>(const char other) const
    {
        return m_a > static_cast<int>(other);
    }

    // Операторы сравнения с bool
    bool operator<(const bool other) const
    {
        return static_cast<bool>(m_a) < other;
    }

    bool operator>(const bool other) const
    {
        return static_cast<bool>(m_a) > other;
    }

private:
    int m_a = 0;
    int m_b = 0;
};

class NewB : public OtherComparisionOperators<NewB>
{
public:
    NewB(std::string_view val) : m_stringView(val){}

    // Операторы сравнения с NewB
    bool operator<(const NewB& other) const
    {
        return m_stringView < other.m_stringView;
    }

    bool operator>(const NewB& other) const
    {
        return m_stringView > other.m_stringView;
    }

    // Операторы сравнения с std::string
    bool operator<(const std::string& other) const
    {
        return m_stringView < other;
    }

    bool operator>(const std::string& other) const
    {
        return m_stringView > other;
    }

private:
    std::string_view m_stringView;
};
