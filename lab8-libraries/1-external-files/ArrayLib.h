// If ArrayLib not defined, define it (and it's prototypes)
#ifndef ArrayLib
    #define ArrayLib

    typedef struct {
        double *vector;
        int count;
        int length;
    } Vector;

    // Prototypes
    Vector create_vector(int length);
    Vector empty_vector();
    int insert(Vector *vec, double dbl);
    void print_vec(Vector vec);
    void print_min(Vector vec);
    void delete_vector(Vector *vec);
    Vector copy(Vector vec);
    Vector copy_range(Vector vec, int from, int to);
    void clear_vector(Vector *vec);
    void zeros(Vector *vec);
    void fill(Vector *vec, double dbl);
    Vector read_from_file(char *filename);
    int write_to_file(Vector vec, char *filename);
    Vector get_from_con();
    void add_from_con(Vector *vec);
    void swap(Vector *vec, int i, int j);
    void sort(Vector *vec);
    void reverse(Vector *vec);
    int dbl_equals(double d1, double d2);
    int search(Vector vec, double dbl);
    double sum(Vector vec);
    double avg(Vector vec);
    double var(Vector vec);
    double stdv(Vector vec);
    Vector add(Vector v1, Vector v2);
    Vector sub(Vector v1, Vector v2);
    Vector mul(Vector v1, Vector v2);
    Vector divv(Vector v1, Vector v2);
    double dot(Vector v1, Vector v2);
    int equals(Vector v1, Vector v2);

#endif