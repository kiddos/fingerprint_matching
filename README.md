Minutiae Based Fingerprint Matching
===================================
[![Build Status](https://travis-ci.org/kiddos/fingerprint_matching.svg?branch=master)](https://travis-ci.org/kiddos/fingerprint_matching)

## Modules
1. Common
  * provide some basic math operations
2. Minutiae
  * describe Minutiae and matching function
3. Minutiaset
  * group Minutia and MinutiaRaw together and provide 2 set matching
4. Fingerprint
  * group MinutiaRawSet and MinutiaSets in a fingerprint
5. FingerprintSet
  * group Fingerprint together and find best match fingerprint
6. SimilarityScore
  * different method of computing similarity of fingerprint

## TODO
- [ ] implement convex hull and compute Oi and Or
- [x] need to adjust threshold functions for 2 minutia matching so that higher similarity score can be reached
- [ ] implement heuristic rule to compute similarity score
- [ ] save similarity score into a file so thay the average can be computed
