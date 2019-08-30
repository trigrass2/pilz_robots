/*
 * Copyright (c) 2019 Pilz GmbH & Co. KG
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef WAIT_FOR_SERVICE_H
#define WAIT_FOR_SERVICE_H

#include <string>

#include <ros/ros.h>
#include <ros/duration.h>

#include <prbt_hardware_support/wait_for_timeouts.h>

namespace prbt_hardware_support
{
/**
 * @brief Waits until the specified service starts.
 */
static inline void
waitForService(const std::string service_name,
               const double retry_timeout = DEFAULT_RETRY_TIMEOUT,
               const double msg_output_period = DEFAULT_MSG_OUTPUT_PERIOD)
{
  while (!ros::service::waitForService(service_name,
                                       ros::Duration(retry_timeout)) &&
         ros::ok())
  {
    ROS_WARN_STREAM_DELAYED_THROTTLE(
        msg_output_period, "Waiting for service \"" + service_name + "\"...");
  }
}

}  // namespace prbt_hardware_support

#endif  // WAIT_FOR_SERVICE_H
