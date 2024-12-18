// sherpa-onnx/csrc/online-transducer-greedy-search-decoder.h
//
// Copyright (c)  2023  Xiaomi Corporation

#ifndef SHERPA_ONNX_CSRC_ONLINE_TRANSDUCER_GREEDY_SEARCH_DECODER_H_
#define SHERPA_ONNX_CSRC_ONLINE_TRANSDUCER_GREEDY_SEARCH_DECODER_H_

#include <vector>

#include "sherpa-onnx/csrc/online-transducer-decoder.h"
#include "sherpa-onnx/csrc/online-transducer-model.h"

namespace sherpa_onnx {

class OnlineTransducerGreedySearchDecoder : public OnlineTransducerDecoder {
 public:
  OnlineTransducerGreedySearchDecoder(OnlineTransducerModel *model,
                                      int32_t unk_id,
                                      float blank_penalty)
      : model_(model), unk_id_(unk_id), blank_penalty_(blank_penalty) {}

  OnlineTransducerDecoderResult GetEmptyResult(OnlineStream *stream) const override;

  void StripLeadingBlanks(OnlineTransducerDecoderResult *r) const override;

  void Decode(Ort::Value encoder_out,
              std::vector<OnlineTransducerDecoderResult> *result) override;

 private:
  OnlineTransducerModel *model_;  // Not owned
  int32_t unk_id_;
  float blank_penalty_;
};

}  // namespace sherpa_onnx

#endif  // SHERPA_ONNX_CSRC_ONLINE_TRANSDUCER_GREEDY_SEARCH_DECODER_H_
