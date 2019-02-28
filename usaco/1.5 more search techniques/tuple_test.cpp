#include <tuple>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    typedef tuple<int, int, int> s_t;
    s_t a{1, 2, 3};
    vector<s_t> b{};
    b.push_back(a);
    return 0;
}
