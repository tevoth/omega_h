#ifndef OMEGA_H_ADAPT_HPP
#define OMEGA_H_ADAPT_HPP

#include <Omega_h_config.h>

namespace Omega_h {

class Mesh;

enum Verbosity { SILENT, EACH_ADAPT, EACH_REBUILD, EXTRA_STATS };

#ifdef OMEGA_H_USE_EGADS
struct Egads;
#endif

struct AdaptOpts {
  AdaptOpts(Int dim);     // sets defaults
  AdaptOpts(Mesh* mesh);  // calls above
  Real min_length_desired;
  Real max_length_desired;
  Real max_length_allowed;
  Real min_quality_allowed;
  Real min_quality_desired;
  Int nsliver_layers;
  Verbosity verbosity;
  Real length_histogram_min;
  Real length_histogram_max;
#ifdef OMEGA_H_USE_EGADS
  Egads* egads_model;
  bool should_smooth_snap;
  Real snap_smooth_tolerance;
#endif
  Int max_motion_steps;
  Real motion_step_size;
  bool should_refine;
  bool should_coarsen;
  bool should_swap;
  bool should_coarsen_slivers;
  bool should_move_for_quality;
  bool should_allow_pinching;
};

Real min_fixable_quality(Mesh* mesh, AdaptOpts const& opts);

/* returns false if the mesh was not modified. */
bool adapt(Mesh* mesh, AdaptOpts const& opts);

bool print_adapt_status(Mesh* mesh, AdaptOpts const& opts);
void print_adapt_histograms(Mesh* mesh, AdaptOpts const& opts);

}

#endif
