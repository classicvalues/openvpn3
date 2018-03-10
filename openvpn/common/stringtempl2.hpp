//    OpenVPN -- An application to securely tunnel IP networks
//               over a single port, with support for SSL/TLS-based
//               session authentication and key exchange,
//               packet encryption, packet authentication, and
//               packet compression.
//
//    Copyright (C) 2012-2017 OpenVPN Inc.
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License Version 3
//    as published by the Free Software Foundation.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program in the COPYING file.
//    If not, see <http://www.gnu.org/licenses/>.


#pragma once

#include <string>
#include <type_traits>

#include <openvpn/common/stringtempl.hpp>

namespace openvpn {
  namespace StringTempl {

    template <typename T>
    inline auto to_string(const T& t) -> decltype(t.to_string())
    {
      return t.to_string();
    }

    template <typename T,
	      typename std::enable_if<std::is_arithmetic<T>::value, int>::type = 0>
    inline std::string to_string(T value)
    {
      return std::to_string(value);
    }

  }
}
