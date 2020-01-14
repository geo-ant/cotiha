/*
 * djb2.hpp
 *
 *  Created on: Jan 14, 2020
 *      Author: geo
 */

#ifndef DJB2_HPP_
#define DJB2_HPP_

#include <string_view>

namespace cotiha
{


namespace detail
{
	template<typename T>
	unsigned long constexpr djb2_xor_impl(const std::basic_string_view<T> & strview, size_t idx, unsigned long hash)
	{
		return (idx>=strview.length()) ? hash : djb2_xor_impl(strview,idx+1,(33*hash)^strview[idx]);
	}
}
	template<typename T>
	unsigned long constexpr djb2_xor(const std::basic_string_view<T> & strview)
	{
		return detail::djb2_xor_impl(strview, 0, 5381);
	}

}

#endif /* DJB2_HPP_ */
