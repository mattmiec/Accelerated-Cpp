// Vec class, a rudimentary implementation of std::vector
#include <memory>

template <class T> class Vec {
public:
    // typedefs
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef std::size_t size_type;
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;

    // constructors
    Vec() {create();}
    explicit Vec(size_type n, const T& t= T()) { create(n, t); }
    Vec(const Vec& v) { create(v.begin(), v.end()); }
    Vec& operator=(const Vec&);
    ~Vec() { uncreate(); }

    // index operator
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    // public methods
    void push_back (const T& t) {
        if (avail == limit)
            grow();
        unchecked_append(t);
    }

    void clear() {
      uncreate();
    }

    void erase(iterator b, iterator e) {
      std::ptrdiff_t diff = e - b;
      for (iterator iter = b; iter != this->end() - diff; ++iter)
        *iter = *(iter + diff);
      avail = avail - diff;
    }

    size_type size() const { return avail - data; }

    iterator begin() { return data; }
    const_iterator begin() const { return data; }

    iterator end() { return avail; }
    const_iterator end() const { return avail; }

private:
    iterator data; // first element in the Vec
    iterator avail; // (one past) last element in the Vec
    iterator limit; // (one past) allocated memory

    // facilities for memory allocation
    std::allocator<T> alloc; // object to handle memory allocation

    // allocate and initialize the underlying array
    void create()
  {
    data = avail = limit = 0;
  }
    void create(size_type n, const T& val)
  {
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, val);
  }
    void create(const_iterator i, const_iterator j)
  {
    data = alloc.allocate(j - i);
    limit = avail = std::uninitialized_copy(i, j, data);
  }

    // destroy the elements in the array and free the memory
    void uncreate()
  {
    if (data) {
      // destroy in reverse order
      iterator it = avail;
      while (it != data)
        alloc.destroy(--it);

      // return all the space that was allocate
      alloc.deallocate(data, limit - data);
    }
    // reset pointers to indicate that the Vec is empty again
    data = limit = avail = 0;
  }

    // support functions for push_back
    void grow()
  {
    // when growing, allocate twice as much space as currently in use
    size_type new_size = std::max(2 * (limit - data), std::ptrdiff_t(1));

    // allocate new space and copy exsting elements to the new space
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    // return the old space
    uncreate();

    // reset pointers to point to the newly allocated space
    data = new_data;
    avail = new_avail;
    limit = data + new_size;
  }
    void unchecked_append(const T& val)
  {
    alloc.construct(avail++, val);
  }

   
};
