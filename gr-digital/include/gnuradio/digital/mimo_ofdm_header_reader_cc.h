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


#ifndef INCLUDED_DIGITAL_MIMO_OFDM_HEADER_READER_CC_H
#define INCLUDED_DIGITAL_MIMO_OFDM_HEADER_READER_CC_H

#include <gnuradio/digital/api.h>
#include <gnuradio/digital/constellation.h>
#include <gnuradio/digital/packet_header_default.h>
#include <gnuradio/block.h>

namespace gr {
  namespace digital {

    /*! \brief Parses header and adds header tags to extracted payload stream.
     *
     * -Input: Synchronized and equalized sample stream with 'start' tags on the beginning of each frame.
     * -Read and demodulate header. Parse and validate header info.
     * -Add header info with stream tags to the beginning of each packet.
     * -Output: Payload stream (not yet demodulated) with header tags at the beginning of each packet.
     */
    class DIGITAL_API mimo_ofdm_header_reader_cc : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<mimo_ofdm_header_reader_cc> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of digital::mimo_ofdm_header_reader_cc.
       *
       * To avoid accidental use of raw pointers, digital::mimo_ofdm_header_reader_cc's
       * constructor is in a private implementation
       * class. digital::mimo_ofdm_header_reader_cc::make is the public interface for
       * creating new instances.
       */
      static sptr make(constellation_sptr constellation, const gr::digital::packet_header_default::sptr &header_formatter, 
                       const std::string &start_key="start", const std::string &len_tag_key="packet_length", 
                       const std::string &frame_len_tag_key="frame_length", const std::string &num_tag_key="packet_num");
    };

  } // namespace digital
} // namespace gr

#endif /* INCLUDED_DIGITAL_MIMO_OFDM_HEADER_READER_CC_H */

