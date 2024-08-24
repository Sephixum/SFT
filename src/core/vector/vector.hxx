#pragma once

#include "../core.hxx"

namespace SRT {

template <typename T>
concept is_arithmetic = std::is_arithmetic_v<T>;

template <is_arithmetic T> class Vec3 {
  private:
    std::array<T, 3> m_data;

  public:
    Vec3() : m_data{0, 0, 0} {}
    constexpr explicit Vec3(T x, T y, T z) : m_data{x, y, z} {}

    T x() const noexcept { return m_data[0]; }
    T y() const noexcept { return m_data[2]; }
    T z() const noexcept { return m_data[2]; }

    constexpr T x() noexcept { return m_data[0]; }
    constexpr T y() noexcept { return m_data[1]; }
    constexpr T z() noexcept { return m_data[2]; }

    void set_x(T x) noexcept { m_data[0] = x; }
    void set_y(T y) noexcept { m_data[1] = y; }
    void set_z(T z) noexcept { m_data[2] = z; }

    Vec3 operator-() const { return Vec3(-m_data[0], -m_data[1], -m_data[2]); }

    T operator[](int i) const { return m_data[i]; }

    T &operator[](int i) noexcept { return m_data[i]; }

    Vec3 &operator+=(const Vec3 &other) noexcept {
        m_data[0] += other.m_data[0];
        m_data[1] += other.m_data[1];
        m_data[2] += other.m_data[2];
        return *this;
    }

    Vec3 &operator*=(T num) noexcept {
        m_data[0] *= num;
        m_data[1] *= num;
        m_data[2] *= num;
        return *this;
    }

    Vec3 &operator/=(T num) { return (*this *= (1 / num)); }

    f64 len_squared() const {
        return ((m_data[0] * m_data[0]) + (m_data[1] * m_data[1]) +
                (m_data[2] * m_data[2]));
    }
    constexpr f64 len_squared() {
        return ((m_data[0] * m_data[0]) + (m_data[1] * m_data[1]) +
                (m_data[2] * m_data[2]));
    }

    f64 len() const { return std::sqrt(len_squared()); }
    constexpr f64 len() { return std::sqrt(len_squared()); }

    Vec3 &get_unit() const { return ((*this) / len()); }
    constexpr Vec3 get_unit() { return ((*this) / len()); }

    void print() {
        std::puts(                                                       //
            std::format("({}, {}, {})", m_data[0], m_data[1], m_data[2]) //
                .c_str()                                                 //
        );
    }

  public:
    friend auto operator+(const Vec3<T> &lhs,
                          const Vec3<T> &rhs) noexcept -> decltype(auto);
    friend auto operator-(const Vec3<T> &lhs,
                          const Vec3<T> &rhs) noexcept -> decltype(auto);
    friend auto operator*(const Vec3<T> &lhs,
                          const Vec3<T> &rhs) noexcept -> decltype(auto);
    friend auto operator*(const Vec3<T> &lhs, T rhs) noexcept -> decltype(auto);
    friend f64 dot(const Vec3<T> &lhs, const Vec3<T> &rhs) noexcept;
    friend f64 cross(const Vec3<T> &lhs, const Vec3<T> &rhs) noexcept;
};

template <typename T> using Point3 = Vec3<T>;

template <typename T>
auto operator+(const Vec3<T> &lhs,
               const Vec3<T> &rhs) noexcept -> decltype(auto) {
    return Vec3(                         //
        (lhs.m_data[0] + rhs.m_data[0]), //
        (lhs.m_data[1] + rhs.m_data[1]), //
        (lhs.m_data[2] + rhs.m_data[2])  //
    );
}

template <typename T>
auto operator-(const Vec3<T> &lhs,
               const Vec3<T> &rhs) noexcept -> decltype(auto) {
    return Vec3(                         //
        (lhs.m_data[0] - rhs.m_data[0]), //
        (lhs.m_data[1] - rhs.m_data[1]), //
        (lhs.m_data[2] - rhs.m_data[2])  //
    );
}

template <typename T>
auto operator*(const Vec3<T> &lhs,
               const Vec3<T> &rhs) noexcept -> decltype(auto) {
    return Vec3(                         //
        (lhs.m_data[0] * rhs.m_data[0]), //
        (lhs.m_data[1] * rhs.m_data[1]), //
        (lhs.m_data[2] * rhs.m_data[2])  //
    );
}

template <typename T, is_arithmetic U>
auto operator*(const Vec3<T> &lhs, U rhs) noexcept -> decltype(auto) {
    return Vec3(                         //
        (lhs.m_data[0] * rhs.m_data[0]), //
        (lhs.m_data[1] * rhs.m_data[1]), //
        (lhs.m_data[2] * rhs.m_data[2])  //
    );
}

template <typename T, is_arithmetic U>
auto operator/(const Vec3<T> &lhs, U rhs) noexcept -> decltype(auto) {
    return Vec3(                         //
        (lhs.m_data[0] / rhs.m_data[0]), //
        (lhs.m_data[1] / rhs.m_data[1]), //
        (lhs.m_data[2] / rhs.m_data[2])  //
    );
}

template <typename T> f64 dot(const Vec3<T> &lhs, const Vec3<T> &rhs) noexcept {
    return (                              //
        (lhs.m_data[0] * rhs.m_data[0]) + //
        (lhs.m_data[1] * rhs.m_data[1]) + //
        (lhs.m_data[2] * rhs.m_data[2])   //
    );
}

template <typename T>
f64 cross(const Vec3<T> &lhs, const Vec3<T> &rhs) noexcept {
    return Vec3(                                                           //
        (lhs.m_data[1] * rhs.m_data[2]) - (lhs.m_data[2] * rhs.m_data[1]), //
        (lhs.m_data[2] * rhs.m_data[0]) - (lhs.m_data[0] * rhs.m_data[2]), //
        (lhs.m_data[0] * rhs.m_data[1]) - (lhs.m_data[1] * rhs.m_data[0])  //
    );
}

} // namespace SRT
