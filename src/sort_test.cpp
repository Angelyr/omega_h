#include <oneapi/dpl/algorithm>
#include <oneapi/dpl/execution>
#include "Omega_h_library.hpp"
//#include "Omega_h_sort.hpp"

int main(int argc, char** argv) {
  using namespace Omega_h;
  auto lib = Library(&argc, &argv);
  auto world = lib.world();
  {
    LOs a({0, 1});
    int const n = a.size();
    Write<LO> perm(n, 0, 1);

    auto space = Kokkos::Experimental::SYCL();
    const auto q = space.impl_internal_space_instance()->m_queue;

    using namespace oneapi::dpl::execution;
    using namespace sycl;
    auto policy = make_device_policy(q);
  }
//    oneapi::dpl::sort(
//        policy, perm.data(), perm.data() + n,
//        [](auto lhs, auto rhs) { return std::get<0>(lhs) < std::get<0>(rhs); });
//
//    OMEGA_H_CHECK(permute == LOs({0, 1}));
//  }
//  {
//    LOs a({0, 2, 0, 1});
//    LOs perm = sort_by_keys(a, 2);
//    OMEGA_H_CHECK(perm == LOs({1, 0}));
//  }
//  {
//    LOs a({0, 2, 1, 1});
//    LOs perm = sort_by_keys(a, 2);
//    OMEGA_H_CHECK(perm == LOs({0, 1}));
//  }
//  {
//    LOs a({1, 2, 3, 1, 2, 2, 3, 0, 0});
//    LOs perm = sort_by_keys(a, 3);
//    OMEGA_H_CHECK(perm == LOs({1, 0, 2}));
//  }
  return 0;
}
