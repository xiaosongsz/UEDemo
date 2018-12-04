// Tencent is pleased to support the open source community by making sluaunreal available.

// Copyright (C) 2018 THL A29 Limited, a Tencent company. All rights reserved.
// Licensed under the BSD 3-Clause License (the "License"); 
// you may not use this file except in compliance with the License. You may obtain a copy of the License at

// https://opensource.org/licenses/BSD-3-Clause

// Unless required by applicable law or agreed to in writing, 
// software distributed under the License is distributed on an "AS IS" BASIS, 
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
// See the License for the specific language governing permissions and limitations under the License.

#include "LuaDelegate.h"
#include "LuaObject.h"
#include "LuaVar.h"

ULuaDelegate::ULuaDelegate(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
    ,luafunction(nullptr)
    ,ufunction(nullptr)
{
}

ULuaDelegate::~ULuaDelegate() {
    SafeDelete(luafunction);
}

void ULuaDelegate::EventTrigger()
{
    ensure(false); // never run here
}

void ULuaDelegate::ProcessEvent( UFunction* f, void* Parms ) {
    ensure(luafunction!=nullptr && ufunction!=nullptr);
    luafunction->callByUFunction(ufunction,reinterpret_cast<uint8*>(Parms));
}

void ULuaDelegate::bindFunction(slua::lua_State* L,int p,UFunction* ufunc) {
    luaL_checktype(L,p,LUA_TFUNCTION);
    ensure(ufunc);
    luafunction = new slua::LuaVar(L,p,slua::LuaVar::LV_FUNCTION);
    ufunction = ufunc;
}

void ULuaDelegate::bindFunction(slua::lua_State* L,int p) {
    luaL_checktype(L,p,LUA_TFUNCTION);
    luafunction = new slua::LuaVar(L,p,slua::LuaVar::LV_FUNCTION);
}

void ULuaDelegate::bindFunction(UFunction *ufunc) {
    ensure(ufunc);
    ufunction = ufunc;
}

namespace slua {

    struct LuaDelegateWrap {
        FMulticastScriptDelegate* delegate;
        UFunction* ufunc;
    };

    DefTypeName(LuaDelegateWrap);

    int LuaDelegate::Add(lua_State* L) {
        CheckUD(LuaDelegateWrap,L,1);

        // bind luafucntion and signature function
        auto obj = NewObject<ULuaDelegate>((UObject*)GetTransientPackage(),ULuaDelegate::StaticClass());
        obj->bindFunction(L,2,UD->ufunc);

        // add event listener
        FScriptDelegate Delegate;
        Delegate.BindUFunction(obj, TEXT("EventTrigger"));
        UD->delegate->AddUnique(Delegate);

        // add reference
        LuaObject::addRef(L,obj);

        lua_pushlightuserdata(L,obj);
        return 1;
    }

    int LuaDelegate::Remove(lua_State* L) {
        CheckUD(LuaDelegateWrap,L,1);
        if(!lua_islightuserdata(L,2))
            luaL_error(L,"arg 2 expect ULuaDelegate");
        auto obj =  reinterpret_cast<ULuaDelegate*>(lua_touserdata(L,2));
        if(!obj->IsValidLowLevel()) return 0;

        FScriptDelegate Delegate;
        Delegate.BindUFunction(obj, TEXT("EventTrigger"));

        // remove delegate
        UD->delegate->Remove(Delegate);

        // remove reference
        LuaObject::removeRef(L,obj);

        return 0;
    }

    int LuaDelegate::Clear(lua_State* L) {
        CheckUD(LuaDelegateWrap,L,1);
        auto array = UD->delegate->GetAllObjects();
        for(auto it:array) {
            LuaObject::removeRef(L,it);
        }
        UD->delegate->Clear();
        return 0;
    }

    int LuaDelegate::gc(lua_State* L) { 
        CheckUD(LuaDelegateWrap,L,1);
        delete UD;
        return 0;    
    }
   

    int LuaDelegate::setupMT(lua_State* L) {
        LuaObject::setupMTSelfSearch(L);

        RegMetaMethod(L,Add);
        RegMetaMethod(L,Remove);
        RegMetaMethod(L,Clear);
        return 0;
    }

    int LuaDelegate::push(lua_State* L,FMulticastScriptDelegate* delegate,UFunction* ufunc) {
        LuaDelegateWrap* wrapobj = new LuaDelegateWrap{delegate,ufunc};
        return LuaObject::pushType<LuaDelegateWrap*>(L,wrapobj,"LuaDelegateWrap",setupMT,gc);
    }



}