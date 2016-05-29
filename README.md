Minutiae Based Fingerprint Matching
===================================

## Modules
1. Common
..* provide some basic math operations
2. Minutiae
..* describe Minutiae and matching function
3. Minutiaset
..* group Minutia and MinutiaRaw together and provide 2 set matching
4. Fingerprint
..* group MinutiaRawSet and MinutiaSets in a fingerprint
5. FingerprintSet
..* group Fingerprint together and find best match fingerprint

## TODO
- [x] need to adjust threshold functions for 2 minutia matching so that higher similarity score can be reached
- [x] implement heuristic rule to compute similarity score
- [x] save similarity score into a file so thay the average can be computed
- [x] implement convex hull and ray casting algorithm to check rather a point is inside the polygon
