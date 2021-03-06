#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cassert>

void AreEqual(const std::string& expected, const std::string& actual)
{
    if (expected == actual)
        std::cout << "\033[32mPASS\033[0m" << std::endl;
    else
    {
        std::cout << "\033[31mFAIL\033[0m" << std::endl;
        std::cout << "expected: " << expected << std::endl;
        std::cout << "actual: " << actual << std::endl;
    }
}

std::string Reverse(const std::string& s)
{
    std::string ss = s;
    char* cs = s.c_str();

    size_t n = s.length();
    for (size_t x = 0; x < n / 2; x++)
        std::swap(*(cs + x), *(cs + n - x - 1));

    return std::move(std::string(cs));
}

int main()
{
    AreEqual("dcba", Reverse("abcd"));
    AreEqual("cba", Reverse("abc"));
    AreEqual("aA", Reverse("Aa"));
    AreEqual("airaM", Reverse("Maria"));
    AreEqual("xelA", Reverse("Alex"));
    AreEqual("", Reverse(""));

    return 0;
}
