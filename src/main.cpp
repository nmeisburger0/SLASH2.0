#include <mpi.h>

#include <iostream>
#include <vector>

#include "slash/Slash.h"
#include "util/Eval.h"
#include "util/Reader.h"
using namespace std;

int main(int argc, char *argv[]) {
  int provided;
  MPI_Init_thread(0, 0, MPI_THREAD_FUNNELED, &provided);
  int my_rank, world_size;
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

//   const std::string webspam =
//       "/mnt/c/Users/nmeis/Research/SLASH/dataset/webspam/webspam_trigram.svm";

// //Num_tables, k, reservoir size, range pow
//   Slash s(24, 4, 64, 12);
// // const string filename, uint64_t numItems, uint64_t batchSize, uint32_t avgDim, uint64_t offset = 0
//   s.store(webspam, 1000, 10, 4000, 100);
// //const string filename, uint32_t avgDim, uint64_t numQueries, uint64_t k,  uint64_t offset = 0
//   auto query = s.topK(webspam, 4000, 100, 32);

//   Reader r(webspam, 4000);

//   auto data = r.readSparse(1100);

//   unsigned int nlist[] = {1, 4, 8, 16, 32};

//   similarityMetric(data.indices, data.values, data.markers, data.indices, data.values,
//                    data.markers + 100, query, 100, 32, nlist, 5);

  string coco_file = "../../../coco_vectors_350.txt"; // Stored on NOTS
  // vector<vector<float>> mat = readvec(coco_file);
  Slash s(50, 10, 400, 10);
  s.storevec(coco_file, 10000);

  MPI_Finalize();

  return 0;
}
