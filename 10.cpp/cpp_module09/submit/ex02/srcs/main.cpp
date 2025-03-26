#include "../include/Pmerge.hpp"

// bool validinput(std::string token) {
//   char *endptr = NULL;
//   double val = strtod(token.c_str(), &endptr);
//   if (val < 0 || *endptr != '\0') {
//     std::cout << "Error: not invalid number\n";
//     return false;
//   }
//   return true;
// }

// bool input(int ac, char **av, Pmerge pm) {
//   int i = 1;
//   while (i < ac) {
//     std::string cmd = av[i];
//     std::stringstream ss(cmd);
//     std::string token;
//     while (ss >> token) {
//       if (!validinput(token)) return false;
//       pm.vec.push_back(static_cast<int>(strtod(token.c_str(), NULL)));
//     }
//     ++i;
//   }
//   return true;
// }

// int main(int ac, char **av) {
//   if (ac < 2) {
//     std::cout << "invalid : not enough arguments\n";
//     return 0;
//   }
//   Pmerge pm;
//   input(ac, av, pm);
//   // int i = 0;
//   // while (av[++i]) {
//   //   char *endptr = NULL;
//   //   double input = strtod(av[i], &endptr);
//   //   pm.vec.push_back(input);
//   //   pm.deq.push_back(input);
//   // }

//   pm.pair();

//   for (int i = 0; i < 6; i++) std::cout << pm.mainchain[i] << " ";
//   std::cout << "\n";
//   pm._usec = (((double)(pm._vecend - pm._vecstart)) / CLOCKS_PER_SEC);
//   std::cout << "took time : " << pm._usec << std::endl;
//   return 0;
// }

int main(int ac, char **av) {
  try {
    if (ac < 2)
      throw std::runtime_error("Error : not enough arguments");
    else {
      Pmerge pm;
      pm.execute(ac, av);
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}