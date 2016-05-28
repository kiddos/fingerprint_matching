#include "similarity.h"

static double similarity_traditional(SimilarityScoreInput input) {
  return input.n*input.n / input.sizei / input.sizer;
}

/** TODO */
static double similarity_heuristic(SimilarityScoreInput input) {
  return input.n*input.n*input.savg/input.sizei/input.sizer/input.oi/input.or;
}

/** TODO */
static double similarity_neuralnet(SimilarityScoreInput input) {
  return input.n*input.n*input.savg/input.sizei/input.sizer/input.oi/input.or;
}

SimilarityScoreInput similarityscore_input_create(int n, int sizei, int sizer,
                                                  int oi, int or, double savg) {
  SimilarityScoreInput input;
  input.n = (double) n;
  input.sizei = (double) sizei;
  input.sizer = (double) sizer;
  input.oi = (double) oi;
  input.or = (double) or;
  input.savg = savg;
  return input;
}

SimilarityScore similarityscore_create(SimilarityScoreMethod method) {
  SimilarityScore score = {method, similarity_traditional};

  switch (method) {
    case TRADITIONAL:
      score.compute_score = similarity_traditional;
      break;
    case HEURISTIC:
      score.compute_score = similarity_heuristic;
      break;
    case NEURALNETWORK:
      score.compute_score = similarity_neuralnet;
      break;
  }
  return score;
}

double similarityscore_compute(SimilarityScore sc, SimilarityScoreInput input) {
  return sc.compute_score(input);
}
