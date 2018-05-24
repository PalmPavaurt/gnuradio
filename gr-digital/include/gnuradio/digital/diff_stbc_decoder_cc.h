/* -*- c++ -*- */
/* 
 * Copyright 2018 Free Software Foundation, Inc.
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


#ifndef INCLUDED_DIGITAL_DIFF_STBC_DECODER_CC_H
#define INCLUDED_DIGITAL_DIFF_STBC_DECODER_CC_H

#include <gnuradio/digital/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace digital {

    /*!
     * \brief <+description of block+>
     * \ingroup digital
     *
     */
    class DIGITAL_API diff_stbc_decoder_cc : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<diff_stbc_decoder_cc> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of digital::diff_stbc_decoder_cc.
       *
       * To avoid accidental use of raw pointers, digital::diff_stbc_decoder_cc's
       * constructor is in a private implementation
       * class. digital::diff_stbc_decoder_cc::make is the public interface for
       * creating new instances.
       */
      static sptr make(float phase_offset=0.0);
    };

  } // namespace digital
} // namespace gr

#endif /* INCLUDED_DIGITAL_DIFF_STBC_DECODER_CC_H */

