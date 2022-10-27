#ifndef SRC_DATA_LIBS_DATA_STAT_H_
#define SRC_DATA_LIBS_DATA_STAT_H_

double max(double *data, int n);
double min(double *data, int n);
double mean(double *data, int n);
double variance(double *data, int n, double mean);
void bubble(double *a, int n);
void swap(double *p1, double *p2);

#endif  // SRC_DATA_LIBS_DATA_STAT_H_
