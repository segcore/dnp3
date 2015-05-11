/**
 * Licensed to Green Energy Corp (www.greenenergycorp.com) under one or
 * more contributor license agreements. See the NOTICE file distributed
 * with this work for additional information regarding copyright ownership.
 * Green Energy Corp licenses this file to you under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except in
 * compliance with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This project was forked on 01/01/2013 by Automatak, LLC and modifications
 * may have been made to this file. Automatak, LLC licenses these modifications
 * to you under the terms of the License.
 */
#ifndef OPENDNP3_IAPDUHANDLER_H
#define OPENDNP3_IAPDUHANDLER_H

#include "opendnp3/app/GroupVariationRecord.h"

#include "opendnp3/app/parsing/ICollection.h"

#include "opendnp3/app/MeasurementTypes.h"
#include "opendnp3/app/IINValue.h"
#include "opendnp3/app/ControlRelayOutputBlock.h"
#include "opendnp3/app/AnalogOutput.h"
#include "opendnp3/app/BinaryCommandEvent.h"
#include "opendnp3/app/AnalogCommandEvent.h"
#include "opendnp3/app/IndexedValue.h"
#include "opendnp3/app/OctetString.h"
#include "opendnp3/app/Range.h"

#include "opendnp3/gen/QualifierCode.h"

#include "opendnp3/objects/Group50.h"
#include "opendnp3/objects/Group51.h"
#include "opendnp3/objects/Group52.h"

#include "opendnp3/objects/Group120.h"
#include "opendnp3/objects/Group121.h"
#include "opendnp3/objects/Group122.h"

namespace opendnp3
{

/**
* Second stage of dealing with
*/
class IAPDUHandler
{
public:

	virtual void AllObjects(const HeaderRecord& record) = 0;
	virtual void OnRangeRequest(const HeaderRecord& record, const Range& range) = 0;
	virtual void OnCountRequest(const HeaderRecord& record, uint16_t count) = 0;

	// ------	Count callbacks for qualifiers 0x07 and 0x08 ------
	
	virtual void OnCount(const HeaderRecord& record, uint16_t pos, uint16_t total, const Group50Var1& value) = 0;
	virtual void OnCount(const HeaderRecord& record, uint16_t pos, uint16_t total, const Group51Var1& value) = 0;
	virtual void OnCount(const HeaderRecord& record, uint16_t pos, uint16_t total, const Group51Var2& value) = 0;
	virtual void OnCount(const HeaderRecord& record, uint16_t pos, uint16_t total, const Group52Var2& value) = 0;
	virtual void OnCount(const HeaderRecord& record, uint16_t pos, uint16_t total, const Group120Var4& value) = 0;

	// ------ Variable-length free-format types  ------

	virtual void OnFreeFormat(const HeaderRecord& record, const Group120Var1& value) = 0;
	virtual void OnFreeFormat(const HeaderRecord& record, const Group120Var2& value) = 0;
	virtual void OnFreeFormat(const HeaderRecord& record, const Group120Var5& value) = 0;
	virtual void OnFreeFormat(const HeaderRecord& record, const Group120Var6& value) = 0;

	// ------ Special ranged values like IIN (group 80) ------

	virtual void OnRange(const HeaderRecord& record, uint32_t count, const IINValue& value, uint16_t index) = 0;

	// ------ range callbacks for qualifiers 0x00 and 0x01 ------

	virtual void OnRange(const HeaderRecord& record, uint32_t count, const Binary& meas, uint16_t index) = 0;
	virtual void OnRange(const HeaderRecord& record, uint32_t count, const DoubleBitBinary& meas, uint16_t index) = 0;
	virtual void OnRange(const HeaderRecord& record, uint32_t count, const BinaryOutputStatus& meas, uint16_t index) = 0;
	virtual void OnRange(const HeaderRecord& record, uint32_t count, const Counter& meas, uint16_t index) = 0;
	virtual void OnRange(const HeaderRecord& record, uint32_t count, const FrozenCounter& meas, uint16_t index) = 0;
	virtual void OnRange(const HeaderRecord& record, uint32_t count, const Analog& meas, uint16_t index) = 0;
	virtual void OnRange(const HeaderRecord& record, uint32_t count, const AnalogOutputStatus& meas, uint16_t index) = 0;
	virtual void OnRange(const HeaderRecord& record, uint32_t count, const OctetString& meas, uint16_t index) = 0;
	virtual void OnRange(const HeaderRecord& record, uint32_t count, const TimeAndInterval& meas, uint16_t index) = 0;
	virtual void OnRange(const HeaderRecord& record, uint32_t count, const Group121Var1& meas, uint16_t index) = 0;

	// ------ index-prefix callbacks for qualifiers 0x17 and 0x28 ------

	virtual void OnIndexPrefix(const HeaderRecord& record, uint32_t count, const Binary& meas, uint16_t index) = 0;
	virtual void OnIndexPrefix(const HeaderRecord& record, uint32_t count, const BinaryOutputStatus& meas, uint16_t index) = 0;
	virtual void OnIndexPrefix(const HeaderRecord& record, uint32_t count, const DoubleBitBinary& meas, uint16_t index) = 0;
	virtual void OnIndexPrefix(const HeaderRecord& record, uint32_t count, const Counter& meas, uint16_t index) = 0;
	virtual void OnIndexPrefix(const HeaderRecord& record, uint32_t count, const FrozenCounter& meas, uint16_t index) = 0;
	virtual void OnIndexPrefix(const HeaderRecord& record, uint32_t count, const Analog& meas, uint16_t index) = 0;
	virtual void OnIndexPrefix(const HeaderRecord& record, uint32_t count, const AnalogOutputStatus& meas, uint16_t index) = 0;
	virtual void OnIndexPrefix(const HeaderRecord& record, uint32_t count, const OctetString& meas, uint16_t index) = 0;
	virtual void OnIndexPrefix(const HeaderRecord& record, uint32_t count, const TimeAndInterval& meas, uint16_t index) = 0;
	virtual void OnIndexPrefix(const HeaderRecord& record, uint32_t count, const BinaryCommandEvent& meas, uint16_t index) = 0;
	virtual void OnIndexPrefix(const HeaderRecord& record, uint32_t count, const AnalogCommandEvent& meas, uint16_t index) = 0;

	// --- security stat events ---

	virtual void OnIndexPrefix(const HeaderRecord& record, uint32_t count, const Group122Var1& meas, uint16_t index) = 0;
	virtual void OnIndexPrefix(const HeaderRecord& record, uint32_t count, const Group122Var2& meas, uint16_t index) = 0;

	// --- commmands ---

	virtual void OnIndexPrefix(const HeaderRecord& record, const ICollection<IndexedValue<ControlRelayOutputBlock, uint16_t>>& meas) = 0;
	virtual void OnIndexPrefix(const HeaderRecord& record, const ICollection<IndexedValue<AnalogOutputInt16, uint16_t>>& meas) = 0;
	virtual void OnIndexPrefix(const HeaderRecord& record, const ICollection<IndexedValue<AnalogOutputInt32, uint16_t>>& meas) = 0;
	virtual void OnIndexPrefix(const HeaderRecord& record, const ICollection<IndexedValue<AnalogOutputFloat32, uint16_t>>& meas) = 0;
	virtual void OnIndexPrefix(const HeaderRecord& record, const ICollection<IndexedValue<AnalogOutputDouble64, uint16_t>>& meas) = 0;
	
};

}

#endif