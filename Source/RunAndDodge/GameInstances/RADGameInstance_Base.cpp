// Fill out your copyright notice in the Description page of Project Settings.


#include "../GameInstances/RADGameInstance_Base.h"

void URADGameInstance_Base::SetbIsVSync(const bool& vSync)
{ bIsVSync = vSync; }

bool URADGameInstance_Base::GetbIsVSync() const
{ return bIsVSync; }
