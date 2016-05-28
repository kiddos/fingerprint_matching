#ifndef SIMILARITY_H
#define SIMILARITY_H

typedef enum similarityscoremethod_t {
  TRADITIONAL, HEURISTIC, NEURALNETWORK
} SimilarityScoreMethod;

typedef struct similarityscore_input {
  double n, sizei, sizer, oi, or, savg;
} SimilarityScoreInput;

typedef struct similarityscore_t {
  SimilarityScoreMethod method;
  double (*compute_score) (SimilarityScoreInput);
} SimilarityScore;

SimilarityScoreInput similarityscore_input_create(int n, int sizei, int sizer,
                                                  int oi, int or, double savg);
SimilarityScore similarityscore_create(SimilarityScoreMethod method);
double similarityscore_compute(SimilarityScore sc, SimilarityScoreInput input);

#endif /* end of include guard: SIMILARITY_H */
