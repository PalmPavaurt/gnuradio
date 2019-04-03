/* -*- c++ -*- */
/* 
 * Copyright 2018, 2019 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_DIGITAL_ALAMOUTI_DECODER_CC_IMPL_H
#define INCLUDED_DIGITAL_ALAMOUTI_DECODER_CC_IMPL_H

#include <gnuradio/digital/alamouti_decoder_cc.h>
#include <vector>

namespace gr {
  namespace digital {
/*! \brief Decodes an incoming stream after the rules of Alamouti's code.
 *
 * The Alamouti decoder works with sequences of length 2, decoding them
 * into a code sequence of length 2.
 * The number of input items is automatically scheduled to a multiple of 2, however,
 * if the input data stream is terminated, the absolute number of input items
 * must be an even number.
 * The Alamouti decoder is a sync block which produces the same amount of
 * output samples as there are input samples (however, because the input items
 * are vectors and the output is in stream mode, the block is actually an
 * interpolator block). The code rate is R=1.
 *
 * The CSI is transported via stream tags with key='csi'.
 * The CSI must be a 3-dimensional vector with the dimensions vlen, N(=1 for Alamouti), M(=2 for Alamouti).
 * For vlen>1 there is provided a separate channel matrix for each vector element.
 * Set vlen>1 if you use a multicarrier system like OFDM
 * (in this case it would be vlen=number of occupied sub-carriers).
 * To generate a proper CSI tag, use the pmt structure pmt_vector(pmt_vector(pmt_c32vector))).
 * Initially the CSI is set to 1.0 + 0j for both branches and are updated
 * with each incoming CSI. Because the Alamouti algorithm works with sequences
 * of length 2, the tags should be set only on samples with even positions.
 * CSI tags on uneven sample positions are not processed until the beginning of
 * the next sequence (in this case one sample delay).
 *
 * There exist different versions of the exact algorithm (changed
 * position of negations). This implementation follows [1] and is therefore
 * consistent with the Alamouti encoding block 'alamouti_encoder_cc'.
 *
 * [1] Andrea Goldsmith. 2005. Wireless Communications.
 *     Cambridge University Press, New York, NY, USA.
 */
    class alamouti_decoder_cc_impl : public alamouti_decoder_cc
    {
     private:
      uint32_t d_vlen; /*!< Vector length of the incoming items. */
      std::vector <gr::tag_t> tags; /*!< Vector that stores the tags in input buffer. */
      const pmt::pmt_t d_csi_key; /*!< PMT stores the key of the CSI tag. */
      std::vector<std::vector<std::vector<gr_complex> > > d_csi; /*!< Current channel matrix. */

      /*!
       * \brief Decodes the given buffer after the rules of Alamouti's code.
       *
       * \details The used CSI is the current vector of d_csi.
       *
       * @param in Pointer to input buffer.
       * @param out Pointer to output buffer.
       * @param length Number of samples that are being decoded.
       */
      void decode_symbol(const gr_complex* in, gr_complex* out, uint32_t length);

     public:
      alamouti_decoder_cc_impl(uint32_t vlen, const std::string &csi_tag_key);
      ~alamouti_decoder_cc_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace digital
} // namespace gr

#endif /* INCLUDED_DIGITAL_ALAMOUTI_DECODER_CC_IMPL_H */

