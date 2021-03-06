/**
MIT License

Copyright (c) 2017 DECTRIS Ltd.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "H5HeaderMsg.h"
#include <assert.h>

H5HeaderMsgPreamble::H5HeaderMsgPreamble(const char *fileAddress, size_t offset):
   H5Object(fileAddress, offset)
{
   this->_init();
}

H5HeaderMsgPreamble::H5HeaderMsgPreamble(const H5Object &other):
   H5Object(other)
{
    this->_init();
}

H5Object H5HeaderMsgPreamble::getHeaderMsg() const
{
    return at(DATA_OFFSET);
}

uint16_t H5HeaderMsgPreamble::type() const
{
   return uint16(0);
}

uint16_t H5HeaderMsgPreamble::size() const
{
   return uint16(2);
}

uint8_t H5HeaderMsgPreamble::flags() const
{
   assert(this->size() > 0 || this->type() == 0);
   return uint8(4);
}

void H5HeaderMsgPreamble::_init()
{
   assert(this->type() <= 0x18);
   assert(this->uint8(5) == 0);
   assert(this->uint8(6) == 0);
   assert(this->uint8(7) == 0);
   assert((flags() & 0x2) == 0); // We do not support shared messages
}

