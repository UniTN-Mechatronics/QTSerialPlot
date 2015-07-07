#ifndef __LOWPASS_LIB__
#define __LOWPASS_LIB__

class Low_pass {
  public:
    void init(double f_c, double y_0); // f_c: cut frequency (Hz), y_0: initial condition
    Low_pass(double f_c);
    Low_pass(double f_c, double y_0);
    double update(double u, double dt);
    void set_y0(double y_0);
  private:
    // double y;   // output
    double y_p; // previous output
    double rc;
    double alpha;
};

#endif
