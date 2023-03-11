#pragma once

template<typename T, typename Compare = const T&>
class OtherComparisionOperators {
public:
    auto derived() const noexcept { return static_cast<const T&>(*this); }

    bool operator<=(Compare other) const {
        return !(derived() > other);
    }

    bool operator>=(Compare other) const {
        return !(derived() < other);
    }

    bool operator==(Compare other) const {
        return derived() <= other && derived() >= other;
    }

    bool operator!=(Compare other) const {
        return !(derived() == other);
    }
};