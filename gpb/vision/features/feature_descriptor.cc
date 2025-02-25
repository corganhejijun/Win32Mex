/*
 * Feature descriptor.
 */
#include "math/matrices/matrix.hh"
#include "vision/features/feature.hh"
#include "vision/features/feature_descriptor.hh"
#include "vision/features/features_id.hh"
#include <memory>

namespace vision {
namespace features {
/*
 * Imports.
 */
using math::matrices::matrix;

/*
 * Constructor.
 * Create a feature descriptor at the given location in scale space.
 * Optionally set its identity.
 */
feature_descriptor::feature_descriptor(
   double x_coord, 
   double y_coord, 
   double ori, 
   double scl,
   const matrix<>& desc,
   std::auto_ptr<feature_id> f_id)
 : feature(x_coord, y_coord, ori, scl, f_id),
   _descriptor(desc)
{ }

/*
 * Copy constructor.
 * The copy does not have an id assigned unless specified.
 */
feature_descriptor::feature_descriptor(
   const feature_descriptor& f, 
   std::auto_ptr<feature_id> f_id)
 : feature(f, f_id),
   _descriptor(f._descriptor)
{ }

/*
 * Destructor.
 */
feature_descriptor::~feature_descriptor() {
   /* do nothing */
}

/*
 * Get the descriptor.
 */
const matrix<>& feature_descriptor::descriptor() const {
   return _descriptor;
}

} /* namespace features */
} /* namespace vision */
