

#include "mlir/IR/BuiltinOps.h"
#include "mlir/Transforms/Passes.h"
#include "src/Dialect/ONNX/ONNXDialect.hpp"
#include "src/Dialect/ONNX/ONNXOps.hpp"
#include "src/Pass/Passes.hpp"
#include "llvm/ADT/StringRef.h"

using namespace mlir;

namespace {
struct SeperateWeightsOutsidePass
    : public PassWrapper<SeperateWeightsOutsidePass,
          OperationPass<mlir::ONNXConstantOp>> {
  MLIR_DEFINE_EXPLICIT_INTERNAL_INLINE_TYPE_ID(SeperateWeightsOutsidePass);

private:
  void runOnOperation() override;
  StringRef getArgument() const final { return "seperate-weights-outside"; }
  StringRef getDescription() const final {
    return "seperate const Op's weight";
  }
};

} // namespace

void SeperateWeightsOutsidePass::runOnOperation() {
  // getOperation()->walk([&]())
}

namespace onnx_mlir {
std::unique_ptr<mlir::Pass> createSeperateWeighsOutsidePass() {
  return std::make_unique<SeperateWeightsOutsidePass>();
}

} // namespace onnx_mlir