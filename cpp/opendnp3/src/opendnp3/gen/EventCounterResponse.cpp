//
//  _   _         ______    _ _ _   _             _ _ _
// | \ | |       |  ____|  | (_) | (_)           | | | |
// |  \| | ___   | |__   __| |_| |_ _ _ __   __ _| | | |
// | . ` |/ _ \  |  __| / _` | | __| | '_ \ / _` | | | |
// | |\  | (_) | | |___| (_| | | |_| | | | | (_| |_|_|_|
// |_| \_|\___/  |______\__,_|_|\__|_|_| |_|\__, (_|_|_)
//                                           __/ |
//                                          |___/
// Copyright 2013 Automatak LLC
// 
// Automatak LLC (www.automatak.com) licenses this file
// to you under the the Apache License Version 2.0 (the "License"):
// 
// http://www.apache.org/licenses/LICENSE-2.0.html
//

#include "EventCounterResponse.h"

namespace opendnp3 {

std::string EventCounterResponseToString(EventCounterResponse arg)
{
  switch(arg)
  {
    case(EventCounterResponse::Group22Var1):
      return "Group22Var1";
    case(EventCounterResponse::Group22Var2):
      return "Group22Var2";
    case(EventCounterResponse::Group22Var5):
      return "Group22Var5";
    case(EventCounterResponse::Group22Var6):
      return "Group22Var6";
  }
  return "Group22Var6";
}
int EventCounterResponseToType(EventCounterResponse arg)
{
  return static_cast<int>(arg);
}
EventCounterResponse EventCounterResponseFromType(int arg)
{
  switch(arg)
  {
    case(0):
      return EventCounterResponse::Group22Var1;
    case(1):
      return EventCounterResponse::Group22Var2;
    case(2):
      return EventCounterResponse::Group22Var5;
    case(3):
      return EventCounterResponse::Group22Var6;
  }
  return EventCounterResponse::Group22Var6;
}

}