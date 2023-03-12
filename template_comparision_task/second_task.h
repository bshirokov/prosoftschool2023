#include <type_traits>
#include <string>

template <typename T, typename ...OtherTypes>
struct any_of
{
    static constexpr bool value = (std::is_same_v<T, OtherTypes> || ...);
};

template <typename T, typename ...OtherTypes>
constexpr bool any_of_v = any_of<T, OtherTypes...>::value;

template<typename T>
class OtherComparisionOperators {
public:
    T& that = *static_cast<T*>(this);

    template <typename OtherT>
    bool operator<=(const OtherT& other) const {
        return !(that > other);
    }

    template <typename OtherT>
    bool operator>=(const OtherT& other) const {
        return !(that < other);
    }

    template <typename OtherT>
    bool operator==(const OtherT& other) const {
        return !(that > other) && !(that < other);
    }

    template <typename OtherT>
    bool operator!=(const OtherT& other) const {
        return !(that == other);
    }
};

class A: public OtherComparisionOperators<A>
{
public:
    A(int a, int b) : m_a(a), m_b(b){}

    template <typename OtherT>
    std::enable_if_t<any_of_v<OtherT, A>, bool>
    operator<(const OtherT& other) const
    {
        return (m_a < other.m_a) && (m_b < other.m_b);
    }

    template <typename OtherT>
    std::enable_if_t<any_of_v<OtherT, A>, bool>
    operator>(const OtherT& other) const
    {
        return (m_a > other.m_a) && (m_b > other.m_b);
    }

    template <typename OtherT>
    std::enable_if_t<std::is_integral_v<OtherT>, bool> 
    operator<(const OtherT& other) const
    {
        return m_a < other;
    }

    template <typename OtherT>
    std::enable_if_t<std::is_integral_v<OtherT>, bool> 
    operator>(const OtherT& other) const
    {
        return m_a > other;
    }

    template <typename OtherT>
    std::enable_if_t<std::is_floating_point_v<OtherT>, bool>
    operator<(const OtherT& other) const
    {
        return static_cast<OtherT>(m_a) < other;
    }

    template <typename OtherT>
    std::enable_if_t<std::is_floating_point_v<OtherT>, bool>
    operator>(const OtherT& other) const
    {
        return static_cast<OtherT>(m_a) > other;
    }

private:
    int m_a = 0;
    int m_b = 0;
};

class B: public OtherComparisionOperators<B>
{
public:
    B(std::string_view str) : m_str(str){}

    template <typename OtherT>
    std::enable_if_t<any_of_v<OtherT, B>, bool>
    operator<(const OtherT& other) const
    {
        return m_str < other.m_str;
    }

    template <typename OtherT>
    std::enable_if_t<any_of_v<OtherT, B>, bool>
    operator>(const OtherT& other) const
    {
        return m_str > other.m_str;
    }

    template <typename OtherT>
    std::enable_if_t<!any_of_v<OtherT, B>, bool>
    operator<(const OtherT& other) const
    {
        return m_str < other;
    }

    template <typename OtherT>
    std::enable_if_t<!any_of_v<OtherT, B>, bool>
    operator>(const OtherT& other) const
    {
        return m_str > other;
    }

private:
    std::string_view m_str;
};
