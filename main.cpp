#include <Kokkos_Core.hpp>

int main(int argc, char* argv[]) {
    Kokkos::ScopeGuard guard(argc ,argv);

    Kokkos::View<int[10]> view("A View", 10);

    printf("enter parallel_for\n");
    Kokkos::parallel_for(10, KOKKOS_LAMBDA (const int &i) {
        view(i) = i;
    });

    printf("print view\n");
    Kokkos::parallel_for(10, KOKKOS_LAMBDA (const int &i) {
        printf("view(i): %d\n", view(i));
    });
    return 0;
}
