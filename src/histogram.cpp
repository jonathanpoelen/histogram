#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

template<class T, std::size_t N>
constexpr std::size_t size(T const (&)[N])
{ return N; }

template<class T, std::size_t N>
constexpr T const & back(T const (&a)[N])
{ return a[N-1]; }

int main(/*int ac, char ** av*/)
{
  // ▓
  // ■ □ ▢ ▣ ▤ ▥ ▦ ▧ ▨ ▩ ▪ ▫ ▬ ▭ ▮ ▯ ○ ◌ ◍ ◎ ● ◘ ◙ ◻ ◼ ◽ ◾ ▀
  //constexpr char const * chars[]{
  //  "▁", "▂", "▃", "▄", "▅", "▆", "▇", "█",
  //};
  constexpr char const * chars[]{
//     "▏", "▎", "▍", "▌", "▋", "▊", "▉", "█",
    "▣"
  };

  // -f --format value, value_legend, legend_value, v, vl, lv
  // -c --color
  // -s --stream
  // -r --range min,max
  // -d --floating floating value

  std::vector<long long> values;
  {
    long long n;
    while (std::cin >> n) {
      values.push_back(n);
    }
  }

  if (values.empty()) {
    return 0;
  }

  using std::begin;
  using std::end;

  long long const chars_count = size(chars);
  auto const width = 80 * chars_count;
  auto const min = *std::min_element(begin(values), end(values));
  auto const adjustment = std::max(-min, 0ll);
  auto const max = *std::max_element(begin(values), end(values)) + adjustment;

  for (auto v : values) {
    v += adjustment;
    auto l = width * v / max;
    std::cout << "[" << std::setw(3) << (v * 100 / max) << "%]";
    for (; l >= chars_count; l -= chars_count) {
      std::cout << back(chars);
    }
    if (l) {
      std::cout << chars[l - 1];
    }
    std::cout << "\n";
  }
}
