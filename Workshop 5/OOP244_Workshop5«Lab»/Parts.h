// Parts.h

#ifndef SDDS_PARTS_H
#define SDDS_PARTS_H

namespace sdds{
  class Arms {
    const int MIN_FORCE = 50;
    int a_force;

    public :

    Arms();
    void AllocateMemoryForForce();
    Arms(int armsForce);
    bool isEmpty() const;
    int getForce() const;
    Arms& operator++();
    Arms operator++(int);
    Arms& operator+=(int add);

  };
}

#endif
