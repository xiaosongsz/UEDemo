// Tencent is pleased to support the open source community by making sluaunreal available.

// Copyright (C) 2018 THL A29 Limited, a Tencent company. All rights reserved.
// Licensed under the BSD 3-Clause License (the "License"); 
// you may not use this file except in compliance with the License. You may obtain a copy of the License at

// https://opensource.org/licenses/BSD-3-Clause

// Unless required by applicable law or agreed to in writing, 
// software distributed under the License is distributed on an "AS IS" BASIS, 
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
// See the License for the specific language governing permissions and limitations under the License.

#pragma once
#include "LuaReference.h"

namespace slua {
	namespace LuaReference {

		void addRefByStruct(FReferenceCollector& collector, UStruct* us, void* base) {
			for (TFieldIterator<const UProperty> it(us); it; ++it)
				addRefByProperty(collector, *it, base);
		}

		void addRefByDelegate(FReferenceCollector& collector, const FScriptDelegate&) {
			// TODO
		}

		void addRefByMulticastDelegate(FReferenceCollector& collector, const FMulticastScriptDelegate&) {
			// TODO
		}


		bool addRefByProperty(FReferenceCollector& collector, const UProperty* prop, void* base) {
			bool ret = false;
			if (auto p = Cast<UObjectProperty>(prop)) {
				for (int n = 0; n < p->ArrayDim; ++n)
				{
					void* value = p->ContainerPtrToValuePtr<void>(base, n);
					UObject* obj = p->GetObjectPropertyValue(value);
					if (obj)
					{
						UObject* newobj = obj;
						collector.AddReferencedObject(newobj);

						if (newobj != obj)
						{
							ret = true;
							p->SetObjectPropertyValue(value, newobj);
						}
					}
				}
				return ret;
			}

			if (auto p = Cast<UArrayProperty>(prop))
			{
				for (int n = 0; n < p->ArrayDim; ++n)
				{
					FScriptArrayHelper_InContainer helper(p, base, n);
					for (int32 index = 0; index < helper.Num(); ++index)
					{
						ret |= addRefByProperty(collector, p->Inner, helper.GetRawPtr(n));
					}
				}
				return ret;
			}

			if (auto p = Cast<UStructProperty>(prop)) {
				for (int n = 0; n < prop->ArrayDim; ++n) {
					addRefByStruct(collector, p->Struct, p->ContainerPtrToValuePtr<void>(base, n));
				}
				return false;
			}

			if (auto p = Cast<UDelegateProperty>(prop)) {
				for (int n = 0; n < prop->ArrayDim; ++n) {
					FScriptDelegate* value = p->GetPropertyValuePtr(p->ContainerPtrToValuePtr<void>(base, n));
					addRefByDelegate(collector, *value);
				}
				return false;
			}

			if (auto p = Cast<UMapProperty>(prop))
			{
				for (int n = 0; n < p->ArrayDim; ++n)
				{
					bool keyChanged = false;
					bool valuesChanged = false;
					FScriptMapHelper_InContainer helper(p, base, n);

					for (int index = 0; index < helper.GetMaxIndex(); ++index)
					{
						if (helper.IsValidIndex(index))
						{
							keyChanged = addRefByProperty(collector, helper.GetKeyProperty(), helper.GetKeyPtr(index));
							valuesChanged = addRefByProperty(collector, helper.GetValueProperty(), helper.GetValuePtr(index));
						}
					}

					if (keyChanged || valuesChanged)
					{
						ret = true;
						if (keyChanged)
						{
							helper.Rehash();
						}
					}
				}
				return ret;
			}

			if (auto p = Cast<UMulticastDelegateProperty>(prop))
			{
				for (int n = 0; n < p->ArrayDim; ++n)
				{
					FMulticastScriptDelegate* Value = p->GetPropertyValuePtr(p->ContainerPtrToValuePtr<void>(base, n));
					addRefByMulticastDelegate(collector, *Value);
				}
				return false;
			}

			return false;
		}
	}
}