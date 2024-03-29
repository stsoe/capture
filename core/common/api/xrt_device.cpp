#include "core/include/xrt/xrt_device.h"

#include <iostream>
#include <memory>
#include <string>

namespace xrt {

class device_impl
{
public:
  device_impl(unsigned int index)
  {
    std::cout << "xrt::device_impl::device_impl(" << index << ")\n";
  }
  ~device_impl()
  {
    std::cout << "xrt::device_impl::~device_impl()\n";
  }
};

} // xrt

////////////////////////////////////////////////////////////////
// xrt_core::capture::device C++ API implementations 
////////////////////////////////////////////////////////////////
namespace xrt_core::capture::device {

std::shared_ptr<xrt::device_impl>
device(unsigned int index)
{
  xrt::device device(index);
  return device.get_handle();
}

xrt::uuid
load_xclbin(xrt::device& device, const std::string& fnm)
{
  return device.load_xclbin(fnm);
}
  
} // xrt_core::capture

namespace xrt {

////////////////////////////////////////////////////////////////
// xrt::device C++ API implementations (xrt_device.h)
////////////////////////////////////////////////////////////////
device::
device(unsigned int index)
  : m_handle(std::make_shared<device_impl>(index))
{
  std::cout << "xrt::device::device(" << index << ")\n";
}
  
device::
~device()
{
  std::cout << "xrt::device::~device()\n";
}

uuid
device::
load_xclbin(const std::string& fnm)
{
  std::cout << "xrt::device::load_xclbin(" << fnm << ")\n";
  return {};
}

} // xrt
