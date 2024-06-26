#include <Kokkos_Core.hpp>
#include <impl/Kokkos_Profiling.hpp>

#define N 10

int main(int argc, char* argv[]) {
    Kokkos::ScopeGuard guard(argc ,argv);
    Kokkos::Profiling::pushRegion("Whole Program");

    Kokkos::View<int[N]> view("A View", N);

    Kokkos::Profiling::pushRegion("Set Values");
    printf("enter parallel_for\n");
    Kokkos::parallel_for(N, KOKKOS_LAMBDA (const int &i) {
        view(i) = i;
    });
    Kokkos::Profiling::popRegion();

    Kokkos::Profiling::pushRegion("Print Values");
    printf("print view\n");
    Kokkos::parallel_for(N, KOKKOS_LAMBDA (const int &i) {
        printf("view(i): %d\n", view(i));
    });
    Kokkos::Profiling::popRegion();

    Kokkos::Profiling::popRegion();
    return 0;
}
